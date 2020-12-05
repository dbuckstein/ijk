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

// ijkQuatP*v
//	Pass-thru array-based quaternion (does nothing).
//		param q_out: output quaternion
//		return: q_out
floatv ijkQuatPfv(float4 q_out);

// ijkDualQuatP*v
//	Pass-thru array-based dual quaternion (does nothing).
//		param dq_out: output dual quaternion
//		return: dq_out
float4m ijkDualQuatPfm(float2x4 dq_out);


//-----------------------------------------------------------------------------

// ijkQuatInitQ*v
//	Initialize identity quaternion (zero vector, one real).
//		param q_out: output quaternion
//		return: q_out
floatv ijkQuatInitQfv(float4 q_out);

// ijkQuatInitZeroQ*v
//	Initialize zero quaternion.
//		param q_out: output quaternion
//		return: q_out
floatv ijkQuatInitZeroQfv(float4 q_out);

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

// ijkQuatInitVecProductQ*v
//	Initialize quaternion as product of two vectors.
//		param q_out: output quaternion
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: q_out
floatv ijkQuatInitVecProductQfv(float4 q_out, float3 const v_lh, float3 const v_rh);

// ijkQuatInitVecProductSqrtQ*v
//	Initialize quaternion as product square root of two vectors.
//		param q_out: output quaternion
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: q_out
floatv ijkQuatInitVecProductSqrtQfv(float4 q_out, float3 const v_lh, float3 const v_rh);

// ijkQuatInitVecProductSqrtUnitQ*v
//	Initialize quaternion as product square root of two unit vectors.
//		param q_out: output quaternion
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: q_out
floatv ijkQuatInitVecProductSqrtUnitQfv(float4 q_out, float3 const v_lh, float3 const v_rh);

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

// ijkQuatConjugateMulQ*vs
//	Conjugate quaternion: negate vector part, copy real part, multiply by 
//	scalar.
//		param q_out: output quaternion, conjugate
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatConjugateMulQfvs(float4 q_out, float4 const q_in, f32 const s);

// ijkQuatNegateConjugateQ*v
//	Negate and conjugate quaternion: negate real part, copy vector part.
//		param q_out: output quaternion, negative conjugate
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatNegateConjugateQfv(float4 q_out, float4 const q_in);

// ijkQuatNegateConjugateMulQ*vs
//	Negate and conjugate quaternion: negate real part, copy vector part, 
//	multiply by scalar.
//		param q_out: output quaternion, negative conjugate
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatNegateConjugateMulQfvs(float4 q_out, float4 const q_in, f32 const s);

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

// ijkQuatMulConjQ*v
//	Calculate product of quaternion with quaternion conjugate.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion, conjugated before multiplying
//		return: q_out
floatv ijkQuatMulConjQfv(float4 q_out, float4 const q_lh, float4 const q_rh);

// ijkQuatConjMulQ*v
//	Calculate product of quaternion conjugate with quaternion.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion, conjugated before multiplying
//		param q_rh: right-hand quaternion
//		return: q_out
floatv ijkQuatConjMulQfv(float4 q_out, float4 const q_lh, float4 const q_rh);

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

// ijkQuatRotateQ*v
//	Make rotation quaternion with Euler angles.
//		param q_out: output quaternion, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
floatv ijkQuatRotateQfv(float4 q_out, ijkRotationOrder const order, float3 const rotateDegXYZ);

// ijkQuatAxisAngleQ*v
//	Make rotation quaternion with unit axis and angle in degrees.
//		param q_out: output quaternion, rotation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: q_out
floatv ijkQuatAxisAngleQfv(float4 q_out, float3 const axis_unit, f32 const angle_degrees);

// ijkQuatScaleQ*v
//	Make rotation quaternion with uniform scale.
//		param q_out: output quaternion, scale
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

// ijkQuatAxisAngleScaleQ*v
//	Make rotation quaternion with unit axis, angle in degrees and uniform scale.
//		param q_out: output quaternion, rotation-scale
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: q_out
floatv ijkQuatAxisAngleScaleQfv(float4 q_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif);

// ijkQuatGetRotateQ*v
//	Extract Euler angles from rotation quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
floatkv ijkQuatGetRotateQfv(float4 const q_in, ijkRotationOrder const order, float3 rotateDegXYZ_out);

// ijkQuatGetAxisAngleQ*v
//	Extract unit axis and angle in degrees from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: q_in
floatkv ijkQuatGetAxisAngleQfv(float4 const q_in, float3 axis_unit_out, f32* const angle_degrees_out);

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

// ijkQuatUnitGetMatQ*v3
//	Convert unit quaternion to 3D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
float3m ijkQuatUnitGetMatQfv3(float3x3 m_out, float4 const q_in);

// ijkQuatGetMatQ*v4
//	Convert quaternion to 4D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
float4m ijkQuatGetMatQfv4(float4x4 m_out, float4 const q_in);

// ijkQuatUnitGetMatQ*v4
//	Convert unit quaternion to 4D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
float4m ijkQuatUnitGetMatQfv4(float4x4 m_out, float4 const q_in);

// ijkQuatGetMatQ*v4t
//	Convert quaternion to 4D matrix, with additional translation vector.
//		param m_out: output matrix
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: m_out
float4m ijkQuatGetMatQfv4t(float4x4 m_out, float4 const q_in, float3 const translate);

// ijkQuatUnitGetMatQ*v4t
//	Convert unit quaternion to 4D matrix, with additional translation vector.
//		param m_out: output matrix
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: m_out
float4m ijkQuatUnitGetMatQfv4t(float4x4 m_out, float4 const q_in, float3 const translate);

// ijkQuatRotateScaleVecQ*v3
//	Rotate and/or scale a 3D vector using a quaternion; result will not be 
//	divided by squared magnitude.
//		param v_out: output vector
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
floatv ijkQuatRotateScaleVecQfv3(float3 v_out, float4 const q_in, float3 const v_in);

// ijkQuatUnitRotateVecQ*v3
//	Rotate a 3D vector using a quaternion; use with unit quaternion for most 
//	optimized solution.
//		param v_out: output vector
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
floatv ijkQuatUnitRotateVecQfv3(float3 v_out, float4 const q_in, float3 const v_in);

// ijkQuatRotateVecQ*v3
//	Rotate a 3D vector using a quaternion; use this when the input quaternion 
//	is non-unit length so that the result will only be rotated.
//		param v_out: output vector
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
floatv ijkQuatRotateVecQfv3(float3 v_out, float4 const q_in, float3 const v_in);

// ijkQuatReflectScaleQ*v
//	Reflect and/or scale a quaternion about an axis.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
floatv ijkQuatReflectScaleQfv(float4 q_out, float4 const q_in, float3 const v_in);

// ijkQuatUnitReflectQ*v
//	Reflect a unit quaternion about an axis; optimized for unit quaternions.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
floatv ijkQuatUnitReflectQfv(float4 q_out, float4 const q_in, float3 const v_in);

// ijkQuatReflectQ*v
//	Reflect a non-unit quaternion about an axis.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
floatv ijkQuatReflectQfv(float4 q_out, float4 const q_in, float3 const v_in);

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

// ijkQuatPowQ*v
//	Calculate quaternion raised to power of exponent.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param u: exponent
//		return: q_out
floatv ijkQuatPowQfv(float4 q_out, float4 const q_in, f32 const u);

// ijkQuatSqrtQ*v
//	Calculate square root of quaternion.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		return: q_out
floatv ijkQuatSqrtQfv(float4 q_out, float4 const q_in);

// ijkQuatLerpQ*v
//	Calculate linear interpolation between two quaternions; yields a uniform 
//	rate of change but affects encoded scale.
//		param q_out: output quaternion, interpolated quaternion
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: q_out
floatv ijkQuatLerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u);

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

// ijkQuatDerivQ*v
//	Calculate derivative of quaternion.
//		param q1_out: output quaternion, derivative of quaternion
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		return: q1_out
floatv ijkQuatDerivQfv(float4 q1_out, float4 const q_in, float3 const angularVelocity);

