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
//	Calculate product of quaternion and 3D vector (result is quaternion).
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param v_rh: right-hand vector
//		return: q_out
floatv ijkQuatMulVecQfv3(float4 q_out, float4 const q_lh, float3 const v_rh);

// ijkQuatMulVecQ*v3q
//	Calculate product of 3D vector and quaternion (result is quaternion).
//		param q_out: output quaternion, product
//		param v_lh: left-hand vector
//		param q_rh: right-hand quaternion
//		return: q_out
floatv ijkQuatMulVecQfv3q(float4 q_out, float3 const v_lh, float4 const q_rh);

// ijkQuatMulQ*v
//	Calculate product of quaternions.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
floatv ijkQuatMulQfv(float4 q_out, float4 const q_lh, float4 const q_rh);

// ijkQuatDivQ*v
//	Calculate quotient of quaternions (multiply by rh inverse).
//		param q_out: output quaternion, quotient
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
floatv ijkQuatDivQfv(float4 q_out, float4 const q_lh, float4 const q_rh);

// ijkQuatRotateXYZQ*v
//	Make rotation quaternion with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
floatv ijkQuatRotateXYZQfv(float4 q_out, float3 const rotateDegXYZ);

// ijkQuatRotateYZXQ*v
//	Make rotation quaternion with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
floatv ijkQuatRotateYZXQfv(float4 q_out, float3 const rotateDegXYZ);

// ijkQuatRotateZXYQ*v
//	Make rotation quaternion with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
floatv ijkQuatRotateZXYQfv(float4 q_out, float3 const rotateDegXYZ);

// ijkQuatRotateYXZQ*v
//	Make rotation quaternion with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
floatv ijkQuatRotateYXZQfv(float4 q_out, float3 const rotateDegXYZ);

// ijkQuatRotateXZYQ*v
//	Make rotation quaternion with Euler angles in written order XZY, meaning 
//	the order of operations is X then Z then Y.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
floatv ijkQuatRotateXZYQfv(float4 q_out, float3 const rotateDegXYZ);

// ijkQuatRotateZYXQ*v
//	Make rotation quaternion with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
floatv ijkQuatRotateZYXQfv(float4 q_out, float3 const rotateDegXYZ);

// ijkQuatRotateQ*v
//	Make rotation quaternion with Euler angles.
//		param q_out: output quaternion, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
floatv ijkQuatRotateQfv(float4 q_out, ijkRotationOrder const order, float3 const rotateDegXYZ);

// ijkQuatScaleQ*v
//	Make rotation quaternion with uniform scale.
//		param q_out: output quaternion, rotation-scale
//		param scale_unif: uniform scale amount
//		return: q_out
floatv ijkQuatScaleQfv(float4 q_out, f32 const scale_unif);

// ijkQuatRotateScaleQ*v
//	Make rotation quaternion with Euler angles and uniform scale.
//		param q_out: output quaternion, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: q_out
floatv ijkQuatRotateScaleQfv(float4 q_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif);

// ijkQuatAxisAngleQ*v
//	Make rotation quaternion with unit axis and angle in degrees.
//		param q_out: output quaternion, rotation-scale
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: q_out
floatv ijkQuatAxisAngleQfv(float4 q_out, float3 const axis_unit, f32 const angle_degrees);

// ijkQuatAxisAngleScaleQ*v
//	Make rotation quaternion with unit axis, angle in degrees and uniform scale.
//		param q_out: output quaternion, rotation-scale
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: q_out
floatv ijkQuatAxisAngleScaleQfv(float4 q_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif);

// ijkQuatGetRotateXYZQ*v
//	Extract Euler angles from rotation quaternion; written order XYZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
floatkv ijkQuatGetRotateXYZQfv(float4 const q_in, float3 rotateDegXYZ_out);

// ijkQuatGetRotateYZXQ*v
//	Extract Euler angles from rotation quaternion; written order YZX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
floatkv ijkQuatGetRotateYZXQfv(float4 const q_in, float3 rotateDegXYZ_out);

