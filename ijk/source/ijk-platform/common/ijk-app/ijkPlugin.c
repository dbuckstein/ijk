/*
   Copyright 2020 Daniel S. Buckstein

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

/*
	ijk: an open-source, cross-platform, light-weight,
		c-based rendering framework
	By Daniel S. Buckstein

	ijkPlugin.c
	Platform-agnostic plugin management source.
*/

#include "ijk/ijk-platform/ijk-app/ijkPlugin.h"

#if ijk_platform_is(WINDOWS)
// Windows / non-GNU-C
#include <Windows.h>
#else	// !WINDOWS
// Unix (Mac/Linux) / GNU-C
#include <dlfcn.h>
#endif	// WINDOWS

#include "ijk/ijk-platform/ijk-app/_util/_inl/ijk-dylib.inl"

#include <stdio.h>
#include <stdlib.h>


//-----------------------------------------------------------------------------

// Default callbacks.
///
iret ijkPluginCallback_default_p(ptr p) { return ijk_fail_invalidparams; }								// Default window callback with pointer parameter.
iret ijkPluginCallback_default_pi(ptr p, i32 i) { return ijk_fail_invalidparams; }						// Default window callback with pointer and integer parameters.
iret ijkPluginCallback_default_pii(ptr p, i32 i0, i32 i1) { return ijk_fail_invalidparams; }			// Default window callback with pointer and two integer parameters.
iret ijkPluginCallback_default_piii(ptr p, i32 i0, i32 i1, i32 i2) { return ijk_fail_invalidparams; }	// Default window callback with pointer and three integer parameters.
iret ijkPluginCallback_default_pip2(ptr p, i32 i, ptr* p_out) { return ijk_fail_invalidparams; }		// Default window callback with pointer and pointer-to-pointer parameters.


//-----------------------------------------------------------------------------

// ijkPluginInternalSetCallbackDefaults
//	Set default callbacks for window interface.
//		param plugin: pointer to plugin descriptor
//			valid: non-null
void ijkPluginInternalSetCallbackDefaults(ijkPlugin* const plugin)
{
	// set default function for all callbacks
	plugin->ijkPluginCallback_load = plugin->ijkPluginCallback_load_hot = ijkPluginCallback_default_pip2;
	plugin->ijkPluginCallback_reload = plugin->ijkPluginCallback_reload_hot = ijkPluginCallback_default_pip2;
	plugin->ijkPluginCallback_unload = plugin->ijkPluginCallback_unload_hot = ijkPluginCallback_default_p;
	plugin->ijkPluginCallback_winActivate = plugin->ijkPluginCallback_winDeactivate = ijkPluginCallback_default_p;
	plugin->ijkPluginCallback_display = plugin->ijkPluginCallback_idle = ijkPluginCallback_default_p;
	plugin->ijkPluginCallback_winMove = plugin->ijkPluginCallback_winResize = ijkPluginCallback_default_pii;
	plugin->ijkPluginCallback_keyPressVirt = plugin->ijkPluginCallback_keyPressAscii = ijkPluginCallback_default_pi;
	plugin->ijkPluginCallback_keyHoldVirt = plugin->ijkPluginCallback_keyHoldAscii = ijkPluginCallback_default_pi;
	plugin->ijkPluginCallback_keyReleaseVirt = plugin->ijkPluginCallback_keyReleaseAscii = ijkPluginCallback_default_pi;
	plugin->ijkPluginCallback_mouseClick = plugin->ijkPluginCallback_mouseClick2 = ijkPluginCallback_default_piii;
	plugin->ijkPluginCallback_mouseRelease = plugin->ijkPluginCallback_mouseWheel = ijkPluginCallback_default_piii;
	plugin->ijkPluginCallback_mouseMove = plugin->ijkPluginCallback_mouseMove_ext = ijkPluginCallback_default_pii;
	plugin->ijkPluginCallback_mouseEnter = plugin->ijkPluginCallback_mouseLeave = ijkPluginCallback_default_pii;
	plugin->ijkPluginCallback_willReload = plugin->ijkPluginCallback_willUnload = ijkPluginCallback_default_p;
	plugin->ijkPluginCallback_user1 = plugin->ijkPluginCallback_user2 = plugin->ijkPluginCallback_user3 = ijkPluginCallback_default_p;
	plugin->ijkPluginCallback_user4c = ijkPluginCallback_default_pip2;
}