// ijkQuatDeriv2Q*v
//	Calculate second derivative of quaternion.
//		param q2_out: output quaternion, second derivative of quaternion
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: q2_out
floatv ijkQuatDeriv2Qfv(float4 q2_out, float4 const q_in, float3 const angularVelocity, float3 const angularAcceleration);

// ijkQuatEncodeTranslateQ*v
//	Encode translation offset vector using quaternion.
//		param qt_out: output quaternion, encoded translation
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: qt_out
floatv ijkQuatEncodeTranslateQfv(float4 qt_out, float3 const translate_in, float4 const q_encode);

// ijkQuatEncodeTranslateX2Q*v
//	Encode double translation offset vector using quaternion.
//		param qt_out: output quaternion, encoded translation
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: qt_out
floatv ijkQuatEncodeTranslateX2Qfv(float4 qt_out, float3 const translate_in, float4 const q_encode);

// ijkQuatDecodeTranslateQ*v
//	Decode translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
floatv ijkQuatDecodeTranslateQfv(float3 translate_out, float4 const qt_in, float4 const q_decode);

// ijkQuatDecodeTranslateD2Q*vs
//	Decode half translation offset vector from quaternion with scalar 
//	multiplier; use if encoding quaternion is unit or if decoded translation 
//	should have additional user-defined scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
floatv ijkQuatDecodeTranslateD2Qfvs(float3 translate_out, float4 const qt_in, float4 const q_decode, f32 const s);

// ijkQuatDecodeTranslateD2Q*v
//	Decode half translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
floatv ijkQuatDecodeTranslateD2Qfv(float3 translate_out, float4 const qt_in, float4 const q_decode);

// ijkQuatDecodeTranslateRemScaleQ*v
//	Decode translation offset vector from quaternion, removing scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
floatv ijkQuatDecodeTranslateRemScaleQfv(float3 translate_out, float4 const qt_in, float4 const q_decode);

// ijkQuatDecodeTranslateRemScaleD2Q*v
//	Decode half translation offset vector from quaternion, removing scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
floatv ijkQuatDecodeTranslateRemScaleD2Qfv(float3 translate_out, float4 const qt_in, float4 const q_decode);


//-----------------------------------------------------------------------------

// ijkDualQuatInitDQ*m
//	Initialize identity dual quaternion (zero dual, identity real).
//		param dq_out: output dual quaternion
//		return: dq_out
float4m ijkDualQuatInitDQfm(float2x4 dq_out);

// ijkDualQuatInitDualReDQ*m
//	Initialize dual quaternion with dual and real parts.
//		param dq_out: output dual quaternion
//		param re: real component (qr)
//		param dual: dual component (E qd)
//		return: dq_out
float4m ijkDualQuatInitDualReDQfm(float2x4 dq_out, float4 const re, float4 const dual);

// ijkDualQuatInitMatDQ*m3
//	Initialize dual quaternion from 3D matrix.
//		param dq_out: output dual quaternion
//		param m_in: input matrix
//		return: dq_out
float4m ijkDualQuatInitMatDQfm3(float2x4 dq_out, float3x3 const m_in);

// ijkDualQuatInitMatDQ*m4
//	Initialize dual quaternion from 4D matrix.
//		param dq_out: output dual quaternion
//		param m_in: input matrix
//		return: dq_out
float4m ijkDualQuatInitMatDQfm4(float2x4 dq_out, float4x4 const m_in);

// ijkDualQuatCopyDQ*m
//	Copy dual quaternion.
//		param dq_out: output dual quaternion
//		param dq_in: input dual quaternion
//		return: dq_out
float4m ijkDualQuatCopyDQfm(float2x4 dq_out, float2x4 const dq_in);

// ijkDualQuatNegateDQ*m
//	Negate dual quaternion.
//		param dq_out: output dual quaternion, negative
//		param dq_in: input dual quaternion
//		return: dq_out
float4m ijkDualQuatNegateDQfm(float2x4 dq_out, float2x4 const dq_in);

// ijkDualQuatConjugateDQ*m
//	Conjugate dual quaternion: take conjugate of both components.
//		param dq_out: output dual quaternion, conjugate
//		param dq_in: input dual quaternion
//		return: dq_out
float4m ijkDualQuatConjugateDQfm(float2x4 dq_out, float2x4 const dq_in);

// ijkDualQuatNegateDualDQ*m
//	Negate dual part: conjugate of dual number.
//		param dq_out: output dual quaternion, dual conjugate
//		param dq_in: input dual quaternion
//		return: dq_out
float4m ijkDualQuatNegateDualDQfm(float2x4 dq_out, float2x4 const dq_in);

// ijkDualQuatConjugateDualDQ*m
//	Conjugate and negate dual part: conjugate of dual number and components.
//		param dq_out: output dual quaternion, complete dual conjugate
//		param dq_in: input dual quaternion
//		return: dq_out
float4m ijkDualQuatConjugateDualDQfm(float2x4 dq_out, float2x4 const dq_in);

// ijkDualQuatAddDQ*m
//	Calculate sum of dual quaternions.
//		param dq_out: output dual quaternion, sum
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
float4m ijkDualQuatAddDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh);

// ijkDualQuatSubDQ*m
//	Calculate difference of dual quaternions.
//		param dq_out: output dual quaternion, difference
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
float4m ijkDualQuatSubDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh);

// ijkDualQuatMulDQ*ms
//	Calculate product of dual quaternion and scalar.
//		param dq_out: output dual quaternion, product
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: dq_out
float4m ijkDualQuatMulDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh);

// ijkDualQuatDivDQ*ms
//	Calculate quotient of dual quaternion and scalar.
//		param dq_out: output dual quaternion, quotient
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: dq_out
float4m ijkDualQuatDivDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh);

// ijkDualQuatDivSafeDQ*ms
//	Calculate quotient of dual quaternion and scalar; division-by-zero safety.
//		param dq_out: output dual quaternion, quotient
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: dq_out
float4m ijkDualQuatDivSafeDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh);

// ijkDualQuatLengthSqDQ*m
//	Calculate squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: squared length
f32 ijkDualQuatLengthSqDQfm(float2x4 const dq_in);

// ijkDualQuatLengthDQ*m
//	Calculate length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: length
f32 ijkDualQuatLengthDQfm(float2x4 const dq_in);

// ijkDualQuatLengthSqInvDQ*m
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
f32 ijkDualQuatLengthSqInvDQfm(float2x4 const dq_in);

// ijkDualQuatLengthInvDQ*m
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
f32 ijkDualQuatLengthInvDQfm(float2x4 const dq_in);

// ijkDualQuatLengthSqInvSafeDQ*m
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
f32 ijkDualQuatLengthSqInvSafeDQfm(float2x4 const dq_in);

// ijkDualQuatLengthInvSafeDQ*m
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
f32 ijkDualQuatLengthInvSafeDQfm(float2x4 const dq_in);

// ijkDualQuatNormalizeDQ*m
//	Normalize dual quaternion.
//		param dq_out: output dual quaternion, unit-length
//		param dq_in: input dual quaternion
//		return: dq_out
float4m ijkDualQuatNormalizeDQfm(float2x4 dq_out, float2x4 const dq_in);

// ijkDualQuatNormalizeSafeDQ*m
//	Normalize dual quaternion; division-by-zero safety.
//		param dq_out: output dual quaternion, unit-length
//		param dq_in: input dual quaternion
//		return: dq_out
float4m ijkDualQuatNormalizeSafeDQfm(float2x4 dq_out, float2x4 const dq_in);

// ijkDualQuatInverseDQ*m
//	Calculate inverse of dual quaternion: conjugate divided by squared length.
//		param dq_out: output dual quaternion, inverse
//		param dq_in: input dual quaternion
//		return: dq_out
float4m ijkDualQuatInverseDQfm(float2x4 dq_out, float2x4 const dq_in);

// ijkDualQuatInverseSafeDQ*m
//	Calculate inverse of dual quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param dq_out: output dual quaternion, inverse
//		param dq_in: input dual quaternion
//		return: dq_out
float4m ijkDualQuatInverseSafeDQfm(float2x4 dq_out, float2x4 const dq_in);

