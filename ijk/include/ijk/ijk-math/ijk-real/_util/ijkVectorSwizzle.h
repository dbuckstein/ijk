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

	ijkVectorSwizzle.h
	Vector swizzling types and functions (built for C++).
*/

#ifdef _IJK_VECTOR_H_
#ifndef _IJK_VECTORSWIZZLE_H_
#define _IJK_VECTORSWIZZLE_H_


#ifdef __cplusplus

// IJK_SWIZZLE_MACRO_DECL
#pragma region IJK_SWIZZLE_MACRO_DECL

// Internal swizzling implementation.
///
#define IJK_SWIZZLE_U1(swiz,inl,cf,ot,rtb,x,...)			swiz(inl,cf,ot,rtb,1,x,,,,x)	// unique 1
#define IJK_SWIZZLE_U2(swiz,inl,cf,ot,rtb,x,y,...)			swiz(inl,cf,ot,rtb,2,x,y,,,x,y)	// unique 2
#define IJK_SWIZZLE_U3(swiz,inl,cf,ot,rtb,x,y,z,...)		swiz(inl,cf,ot,rtb,3,x,y,z,,x,y,z)	// unique 3
#define IJK_SWIZZLE_U4(swiz,inl,cf,ot,rtb,x,y,z,w,...)		swiz(inl,cf,ot,rtb,4,x,y,z,w,x,y,z,w)	// unique 4
#define IJK_SWIZZLE_D1(swiz,inl,cf,ot,rtb,x,...)			swiz(inl,cf,ot,rtb,2,x,x,,,x,x); swiz(inl,cf,ot,rtb,3,x,x,x,,x,x,x); swiz(inl,cf,ot,rtb,4,x,x,x,x,x,x,x,x)	// duplicate 1
#define IJK_SWIZZLE_D2(swiz,inl,cf,ot,rtb,x,y,...)			swiz(inl,cf,ot,rtb,3,x,x,y,,x,x,y); swiz(inl,cf,ot,rtb,3,x,y,x,,x,y,x); swiz(inl,cf,ot,rtb,3,x,y,y,,x,y,y); swiz(inl,cf,ot,rtb,4,x,x,x,y,x,x,x,y); swiz(inl,cf,ot,rtb,4,x,x,y,x,x,x,y,x); swiz(inl,cf,ot,rtb,4,x,x,y,y,x,x,y,y); swiz(inl,cf,ot,rtb,4,x,y,x,x,x,y,x,x); swiz(inl,cf,ot,rtb,4,x,y,x,y,x,y,x,y); swiz(inl,cf,ot,rtb,4,x,y,y,x,x,y,y,x); swiz(inl,cf,ot,rtb,4,x,y,y,y,x,y,y,y)	// duplicate 2
#define IJK_SWIZZLE_D3(swiz,inl,cf,ot,rtb,x,y,z,...)		swiz(inl,cf,ot,rtb,4,x,x,y,z,x,x,y,z); swiz(inl,cf,ot,rtb,4,x,y,x,z,x,y,x,z); swiz(inl,cf,ot,rtb,4,x,y,y,z,x,y,y,z); swiz(inl,cf,ot,rtb,4,x,y,z,z,x,y,z,z); swiz(inl,cf,ot,rtb,4,x,y,z,y,x,y,z,y); swiz(inl,cf,ot,rtb,4,x,y,z,x,x,y,z,x)	// duplicate 3
#define IJK_SWIZZLE_D4(swiz,inl,cf,ot,rtb,x,y,z,w,...)		// duplicate 4	// empty set, no combos remaining
#define IJK_SWIZZLE_F1(swiz,inl,cf,ot,rtb,f1,...)			f1(swiz,inl,cf,ot,rtb,x,,,)
#define IJK_SWIZZLE_F2(swiz,inl,cf,ot,rtb,f1,f2,...)		IJK_SWIZZLE_F1(swiz,inl,cf,ot,rtb,f1); f1(swiz,inl,cf,ot,rtb,y,,,); f2(swiz,inl,cf,ot,rtb,x,y,,); f2(swiz,inl,cf,ot,rtb,y,x,,)
#define IJK_SWIZZLE_F3(swiz,inl,cf,ot,rtb,f1,f2,f3,...)		IJK_SWIZZLE_F2(swiz,inl,cf,ot,rtb,f1,f2); f1(swiz,inl,cf,ot,rtb,z,,,); f2(swiz,inl,cf,ot,rtb,x,z,,); f2(swiz,inl,cf,ot,rtb,z,x,,); f2(swiz,inl,cf,ot,rtb,y,z,,); f2(swiz,inl,cf,ot,rtb,z,y,,); f3(swiz,inl,cf,ot,rtb,x,y,z,); f3(swiz,inl,cf,ot,rtb,y,z,x,); f3(swiz,inl,cf,ot,rtb,z,x,y,); f3(swiz,inl,cf,ot,rtb,y,x,z,); f3(swiz,inl,cf,ot,rtb,x,z,y,); f3(swiz,inl,cf,ot,rtb,z,y,x,)
#define IJK_SWIZZLE_F4(swiz,inl,cf,ot,rtb,f1,f2,f3,f4,...)	IJK_SWIZZLE_F3(swiz,inl,cf,ot,rtb,f1,f2,f3); f1(swiz,inl,cf,ot,rtb,w,,,); f2(swiz,inl,cf,ot,rtb,x,w,,); f2(swiz,inl,cf,ot,rtb,w,x,,); f2(swiz,inl,cf,ot,rtb,y,w,,); f2(swiz,inl,cf,ot,rtb,w,y,,); f2(swiz,inl,cf,ot,rtb,z,w,,); f2(swiz,inl,cf,ot,rtb,w,z,,); f3(swiz,inl,cf,ot,rtb,x,y,w,); f3(swiz,inl,cf,ot,rtb,y,x,w,); f3(swiz,inl,cf,ot,rtb,x,z,w,); f3(swiz,inl,cf,ot,rtb,z,x,w,); f3(swiz,inl,cf,ot,rtb,x,w,y,); f3(swiz,inl,cf,ot,rtb,w,x,y,); f3(swiz,inl,cf,ot,rtb,y,z,w,); f3(swiz,inl,cf,ot,rtb,z,y,w,); f3(swiz,inl,cf,ot,rtb,y,w,x,); f3(swiz,inl,cf,ot,rtb,w,y,x,); f3(swiz,inl,cf,ot,rtb,x,w,z,); f3(swiz,inl,cf,ot,rtb,w,x,z,); f3(swiz,inl,cf,ot,rtb,y,w,z,); f3(swiz,inl,cf,ot,rtb,w,y,z,); f3(swiz,inl,cf,ot,rtb,z,w,x,); f3(swiz,inl,cf,ot,rtb,w,z,x,); f3(swiz,inl,cf,ot,rtb,z,w,y,); f3(swiz,inl,cf,ot,rtb,w,z,y,); f4(swiz,inl,cf,ot,rtb,x,y,z,w); f4(swiz,inl,cf,ot,rtb,x,y,w,z); f4(swiz,inl,cf,ot,rtb,x,z,y,w); f4(swiz,inl,cf,ot,rtb,x,z,w,y); f4(swiz,inl,cf,ot,rtb,x,w,y,z); f4(swiz,inl,cf,ot,rtb,x,w,z,y); f4(swiz,inl,cf,ot,rtb,y,x,z,w); f4(swiz,inl,cf,ot,rtb,y,x,w,z); f4(swiz,inl,cf,ot,rtb,y,z,x,w); f4(swiz,inl,cf,ot,rtb,y,z,w,x); f4(swiz,inl,cf,ot,rtb,y,w,x,z); f4(swiz,inl,cf,ot,rtb,y,w,z,x); f4(swiz,inl,cf,ot,rtb,z,x,y,w); f4(swiz,inl,cf,ot,rtb,z,x,w,y); f4(swiz,inl,cf,ot,rtb,z,y,x,w); f4(swiz,inl,cf,ot,rtb,z,y,w,x); f4(swiz,inl,cf,ot,rtb,z,w,x,y); f4(swiz,inl,cf,ot,rtb,z,w,y,x); f4(swiz,inl,cf,ot,rtb,w,x,y,z); f4(swiz,inl,cf,ot,rtb,w,x,z,y); f4(swiz,inl,cf,ot,rtb,w,y,x,z); f4(swiz,inl,cf,ot,rtb,w,y,z,x); f4(swiz,inl,cf,ot,rtb,w,z,x,y); f4(swiz,inl,cf,ot,rtb,w,z,y,x)
#define IJK_SWIZZLE(F,swiz,inl,cf,ot,rtb,f1,f2,f3,f4)		F(swiz,inl,cf,ot,rtb,f1,f2,f3,f4)