//-----------------------------------------------------------------------------

// ijk_plugin_load_symbol
//	Load symbol with contingency.
#define ijk_plugin_load_symbol(plugin,symbol,def)	if (ijk_isfailure(ijkDylibGetSymbol((IJK_DYLIB_FUNC*)(&plugin->symbol), plugin->handle, ijk_tokenstr(symbol)))) plugin->symbol = def


//-----------------------------------------------------------------------------

iret ijkPluginInfoSet(ijkPluginInfo* const pluginInfo_out, tag const name, tag const dylib, tag const author, tag const version, byte const info[128])
{
	if (pluginInfo_out)
	{
		// defaults
		ijkPluginInfo const def = { "ijk Plugin (SDK)", "ijk-plugin", "Daniel S. Buckstein", "ijk-plugin:0.0.0", "Default plugin loaded and built with current SDK configuration." };

		// copy
		strncpy(pluginInfo_out->name, (name && *name) ? name : def.name, szb(pluginInfo_out->name));
		strncpy(pluginInfo_out->dylib, (dylib && *dylib) ? dylib : def.dylib, szb(pluginInfo_out->dylib));
		strncpy(pluginInfo_out->author, (author && *author) ? author : def.author, szb(pluginInfo_out->author));
		strncpy(pluginInfo_out->version, (version && *version) ? version : def.version, szb(pluginInfo_out->version));
		strncpy(pluginInfo_out->info, (info && *info) ? info : def.info, szb(pluginInfo_out->info));

		// done
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


iret ijkPluginInfoSetDefault(ijkPluginInfo* const pluginInfo_out, tag const author, tag const version)
{
	return ijkPluginInfoSet(pluginInfo_out, 0, 0, author, version, 0);
}


iret ijkPluginInfoReset(ijkPluginInfo* const pluginInfo)
{
	return ijkPluginInfoSet(pluginInfo, 0, 0, 0, 0, 0);
}


iret ijkPluginInfoListLoad(ijkPluginInfo** const pluginInfoList_out, size* const count_out, kptag const resourceFile)
{
	if (pluginInfoList_out && !*pluginInfoList_out && count_out && resourceFile && *resourceFile)
	{
		iret result = ijk_fail_operationfail;
		FILE* fp;
		if (fp = fopen(resourceFile, "r"))
		{
			byte line[512] = { 0 }, * linePtr;
			size count = 0;
			i32 const sz = szb(line);

			// get number of list items
			while (fgets(line, sz, fp))
				if (*line == '@')
					++count;

			// if found potential entries
			if (count)
			{
				if (fp = freopen(resourceFile, "r", fp))
				{
					ijkPluginInfo tmp = { 0 }, * const list = (ijkPluginInfo*)malloc(szb(tmp) * count);
					ptag data;

					// parse entries
					count = 0;
					while (linePtr = fgets(line, sz, fp))
						if (*(linePtr++) == '@')
						{
							// skip opening quote and copy until closing quote
							// name
							data = tmp.name;
							while (*(linePtr++) != '\"');
							while (*(linePtr) != '\"')
								*(data++) = *(linePtr++);
							++linePtr;

							// library file
							data = tmp.dylib;
							while (*(linePtr++) != '\"');
							while (*(linePtr) != '\"')
								*(data++) = *(linePtr++);
							++linePtr;

							// author
							data = tmp.author;
							while (*(linePtr++) != '\"');
							while (*(linePtr) != '\"')
								*(data++) = *(linePtr++);
							++linePtr;

							// version
							data = tmp.version;
							while (*(linePtr++) != '\"');
							while (*(linePtr) != '\"')
								*(data++) = *(linePtr++);
							++linePtr;

							// description
							data = tmp.info;
							while (*(linePtr++) != '\"');
							while (*(linePtr) != '\"')
								*(data++) = *(linePtr++);
							++linePtr;

							// copy
							list[count++] = tmp;
						}

					// if still valid entries
					if (count)
					{
						// done
						*pluginInfoList_out = list;
						*count_out = count;
						result = ijk_success;
					}
				}
			}
			// close
			fclose(fp);
		}
		return result;
	}
	return ijk_fail_invalidparams;
}


iret ijkPluginInfoListRelease(ijkPluginInfo** const pluginInfoList)
{
	if (pluginInfoList && *pluginInfoList)
	{
		// release
		free(*pluginInfoList);
		*pluginInfoList = 0;

		// done
		return ijk_success;
	}
	return ijk_fail_invalidparams;
}


iret ijkPluginLoad(ijkPlugin* const plugin_out, ijkPluginInfo const* const pluginInfo)
{
	if (plugin_out && !plugin_out->handle)
	{
		// set path
		byte path[64] = "./ijk-plugin/";
		strcat(strcat(path, pluginInfo->dylib), IJK_DYLIB_EXT);
		if (ijk_issuccess(ijkDylibLoad((IJK_DYLIB_HANDLE*)(&plugin_out->handle), path)))
		{
			// attempt to load all symbols
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_load, ijkPluginCallback_default_pip2);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_load_hot, ijkPluginCallback_default_pip2);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_reload, ijkPluginCallback_default_pip2);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_reload_hot, ijkPluginCallback_default_pip2);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_unload, ijkPluginCallback_default_p);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_unload_hot, ijkPluginCallback_default_p);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_winActivate, ijkPluginCallback_default_p);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_winDeactivate, ijkPluginCallback_default_p);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_display, ijkPluginCallback_default_p);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_idle, ijkPluginCallback_default_p);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_winMove, ijkPluginCallback_default_pii);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_winResize, ijkPluginCallback_default_pii);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_keyPressVirt, ijkPluginCallback_default_pi);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_keyPressAscii, ijkPluginCallback_default_pi);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_keyHoldVirt, ijkPluginCallback_default_pi);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_keyHoldAscii, ijkPluginCallback_default_pi);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_keyReleaseVirt, ijkPluginCallback_default_pi);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_keyReleaseAscii, ijkPluginCallback_default_pi);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_mouseClick, ijkPluginCallback_default_piii);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_mouseClick2, ijkPluginCallback_default_piii);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_mouseRelease, ijkPluginCallback_default_piii);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_mouseWheel, ijkPluginCallback_default_piii);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_mouseMove, ijkPluginCallback_default_pii);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_mouseMove_ext, ijkPluginCallback_default_pii);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_mouseEnter, ijkPluginCallback_default_pii);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_mouseLeave, ijkPluginCallback_default_pii);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_willReload, ijkPluginCallback_default_p);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_willUnload, ijkPluginCallback_default_p);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_user1, ijkPluginCallback_default_p);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_user2, ijkPluginCallback_default_p);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_user3, ijkPluginCallback_default_p);
			ijk_plugin_load_symbol(plugin_out, ijkPluginCallback_user4c, ijkPluginCallback_default_pip2);

			// done
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


iret ijkPluginUnload(ijkPlugin* const plugin)
{
	if (plugin && plugin->handle)
	{
		// unload
		if (ijk_issuccess(ijkDylibUnload((IJK_DYLIB_HANDLE)(plugin->handle))))
		{
			// reset
			ijkPluginInternalSetCallbackDefaults(plugin);
			return ijk_success;
		}
		return ijk_fail_operationfail;
	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------