// ijkDualQuatMulVecDQ*m3
//	Calculate product of dual quaternion and 3D vector (result is dual quaternion).
//		param dq_out: output dual quaternion, product
//		param dq_lh: left-hand dual quaternion
//		param v_rh: right-hand vector
//		return: dq_out
float4m ijkDualQuatMulVecDQfm3(float2x4 dq_out, float2x4 const dq_lh, float3 const v_rh);

// ijkDualQuatMulVecDQ*m3q
//	Calculate product of 3D vector and dual quaternion (result is dual quaternion).
//		param dq_out: output dual quaternion, product
//		param v_lh: left-hand vector
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
float4m ijkDualQuatMulVecDQfm3q(float2x4 dq_out, float3 const v_lh, float2x4 const dq_rh);

// ijkDualQuatMulDQ*m
//	Calculate product of dual quaternions, or concatenate unit dual quaternions
//	representing transformations.
//		param dq_out: output dual quaternion, product
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
float4m ijkDualQuatMulDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh);

// ijkDualQuatMulScaleDQ*m
//	Correctly concatenate dual quaternions that represent transformations such 
//	that the right-hand input's translation is correctly affected by the left-
//	hand input's scale, when used to transform a vector later.
//		param dq_out: output dual quaternion
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
float4m ijkDualQuatMulScaleDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh);

// ijkDualQuatDivDQ*m
//	Calculate quotient of dual quaternions (multiply by rh inverse).
//		param dq_out: output dual quaternion, quotient
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
float4m ijkDualQuatDivDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh);

// ijkDualQuatRotateDQ*m
//	Make rotation dual quaternion with Euler angles.
//		param dq_out: output dual quaternion, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: dq_out
float4m ijkDualQuatRotateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ);

// ijkDualQuatAxisAngleDQ*m
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param dq_out: output dual quaternion, rotation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: dq_out
float4m ijkDualQuatAxisAngleDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees);

// ijkDualQuatScaleDQ*m
//	Make rotation dual quaternion with uniform scale.
//		param dq_out: output dual quaternion, scale
//		param scale_unif: uniform scale amount
//		return: dq_out
float4m ijkDualQuatScaleDQfm(float2x4 dq_out, f32 const scale_unif);

// ijkDualQuatRotateScaleDQ*m
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: dq_out
float4m ijkDualQuatRotateScaleDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif);

// ijkDualQuatAxisAngleScaleDQ*m
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: dq_out
float4m ijkDualQuatAxisAngleScaleDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif);

// ijkDualQuatTranslateDQ*m
//	Make rotation dual quaternion with Euler angles.
//		param dq_out: output dual quaternion, translation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param translate: translation offset vector
//		return: dq_out
float4m ijkDualQuatTranslateDQfm(float2x4 dq_out, float3 const translate);

// ijkDualQuatRotateTranslateDQ*m
//	Make rotation dual quaternion with Euler angles.
//		param dq_out: output dual quaternion, rotation-translation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param translate: translation offset vector
//		return: dq_out
float4m ijkDualQuatRotateTranslateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const translate);

// ijkDualQuatAxisAngleTranslateDQ*m
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param dq_out: output dual quaternion, rotation-translation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: dq_out
float4m ijkDualQuatAxisAngleTranslateDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, float3 const translate);

// ijkDualQuatScaleTranslateDQ*m
//	Make rotation dual quaternion with uniform scale.
//		param dq_out: output dual quaternion, scale-translation
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: dq_out
float4m ijkDualQuatScaleTranslateDQfm(float2x4 dq_out, f32 const scale_unif, float3 const translate);

// ijkDualQuatRotateScaleTranslateDQ*m
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale-translation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: dq_out
float4m ijkDualQuatRotateScaleTranslateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif, float3 const translate);

// ijkDualQuatAxisAngleScaleTranslateDQ*m
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale-translation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: dq_out
float4m ijkDualQuatAxisAngleScaleTranslateDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif, float3 const translate);

// ijkDualQuatGetRotateDQ*m
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: dq_in
float4km ijkDualQuatGetRotateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out);

// ijkDualQuatGetAxisAngleDQ*m
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: dq_in
float4km ijkDualQuatGetAxisAngleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out);

// ijkDualQuatGetScaleDQ*m
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
float4km ijkDualQuatGetScaleDQfm(float2x4 const dq_in, f32* const scale_unif_out);

// ijkDualQuatGetRotateScaleDQ*m
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
float4km ijkDualQuatGetRotateScaleDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out);

// ijkDualQuatGetAxisAngleScaleDQ*m
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
float4km ijkDualQuatGetAxisAngleScaleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out);

// ijkDualQuatGetTranslateDQ*m
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetTranslateDQfm(float2x4 const dq_in, float3 translate_out);

// ijkDualQuatGetRotateTranslateDQ*m
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetRotateTranslateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 translate_out);

// ijkDualQuatGetAxisAngleTranslateDQ*m
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetAxisAngleTranslateDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out);

// ijkDualQuatGetScaleTranslateDQ*m
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetScaleTranslateDQfm(float2x4 const dq_in, f32* const scale_unif_out, float3 translate_out);

// ijkDualQuatGetRotateScaleTranslateDQ*m
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetRotateScaleTranslateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out, float3 translate_out);

// ijkDualQuatGetAxisAngleScaleTranslateDQ*m
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetAxisAngleScaleTranslateDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out, float3 translate_out);

// ijkDualQuatGetTranslateRemScaleDQ*m
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetTranslateRemScaleDQfm(float2x4 const dq_in, float3 translate_out);

// ijkDualQuatGetRotateTranslateRemScaleDQ*m
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetRotateTranslateRemScaleDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 translate_out);

// ijkDualQuatGetAxisAngleTranslateRemScaleDQ*m
//	Extract unit axis and angle in degrees from dual quaternion, removing 
//	scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetAxisAngleTranslateRemScaleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out);

// ijkDualQuatGetScaleTranslateRemScaleDQ*m
//	Extract uniform scale from dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetScaleTranslateRemScaleDQfm(float2x4 const dq_in, f32* const scale_unif_out, float3 translate_out);

// ijkDualQuatGetRotateScaleTranslateRemScaleDQ*m
//	Extract Euler angles and uniform scale from dual quaternion, removing 
//	scale from translation part.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetRotateScaleTranslateRemScaleDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out, float3 translate_out);

// ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQ*m
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion,
//	removing scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
float4km ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out, float3 translate_out);

// ijkDualQuatGetScrewParamsDQ*m
//	Extract screw parameters from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		param momentArm_out: storage for moment arm
//		param screwDisplace_out: storage for screw displacement parameter
//		return: dq_in
float4km ijkDualQuatGetScrewParamsDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out, float3 momentArm_out, f32* const screwDisplace_out);

// ijkDualQuatGetMatDQ*m3
//	Convert dual quaternion's real part to 3D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
float3m ijkDualQuatGetMatDQfm3(float3x3 m_out, float2x4 const dq_in);

// ijkDualQuatUnitGetMatDQ*m3
//	Convert unit dual quaternion's real part to 3D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
float3m ijkDualQuatUnitGetMatDQfm3(float3x3 m_out, float2x4 const dq_in);

// ijkDualQuatGetMatTranslateDQ*m3
//	Convert dual quaternion's real part to 3D matrix and extract translation.
//		param m_out: output matrix
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: m_out
float3m ijkDualQuatGetMatTranslateDQfm3(float3x3 m_out, float3 translate_out, float2x4 const dq_in);

// ijkDualQuatUnitGetMatTranslateDQ*m3
//	Convert unit dual quaternion's real part to 3D matrix and extract 
//	translation.
//		param m_out: output matrix
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: m_out
float3m ijkDualQuatUnitGetMatTranslateDQfm3(float3x3 m_out, float3 translate_out, float2x4 const dq_in);