// IJK_SWIZZLE_READONLY
//	Configure read-only (constant) swizzling in calling interface.
//		param swizzleFormat: swizzle function format (see options below)
//		param returnTypeBase: return type, without size, of swizzle results (e.g. 'ivec' not 'ivec2'; may differ from 'ownerTypeBase')
//		param ownerTypeBase: owner type, without size, of swizzle function (e.g. 'ivec' not 'ivec2')
//		param ownerTypeSize: owner type size (e.g. just '2' for some version of 2D vector)
//		param __VA_ARGS__ (optional): pass 'inline' to add inline qualifier to functions
#define IJK_SWIZZLE_READONLY(swizzleFormat,returnTypeBase,ownerTypeBase,ownerTypeSize,...)	IJK_SWIZZLE(IJK_SWIZZLE_F##ownerTypeSize,swizzleFormat,__VA_ARGS__,const,ownerTypeBase##ownerTypeSize,returnTypeBase,IJK_SWIZZLE_D1,IJK_SWIZZLE_D2,IJK_SWIZZLE_D3,IJK_SWIZZLE_D4); IJK_SWIZZLE(IJK_SWIZZLE_F##ownerTypeSize,swizzleFormat,__VA_ARGS__,const,ownerTypeBase##ownerTypeSize,returnTypeBase,IJK_SWIZZLE_U1,IJK_SWIZZLE_U2,IJK_SWIZZLE_U3,IJK_SWIZZLE_U4)

// IJK_SWIZZLE_WRITABLE
//	Configure writable (non-constant) swizzling in calling interface.
//		param swizzleFormat: swizzle function format (see options below)
//		param returnTypeBase: return type, without size, of swizzle results (e.g. 'ivec' not 'ivec2'; may differ from 'ownerTypeBase')
//		param ownerTypeBase: owner type, without size, of swizzle function (e.g. 'ivec' not 'ivec2')
//		param ownerTypeSize: owner type size (e.g. just '2' for some version of 2D vector)
//		param __VA_ARGS__ (optional): pass 'inline' to add inline qualifier to functions
#define IJK_SWIZZLE_WRITABLE(swizzleFormat,returnTypeBase,ownerTypeBase,ownerTypeSize,...)	IJK_SWIZZLE(IJK_SWIZZLE_F##ownerTypeSize,swizzleFormat,__VA_ARGS__,,ownerTypeBase##ownerTypeSize,returnTypeBase,IJK_SWIZZLE_U1,IJK_SWIZZLE_U2,IJK_SWIZZLE_U3,IJK_SWIZZLE_U4)