// ijkQuatGetRotateZXYQ*v
//	Extract Euler angles from rotation quaternion; written order ZXY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
floatkv ijkQuatGetRotateZXYQfv(float4 const q_in, float3 rotateDegXYZ_out);

// ijkQuatGetRotateYXZQ*v
//	Extract Euler angles from rotation quaternion; written order YXZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
floatkv ijkQuatGetRotateYXZQfv(float4 const q_in, float3 rotateDegXYZ_out);

// ijkQuatGetRotateXZYQ*v
//	Extract Euler angles from rotation quaternion; written order XZY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
floatkv ijkQuatGetRotateXZYQfv(float4 const q_in, float3 rotateDegXYZ_out);

// ijkQuatGetRotateZYXQ*v
//	Extract Euler angles from rotation quaternion; written order ZYX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
floatkv ijkQuatGetRotateZYXQfv(float4 const q_in, float3 rotateDegXYZ_out);

// ijkQuatGetRotateQ*v
//	Extract Euler angles from rotation quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
floatkv ijkQuatGetRotateQfv(float4 const q_in, ijkRotationOrder const order, float3 rotateDegXYZ_out);

// ijkQuatGetScaleQ*v
//	Extract uniform scale from quaternion.
//		param q_in: input quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
floatkv ijkQuatGetScaleQfv(float4 const q_in, f32* const scale_unif_out);

// ijkQuatGetRotateScaleQ*v
//	Extract Euler angles and uniform scale from quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
floatkv ijkQuatGetRotateScaleQfv(float4 const q_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out);

// ijkQuatGetAxisAngleQ*v
//	Extract unit axis and angle in degrees from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: q_in
floatkv ijkQuatGetAxisAngleQfv(float4 const q_in, float3 axis_unit_out, f32* const angle_degrees_out);

// ijkQuatGetAxisAngleScaleQ*v
//	Extract unit axis, angle in degrees and uniform scale from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
floatkv ijkQuatGetAxisAngleScaleQfv(float4 const q_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out);

// ijkQuatGetMatQ*v3
//	Convert quaternion to 3D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
float3m ijkQuatGetMatQfv3(float3x3 m_out, float4 const q_in);

// ijkQuatGetMatQ*v4
//	Convert quaternion to 4D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
float4m ijkQuatGetMatQfv4(float4x4 m_out, float4 const q_in);

// ijkQuatGetMatQ*v4t
//	Convert quaternion to 4D matrix, with additional translation vector.
//		param m_out: output matrix
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: m_out
float4m ijkQuatGetMatQfv4t(float4x4 m_out, float4 const q_in, float3 const translate);

// ijkQuatRotateVecQ*v3
//	Rotate and/or scale a 3D vector using a quaternion.
//		param v_out: output vector
//		param q_in: input quaternion
//		return: v_out
floatv ijkQuatRotateVecQfv3(float3 v_out, float4 const q_in);

// ijkQuatRotateVecQ*v4
//	Rotate and/or scale a 4D vector using a quaternion.
//		param v_out: output vector
//		param q_in: input quaternion
//		return: v_out
floatv ijkQuatRotateVecQfv4(float4 v_out, float4 const q_in);

// ijkQuatExpQ*v
//	Calculate quaternion as natural exponent base (e) raised to vector power.
//		param q_out: output quaternion
//		param v_in: input vector
//		return: q_out
floatv ijkQuatExpQfv(float4 q_out, float3 const v_in);

// ijkQuatLnQ*v
//	Calculate quaternion or vector as natural logarithm of quaternion.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatLnQfv(float4 q_out, float4 const q_in);

// ijkQuatNlerpQ*v
//	Calculate normalized linear interpolation between two quaternions; keeps 
//	result at unit-length but yields a non-uniform rate of change.
//		param q_out: output quaternion, interpolated quaternion
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: q_out
floatv ijkQuatNlerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u);

// ijkQuatSlerpQ*v
//	Calculate spherical linear interpolation between two unit quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param q_out: output quaternion, interpolated quaternion
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: q_out
floatv ijkQuatSlerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u);


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