// ijkDualQuatGetMatTranslateRemScaleDQ*m3
//	Convert dual quaternion's real part to 3D matrix and extract translation 
//	with scale removed.
//		param m_out: output matrix
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: m_out
float3m ijkDualQuatGetMatTranslateRemScaleDQfm3(float3x3 m_out, float3 translate_out, float2x4 const dq_in);

// ijkDualQuatGetMatDQ*m4
//	Convert dual quaternion to 4D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
float4m ijkDualQuatGetMatDQfm4(float4x4 m_out, float2x4 const dq_in);

// ijkDualQuatUnitGetMatDQ*m4
//	Convert unit dual quaternion to 4D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
float4m ijkDualQuatUnitGetMatDQfm4(float4x4 m_out, float2x4 const dq_in);

// ijkDualQuatGetMatTranslateRemScaleDQ*m4
//	Convert dual quaternion to 4D matrix, scale removed from translation part.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
float4m ijkDualQuatGetMatTranslateRemScaleDQfm4(float4x4 m_out, float2x4 const dq_in);

// ijkDualQuatTransformScaleVecDQ*m3
//	Transform a 3D vector using a dual quaternion with scale; use when dual 
//	quaternion has scale to prevent translation part from being scaled.
//		param v_out: output vector
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: v_out
floatv ijkDualQuatTransformScaleVecDQfm3(float3 v_out, float2x4 const dq_in, float3 const v_in);

// ijkDualQuatUnitTransformVecDQ*m3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	unit-length for most optimized solution or when translation part should 
//	also be scaled.
//		param v_out: output vector
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: v_out
floatv ijkDualQuatUnitTransformVecDQfm3(float3 v_out, float2x4 const dq_in, float3 const v_in);

// ijkDualQuatTransformVecDQ*m3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	non-unit length to remove scale from all parts.
//		param v_out: output vector
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: v_out
floatv ijkDualQuatTransformVecDQfm3(float3 v_out, float2x4 const dq_in, float3 const v_in);

// ijkDualQuatLerpDQ*m
//	Calculate linear interpolation between two dual quaternions; yields uniform
//	rate of change but affects translation path and scale.
//		param dq_out: output dual quaternion, interpolated dual quaternion
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: dq_out
float4m ijkDualQuatLerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u);

// ijkDualQuatNlerpDQ*m
//	Calculate normalized linear interpolation between two dual quaternions; 
//	keeps result at unit-length but yields a non-uniform rate of change.
//		param dq_out: output dual quaternion, interpolated dual quaternion
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: dq_out
float4m ijkDualQuatNlerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u);

// ijkDualQuatSclerpDQ*m
//	Calculate screw linear interpolation between two unit dual quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param dq_out: output dual quaternion, interpolated dual quaternion
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: dq_out
float4m ijkDualQuatSclerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u);

// ijkDualQuatDerivDQ*m
//	Calculate derivative of dual quaternion.
//		param dq1_out: output dual quaternion, derivative of dual quaternion
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param angularVelocity: angular velocity vector
//		return: dq1_out
float4m ijkDualQuatDerivDQfm(float2x4 dq1_out, float2x4 const dq_in, float3 const linearVelocity, float3 const angularVelocity);

// ijkDualQuatDeriv2DQ*m
//	Calculate second derivative of dual quaternion.
//		param dq2_out: output dual quaternion, second derivative of dual quaternion
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param linearAcceleration: linear acceleration vector
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: dq2_out
float4m ijkDualQuatDeriv2DQfm(float2x4 dq2_out, float2x4 const dq_in, float3 const linearVelocity, float3 const linearAcceleration, float3 const angularVelocity, float3 const angularAcceleration);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkQuatInitQ*
//	Initialize identity quaternion (zero vector, one real).
//		return: identity quaternion
fquat ijkQuatInitQf();

// ijkQuatInitZeroQ*
//	Initialize zero quaternion.
//		return: zero quaternion
fquat ijkQuatInitZeroQf();

// ijkQuatInitElemsQ*
//	Initialize individual elements of quaternion.
//		params x, y, z, w: components
//		return: xyzw quaternion
fquat ijkQuatInitElemsQf(float const x, float const y, float const z, float const w);

// ijkQuatInitVecReQ*
//	Initialize quaternion with vector and real parts.
//		param vec: vector components (xyz)
//		param re: real component (w)
//		return: output quaternion
fquat ijkQuatInitVecReQf(fvec3 const vec, float const re);

// ijkQuatInitVecProductQ*
//	Initialize quaternion as product of two vectors.
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: output quaternion
fquat ijkQuatInitVecProductQf(fvec3 const v_lh, fvec3 const v_rh);

// ijkQuatInitVecProductSqrtQ*
//	Initialize quaternion as product square root of two vectors.
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: output quaternion
fquat ijkQuatInitVecProductSqrtQf(fvec3 const v_lh, fvec3 const v_rh);

// ijkQuatInitVecProductSqrtUnitQ*
//	Initialize quaternion as product square root of two unit vectors.
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: output quaternion
fquat ijkQuatInitVecProductSqrtUnitQf(fvec3 const v_lh, fvec3 const v_rh);

// ijkQuatInitMatQ*3
//	Initialize quaternion from 3D matrix.
//		param m_in: input matrix
//		return: output quaternion
fquat ijkQuatInitMatQf3(fmat3 const m_in);

// ijkQuatInitMatQ*4
//	Initialize quaternion from 4D matrix.
//		param m_in: input matrix
//		return: output quaternion
fquat ijkQuatInitMatQf4(fmat4 const m_in);

// ijkQuatCopyQ*
//	Copy quaternion.
//		param q_in: input quaternion
//		return: copy
fquat ijkQuatCopyQf(fquat const q_in);

// ijkQuatNegateQ*
//	Negate quaternion.
//		param q_in: input quaternion
//		return: negative quaternion
fquat ijkQuatNegateQf(fquat const q_in);

// ijkQuatConjugateQ*
//	Conjugate quaternion: negate vector part, copy real part.
//		param q_in: input quaternion
//		return: conjugate quaternion
fquat ijkQuatConjugateQf(fquat const q_in);

// ijkQuatConjugateMulQ*s
//	Conjugate quaternion: negate vector part, copy real part, multiply by 
//	scalar.
//		param q_in: input quaternion
//		return: scaled conjugate quaternion
fquat ijkQuatConjugateMulQfs(fquat const q_in, float const s);

// ijkQuatNegateConjugateQ*
//	Negate and conjugate quaternion: negate real part, copy vector part.
//		param q_in: input quaternion
//		return: negative conjugate quaternion
fquat ijkQuatNegateConjugateQf(fquat const q_in);

// ijkQuatNegateConjugateMulQ*s
//	Negate and conjugate quaternion: negate real part, copy vector part, 
//	multiply by scalar.
//		param q_in: input quaternion
//		return: scaled negative conjugate quaternion
fquat ijkQuatNegateConjugateMulQfs(fquat const q_in, float const s);

// ijkQuatAddQ*
//	Calculate sum of quaternions.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: sum quaternion
fquat ijkQuatAddQf(fquat const q_lh, fquat const q_rh);

// ijkQuatSubQ*
//	Calculate difference of quaternions.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: difference quaternion
fquat ijkQuatSubQf(fquat const q_lh, fquat const q_rh);

// ijkQuatMulQ*s
//	Calculate product of quaternion and scalar.
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: product quaternion
fquat ijkQuatMulQfs(fquat const q_lh, float const s_rh);

// ijkQuatDivQ*s
//	Calculate quotient of quaternion and scalar.
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: quotient quaternion
fquat ijkQuatDivQfs(fquat const q_lh, float const s_rh);

// ijkQuatDivSafeQ*s
//	Calculate quotient of quaternion and scalar; division-by-zero safety.
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: quotient quaternion
fquat ijkQuatDivSafeQfs(fquat const q_lh, float const s_rh);

// ijkQuatLengthSqQ*
//	Calculate squared length of quaternion.
//		param q_in: input quaternion
//		return: squared length
float ijkQuatLengthSqQf(fquat const q_in);