// IJK_SWIZZLE_ALL
//	Configure swizzling in calling interface.
//		param swizzleFormat_readonly: swizzle function format for read-only functions (see options below)
//		param swizzleFormat_writable: swizzle function format for writable functions (see options below)
//		param returnTypeBase_readonly: return type, without size, of read-only swizzle results
//		param returnTypeBase_writable: return type, without size, of read-only swizzle results
//		param ownerTypeBase: owner type, without size, of swizzle function (e.g. 'ivec' not 'ivec2')
//		param ownerTypeSize: owner type size (e.g. just '2' for some version of 2D vector)
//		param __VA_ARGS__ (optional): pass 'inline' to add inline qualifier to functions
#define IJK_SWIZZLE_ALL(swizzleFormat_readonly,swizzleFormat_writable,returnTypeBase_readonly,returnTypeBase_writable,ownerTypeBase,ownerTypeSize,...)	IJK_SWIZZLE_READONLY(swizzleFormat_readonly,returnTypeBase_readonly,ownerTypeBase,ownerTypeSize,__VA_ARGS__); IJK_SWIZZLE_WRITABLE(swizzleFormat_writable,returnTypeBase_writable,ownerTypeBase,ownerTypeSize,__VA_ARGS__)


// IJK_SWIZZLE_DECL
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to declare swizzling functions within target interface.
//	Requires paired use of IJK_SWIZZLE_IMPL_TEMP, IJK_SWIZZLE_IMPL_RTEMP or
//	IJK_SWIZZLE_IMPL outside of target interface.
#define IJK_SWIZZLE_DECL(inl,cf,ot,rtb,rts,x,y,z,w,...)										inl cf rtb##rts __swiz__##x##y##z##w() cf

// IJK_SWIZZLE_DECL_IMPL
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to declare and implement swizzling functions within
//	target interface.
#define IJK_SWIZZLE_DECL_IMPL(inl,cf,ot,rtb,rts,x,y,z,w,...)								inl cf rtb##rts __swiz__##x##y##z##w() cf { return rtb##rts(__VA_ARGS__); }

// IJK_SWIZZLE_IMPL
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to implement swizzling functions outside of target
//	interface. Requires prior paired use of IJK_SWIZZLE_DECL within target
//	interface.
#define IJK_SWIZZLE_IMPL(inl,cf,ot,rtb,rts,x,y,z,w,...)										inl cf rtb##rts ot::__swiz__##x##y##z##w() cf { return rtb##rts(__VA_ARGS__); }

// IJK_SWIZZLE_DECL_RTEMP
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to declare swizzling functions within target interface
//	using template return types. Requires paired use of IJK_SWIZZLE_IMPL_RTEMP
//	outside of target interface.
#define IJK_SWIZZLE_DECL_RTEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)								inl cf rtb##rts<type> __swiz__##x##y##z##w() cf

// IJK_SWIZZLE_DECL_IMPL_RTEMP
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to declare and implement swizzling functions within target
//	template interface using template return types.
#define IJK_SWIZZLE_DECL_IMPL_RTEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)							inl cf rtb##rts<type> __swiz__##x##y##z##w() cf { return rtb##rts<type>(__VA_ARGS__); }

// IJK_SWIZZLE_IMPL_TEMP
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to implement swizzling functions outside of target template
//	interface. Requires prior paired use of IJK_SWIZZLE_DECL within target
//	interface.
#define IJK_SWIZZLE_IMPL_TEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)								template<typename type> inl cf rtb##rts ot<type>::__swiz__##x##y##z##w() cf { return rtb##rts(__VA_ARGS__); }

// IJK_SWIZZLE_IMPL_RTEMP
//	Pass as 'swizzleFormat' to IJK_SWIZZLE_READONLY, IJK_SWIZZLE_READONLY or
//	IJK_SWIZZLE_ALL to implement swizzling functions outside of target template
//	interface using template return types. Requires prior IJK_SWIZZLE_DECL or
//	IJK_SWIZZLE_DECL_RTEMP within target interface.
#define IJK_SWIZZLE_IMPL_RTEMP(inl,cf,ot,rtb,rts,x,y,z,w,...)								template<typename type> inl cf rtb##rts<type> ot<type>::__swiz__##x##y##z##w() cf { return rtb##rts<type>(__VA_ARGS__); }

// Convenience macros for declaring template vector types.
///
#define IJK_TVEC_IMPL(vecSize)			IJK_VECA_IMPL(type,vecSize)

#pragma endregion
// IJK_SWIZZLE_MACRO_DECL

//-----------------------------------------------------------------------------

template<typename type> struct ttvec1;	// Swizzle scalar base type
template<typename type> struct ttvec2;	// Swizzle 2D vector base type
template<typename type> struct ttvec3;	// Swizzle 3D vector base type
template<typename type> struct ttvec4;	// Swizzle 4D vector base type

template<typename type> struct stvec1;	// Swizzle scalar utility type
template<typename type> struct stvec2;	// Swizzle 2D vector utility type
template<typename type> struct stvec3;	// Swizzle 2D vector utility type
template<typename type> struct stvec4;	// Swizzle 2D vector utility type


//-----------------------------------------------------------------------------

// Template scalar type.
template<typename type>
struct ttvec1
{
	ttvec1(type const& xc = 0);
	ttvec1(ttvec1 const& xc);
	ttvec1(stvec1<type> const& xc);

	ttvec1& operator =(ttvec1 const& v_rh);
	ttvec1& operator =(stvec1<type> const& v_rh);
	ttvec1& operator =(type const& s_rh);

