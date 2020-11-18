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

	ijkQuaternion_float.h
	Declarations for float quaternion functions.
*/

#ifdef _IJK_QUATERNION_H_
#ifndef _IJK_QUATERNION_FLOAT_H_
#define _IJK_QUATERNION_FLOAT_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkQuatInitQ*v
//	Initialize identity quaternion (zero vector, one real).
//		param q_out: output quaternion
//		return: q_out
floatv ijkQuatInitQfv(float4 q_out);

// ijkQuatInitElemsQ*v
//	Initialize individual elements of quaternion.
//		param q_out: output quaternion
//		params x, y, z, w: components
//		return: q_out
floatv ijkQuatInitElemsQfv(float4 q_out, f32 const x, f32 const y, f32 const z, f32 const w);

// ijkQuatInitVecReQ*v
//	Initialize quaternion with vector and real parts.
//		param q_out: output quaternion
//		param vec: vector components (xyz)
//		param re: real component (w)
//		return: q_out
floatv ijkQuatInitVecReQfv(float4 q_out, float3 const vec, f32 const re);

// ijkQuatInitMatQ*v3
//	Initialize quaternion from 3D matrix.
//		param q_out: output quaternion
//		param m_in: input matrix
//		return: q_out
floatv ijkQuatInitMatQfv3(float4 q_out, float3x3 const m_in);

// ijkQuatInitMatQ*v4
//	Initialize quaternion from 4D matrix.
//		param q_out: output quaternion
//		param m_in: input matrix
//		return: q_out
floatv ijkQuatInitMatQfv4(float4 q_out, float4x4 const m_in);

// ijkQuatCopyQ*v
//	Copy quaternion.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatCopyQfv(float4 q_out, float4 const q_in);

// ijkQuatNegateQ*v
//	Negate quaternion.
//		param q_out: output quaternion, negative
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatNegateQfv(float4 q_out, float4 const q_in);

// ijkQuatConjugateQ*v
//	Conjugate quaternion: negate vector part, copy real part.
//		param q_out: output quaternion, conjugate
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatConjugateQfv(float4 q_out, float4 const q_in);

// ijkQuatAddQ*v
//	Calculate sum of quaternions.
//		param q_out: output quaternion, sum
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
floatv ijkQuatAddQfv(float4 q_out, float4 const q_lh, float4 const q_rh);

// ijkQuatSubQ*v
//	Calculate difference of quaternions.
//		param q_out: output quaternion, difference
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
floatv ijkQuatSubQfv(float4 q_out, float4 const q_lh, float4 const q_rh);

// ijkQuatMulQ*vs
//	Calculate product of quaternion and scalar.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: q_out
floatv ijkQuatMulQfvs(float4 q_out, float4 const q_lh, f32 const s_rh);

// ijkQuatDivQ*vs
//	Calculate quotient of quaternion and scalar.
//		param q_out: output quaternion, quotient
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: q_out
floatv ijkQuatDivQfvs(float4 q_out, float4 const q_lh, f32 const s_rh);

// ijkQuatDivSafeQ*vs
//	Calculate quotient of quaternion and scalar; division-by-zero safety.
//		param q_out: output quaternion, quotient
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: q_out
floatv ijkQuatDivSafeQfvs(float4 q_out, float4 const q_lh, f32 const s_rh);

// ijkQuatLengthSqQ*v
//	Calculate squared length of quaternion.
//		param q_in: input quaternion
//		return: squared length
f32 ijkQuatLengthSqQfv(float4 const q_in);

// ijkQuatLengthQ*v
//	Calculate length of quaternion.
//		param q_in: input quaternion
//		return: length
f32 ijkQuatLengthQfv(float4 const q_in);

// ijkQuatLengthSqInvQ*v
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
f32 ijkQuatLengthSqInvQfv(float4 const q_in);

// ijkQuatLengthInvQ*v
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
f32 ijkQuatLengthInvQfv(float4 const q_in);

// ijkQuatLengthSqInvSafeQ*v
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
f32 ijkQuatLengthSqInvSafeQfv(float4 const q_in);

// ijkQuatLengthInvSafeQ*v
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
f32 ijkQuatLengthInvSafeQfv(float4 const q_in);

// ijkQuatNormalizeQ*v
//	Normalize quaternion.
//		param q_out: output quaternion, unit-length
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatNormalizeQfv(float4 q_out, float4 const q_in);

// ijkQuatNormalizeSafeQ*v
//	Normalize quaternion; division-by-zero safety.
//		param q_out: output quaternion, unit-length
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatNormalizeSafeQfv(float4 q_out, float4 const q_in);

// ijkQuatInverseQ*v
//	Calculate inverse of quaternion: conjugate divided by squared length.
//		param q_out: output quaternion, inverse
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatInverseQfv(float4 q_out, float4 const q_in);

// ijkQuatInverseSafeQ*v
//	Calculate inverse of quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param q_out: output quaternion, inverse
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatInverseSafeQfv(float4 q_out, float4 const q_in);

// ijkQuatMulVecQ*v3

// ijkQuatMulVecQ*v3q

// ijkQuatMulQ*v

// ijkQuatDivQ*v

// ijkQuatToMatQ*v3

// ijkQuatToMatQ*v4

// ijkQuatToMatQ*v4t

// ijkQuatRotateXYZQ*v

// ijkQuatRotateYZXQ*v

// ijkQuatRotateZXYQ*v

// ijkQuatRotateYXZQ*v

// ijkQuatRotateXZYQ*v

// ijkQuatRotateZYXQ*v

// ijkQuatRotateQ*v

// ijkQuatScaleQ*v

// ijkQuatRotateScaleQ*v

// ijkQuatAxisAngleQ*v

// ijkQuatAxisAngleScaleQ*v

// ijkQuatGetRotateXYZQ*v

// ijkQuatGetRotateYZXQ*v

// ijkQuatGetRotateZXYQ*v

// ijkQuatGetRotateYXZQ*v

// ijkQuatGetRotateXZYQ*v

// ijkQuatGetRotateZYXQ*v

// ijkQuatGetRotateQ*v

// ijkQuatGetScaleQ*v

// ijkQuatGetRotateScaleQ*v

// ijkQuatGetAxisAngleQ*v

// ijkQuatGetAxisAngleScaleQ*v

// ijkQuatRotateVecQ*v3

// ijkQuatRotateVecQ*v4

// ijkQuatExpQ*v

// ijkQuatLnQ*v

// ijkQuatNlerpQ*v

// ijkQuatSlerpQ*v


//-----------------------------------------------------------------------------

	

//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------
	


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#include "_inl/ijkQuaternion_float.inl"


#endif	// !_IJK_QUATERNION_FLOAT_H_
#endif	// _IJK_QUATERNION_H_