// ijkQuatLengthQ*
//	Calculate length of quaternion.
//		param q_in: input quaternion
//		return: length
float ijkQuatLengthQf(fquat const q_in);

// ijkQuatLengthSqInvQ*
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
float ijkQuatLengthSqInvQf(fquat const q_in);

// ijkQuatLengthInvQ*
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
float ijkQuatLengthInvQf(fquat const q_in);

// ijkQuatLengthSqInvSafeQ*
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
float ijkQuatLengthSqInvSafeQf(fquat const q_in);

// ijkQuatLengthInvSafeQ*
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
float ijkQuatLengthInvSafeQf(fquat const q_in);

// ijkQuatNormalizeQ*
//	Normalize quaternion.
//		param q_in: input quaternion
//		return: unit quaternion
fquat ijkQuatNormalizeQf(fquat const q_in);

// ijkQuatNormalizeSafeQ*
//	Normalize quaternion; division-by-zero safety.
//		param q_in: input quaternion
//		return: unit quaternion
fquat ijkQuatNormalizeSafeQf(fquat const q_in);

// ijkQuatInverseQ*
//	Calculate inverse of quaternion: conjugate divided by squared length.
//		param q_in: input quaternion
//		return: inverse quaternion
fquat ijkQuatInverseQf(fquat const q_in);

// ijkQuatInverseSafeQ*
//	Calculate inverse of quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param q_in: input quaternion
//		return: inverse quaternion
fquat ijkQuatInverseSafeQf(fquat const q_in);

// ijkQuatMulVecQ*3
//	Calculate product of quaternion and 3D vector (result is quaternion).
//		param q_lh: left-hand quaternion
//		param v_rh: right-hand vector
//		return: product quaternion
fquat ijkQuatMulVecQf3(fquat const q_lh, fvec3 const v_rh);

// ijkQuatMulVecQ*3q
//	Calculate product of 3D vector and quaternion (result is quaternion).
//		param v_lh: left-hand vector
//		param q_rh: right-hand quaternion
//		return: product quaternion
fquat ijkQuatMulVecQf3q(fvec3 const v_lh, fquat const q_rh);

// ijkQuatMulQ*
//	Calculate product of quaternions.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: product quaternion
fquat ijkQuatMulQf(fquat const q_lh, fquat const q_rh);

// ijkQuatMulConjQ*
//	Calculate product of quaternion with quaternion conjugate.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion, conjugated before multiplying
//		return: product quaternion
fquat ijkQuatMulConjQf(fquat const q_lh, fquat const q_rh);

// ijkQuatConjMulQ*
//	Calculate product of quaternion conjugate with quaternion.
//		param q_lh: left-hand quaternion, conjugated before multiplying
//		param q_rh: right-hand quaternion
//		return: product quaternion
fquat ijkQuatConjMulQf(fquat const q_lh, fquat const q_rh);

// ijkQuatDivQ*
//	Calculate quotient of quaternions (multiply by rh inverse).
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: quotient quaternion
fquat ijkQuatDivQf(fquat const q_lh, fquat const q_rh);

// ijkQuatRotateXYZQ*
//	Make rotation quaternion with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
fquat ijkQuatRotateXYZQf(fvec3 const rotateDegXYZ);

// ijkQuatRotateYZXQ*
//	Make rotation quaternion with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
fquat ijkQuatRotateYZXQf(fvec3 const rotateDegXYZ);

// ijkQuatRotateZXYQ*
//	Make rotation quaternion with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
fquat ijkQuatRotateZXYQf(fvec3 const rotateDegXYZ);

// ijkQuatRotateYXZQ*
//	Make rotation quaternion with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
fquat ijkQuatRotateYXZQf(fvec3 const rotateDegXYZ);

// ijkQuatRotateXZYQ*
//	Make rotation quaternion with Euler angles in written order XZY, meaning 
//	the order of operations is X then Z then Y.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
fquat ijkQuatRotateXZYQf(fvec3 const rotateDegXYZ);

// ijkQuatRotateZYXQ*
//	Make rotation quaternion with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
fquat ijkQuatRotateZYXQf(fvec3 const rotateDegXYZ);

// ijkQuatGetRotateXYZQ*
//	Extract Euler angles from rotation quaternion; written order XYZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
fquat ijkQuatGetRotateXYZQf(fquat const q_in, fvec3* const rotateDegXYZ_out);

// ijkQuatGetRotateYZXQ*
//	Extract Euler angles from rotation quaternion; written order YZX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
fquat ijkQuatGetRotateYZXQf(fquat const q_in, fvec3* const rotateDegXYZ_out);

// ijkQuatGetRotateZXYQ*
//	Extract Euler angles from rotation quaternion; written order ZXY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
fquat ijkQuatGetRotateZXYQf(fquat const q_in, fvec3* const rotateDegXYZ_out);

// ijkQuatGetRotateYXZQ*
//	Extract Euler angles from rotation quaternion; written order YXZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
fquat ijkQuatGetRotateYXZQf(fquat const q_in, fvec3* const rotateDegXYZ_out);

// ijkQuatGetRotateXZYQ*
//	Extract Euler angles from rotation quaternion; written order XZY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
fquat ijkQuatGetRotateXZYQf(fquat const q_in, fvec3* const rotateDegXYZ_out);

// ijkQuatGetRotateZYXQ*
//	Extract Euler angles from rotation quaternion; written order ZYX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
fquat ijkQuatGetRotateZYXQf(fquat const q_in, fvec3* const rotateDegXYZ_out);

// ijkQuatRotateQ*
//	Make rotation quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
fquat ijkQuatRotateQf(ijkRotationOrder const order, fvec3 const rotateDegXYZ);

// ijkQuatAxisAngleQ*
//	Make rotation quaternion with unit axis and angle in degrees.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation quaternion
fquat ijkQuatAxisAngleQf(fvec3 const axis_unit, float const angle_degrees);

// ijkQuatScaleQ*
//	Make rotation quaternion with uniform scale.
//		param scale_unif: uniform scale amount
//		return: scale quaternion
fquat ijkQuatScaleQf(float const scale_unif);

// ijkQuatRotateScaleQ*
//	Make rotation quaternion with Euler angles and uniform scale.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: rotation-scale quaternion
fquat ijkQuatRotateScaleQf(ijkRotationOrder const order, fvec3 const rotateDegXYZ, float const scale_unif);

// ijkQuatAxisAngleScaleQ*
//	Make rotation quaternion with unit axis, angle in degrees and uniform scale.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: rotation-scale quaternion
fquat ijkQuatAxisAngleScaleQf(fvec3 const axis_unit, float const angle_degrees, float const scale_unif);

// ijkQuatGetRotateQ*
//	Extract Euler angles from rotation quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
fquat ijkQuatGetRotateQf(fquat const q_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out);

// ijkQuatGetAxisAngleQ*
//	Extract unit axis and angle in degrees from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: q_in
fquat ijkQuatGetAxisAngleQf(fquat const q_in, fvec3* const axis_unit_out, float* const angle_degrees_out);

// ijkQuatGetScaleQ*
//	Extract uniform scale from quaternion.
//		param q_in: input quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
fquat ijkQuatGetScaleQf(fquat const q_in, float* const scale_unif_out);

// ijkQuatGetRotateScaleQ*
//	Extract Euler angles and uniform scale from quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
fquat ijkQuatGetRotateScaleQf(fquat const q_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, float* const scale_unif_out);

// ijkQuatGetAxisAngleScaleQ*
//	Extract unit axis, angle in degrees and uniform scale from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
fquat ijkQuatGetAxisAngleScaleQf(fquat const q_in, fvec3* const axis_unit_out, float* const angle_degrees_out, float* const scale_unif_out);

// ijkQuatGetMatQ*3
//	Convert quaternion to 3D matrix.
//		param q_in: input quaternion
//		return: output matrix
fmat3 ijkQuatGetMatQf3(fquat const q_in);

// ijkQuatUnitGetMatQ*3
//	Convert unit quaternion to 3D matrix.
//		param q_in: input quaternion
//		return: output matrix
fmat3 ijkQuatUnitGetMatQf3(fquat const q_in);