	operator type const () const;
	operator type& ();

#ifdef IJK_VECTOR_SWIZZLE
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, ttvec, 1);
#endif	// IJK_VECTOR_SWIZZLE
	type x;
};


//-----------------------------------------------------------------------------

// Template 2D vector type.
template<typename type>
struct ttvec2
{
	ttvec2(type const& xy = 0);										// Construct vector with all elements set to single scalar.
	ttvec2(type const& xc, type const& yc);							// Construct vector with elements set individually.
	ttvec2(ttvec2 const& xy);										// Construct vector given another 2D vector.
	explicit ttvec2(ttvec3<type> const& xy);						// Construct vector given the first two elements of a 3D vector.
	explicit ttvec2(ttvec4<type> const& xy);						// Construct vector given the first two elements of a 4D vector.
	ttvec2(stvec2<type> const& xy);									// Construct vector given 2D swizzle vector.
	explicit ttvec2(stvec3<type> const& xy);						// Construct vector given 3D swizzle vector.
	explicit ttvec2(stvec4<type> const& xy);						// Construct vector given 4D swizzle vector.

	explicit ttvec2(bool2 const xy);								// Construct vector given boolean array-based vector.
	explicit ttvec2(int2 const xy);								// Construct vector given signed 32-bit integer array-based vector.
	explicit ttvec2(intl2 const xy);								// Construct vector given signed 64-bit integer array-based vector.
	explicit ttvec2(uint2 const xy);								// Construct vector given unsigned 32-bit integer array-based vector.
	explicit ttvec2(uintl2 const xy);								// Construct vector given unsigned 64-bit integer array-based vector.
	explicit ttvec2(float2 const xy);								// Construct vector given float array-based vector.
	explicit ttvec2(double2 const xy);								// Construct vector given double array-based vector.
	explicit ttvec2(ttvec1<bool> const xy[2]);						// Construct vector given boolean array-based vector.
	explicit ttvec2(ttvec1<i32> const xy[2]);						// Construct vector given signed 32-bit integer array-based vector.
	explicit ttvec2(ttvec1<intl> const xy[2]);						// Construct vector given signed 64-bit integer array-based vector.
	explicit ttvec2(ttvec1<uint> const xy[2]);						// Construct vector given unsigned 32-bit integer array-based vector.
	explicit ttvec2(ttvec1<uintl> const xy[2]);						// Construct vector given unsigned 64-bit integer array-based vector.
	explicit ttvec2(ttvec1<f32> const xy[2]);						// Construct vector given float array-based vector.
	explicit ttvec2(ttvec1<f64> const xy[2]);						// Construct vector given double array-based vector.

	ttvec2 const operator +() const;
	ttvec2 const operator -() const;
	ttvec2 const operator ~() const;
	ttvec2<bool> const operator !() const;
	ttvec2 const operator +(ttvec2 const& v_rh) const;
	ttvec2 const operator -(ttvec2 const& v_rh) const;
	ttvec2 const operator *(ttvec2 const& v_rh) const;
	ttvec2 const operator /(ttvec2 const& v_rh) const;
	ttvec2 const operator %(ttvec2 const& v_rh) const;
	ttvec2 const operator &(ttvec2 const& v_rh) const;
	ttvec2 const operator |(ttvec2 const& v_rh) const;
	ttvec2 const operator ^(ttvec2 const& v_rh) const;
	ttvec2 const operator <<(ttvec2 const& v_rh) const;
	ttvec2 const operator >>(ttvec2 const& v_rh) const;
	ttvec2<bool> const operator ==(ttvec2 const& v_rh) const;
	ttvec2<bool> const operator !=(ttvec2 const& v_rh) const;
	ttvec2<bool> const operator <=(ttvec2 const& v_rh) const;
	ttvec2<bool> const operator >=(ttvec2 const& v_rh) const;
	ttvec2<bool> const operator <(ttvec2 const& v_rh) const;
	ttvec2<bool> const operator >(ttvec2 const& v_rh) const;
	ttvec2 const operator +(type const& s_rh) const;
	ttvec2 const operator -(type const& s_rh) const;
	ttvec2 const operator *(type const& s_rh) const;
	ttvec2 const operator /(type const& s_rh) const;
	ttvec2 const operator %(type const& s_rh) const;
	ttvec2 const operator &(type const& s_rh) const;
	ttvec2 const operator |(type const& s_rh) const;
	ttvec2 const operator ^(type const& s_rh) const;
	ttvec2 const operator <<(type const& s_rh) const;
	ttvec2 const operator >>(type const& s_rh) const;
	ttvec2<bool> const operator ==(type const& s_rh) const;
	ttvec2<bool> const operator !=(type const& s_rh) const;
	ttvec2<bool> const operator <=(type const& s_rh) const;
	ttvec2<bool> const operator >=(type const& s_rh) const;
	ttvec2<bool> const operator <(type const& s_rh) const;
	ttvec2<bool> const operator >(type const& s_rh) const;
	type const operator [](index const i) const;
	operator type const* () const;

