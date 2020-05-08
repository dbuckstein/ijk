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

	ijkThread.inl
	Thread utility inline implementation.
*/

#ifdef _IJK_THREAD_H_
#ifndef _IJK_THREAD_INL_
#define _IJK_THREAD_INL_


//-----------------------------------------------------------------------------

ijk_inl iret ijkMutexLock(ijkMutex* const mutex)
{
	if (mutex)
	{

	}
	return ijk_fail_invalidparams;
}

ijk_inl iret ijkMutexLockWait(ijkMutex* const mutex)
{
	if (mutex)
	{

	}
	return ijk_fail_invalidparams;
}

ijk_inl iret ijkMutexUnlock(ijkMutex* const mutex)
{
	if (mutex)
	{

	}
	return ijk_fail_invalidparams;
}

ijk_inl iret ijkMutexIsLocked(ijkMutex const* const mutex)
{
	if (mutex)
	{

	}
	return ijk_fail_invalidparams;
}

ijk_inl iret ijkMutexIsLockedByCaller(ijkMutex const* const mutex)
{
	if (mutex)
	{

	}
	return ijk_fail_invalidparams;
}

ijk_inl iret ijkMutexIsUnlocked(ijkMutex const* const mutex)
{
	if (mutex)
	{

	}
	return ijk_fail_invalidparams;
}


//-----------------------------------------------------------------------------


#endif	// !_IJK_THREAD_INL_
#endif	// _IJK_THREAD_H_