// ijkQuatGetMatQ*4
//	Convert quaternion to 4D matrix.
//		param q_in: input quaternion
//		return: output matrix
fmat4 ijkQuatGetMatQf4(fquat const q_in);

// ijkQuatUnitGetMatQ*4
//	Convert unit quaternion to 4D matrix.
//		param q_in: input quaternion
//		return: output matrix
fmat4 ijkQuatUnitGetMatQf4(fquat const q_in);

// ijkQuatGetMatQ*4t
//	Convert quaternion to 4D matrix, with additional translation vector.
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: output matrix
fmat4 ijkQuatGetMatQf4t(fquat const q_in, fvec3 const translate);

// ijkQuatUnitGetMatQ*4t
//	Convert unit quaternion to 4D matrix, with additional translation vector.
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: output matrix
fmat4 ijkQuatUnitGetMatQf4t(fquat const q_in, fvec3 const translate);

// ijkQuatRotateScaleVecQ*3
//	Rotate and/or scale a 3D vector using a quaternion; result will not be 
//	divided by squared magnitude.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: rotated vector
fvec3 ijkQuatRotateScaleVecQf3(fquat const q_in, fvec3 const v_in);

// ijkQuatUnitRotateVecQ*3
//	Rotate a 3D vector using a quaternion; use with unit quaternion for most 
//	optimized solution.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: rotated vector
fvec3 ijkQuatUnitRotateVecQf3(fquat const q_in, fvec3 const v_in);

// ijkQuatRotateVecQ*3
//	Rotate a 3D vector using a quaternion; use this when the input quaternion 
//	is non-unit length so that the result will only be rotated.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: rotated vector
fvec3 ijkQuatRotateVecQf3(fquat const q_in, fvec3 const v_in);

// ijkQuatReflectScaleQ*
//	Reflect and/or scale a quaternion about an axis.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: reflected quaternion
fquat ijkQuatReflectScaleQf(fquat const q_in, fvec3 const v_in);

// ijkQuatUnitReflectQ*
//	Reflect a unit quaternion about an axis; optimized for unit quaternions.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: reflected quaternion
fquat ijkQuatUnitReflectQf(fquat const q_in, fvec3 const v_in);

// ijkQuatReflectQ*
//	Reflect a non-unit quaternion about an axis.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: reflected quaternion
fquat ijkQuatReflectQf(fquat const q_in, fvec3 const v_in);

// ijkQuatExpQ*
//	Calculate quaternion as natural exponent base (e) raised to vector power.
//		param v_in: input vector
//		return: exp
fquat ijkQuatExpQf(fvec3 const v_in);

// ijkQuatLnQ*
//	Calculate quaternion or vector as natural logarithm of quaternion.
//		param q_in: input quaternion
//		return: ln
fquat ijkQuatLnQf(fquat const q_in);

// ijkQuatPowQ*
//	Calculate quaternion raised to power of exponent.
//		param q_in: input quaternion
//		param u: exponent
//		return: pow
fquat ijkQuatPowQf(fquat const q_in, float const u);

// ijkQuatSqrtQ*
//	Calculate square root of quaternion.
//		param q_in: input quaternion
//		return: sqrt
fquat ijkQuatSqrtQf(fquat const q_in);

// ijkQuatLerpQ*
//	Calculate linear interpolation between two quaternions; yields a uniform 
//	rate of change but affects encoded scale.
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: interpolated quaternion
fquat ijkQuatLerpQf(fquat const q0, fquat const q1, float const u);

// ijkQuatNlerpQ*
//	Calculate normalized linear interpolation between two quaternions; keeps 
//	result at unit-length but yields a non-uniform rate of change.
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: interpolated quaternion
fquat ijkQuatNlerpQf(fquat const q0, fquat const q1, float const u);

// ijkQuatSlerpQ*
//	Calculate spherical linear interpolation between two unit quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: interpolated quaternion
fquat ijkQuatSlerpQf(fquat const q0, fquat const q1, float const u);

// ijkQuatDerivQ*
//	Calculate derivative of quaternion.
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		return: derivative of quaternion
fquat ijkQuatDerivQf(fquat const q_in, fvec3 const angularVelocity);

// ijkQuatDeriv2Q*
//	Calculate second derivative of quaternion.
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: second derivative of quaternion
fquat ijkQuatDeriv2Qf(fquat const q_in, fvec3 const angularVelocity, fvec3 const angularAcceleration);

// ijkQuatEncodeTranslateQ*
//	Encode translation offset vector using quaternion.
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: encoded translation
fquat ijkQuatEncodeTranslateQf(fvec3 const translate_in, fquat const q_encode);

// ijkQuatEncodeTranslateX2Q*
//	Encode double translation offset vector using quaternion.
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: encoded translation
fquat ijkQuatEncodeTranslateX2Qf(fvec3 const translate_in, fquat const q_encode);

// ijkQuatDecodeTranslateQ*
//	Decode translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
fvec3 ijkQuatDecodeTranslateQf(fquat const qt_in, fquat const q_decode);

// ijkQuatDecodeTranslateD2Q*s
//	Decode half translation offset vector from quaternion with scalar 
//	multiplier; use if encoding quaternion is unit or if decoded translation 
//	should have additional user-defined scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
fvec3 ijkQuatDecodeTranslateD2Qfs(fquat const qt_in, fquat const q_decode, float const s);

// ijkQuatDecodeTranslateD2Q*
//	Decode half translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
fvec3 ijkQuatDecodeTranslateD2Qf(fquat const qt_in, fquat const q_decode);

// ijkQuatDecodeTranslateRemScaleQ*
//	Decode translation offset vector from quaternion, removing scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
fvec3 ijkQuatDecodeTranslateRemScaleQf(fquat const qt_in, fquat const q_decode);

// ijkQuatDecodeTranslateRemScaleD2Q*
//	Decode half translation offset vector from quaternion, removing scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
fvec3 ijkQuatDecodeTranslateRemScaleD2Qf(fquat const qt_in, fquat const q_decode);


//-----------------------------------------------------------------------------

// ijkDualQuatInitDQ*
//	Initialize identity dual quaternion (zero dual, identity real).
//		return: identity dual quaternion
fdualquat ijkDualQuatInitDQf();

// ijkDualQuatInitDualReDQ*
//	Initialize dual quaternion with dual and real parts.
//		param re: real component (qr)
//		param dual: dual component (E qd)
//		return: r+Ed dual quaternion
fdualquat ijkDualQuatInitDualReDQf(fquat const re, fquat const dual);

// ijkDualQuatInitMatDQ*3
//	Initialize dual quaternion from 3D matrix.
//		param m_in: input matrix
//		return: output dual quaternion
fdualquat ijkDualQuatInitMatDQf3(fmat3 const m_in);

// ijkDualQuatInitMatDQ*4
//	Initialize dual quaternion from 4D matrix.
//		param m_in: input matrix
//		return: output dual quaternion
fdualquat ijkDualQuatInitMatDQf4(fmat4 const m_in);

// ijkDualQuatCopyDQ*
//	Copy dual quaternion.
//		param dq_in: input dual quaternion
//		return: copy
fdualquat ijkDualQuatCopyDQf(fdualquat const dq_in);

// ijkDualQuatNegateDQ*
//	Negate dual quaternion.
//		param dq_in: input dual quaternion
//		return: negative dual quaternion
fdualquat ijkDualQuatNegateDQf(fdualquat const dq_in);

// ijkDualQuatConjugateDQ*
//	Conjugate dual quaternion: take conjugate of both components.
//		param dq_in: input dual quaternion
//		return: conjugate dual quaternion
fdualquat ijkDualQuatConjugateDQf(fdualquat const dq_in);

// ijkDualQuatNegateDualDQ*
//	Negate dual part: conjugate of dual number.
//		param dq_in: input dual quaternion
//		return: dual conjugate dual quaternion
fdualquat ijkDualQuatNegateDualDQf(fdualquat const dq_in);