	ttvec2& operator =(ttvec2 const& v_rh);
	ttvec2& operator =(stvec2<type> const& v_rh);
	ttvec2& operator +=(ttvec2 const& v_rh);
	ttvec2& operator -=(ttvec2 const& v_rh);
	ttvec2& operator *=(ttvec2 const& v_rh);
	ttvec2& operator /=(ttvec2 const& v_rh);
	ttvec2& operator %=(ttvec2 const& v_rh);
	ttvec2& operator &=(ttvec2 const& v_rh);
	ttvec2& operator |=(ttvec2 const& v_rh);
	ttvec2& operator ^=(ttvec2 const& v_rh);
	ttvec2& operator <<=(ttvec2 const& v_rh);
	ttvec2& operator >>=(ttvec2 const& v_rh);
	ttvec2& operator =(type const& s_rh);
	ttvec2& operator +=(type const& s_rh);
	ttvec2& operator -=(type const& s_rh);
	ttvec2& operator *=(type const& s_rh);
	ttvec2& operator /=(type const& s_rh);
	ttvec2& operator %=(type const& s_rh);
	ttvec2& operator &=(type const& s_rh);
	ttvec2& operator |=(type const& s_rh);
	ttvec2& operator ^=(type const& s_rh);
	ttvec2& operator <<=(type const& s_rh);
	ttvec2& operator >>=(type const& s_rh);
	type& operator [](index const i);
	operator type* ();

#ifdef IJK_VECTOR_SWIZZLE
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, ttvec, 2);
#endif	// IJK_VECTOR_SWIZZLE
	union { IJK_TVEC_IMPL(2); };
	inline operator ttvec1<type> const* () const { return (ttvec1<type>*)xy; }
	inline operator ttvec1<type>* () { return (ttvec1<type>*)xy; }
};

template<typename type> ttvec2<type> const operator +(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<type> const operator -(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<type> const operator *(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<type> const operator /(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<type> const operator %(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<type> const operator &(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<type> const operator |(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<type> const operator ^(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<type> const operator <<(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<type> const operator >>(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<bool> const operator ==(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<bool> const operator !=(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<bool> const operator <=(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<bool> const operator >=(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<bool> const operator <(type const& s_lh, ttvec2<type> const& v_rh);
template<typename type> ttvec2<bool> const operator >(type const& s_lh, ttvec2<type> const& v_rh);


//-----------------------------------------------------------------------------

// Template 3D vector type.
template<typename type>
struct ttvec3
{
	ttvec3(type const& xyz = 0);											// Construct vector with all elements set to single scalar.
	ttvec3(type const& xc, type const& yc, type const& zc = 0);				// Construct vector with elements set individually.
	explicit ttvec3(ttvec2<type> const& xy, type const& zc = 0);			// Construct vector given 2D vector and one scalar.
	explicit ttvec3(type const& xc, ttvec2<type> const& yz);				// Construct vector given 2D vector and one scalar.
	ttvec3(ttvec3 const& xyz);												// Construct vector given another 3D vector.
	explicit ttvec3(ttvec4<type> const& xyz);								// Construct vector given the first three elements of a 4D vector.
	explicit ttvec3(stvec2<type> const& xy, type const& zc = 0);			// Construct vector given 2D swizzle vector and one scalar.
	explicit ttvec3(type const& xc, stvec2<type> const& yz);				// Construct vector given 2D swizzle vector and one scalar.
	ttvec3(stvec3<type> const& xyz);										// Construct vector given 3D swizzle vector.
	explicit ttvec3(stvec4<type> const& xyz);								// Construct vector given 4D swizzle vector.

	explicit ttvec3(bool3 const xyz);										// Construct vector given boolean array-based vector.
	explicit ttvec3(int3 const xyz);										// Construct vector given 32-bit signed integer array-based vector.
	explicit ttvec3(intl3 const xyz);										// Construct vector given 64-bit signed integer array-based vector.
	explicit ttvec3(uint3 const xyz);										// Construct vector given unsigned 32-bit integer array-based vector.
	explicit ttvec3(uintl3 const xyz);										// Construct vector given unsigned 64-bit integer array-based vector.
	explicit ttvec3(float3 const xyz);										// Construct vector given float array-based vector.
	explicit ttvec3(double3 const xyz);										// Construct vector given double array-based vector.
	explicit ttvec3(ttvec1<bool> const xyz[3]);								// Construct vector given boolean array-based vector.
	explicit ttvec3(ttvec1<i32> const xyz[3]);								// Construct vector given 32-bit signed integer array-based vector.
	explicit ttvec3(ttvec1<i64> const xyz[3]);								// Construct vector given 64-bit signed integer array-based vector.
	explicit ttvec3(ttvec1<ui32> const xyz[3]);								// Construct vector given unsigned 32-bit integer array-based vector.
	explicit ttvec3(ttvec1<ui64> const xyz[3]);								// Construct vector given unsigned 64-bit integer array-based vector.
	explicit ttvec3(ttvec1<f32> const xyz[3]);								// Construct vector given float array-based vector.
	explicit ttvec3(ttvec1<f64> const xyz[3]);								// Construct vector given double array-based vector.

	ttvec3 const operator +() const;
	ttvec3 const operator -() const;
	ttvec3 const operator ~() const;
	ttvec3<bool> const operator !() const;
	ttvec3 const operator +(ttvec3 const& v_rh) const;
	ttvec3 const operator -(ttvec3 const& v_rh) const;
	ttvec3 const operator *(ttvec3 const& v_rh) const;
	ttvec3 const operator /(ttvec3 const& v_rh) const;
	ttvec3 const operator %(ttvec3 const& v_rh) const;
	ttvec3 const operator &(ttvec3 const& v_rh) const;
	ttvec3 const operator |(ttvec3 const& v_rh) const;
	ttvec3 const operator ^(ttvec3 const& v_rh) const;
	ttvec3 const operator <<(ttvec3 const& v_rh) const;
	ttvec3 const operator >>(ttvec3 const& v_rh) const;
	ttvec3<bool> const operator ==(ttvec3 const& v_rh) const;
	ttvec3<bool> const operator !=(ttvec3 const& v_rh) const;
	ttvec3<bool> const operator <=(ttvec3 const& v_rh) const;
	ttvec3<bool> const operator >=(ttvec3 const& v_rh) const;
	ttvec3<bool> const operator <(ttvec3 const& v_rh) const;
	ttvec3<bool> const operator >(ttvec3 const& v_rh) const;
	ttvec3 const operator +(type const& s_rh) const;
	ttvec3 const operator -(type const& s_rh) const;
	ttvec3 const operator *(type const& s_rh) const;
	ttvec3 const operator /(type const& s_rh) const;
	ttvec3 const operator %(type const& s_rh) const;
	ttvec3 const operator &(type const& s_rh) const;
	ttvec3 const operator |(type const& s_rh) const;
	ttvec3 const operator ^(type const& s_rh) const;
	ttvec3 const operator <<(type const& s_rh) const;
	ttvec3 const operator >>(type const& s_rh) const;
	ttvec3<bool> const operator ==(type const& s_rh) const;
	ttvec3<bool> const operator !=(type const& s_rh) const;
	ttvec3<bool> const operator <=(type const& s_rh) const;
	ttvec3<bool> const operator >=(type const& s_rh) const;
	ttvec3<bool> const operator <(type const& s_rh) const;
	ttvec3<bool> const operator >(type const& s_rh) const;
	type const operator [](index const i) const;
	operator type const* () const;
	
	ttvec3& operator =(ttvec3 const& v_rh);
	ttvec3& operator =(stvec3<type> const& v_rh);
	ttvec3& operator +=(ttvec3 const& v_rh);
	ttvec3& operator -=(ttvec3 const& v_rh);
	ttvec3& operator *=(ttvec3 const& v_rh);
	ttvec3& operator /=(ttvec3 const& v_rh);
	ttvec3& operator %=(ttvec3 const& v_rh);
	ttvec3& operator &=(ttvec3 const& v_rh);
	ttvec3& operator |=(ttvec3 const& v_rh);
	ttvec3& operator ^=(ttvec3 const& v_rh);
	ttvec3& operator <<=(ttvec3 const& v_rh);
	ttvec3& operator >>=(ttvec3 const& v_rh);
	ttvec3& operator =(type const& s_rh);
	ttvec3& operator +=(type const& s_rh);
	ttvec3& operator -=(type const& s_rh);
	ttvec3& operator *=(type const& s_rh);
	ttvec3& operator /=(type const& s_rh);
	ttvec3& operator %=(type const& s_rh);
	ttvec3& operator &=(type const& s_rh);
	ttvec3& operator |=(type const& s_rh);
	ttvec3& operator ^=(type const& s_rh);
	ttvec3& operator <<=(type const& s_rh);
	ttvec3& operator >>=(type const& s_rh);
	type& operator [](index const i);
	operator type* ();

#ifdef IJK_VECTOR_SWIZZLE
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, ttvec, 3);
#endif	// IJK_VECTOR_SWIZZLE
	union { IJK_TVEC_IMPL(3); };
	inline operator ttvec1<type> const* () const { return (ttvec1<type>*)xyz; }
	inline operator ttvec1<type>* () { return (ttvec1<type>*)xyz; }
};

template<typename type> ttvec3<type> const operator +(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<type> const operator -(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<type> const operator *(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<type> const operator /(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<type> const operator %(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<type> const operator &(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<type> const operator |(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<type> const operator ^(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<type> const operator <<(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<type> const operator >>(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<bool> const operator ==(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<bool> const operator !=(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<bool> const operator <=(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<bool> const operator >=(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<bool> const operator <(type const& s_lh, ttvec3<type> const& v_rh);
template<typename type> ttvec3<bool> const operator >(type const& s_lh, ttvec3<type> const& v_rh);


//-----------------------------------------------------------------------------

// Template 4D vector type.
template<typename type>
struct ttvec4
{
	ttvec4(type const& xyzw = 0);																// Construct vector with all elements set to single scalar.
	ttvec4(type const& xc, type const& yc, type const& zc = 0, type const& wc = 0);				// Construct vector with elements set individually.
	explicit ttvec4(ttvec2<type> const& xy, type const& zc = 0, type const& wc = 0);			// Construct vector given 2D vector and two scalars.
	explicit ttvec4(type const& xc, ttvec2<type> const& yz, type const& wc = 0);				// Construct vector given 2D vector and two scalars.
	explicit ttvec4(type const& xc, type const& yc, ttvec2<type> const& zw);					// Construct vector given 2D vector and two scalars.
	explicit ttvec4(ttvec2<type> const& xy, ttvec2<type> const& zw);							// Construct vector given 2D vector and two scalars.
	explicit ttvec4(ttvec3<type> const& xyz, type const& wc = 0);								// Construct vector given 3D vector and one scalar.
	explicit ttvec4(type const& xc, ttvec3<type> const& yzw);									// Construct vector given 3D vector and one scalar.
	ttvec4(ttvec4 const& xyzw);																	// Construct vector given another 4D vector.
	explicit ttvec4(stvec2<type> const& xy, type const& zc = 0, type const& wc = 0);			// Construct vector given 2D swizzle vector and two scalars.
	explicit ttvec4(type const& xc, stvec2<type> const& yz, type const& wc = 0);				// Construct vector given 2D swizzle vector and two scalars.
	explicit ttvec4(type const& xc, type const& yc, stvec2<type> const& zw);					// Construct vector given 2D swizzle vector and two scalars.
	explicit ttvec4(stvec2<type> const& xy, stvec2<type> const& zw);							// Construct vector given 2D swizzle vector and two scalars.
	explicit ttvec4(stvec3<type> const& xyz, type const& wc = 0);								// Construct vector given 3D swizzle vector and one scalar.
	explicit ttvec4(type const& xc, stvec3<type> const& yzw);									// Construct vector given 3D swizzle vector and one scalar.
	ttvec4(stvec4<type> const& xyzw);															// Construct vector given 4D swizzle vector.

	explicit ttvec4(bool4 const xyzw);														// Construct vector given boolean array-based vector.
	explicit ttvec4(int4 const xyzw);															// Construct vector given signed 32-bit integer array-based vector.
	explicit ttvec4(intl4 const xyzw);															// Construct vector given signed 64-bit integer array-based vector.
	explicit ttvec4(uint4 const xyzw);														// Construct vector given unsigned 32-bit integer array-based vector.
	explicit ttvec4(uintl4 const xyzw);														// Construct vector given unsigned 64-bit integer array-based vector.
	explicit ttvec4(float4 const xyzw);															// Construct vector given float array-based vector.
	explicit ttvec4(double4 const xyzw);															// Construct vector given double array-based vector.
	explicit ttvec4(ttvec1<bool> const xyzw[4]);												// Construct vector given boolean array-based vector.
	explicit ttvec4(ttvec1<i32> const xyzw[4]);													// Construct vector given signed 32-bit integer array-based vector.
	explicit ttvec4(ttvec1<i64> const xyzw[4]);													// Construct vector given signed 64-bit integer array-based vector.
	explicit ttvec4(ttvec1<ui32> const xyzw[4]);												// Construct vector given unsigned 32-bit integer array-based vector.
	explicit ttvec4(ttvec1<ui64> const xyzw[4]);												// Construct vector given unsigned 64-bit integer array-based vector.
	explicit ttvec4(ttvec1<f32> const xyzw[4]);													// Construct vector given float array-based vector.
	explicit ttvec4(ttvec1<f64> const xyzw[4]);													// Construct vector given double array-based vector.

	ttvec4 const operator +() const;
	ttvec4 const operator -() const;
	ttvec4 const operator ~() const;
	ttvec4<bool> const operator !() const;
	ttvec4 const operator +(ttvec4 const& v_rh) const;
	ttvec4 const operator -(ttvec4 const& v_rh) const;
	ttvec4 const operator *(ttvec4 const& v_rh) const;
	ttvec4 const operator /(ttvec4 const& v_rh) const;
	ttvec4 const operator %(ttvec4 const& v_rh) const;
	ttvec4 const operator &(ttvec4 const& v_rh) const;
	ttvec4 const operator |(ttvec4 const& v_rh) const;
	ttvec4 const operator ^(ttvec4 const& v_rh) const;
	ttvec4 const operator <<(ttvec4 const& v_rh) const;
	ttvec4 const operator >>(ttvec4 const& v_rh) const;
	ttvec4<bool> const operator ==(ttvec4 const& v_rh) const;
	ttvec4<bool> const operator !=(ttvec4 const& v_rh) const;
	ttvec4<bool> const operator <=(ttvec4 const& v_rh) const;
	ttvec4<bool> const operator >=(ttvec4 const& v_rh) const;
	ttvec4<bool> const operator <(ttvec4 const& v_rh) const;
	ttvec4<bool> const operator >(ttvec4 const& v_rh) const;
	ttvec4 const operator +(type const& s_rh) const;
	ttvec4 const operator -(type const& s_rh) const;
	ttvec4 const operator *(type const& s_rh) const;
	ttvec4 const operator /(type const& s_rh) const;
	ttvec4 const operator %(type const& s_rh) const;
	ttvec4 const operator &(type const& s_rh) const;
	ttvec4 const operator |(type const& s_rh) const;
	ttvec4 const operator ^(type const& s_rh) const;
	ttvec4 const operator <<(type const& s_rh) const;
	ttvec4 const operator >>(type const& s_rh) const;
	ttvec4<bool> const operator ==(type const& s_rh) const;
	ttvec4<bool> const operator !=(type const& s_rh) const;
	ttvec4<bool> const operator <=(type const& s_rh) const;
	ttvec4<bool> const operator >=(type const& s_rh) const;
	ttvec4<bool> const operator <(type const& s_rh) const;
	ttvec4<bool> const operator >(type const& s_rh) const;
	type const operator [](index const i) const;
	operator type const* () const;

	ttvec4& operator =(ttvec4 const& v_rh);
	ttvec4& operator =(stvec4<type> const& v_rh);
	ttvec4& operator +=(ttvec4 const& v_rh);
	ttvec4& operator -=(ttvec4 const& v_rh);
	ttvec4& operator *=(ttvec4 const& v_rh);
	ttvec4& operator /=(ttvec4 const& v_rh);
	ttvec4& operator %=(ttvec4 const& v_rh);
	ttvec4& operator &=(ttvec4 const& v_rh);
	ttvec4& operator |=(ttvec4 const& v_rh);
	ttvec4& operator ^=(ttvec4 const& v_rh);
	ttvec4& operator <<=(ttvec4 const& v_rh);
	ttvec4& operator >>=(ttvec4 const& v_rh);
	ttvec4& operator =(type const& s_rh);
	ttvec4& operator +=(type const& s_rh);
	ttvec4& operator -=(type const& s_rh);
	ttvec4& operator *=(type const& s_rh);
	ttvec4& operator /=(type const& s_rh);
	ttvec4& operator %=(type const& s_rh);
	ttvec4& operator &=(type const& s_rh);
	ttvec4& operator |=(type const& s_rh);
	ttvec4& operator ^=(type const& s_rh);
	ttvec4& operator <<=(type const& s_rh);
	ttvec4& operator >>=(type const& s_rh);
	type& operator [](index const i);
	operator type* ();

#ifdef IJK_VECTOR_SWIZZLE
	IJK_SWIZZLE_ALL(IJK_SWIZZLE_DECL_RTEMP, IJK_SWIZZLE_DECL_RTEMP, ttvec, stvec, ttvec, 4);
#endif	// IJK_VECTOR_SWIZZLE
	union { IJK_TVEC_IMPL(4); };
	inline operator ttvec1<type> const* () const { return (ttvec1<type>*)xyzw; }
	inline operator ttvec1<type>* () { return (ttvec1<type>*)xyzw; }
};

template<typename type> ttvec4<type> const operator +(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<type> const operator -(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<type> const operator *(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<type> const operator /(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<type> const operator %(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<type> const operator &(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<type> const operator |(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<type> const operator ^(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<type> const operator <<(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<type> const operator >>(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<bool> const operator ==(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<bool> const operator !=(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<bool> const operator <=(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<bool> const operator >=(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<bool> const operator <(type const& s_lh, ttvec4<type> const& v_rh);
template<typename type> ttvec4<bool> const operator >(type const& s_lh, ttvec4<type> const& v_rh);


//-----------------------------------------------------------------------------

// Swizzle scalar type.
template<typename type>
struct stvec1 : ttvec1<type>
{
	ttvec1<type> const operator =(ttvec1<type> const v);
	ttvec1<type> const operator =(stvec1 const& v);
	ttvec1<type> const operator =(type const& xc);
	~stvec1();
private:
	type& xr;
	stvec1(type& xr);
	friend stvec2<type>;
	friend stvec3<type>;
	friend stvec4<type>;
	friend ttvec1<type>;
	friend ttvec2<type>;
	friend ttvec3<type>;
	friend ttvec4<type>;
};

// Swizzle 2D vector type.
template<typename type>
struct stvec2 : ttvec2<type>
{
	ttvec2<type> const operator =(ttvec2<type> const v);
	ttvec2<type> const operator =(stvec2 const& v);
	ttvec2<type> const operator =(type const& xy);
	~stvec2();
private:
	type& xr, & yr;
	stvec2(type& xr, type& yr);
	friend stvec3<type>;
	friend stvec4<type>;
	friend ttvec2<type>;
	friend ttvec3<type>;
	friend ttvec4<type>;
};

// Swizzle 3D vector type.
template<typename type>
struct stvec3 : ttvec3<type>
{
	ttvec3<type> const operator =(ttvec3<type> const v);
	ttvec3<type> const operator =(stvec3 const& v);
	ttvec3<type> const operator =(type const& xyz);
	~stvec3();
private:
	type& xr, & yr, & zr;
	stvec3(type& xr, type& yr, type& zr);
	friend stvec4<type>;
	friend ttvec3<type>;
	friend ttvec4<type>;
};

// Swizzle 4D vector type.
template<typename type>
struct stvec4 : ttvec4<type>
{
	ttvec4<type> const operator =(ttvec4<type> const v);
	ttvec4<type> const operator =(stvec4 const& v);
	ttvec4<type> const operator =(type const& xyzw);
	~stvec4();
private:
	type& xr, & yr, & zr, & wr;
	stvec4(type& xr, type& yr, type& zr, type& wr);
	friend ttvec4<type>;
};


//-----------------------------------------------------------------------------

#endif	// __cplusplus


#include "_inl/ijkVectorSwizzle.inl"


#ifdef __cplusplus

//-----------------------------------------------------------------------------

typedef ttvec2<bool>	bvec2;		// 2D boolean/byte vector
typedef ttvec3<bool>	bvec3;		// 3D boolean/byte vector
typedef ttvec4<bool>	bvec4;		// 4D boolean/byte vector

typedef ttvec2<i32>		ivec2;		// 2D signed 32-bit integer vector
typedef ttvec3<i32>		ivec3;		// 3D signed 32-bit integer vector
typedef ttvec4<i32>		ivec4;		// 4D signed 32-bit integer vector

typedef ttvec2<i64>		ilvec2;		// 2D signed 64-bit integer vector
typedef ttvec3<i64>		ilvec3;		// 3D signed 64-bit integer vector
typedef ttvec4<i64>		ilvec4;		// 4D signed 64-bit integer vector

typedef ttvec2<ui32>	uvec2;		// 2D unsigned 32-bit integer vector
typedef ttvec3<ui32>	uvec3;		// 3D unsigned 32-bit integer vector
typedef ttvec4<ui32>	uvec4;		// 4D unsigned 32-bit integer vector

typedef ttvec2<ui64>	ulvec2;		// 2D unsigned 64-bit integer vector
typedef ttvec3<ui64>	ulvec3;		// 3D unsigned 64-bit integer vector
typedef ttvec4<ui64>	ulvec4;		// 4D unsigned 64-bit integer vector

typedef ttvec2<f32>		fvec2;		// 2D single-precision floating point vector
typedef ttvec3<f32>		fvec3;		// 3D single-precision floating point vector
typedef ttvec4<f32>		fvec4;		// 4D single-precision floating point vector

typedef ttvec2<f64>		dvec2;		// 2D double-precision floating point vector
typedef ttvec3<f64>		dvec3;		// 3D double-precision floating point vector
typedef ttvec4<f64>		dvec4;		// 4D double-precision floating point vector

// Built-in type overrides.
///
#define bool			ttvec1<bool>	// sizeof(bool) = 1; does not align with GLSL
#define int				ttvec1<i32>
#define intl			ttvec1<i64>		// sizeof(intl) = 8; does not align with GLSL
#define uint			ttvec1<ui32>
#define uintl			ttvec1<ui64>	// sizeof(uintl) = 8; does not align with GLSL
#define float			ttvec1<f32>
#define double			ttvec1<f64>


//-----------------------------------------------------------------------------

#endif	// __cplusplus


#endif	// !_IJK_VECTORSWIZZLE_H_
#endif	// _IJK_VECTOR_H_