// ijkDualQuatConjugateDualDQ*
//	Conjugate and negate dual part: conjugate of dual number and components.
//		param dq_in: input dual quaternion
//		return: full dual conjugate dual quaternion
fdualquat ijkDualQuatConjugateDualDQf(fdualquat const dq_in);

// ijkDualQuatAddDQ*
//	Calculate sum of dual quaternions.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: sum dual quaternion
fdualquat ijkDualQuatAddDQf(fdualquat const dq_lh, fdualquat const dq_rh);

// ijkDualQuatSubDQ*
//	Calculate difference of dual quaternions.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: difference dual quaternion
fdualquat ijkDualQuatSubDQf(fdualquat const dq_lh, fdualquat const dq_rh);

// ijkDualQuatMulDQ*s
//	Calculate product of dual quaternion and scalar.
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: product dual quaternion
fdualquat ijkDualQuatMulDQfs(fdualquat const dq_lh, float const s_rh);

// ijkDualQuatDivDQ*s
//	Calculate quotient of dual quaternion and scalar.
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: quotient dual quaternion
fdualquat ijkDualQuatDivDQfs(fdualquat const dq_lh, float const s_rh);

// ijkDualQuatDivSafeDQ*s
//	Calculate quotient of dual quaternion and scalar; division-by-zero safety.
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: quotient dual quaternion
fdualquat ijkDualQuatDivSafeDQfs(fdualquat const dq_lh, float const s_rh);

// ijkDualQuatLengthSqDQ*
//	Calculate squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: squared length
float ijkDualQuatLengthSqDQf(fdualquat const dq_in);

// ijkDualQuatLengthDQ*
//	Calculate length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: length
float ijkDualQuatLengthDQf(fdualquat const dq_in);

// ijkDualQuatLengthSqInvDQ*
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
float ijkDualQuatLengthSqInvDQf(fdualquat const dq_in);

// ijkDualQuatLengthInvDQ*
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
float ijkDualQuatLengthInvDQf(fdualquat const dq_in);

// ijkDualQuatLengthSqInvSafeDQ*
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
float ijkDualQuatLengthSqInvSafeDQf(fdualquat const dq_in);

// ijkDualQuatLengthInvSafeDQ*
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
float ijkDualQuatLengthInvSafeDQf(fdualquat const dq_in);

// ijkDualQuatNormalizeDQ*
//	Normalize dual quaternion.
//		param dq_in: input dual quaternion
//		return: unit dual quaternion
fdualquat ijkDualQuatNormalizeDQf(fdualquat const dq_in);

// ijkDualQuatNormalizeSafeDQ*
//	Normalize dual quaternion; division-by-zero safety.
//		param dq_in: input dual quaternion
//		return: unit dual quaternion
fdualquat ijkDualQuatNormalizeSafeDQf(fdualquat const dq_in);

// ijkDualQuatInverseDQ*
//	Calculate inverse of dual quaternion: conjugate divided by squared length.
//		param dq_in: input dual quaternion
//		return: inverse dual quaternion
fdualquat ijkDualQuatInverseDQf(fdualquat const dq_in);

// ijkDualQuatInverseSafeDQ*
//	Calculate inverse of dual quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param dq_in: input dual quaternion
//		return: inverse dual quaternion
fdualquat ijkDualQuatInverseSafeDQf(fdualquat const dq_in);

// ijkDualQuatMulVecDQ*3
//	Calculate product of dual quaternion and 3D vector (result is dual quaternion).
//		param dq_lh: left-hand dual quaternion
//		param v_rh: right-hand vector
//		return: product dual quaternion
fdualquat ijkDualQuatMulVecDQf3(fdualquat const dq_lh, fvec3 const v_rh);

// ijkDualQuatMulVecDQ*3q
//	Calculate product of 3D vector and dual quaternion (result is dual quaternion).
//		param v_lh: left-hand vector
//		param dq_rh: right-hand dual quaternion
//		return: product dual quaternion
fdualquat ijkDualQuatMulVecDQf3q(fvec3 const v_lh, fdualquat const dq_rh);

// ijkDualQuatMulDQ*
//	Calculate product of dual quaternions, or concatenate unit dual quaternions
//	representing transformations.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: product dual quaternion
fdualquat ijkDualQuatMulDQf(fdualquat const dq_lh, fdualquat const dq_rh);

// ijkDualQuatMulScaleDQ*
//	Correctly concatenate dual quaternions that represent transformations such 
//	that the right-hand input's translation is correctly affected by the left-
//	hand input's scale, when used to transform a vector later.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: product dual quaternion
fdualquat ijkDualQuatMulScaleDQf(fdualquat const dq_lh, fdualquat const dq_rh);

// ijkDualQuatDivDQ*
//	Calculate quotient of dual quaternions (multiply by rh inverse).
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: quotient dual quaternion
fdualquat ijkDualQuatDivDQf(fdualquat const dq_lh, fdualquat const dq_rh);

// ijkDualQuatRotateDQ*
//	Make rotation dual quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation dual quaternion
fdualquat ijkDualQuatRotateDQf(ijkRotationOrder const order, fvec3 const rotateDegXYZ);

// ijkDualQuatAxisAngleDQ*
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation dual quaternion
fdualquat ijkDualQuatAxisAngleDQf(fvec3 const axis_unit, float const angle_degrees);

// ijkDualQuatScaleDQ*
//	Make rotation dual quaternion with uniform scale.
//		param scale_unif: uniform scale amount
//		return: scale dual quaternion
fdualquat ijkDualQuatScaleDQf(float const scale_unif);

// ijkDualQuatRotateScaleDQ*
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: rotation-scale dual quaternion
fdualquat ijkDualQuatRotateScaleDQf(ijkRotationOrder const order, fvec3 const rotateDegXYZ, float const scale_unif);

// ijkDualQuatAxisAngleScaleDQ*
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: rotation-scale dual quaternion
fdualquat ijkDualQuatAxisAngleScaleDQf(fvec3 const axis_unit, float const angle_degrees, float const scale_unif);

// ijkDualQuatTranslateDQ*
//	Make rotation dual quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param translate: translation offset vector
//		return: translation dual quaternion
fdualquat ijkDualQuatTranslateDQf(fvec3 const translate);

// ijkDualQuatRotateTranslateDQ*
//	Make rotation dual quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param translate: translation offset vector
//		return: rotation-translation dual quaternion
fdualquat ijkDualQuatRotateTranslateDQf(ijkRotationOrder const order, fvec3 const rotateDegXYZ, fvec3 const translate);

// ijkDualQuatAxisAngleTranslateDQ*
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: rotation-translation dual quaternion
fdualquat ijkDualQuatAxisAngleTranslateDQf(fvec3 const axis_unit, float const angle_degrees, fvec3 const translate);

// ijkDualQuatScaleTranslateDQ*
//	Make rotation dual quaternion with uniform scale.
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: scale-translation dual quaternion
fdualquat ijkDualQuatScaleTranslateDQf(float const scale_unif, fvec3 const translate);

// ijkDualQuatRotateScaleTranslateDQ*
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: rotation-scale-translation dual quaternion
fdualquat ijkDualQuatRotateScaleTranslateDQf(ijkRotationOrder const order, fvec3 const rotateDegXYZ, float const scale_unif, fvec3 const translate);

// ijkDualQuatAxisAngleScaleTranslateDQ*
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: rotation-scale-translation dual quaternion
fdualquat ijkDualQuatAxisAngleScaleTranslateDQf(fvec3 const axis_unit, float const angle_degrees, float const scale_unif, fvec3 const translate);

// ijkDualQuatGetRotateDQ*
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: dq_in
fdualquat ijkDualQuatGetRotateDQf(fdualquat const dq_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out);

// ijkDualQuatGetAxisAngleDQ*
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: dq_in
fdualquat ijkDualQuatGetAxisAngleDQf(fdualquat const dq_in, fvec3* const axis_unit_out, float* const angle_degrees_out);

// ijkDualQuatGetScaleDQ*
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
fdualquat ijkDualQuatGetScaleDQf(fdualquat const dq_in, float* const scale_unif_out);

// ijkDualQuatGetRotateScaleDQ*
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
fdualquat ijkDualQuatGetRotateScaleDQf(fdualquat const dq_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, float* const scale_unif_out);

// ijkDualQuatGetAxisAngleScaleDQ*
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
fdualquat ijkDualQuatGetAxisAngleScaleDQf(fdualquat const dq_in, fvec3* const axis_unit_out, float* const angle_degrees_out, float* const scale_unif_out);

// ijkDualQuatGetTranslateDQ*
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetTranslateDQf(fdualquat const dq_in, fvec3* const translate_out);

// ijkDualQuatGetRotateTranslateDQ*
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetRotateTranslateDQf(fdualquat const dq_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, fvec3* const translate_out);

// ijkDualQuatGetAxisAngleTranslateDQ*
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetAxisAngleTranslateDQf(fdualquat const dq_in, fvec3* const axis_unit_out, float* const angle_degrees_out, fvec3* const translate_out);

// ijkDualQuatGetScaleTranslateDQ*
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetScaleTranslateDQf(fdualquat const dq_in, float* const scale_unif_out, fvec3* const translate_out);

// ijkDualQuatGetRotateScaleTranslateDQ*
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetRotateScaleTranslateDQf(fdualquat const dq_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, float* const scale_unif_out, fvec3* const translate_out);

// ijkDualQuatGetAxisAngleScaleTranslateDQ*
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetAxisAngleScaleTranslateDQf(fdualquat const dq_in, fvec3* const axis_unit_out, float* const angle_degrees_out, float* const scale_unif_out, fvec3* const translate_out);

// ijkDualQuatGetTranslateRemScaleDQ*
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetTranslateRemScaleDQf(fdualquat const dq_in, fvec3* const translate_out);

// ijkDualQuatGetRotateTranslateRemScaleDQ*
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetRotateTranslateRemScaleDQf(fdualquat const dq_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, fvec3* const translate_out);

// ijkDualQuatGetAxisAngleTranslateRemScaleDQ*
//	Extract unit axis and angle in degrees from dual quaternion, removing 
//	scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetAxisAngleTranslateRemScaleDQf(fdualquat const dq_in, fvec3* const axis_unit_out, float* const angle_degrees_out, fvec3* const translate_out);

// ijkDualQuatGetScaleTranslateRemScaleDQ*
//	Extract uniform scale from dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetScaleTranslateRemScaleDQf(fdualquat const dq_in, float* const scale_unif_out, fvec3* const translate_out);

// ijkDualQuatGetRotateScaleTranslateRemScaleDQ*
//	Extract Euler angles and uniform scale from dual quaternion, removing 
//	scale from translation part.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetRotateScaleTranslateRemScaleDQf(fdualquat const dq_in, ijkRotationOrder const order, fvec3* const rotateDegXYZ_out, float* const scale_unif_out, fvec3* const translate_out);

// ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQ*
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion,
//	removing scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
fdualquat ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQf(fdualquat const dq_in, fvec3* const axis_unit_out, float* const angle_degrees_out, float* const scale_unif_out, fvec3* const translate_out);

// ijkDualQuatGetScrewParamsDQ*
//	Extract screw parameters from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		param momentArm_out: storage for moment arm
//		param screwDisplace_out: storage for screw displacement parameter
//		return: dq_in
fdualquat ijkDualQuatGetScrewParamsDQf(fdualquat const dq_in, fvec3* const axis_unit_out, float* const angle_degrees_out, fvec3* const translate_out, fvec3* const momentArm_out, float* const screwDisplace_out);

// ijkDualQuatGetMatDQ*3
//	Convert dual quaternion's real part to 3D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
fmat3 ijkDualQuatGetMatDQf3(fdualquat const dq_in);

// ijkDualQuatUnitGetMatDQ*3
//	Convert unit dual quaternion's real part to 3D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
fmat3 ijkDualQuatUnitGetMatDQf3(fdualquat const dq_in);

// ijkDualQuatGetMatTranslateDQ*3
//	Convert dual quaternion's real part to 3D matrix and extract translation.
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: output matrix
fmat3 ijkDualQuatGetMatTranslateDQf3(fvec3* const translate_out, fdualquat const dq_in);

// ijkDualQuatUnitGetMatTranslateDQ*3
//	Convert unit dual quaternion's real part to 3D matrix and extract 
//	translation.
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: output matrix
fmat3 ijkDualQuatUnitGetMatTranslateDQf3(fvec3* const translate_out, fdualquat const dq_in);

// ijkDualQuatGetMatTranslateRemScaleDQ*3
//	Convert dual quaternion's real part to 3D matrix and extract translation 
//	with scale removed.
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: output matrix
fmat3 ijkDualQuatGetMatTranslateRemScaleDQf3(fvec3* const translate_out, fdualquat const dq_in);

// ijkDualQuatGetMatDQ*4
//	Convert dual quaternion to 4D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
fmat4 ijkDualQuatGetMatDQf4(fdualquat const dq_in);

// ijkDualQuatUnitGetMatDQ*4
//	Convert unit dual quaternion to 4D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
fmat4 ijkDualQuatUnitGetMatDQf4(fdualquat const dq_in);

// ijkDualQuatGetMatTranslateRemScaleDQ*4
//	Convert dual quaternion to 4D matrix, scale removed from translation part.
//		param dq_in: input dual quaternion
//		return: output matrix
fmat4 ijkDualQuatGetMatTranslateRemScaleDQf4(fdualquat const dq_in);

// ijkDualQuatTransformScaleVecDQ*3
//	Transform a 3D vector using a dual quaternion with scale; use when dual 
//	quaternion has scale to prevent translation part from being scaled.
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: transformed vector
fvec3 ijkDualQuatTransformScaleVecDQf3(fdualquat const dq_in, fvec3 const v_in);

// ijkDualQuatUnitTransformVecDQ*3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	unit-length for most optimized solution or when translation part should 
//	also be scaled.
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: transformed vector
fvec3 ijkDualQuatUnitTransformVecDQf3(fdualquat const dq_in, fvec3 const v_in);

// ijkDualQuatTransformVecDQ*3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	non-unit length to remove scale from all parts.
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: transformed vector
fvec3 ijkDualQuatTransformVecDQf3(fdualquat const dq_in, fvec3 const v_in);

// ijkDualQuatLerpDQ*
//	Calculate linear interpolation between two dual quaternions; yields uniform
//	rate of change but affects translation path and scale.
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: interpolated dual quaternion
fdualquat ijkDualQuatLerpDQf(fdualquat const dq0, fdualquat const dq1, float const u);

// ijkDualQuatNlerpDQ*
//	Calculate normalized linear interpolation between two dual quaternions; 
//	keeps result at unit-length but yields a non-uniform rate of change.
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: interpolated dual quaternion
fdualquat ijkDualQuatNlerpDQf(fdualquat const dq0, fdualquat const dq1, float const u);

// ijkDualQuatSclerpDQ*
//	Calculate screw linear interpolation between two unit dual quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: interpolated dual quaternion
fdualquat ijkDualQuatSclerpDQf(fdualquat const dq0, fdualquat const dq1, float const u);

// ijkDualQuatDerivDQ*
//	Calculate derivative of dual quaternion.
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param angularVelocity: angular velocity vector
//		return: derivative of dual quaternion
fdualquat ijkDualQuatDerivDQf(fdualquat const dq_in, fvec3 const linearVelocity, fvec3 const angularVelocity);

// ijkDualQuatDeriv2DQ*
//	Calculate second derivative of dual quaternion.
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param linearAcceleration: linear acceleration vector
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: second derivative of dual quaternion
fdualquat ijkDualQuatDeriv2DQf(fdualquat const dq_in, fvec3 const linearVelocity, fvec3 const linearAcceleration, fvec3 const angularVelocity, fvec3 const angularAcceleration);


//-----------------------------------------------------------------------------


#include "_inl/ijkQuaternion_float.inl"


#endif	// !_IJK_QUATERNION_FLOAT_H_
#endif	// _IJK_QUATERNION_H_