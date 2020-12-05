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

	ijkQuaternion_double.h
	Declarations for double quaternion functions.
*/

#ifdef _IJK_QUATERNION_H_
#ifndef _IJK_QUATERNION_DOUBLE_H_
#define _IJK_QUATERNION_DOUBLE_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkQuatP*v
//	Pass-thru array-based quaternion (does nothing).
//		param q_out: output quaternion
//		return: q_out
doublev ijkQuatPdv(double4 q_out);

// ijkDualQuatP*v
//	Pass-thru array-based dual quaternion (does nothing).
//		param dq_out: output dual quaternion
//		return: dq_out
double4m ijkDualQuatPdm(double2x4 dq_out);


//-----------------------------------------------------------------------------

// ijkQuatInitQ*v
//	Initialize identity quaternion (zero vector, one real).
//		param q_out: output quaternion
//		return: q_out
doublev ijkQuatInitQdv(double4 q_out);

// ijkQuatInitZeroQ*v
//	Initialize zero quaternion.
//		param q_out: output quaternion
//		return: q_out
doublev ijkQuatInitZeroQdv(double4 q_out);

// ijkQuatInitElemsQ*v
//	Initialize individual elements of quaternion.
//		param q_out: output quaternion
//		params x, y, z, w: components
//		return: q_out
doublev ijkQuatInitElemsQdv(double4 q_out, f64 const x, f64 const y, f64 const z, f64 const w);

// ijkQuatInitVecReQ*v
//	Initialize quaternion with vector and real parts.
//		param q_out: output quaternion
//		param vec: vector components (xyz)
//		param re: real component (w)
//		return: q_out
doublev ijkQuatInitVecReQdv(double4 q_out, double3 const vec, f64 const re);

// ijkQuatInitVecProductQ*v
//	Initialize quaternion as product of two vectors.
//		param q_out: output quaternion
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: q_out
doublev ijkQuatInitVecProductQdv(double4 q_out, double3 const v_lh, double3 const v_rh);

// ijkQuatInitVecProductSqrtQ*v
//	Initialize quaternion as product square root of two vectors.
//		param q_out: output quaternion
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: q_out
doublev ijkQuatInitVecProductSqrtQdv(double4 q_out, double3 const v_lh, double3 const v_rh);

// ijkQuatInitVecProductSqrtUnitQ*v
//	Initialize quaternion as product square root of two unit vectors.
//		param q_out: output quaternion
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: q_out
doublev ijkQuatInitVecProductSqrtUnitQdv(double4 q_out, double3 const v_lh, double3 const v_rh);

// ijkQuatInitMatQ*v3
//	Initialize quaternion from 3D matrix.
//		param q_out: output quaternion
//		param m_in: input matrix
//		return: q_out
doublev ijkQuatInitMatQdv3(double4 q_out, double3x3 const m_in);

// ijkQuatInitMatQ*v4
//	Initialize quaternion from 4D matrix.
//		param q_out: output quaternion
//		param m_in: input matrix
//		return: q_out
doublev ijkQuatInitMatQdv4(double4 q_out, double4x4 const m_in);

// ijkQuatCopyQ*v
//	Copy quaternion.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatCopyQdv(double4 q_out, double4 const q_in);

// ijkQuatNegateQ*v
//	Negate quaternion.
//		param q_out: output quaternion, negative
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatNegateQdv(double4 q_out, double4 const q_in);

// ijkQuatConjugateQ*v
//	Conjugate quaternion: negate vector part, copy real part.
//		param q_out: output quaternion, conjugate
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatConjugateQdv(double4 q_out, double4 const q_in);

// ijkQuatConjugateMulQ*vs
//	Conjugate quaternion: negate vector part, copy real part, multiply by 
//	scalar.
//		param q_out: output quaternion, conjugate
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatConjugateMulQdvs(double4 q_out, double4 const q_in, f64 const s);

// ijkQuatNegateConjugateQ*v
//	Negate and conjugate quaternion: negate real part, copy vector part.
//		param q_out: output quaternion, negative conjugate
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatNegateConjugateQdv(double4 q_out, double4 const q_in);

// ijkQuatNegateConjugateMulQ*vs
//	Negate and conjugate quaternion: negate real part, copy vector part, 
//	multiply by scalar.
//		param q_out: output quaternion, negative conjugate
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatNegateConjugateMulQdvs(double4 q_out, double4 const q_in, f64 const s);

// ijkQuatAddQ*v
//	Calculate sum of quaternions.
//		param q_out: output quaternion, sum
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
doublev ijkQuatAddQdv(double4 q_out, double4 const q_lh, double4 const q_rh);

// ijkQuatSubQ*v
//	Calculate difference of quaternions.
//		param q_out: output quaternion, difference
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
doublev ijkQuatSubQdv(double4 q_out, double4 const q_lh, double4 const q_rh);

// ijkQuatMulQ*vs
//	Calculate product of quaternion and scalar.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: q_out
doublev ijkQuatMulQdvs(double4 q_out, double4 const q_lh, f64 const s_rh);

// ijkQuatDivQ*vs
//	Calculate quotient of quaternion and scalar.
//		param q_out: output quaternion, quotient
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: q_out
doublev ijkQuatDivQdvs(double4 q_out, double4 const q_lh, f64 const s_rh);

// ijkQuatDivSafeQ*vs
//	Calculate quotient of quaternion and scalar; division-by-zero safety.
//		param q_out: output quaternion, quotient
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: q_out
doublev ijkQuatDivSafeQdvs(double4 q_out, double4 const q_lh, f64 const s_rh);

// ijkQuatLengthSqQ*v
//	Calculate squared length of quaternion.
//		param q_in: input quaternion
//		return: squared length
f64 ijkQuatLengthSqQdv(double4 const q_in);

// ijkQuatLengthQ*v
//	Calculate length of quaternion.
//		param q_in: input quaternion
//		return: length
f64 ijkQuatLengthQdv(double4 const q_in);

// ijkQuatLengthSqInvQ*v
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
f64 ijkQuatLengthSqInvQdv(double4 const q_in);

// ijkQuatLengthInvQ*v
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
f64 ijkQuatLengthInvQdv(double4 const q_in);

// ijkQuatLengthSqInvSafeQ*v
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
f64 ijkQuatLengthSqInvSafeQdv(double4 const q_in);

// ijkQuatLengthInvSafeQ*v
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
f64 ijkQuatLengthInvSafeQdv(double4 const q_in);

// ijkQuatNormalizeQ*v
//	Normalize quaternion.
//		param q_out: output quaternion, unit-length
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatNormalizeQdv(double4 q_out, double4 const q_in);

// ijkQuatNormalizeSafeQ*v
//	Normalize quaternion; division-by-zero safety.
//		param q_out: output quaternion, unit-length
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatNormalizeSafeQdv(double4 q_out, double4 const q_in);

// ijkQuatInverseQ*v
//	Calculate inverse of quaternion: conjugate divided by squared length.
//		param q_out: output quaternion, inverse
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatInverseQdv(double4 q_out, double4 const q_in);

// ijkQuatInverseSafeQ*v
//	Calculate inverse of quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param q_out: output quaternion, inverse
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatInverseSafeQdv(double4 q_out, double4 const q_in);

// ijkQuatMulVecQ*v3
//	Calculate product of quaternion and 3D vector (result is quaternion).
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param v_rh: right-hand vector
//		return: q_out
doublev ijkQuatMulVecQdv3(double4 q_out, double4 const q_lh, double3 const v_rh);

// ijkQuatMulVecQ*v3q
//	Calculate product of 3D vector and quaternion (result is quaternion).
//		param q_out: output quaternion, product
//		param v_lh: left-hand vector
//		param q_rh: right-hand quaternion
//		return: q_out
doublev ijkQuatMulVecQdv3q(double4 q_out, double3 const v_lh, double4 const q_rh);

// ijkQuatMulQ*v
//	Calculate product of quaternions.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
doublev ijkQuatMulQdv(double4 q_out, double4 const q_lh, double4 const q_rh);

// ijkQuatMulConjQ*v
//	Calculate product of quaternion with quaternion conjugate.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion, conjugated before multiplying
//		return: q_out
doublev ijkQuatMulConjQdv(double4 q_out, double4 const q_lh, double4 const q_rh);

// ijkQuatConjMulQ*v
//	Calculate product of quaternion conjugate with quaternion.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion, conjugated before multiplying
//		param q_rh: right-hand quaternion
//		return: q_out
doublev ijkQuatConjMulQdv(double4 q_out, double4 const q_lh, double4 const q_rh);

// ijkQuatDivQ*v
//	Calculate quotient of quaternions (multiply by rh inverse).
//		param q_out: output quaternion, quotient
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
doublev ijkQuatDivQdv(double4 q_out, double4 const q_lh, double4 const q_rh);

// ijkQuatRotateXYZQ*v
//	Make rotation quaternion with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
doublev ijkQuatRotateXYZQdv(double4 q_out, double3 const rotateDegXYZ);

// ijkQuatRotateYZXQ*v
//	Make rotation quaternion with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
doublev ijkQuatRotateYZXQdv(double4 q_out, double3 const rotateDegXYZ);

// ijkQuatRotateZXYQ*v
//	Make rotation quaternion with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
doublev ijkQuatRotateZXYQdv(double4 q_out, double3 const rotateDegXYZ);

// ijkQuatRotateYXZQ*v
//	Make rotation quaternion with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
doublev ijkQuatRotateYXZQdv(double4 q_out, double3 const rotateDegXYZ);

// ijkQuatRotateXZYQ*v
//	Make rotation quaternion with Euler angles in written order XZY, meaning 
//	the order of operations is X then Z then Y.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
doublev ijkQuatRotateXZYQdv(double4 q_out, double3 const rotateDegXYZ);

// ijkQuatRotateZYXQ*v
//	Make rotation quaternion with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
doublev ijkQuatRotateZYXQdv(double4 q_out, double3 const rotateDegXYZ);

// ijkQuatGetRotateXYZQ*v
//	Extract Euler angles from rotation quaternion; written order XYZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
doublekv ijkQuatGetRotateXYZQdv(double4 const q_in, double3 rotateDegXYZ_out);

// ijkQuatGetRotateYZXQ*v
//	Extract Euler angles from rotation quaternion; written order YZX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
doublekv ijkQuatGetRotateYZXQdv(double4 const q_in, double3 rotateDegXYZ_out);

// ijkQuatGetRotateZXYQ*v
//	Extract Euler angles from rotation quaternion; written order ZXY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
doublekv ijkQuatGetRotateZXYQdv(double4 const q_in, double3 rotateDegXYZ_out);

// ijkQuatGetRotateYXZQ*v
//	Extract Euler angles from rotation quaternion; written order YXZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
doublekv ijkQuatGetRotateYXZQdv(double4 const q_in, double3 rotateDegXYZ_out);

// ijkQuatGetRotateXZYQ*v
//	Extract Euler angles from rotation quaternion; written order XZY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
doublekv ijkQuatGetRotateXZYQdv(double4 const q_in, double3 rotateDegXYZ_out);

// ijkQuatGetRotateZYXQ*v
//	Extract Euler angles from rotation quaternion; written order ZYX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
doublekv ijkQuatGetRotateZYXQdv(double4 const q_in, double3 rotateDegXYZ_out);

// ijkQuatRotateQ*v
//	Make rotation quaternion with Euler angles.
//		param q_out: output quaternion, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
doublev ijkQuatRotateQdv(double4 q_out, ijkRotationOrder const order, double3 const rotateDegXYZ);

// ijkQuatAxisAngleQ*v
//	Make rotation quaternion with unit axis and angle in degrees.
//		param q_out: output quaternion, rotation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: q_out
doublev ijkQuatAxisAngleQdv(double4 q_out, double3 const axis_unit, f64 const angle_degrees);

// ijkQuatScaleQ*v
//	Make rotation quaternion with uniform scale.
//		param q_out: output quaternion, scale
//		param scale_unif: uniform scale amount
//		return: q_out
doublev ijkQuatScaleQdv(double4 q_out, f64 const scale_unif);

// ijkQuatRotateScaleQ*v
//	Make rotation quaternion with Euler angles and uniform scale.
//		param q_out: output quaternion, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: q_out
doublev ijkQuatRotateScaleQdv(double4 q_out, ijkRotationOrder const order, double3 const rotateDegXYZ, f64 const scale_unif);

// ijkQuatAxisAngleScaleQ*v
//	Make rotation quaternion with unit axis, angle in degrees and uniform scale.
//		param q_out: output quaternion, rotation-scale
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: q_out
doublev ijkQuatAxisAngleScaleQdv(double4 q_out, double3 const axis_unit, f64 const angle_degrees, f64 const scale_unif);

// ijkQuatGetRotateQ*v
//	Extract Euler angles from rotation quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
doublekv ijkQuatGetRotateQdv(double4 const q_in, ijkRotationOrder const order, double3 rotateDegXYZ_out);

// ijkQuatGetAxisAngleQ*v
//	Extract unit axis and angle in degrees from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: q_in
doublekv ijkQuatGetAxisAngleQdv(double4 const q_in, double3 axis_unit_out, f64* const angle_degrees_out);

// ijkQuatGetScaleQ*v
//	Extract uniform scale from quaternion.
//		param q_in: input quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
doublekv ijkQuatGetScaleQdv(double4 const q_in, f64* const scale_unif_out);

// ijkQuatGetRotateScaleQ*v
//	Extract Euler angles and uniform scale from quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
doublekv ijkQuatGetRotateScaleQdv(double4 const q_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, f64* const scale_unif_out);

// ijkQuatGetAxisAngleScaleQ*v
//	Extract unit axis, angle in degrees and uniform scale from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
doublekv ijkQuatGetAxisAngleScaleQdv(double4 const q_in, double3 axis_unit_out, f64* const angle_degrees_out, f64* const scale_unif_out);

// ijkQuatGetMatQ*v3
//	Convert quaternion to 3D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
double3m ijkQuatGetMatQdv3(double3x3 m_out, double4 const q_in);

// ijkQuatUnitGetMatQ*v3
//	Convert unit quaternion to 3D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
double3m ijkQuatUnitGetMatQdv3(double3x3 m_out, double4 const q_in);

// ijkQuatGetMatQ*v4
//	Convert quaternion to 4D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
double4m ijkQuatGetMatQdv4(double4x4 m_out, double4 const q_in);

// ijkQuatUnitGetMatQ*v4
//	Convert unit quaternion to 4D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
double4m ijkQuatUnitGetMatQdv4(double4x4 m_out, double4 const q_in);

// ijkQuatGetMatQ*v4t
//	Convert quaternion to 4D matrix, with additional translation vector.
//		param m_out: output matrix
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: m_out
double4m ijkQuatGetMatQdv4t(double4x4 m_out, double4 const q_in, double3 const translate);

// ijkQuatUnitGetMatQ*v4t
//	Convert unit quaternion to 4D matrix, with additional translation vector.
//		param m_out: output matrix
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: m_out
double4m ijkQuatUnitGetMatQdv4t(double4x4 m_out, double4 const q_in, double3 const translate);

// ijkQuatRotateScaleVecQ*v3
//	Rotate and/or scale a 3D vector using a quaternion; result will not be 
//	divided by squared magnitude.
//		param v_out: output vector
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
doublev ijkQuatRotateScaleVecQdv3(double3 v_out, double4 const q_in, double3 const v_in);

// ijkQuatUnitRotateVecQ*v3
//	Rotate a 3D vector using a quaternion; use with unit quaternion for most 
//	optimized solution.
//		param v_out: output vector
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
doublev ijkQuatUnitRotateVecQdv3(double3 v_out, double4 const q_in, double3 const v_in);

// ijkQuatRotateVecQ*v3
//	Rotate a 3D vector using a quaternion; use this when the input quaternion 
//	is non-unit length so that the result will only be rotated.
//		param v_out: output vector
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
doublev ijkQuatRotateVecQdv3(double3 v_out, double4 const q_in, double3 const v_in);

// ijkQuatReflectScaleQ*v
//	Reflect and/or scale a quaternion about an axis.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
doublev ijkQuatReflectScaleQdv(double4 q_out, double4 const q_in, double3 const v_in);

// ijkQuatUnitReflectQ*v
//	Reflect a unit quaternion about an axis; optimized for unit quaternions.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
doublev ijkQuatUnitReflectQdv(double4 q_out, double4 const q_in, double3 const v_in);

// ijkQuatReflectQ*v
//	Reflect a non-unit quaternion about an axis.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
doublev ijkQuatReflectQdv(double4 q_out, double4 const q_in, double3 const v_in);

// ijkQuatExpQ*v
//	Calculate quaternion as natural exponent base (e) raised to vector power.
//		param q_out: output quaternion
//		param v_in: input vector
//		return: q_out
doublev ijkQuatExpQdv(double4 q_out, double3 const v_in);

// ijkQuatLnQ*v
//	Calculate quaternion or vector as natural logarithm of quaternion.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatLnQdv(double4 q_out, double4 const q_in);

// ijkQuatPowQ*v
//	Calculate quaternion raised to power of exponent.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param u: exponent
//		return: q_out
doublev ijkQuatPowQdv(double4 q_out, double4 const q_in, f64 const u);

// ijkQuatSqrtQ*v
//	Calculate square root of quaternion.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		return: q_out
doublev ijkQuatSqrtQdv(double4 q_out, double4 const q_in);

// ijkQuatLerpQ*v
//	Calculate linear interpolation between two quaternions; yields a uniform 
//	rate of change but affects encoded scale.
//		param q_out: output quaternion, interpolated quaternion
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: q_out
doublev ijkQuatLerpQdv(double4 q_out, double4 const q0, double4 const q1, f64 const u);

// ijkQuatNlerpQ*v
//	Calculate normalized linear interpolation between two quaternions; keeps 
//	result at unit-length but yields a non-uniform rate of change.
//		param q_out: output quaternion, interpolated quaternion
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: q_out
doublev ijkQuatNlerpQdv(double4 q_out, double4 const q0, double4 const q1, f64 const u);

// ijkQuatSlerpQ*v
//	Calculate spherical linear interpolation between two unit quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param q_out: output quaternion, interpolated quaternion
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: q_out
doublev ijkQuatSlerpQdv(double4 q_out, double4 const q0, double4 const q1, f64 const u);

// ijkQuatDerivQ*v
//	Calculate derivative of quaternion.
//		param q1_out: output quaternion, derivative of quaternion
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		return: q1_out
doublev ijkQuatDerivQdv(double4 q1_out, double4 const q_in, double3 const angularVelocity);

// ijkQuatDeriv2Q*v
//	Calculate second derivative of quaternion.
//		param q2_out: output quaternion, second derivative of quaternion
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: q2_out
doublev ijkQuatDeriv2Qdv(double4 q2_out, double4 const q_in, double3 const angularVelocity, double3 const angularAcceleration);

// ijkQuatEncodeTranslateQ*v
//	Encode translation offset vector using quaternion.
//		param qt_out: output quaternion, encoded translation
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: qt_out
doublev ijkQuatEncodeTranslateQdv(double4 qt_out, double3 const translate_in, double4 const q_encode);

// ijkQuatEncodeTranslateX2Q*v
//	Encode double translation offset vector using quaternion.
//		param qt_out: output quaternion, encoded translation
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: qt_out
doublev ijkQuatEncodeTranslateX2Qdv(double4 qt_out, double3 const translate_in, double4 const q_encode);

// ijkQuatDecodeTranslateQ*v
//	Decode translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
doublev ijkQuatDecodeTranslateQdv(double3 translate_out, double4 const qt_in, double4 const q_decode);

// ijkQuatDecodeTranslateD2Q*vs
//	Decode half translation offset vector from quaternion with scalar 
//	multiplier; use if encoding quaternion is unit or if decoded translation 
//	should have additional user-defined scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
doublev ijkQuatDecodeTranslateD2Qdvs(double3 translate_out, double4 const qt_in, double4 const q_decode, f64 const s);

// ijkQuatDecodeTranslateD2Q*v
//	Decode half translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
doublev ijkQuatDecodeTranslateD2Qdv(double3 translate_out, double4 const qt_in, double4 const q_decode);

// ijkQuatDecodeTranslateRemScaleQ*v
//	Decode translation offset vector from quaternion, removing scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
doublev ijkQuatDecodeTranslateRemScaleQdv(double3 translate_out, double4 const qt_in, double4 const q_decode);

// ijkQuatDecodeTranslateRemScaleD2Q*v
//	Decode half translation offset vector from quaternion, removing scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
doublev ijkQuatDecodeTranslateRemScaleD2Qdv(double3 translate_out, double4 const qt_in, double4 const q_decode);


//-----------------------------------------------------------------------------

// ijkDualQuatInitDQ*m
//	Initialize identity dual quaternion (zero dual, identity real).
//		param dq_out: output dual quaternion
//		return: dq_out
double4m ijkDualQuatInitDQdm(double2x4 dq_out);

// ijkDualQuatInitDualReDQ*m
//	Initialize dual quaternion with dual and real parts.
//		param dq_out: output dual quaternion
//		param re: real component (qr)
//		param dual: dual component (E qd)
//		return: dq_out
double4m ijkDualQuatInitDualReDQdm(double2x4 dq_out, double4 const re, double4 const dual);

// ijkDualQuatInitMatDQ*m3
//	Initialize dual quaternion from 3D matrix.
//		param dq_out: output dual quaternion
//		param m_in: input matrix
//		return: dq_out
double4m ijkDualQuatInitMatDQdm3(double2x4 dq_out, double3x3 const m_in);

// ijkDualQuatInitMatDQ*m4
//	Initialize dual quaternion from 4D matrix.
//		param dq_out: output dual quaternion
//		param m_in: input matrix
//		return: dq_out
double4m ijkDualQuatInitMatDQdm4(double2x4 dq_out, double4x4 const m_in);

// ijkDualQuatCopyDQ*m
//	Copy dual quaternion.
//		param dq_out: output dual quaternion
//		param dq_in: input dual quaternion
//		return: dq_out
double4m ijkDualQuatCopyDQdm(double2x4 dq_out, double2x4 const dq_in);

// ijkDualQuatNegateDQ*m
//	Negate dual quaternion.
//		param dq_out: output dual quaternion, negative
//		param dq_in: input dual quaternion
//		return: dq_out
double4m ijkDualQuatNegateDQdm(double2x4 dq_out, double2x4 const dq_in);

// ijkDualQuatConjugateDQ*m
//	Conjugate dual quaternion: take conjugate of both components.
//		param dq_out: output dual quaternion, conjugate
//		param dq_in: input dual quaternion
//		return: dq_out
double4m ijkDualQuatConjugateDQdm(double2x4 dq_out, double2x4 const dq_in);

// ijkDualQuatNegateDualDQ*m
//	Negate dual part: conjugate of dual number.
//		param dq_out: output dual quaternion, dual conjugate
//		param dq_in: input dual quaternion
//		return: dq_out
double4m ijkDualQuatNegateDualDQdm(double2x4 dq_out, double2x4 const dq_in);

// ijkDualQuatConjugateDualDQ*m
//	Conjugate and negate dual part: conjugate of dual number and components.
//		param dq_out: output dual quaternion, complete dual conjugate
//		param dq_in: input dual quaternion
//		return: dq_out
double4m ijkDualQuatConjugateDualDQdm(double2x4 dq_out, double2x4 const dq_in);

// ijkDualQuatAddDQ*m
//	Calculate sum of dual quaternions.
//		param dq_out: output dual quaternion, sum
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
double4m ijkDualQuatAddDQdm(double2x4 dq_out, double2x4 const dq_lh, double2x4 const dq_rh);

// ijkDualQuatSubDQ*m
//	Calculate difference of dual quaternions.
//		param dq_out: output dual quaternion, difference
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
double4m ijkDualQuatSubDQdm(double2x4 dq_out, double2x4 const dq_lh, double2x4 const dq_rh);

// ijkDualQuatMulDQ*ms
//	Calculate product of dual quaternion and scalar.
//		param dq_out: output dual quaternion, product
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: dq_out
double4m ijkDualQuatMulDQdms(double2x4 dq_out, double2x4 const dq_lh, f64 const s_rh);

// ijkDualQuatDivDQ*ms
//	Calculate quotient of dual quaternion and scalar.
//		param dq_out: output dual quaternion, quotient
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: dq_out
double4m ijkDualQuatDivDQdms(double2x4 dq_out, double2x4 const dq_lh, f64 const s_rh);

// ijkDualQuatDivSafeDQ*ms
//	Calculate quotient of dual quaternion and scalar; division-by-zero safety.
//		param dq_out: output dual quaternion, quotient
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: dq_out
double4m ijkDualQuatDivSafeDQdms(double2x4 dq_out, double2x4 const dq_lh, f64 const s_rh);

// ijkDualQuatLengthSqDQ*m
//	Calculate squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: squared length
f64 ijkDualQuatLengthSqDQdm(double2x4 const dq_in);

// ijkDualQuatLengthDQ*m
//	Calculate length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: length
f64 ijkDualQuatLengthDQdm(double2x4 const dq_in);

// ijkDualQuatLengthSqInvDQ*m
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
f64 ijkDualQuatLengthSqInvDQdm(double2x4 const dq_in);

// ijkDualQuatLengthInvDQ*m
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
f64 ijkDualQuatLengthInvDQdm(double2x4 const dq_in);

// ijkDualQuatLengthSqInvSafeDQ*m
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
f64 ijkDualQuatLengthSqInvSafeDQdm(double2x4 const dq_in);

// ijkDualQuatLengthInvSafeDQ*m
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
f64 ijkDualQuatLengthInvSafeDQdm(double2x4 const dq_in);

// ijkDualQuatNormalizeDQ*m
//	Normalize dual quaternion.
//		param dq_out: output dual quaternion, unit-length
//		param dq_in: input dual quaternion
//		return: dq_out
double4m ijkDualQuatNormalizeDQdm(double2x4 dq_out, double2x4 const dq_in);

// ijkDualQuatNormalizeSafeDQ*m
//	Normalize dual quaternion; division-by-zero safety.
//		param dq_out: output dual quaternion, unit-length
//		param dq_in: input dual quaternion
//		return: dq_out
double4m ijkDualQuatNormalizeSafeDQdm(double2x4 dq_out, double2x4 const dq_in);

// ijkDualQuatInverseDQ*m
//	Calculate inverse of dual quaternion: conjugate divided by squared length.
//		param dq_out: output dual quaternion, inverse
//		param dq_in: input dual quaternion
//		return: dq_out
double4m ijkDualQuatInverseDQdm(double2x4 dq_out, double2x4 const dq_in);

// ijkDualQuatInverseSafeDQ*m
//	Calculate inverse of dual quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param dq_out: output dual quaternion, inverse
//		param dq_in: input dual quaternion
//		return: dq_out
double4m ijkDualQuatInverseSafeDQdm(double2x4 dq_out, double2x4 const dq_in);

// ijkDualQuatMulVecDQ*m3
//	Calculate product of dual quaternion and 3D vector (result is dual quaternion).
//		param dq_out: output dual quaternion, product
//		param dq_lh: left-hand dual quaternion
//		param v_rh: right-hand vector
//		return: dq_out
double4m ijkDualQuatMulVecDQdm3(double2x4 dq_out, double2x4 const dq_lh, double3 const v_rh);

// ijkDualQuatMulVecDQ*m3q
//	Calculate product of 3D vector and dual quaternion (result is dual quaternion).
//		param dq_out: output dual quaternion, product
//		param v_lh: left-hand vector
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
double4m ijkDualQuatMulVecDQdm3q(double2x4 dq_out, double3 const v_lh, double2x4 const dq_rh);

// ijkDualQuatMulDQ*m
//	Calculate product of dual quaternions, or concatenate unit dual quaternions
//	representing transformations.
//		param dq_out: output dual quaternion, product
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
double4m ijkDualQuatMulDQdm(double2x4 dq_out, double2x4 const dq_lh, double2x4 const dq_rh);

// ijkDualQuatMulScaleDQ*m
//	Correctly concatenate dual quaternions that represent transformations such 
//	that the right-hand input's translation is correctly affected by the left-
//	hand input's scale, when used to transform a vector later.
//		param dq_out: output dual quaternion
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
double4m ijkDualQuatMulScaleDQdm(double2x4 dq_out, double2x4 const dq_lh, double2x4 const dq_rh);

// ijkDualQuatDivDQ*m
//	Calculate quotient of dual quaternions (multiply by rh inverse).
//		param dq_out: output dual quaternion, quotient
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
double4m ijkDualQuatDivDQdm(double2x4 dq_out, double2x4 const dq_lh, double2x4 const dq_rh);

// ijkDualQuatRotateDQ*m
//	Make rotation dual quaternion with Euler angles.
//		param dq_out: output dual quaternion, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: dq_out
double4m ijkDualQuatRotateDQdm(double2x4 dq_out, ijkRotationOrder const order, double3 const rotateDegXYZ);

// ijkDualQuatAxisAngleDQ*m
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param dq_out: output dual quaternion, rotation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: dq_out
double4m ijkDualQuatAxisAngleDQdm(double2x4 dq_out, double3 const axis_unit, f64 const angle_degrees);

// ijkDualQuatScaleDQ*m
//	Make rotation dual quaternion with uniform scale.
//		param dq_out: output dual quaternion, scale
//		param scale_unif: uniform scale amount
//		return: dq_out
double4m ijkDualQuatScaleDQdm(double2x4 dq_out, f64 const scale_unif);

// ijkDualQuatRotateScaleDQ*m
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: dq_out
double4m ijkDualQuatRotateScaleDQdm(double2x4 dq_out, ijkRotationOrder const order, double3 const rotateDegXYZ, f64 const scale_unif);

// ijkDualQuatAxisAngleScaleDQ*m
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: dq_out
double4m ijkDualQuatAxisAngleScaleDQdm(double2x4 dq_out, double3 const axis_unit, f64 const angle_degrees, f64 const scale_unif);

// ijkDualQuatTranslateDQ*m
//	Make rotation dual quaternion with Euler angles.
//		param dq_out: output dual quaternion, translation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param translate: translation offset vector
//		return: dq_out
double4m ijkDualQuatTranslateDQdm(double2x4 dq_out, double3 const translate);

// ijkDualQuatRotateTranslateDQ*m
//	Make rotation dual quaternion with Euler angles.
//		param dq_out: output dual quaternion, rotation-translation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param translate: translation offset vector
//		return: dq_out
double4m ijkDualQuatRotateTranslateDQdm(double2x4 dq_out, ijkRotationOrder const order, double3 const rotateDegXYZ, double3 const translate);

// ijkDualQuatAxisAngleTranslateDQ*m
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param dq_out: output dual quaternion, rotation-translation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: dq_out
double4m ijkDualQuatAxisAngleTranslateDQdm(double2x4 dq_out, double3 const axis_unit, f64 const angle_degrees, double3 const translate);

// ijkDualQuatScaleTranslateDQ*m
//	Make rotation dual quaternion with uniform scale.
//		param dq_out: output dual quaternion, scale-translation
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: dq_out
double4m ijkDualQuatScaleTranslateDQdm(double2x4 dq_out, f64 const scale_unif, double3 const translate);

// ijkDualQuatRotateScaleTranslateDQ*m
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale-translation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: dq_out
double4m ijkDualQuatRotateScaleTranslateDQdm(double2x4 dq_out, ijkRotationOrder const order, double3 const rotateDegXYZ, f64 const scale_unif, double3 const translate);

// ijkDualQuatAxisAngleScaleTranslateDQ*m
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale-translation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: dq_out
double4m ijkDualQuatAxisAngleScaleTranslateDQdm(double2x4 dq_out, double3 const axis_unit, f64 const angle_degrees, f64 const scale_unif, double3 const translate);

// ijkDualQuatGetRotateDQ*m
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: dq_in
double4km ijkDualQuatGetRotateDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out);

// ijkDualQuatGetAxisAngleDQ*m
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: dq_in
double4km ijkDualQuatGetAxisAngleDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out);

// ijkDualQuatGetScaleDQ*m
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
double4km ijkDualQuatGetScaleDQdm(double2x4 const dq_in, f64* const scale_unif_out);

// ijkDualQuatGetRotateScaleDQ*m
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
double4km ijkDualQuatGetRotateScaleDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, f64* const scale_unif_out);

// ijkDualQuatGetAxisAngleScaleDQ*m
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
double4km ijkDualQuatGetAxisAngleScaleDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, f64* const scale_unif_out);

// ijkDualQuatGetTranslateDQ*m
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
double4km ijkDualQuatGetTranslateDQdm(double2x4 const dq_in, double3 translate_out);

// ijkDualQuatGetRotateTranslateDQ*m
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
double4km ijkDualQuatGetRotateTranslateDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 translate_out);

// ijkDualQuatGetAxisAngleTranslateDQ*m
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
double4km ijkDualQuatGetAxisAngleTranslateDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 translate_out);

// ijkDualQuatGetScaleTranslateDQ*m
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
double4km ijkDualQuatGetScaleTranslateDQdm(double2x4 const dq_in, f64* const scale_unif_out, double3 translate_out);

// ijkDualQuatGetRotateScaleTranslateDQ*m
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
double4km ijkDualQuatGetRotateScaleTranslateDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, f64* const scale_unif_out, double3 translate_out);

// ijkDualQuatGetAxisAngleScaleTranslateDQ*m
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
double4km ijkDualQuatGetAxisAngleScaleTranslateDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, f64* const scale_unif_out, double3 translate_out);

// ijkDualQuatGetTranslateRemScaleDQ*m
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
double4km ijkDualQuatGetTranslateRemScaleDQdm(double2x4 const dq_in, double3 translate_out);

// ijkDualQuatGetRotateTranslateRemScaleDQ*m
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
double4km ijkDualQuatGetRotateTranslateRemScaleDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, double3 translate_out);

// ijkDualQuatGetAxisAngleTranslateRemScaleDQ*m
//	Extract unit axis and angle in degrees from dual quaternion, removing 
//	scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
double4km ijkDualQuatGetAxisAngleTranslateRemScaleDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 translate_out);

// ijkDualQuatGetScaleTranslateRemScaleDQ*m
//	Extract uniform scale from dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
double4km ijkDualQuatGetScaleTranslateRemScaleDQdm(double2x4 const dq_in, f64* const scale_unif_out, double3 translate_out);

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
double4km ijkDualQuatGetRotateScaleTranslateRemScaleDQdm(double2x4 const dq_in, ijkRotationOrder const order, double3 rotateDegXYZ_out, f64* const scale_unif_out, double3 translate_out);

// ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQ*m
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion,
//	removing scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
double4km ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, f64* const scale_unif_out, double3 translate_out);

// ijkDualQuatGetScrewParamsDQ*m
//	Extract screw parameters from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		param momentArm_out: storage for moment arm
//		param screwDisplace_out: storage for screw displacement parameter
//		return: dq_in
double4km ijkDualQuatGetScrewParamsDQdm(double2x4 const dq_in, double3 axis_unit_out, f64* const angle_degrees_out, double3 translate_out, double3 momentArm_out, f64* const screwDisplace_out);

// ijkDualQuatGetMatDQ*m3
//	Convert dual quaternion's real part to 3D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
double3m ijkDualQuatGetMatDQdm3(double3x3 m_out, double2x4 const dq_in);

// ijkDualQuatUnitGetMatDQ*m3
//	Convert unit dual quaternion's real part to 3D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
double3m ijkDualQuatUnitGetMatDQdm3(double3x3 m_out, double2x4 const dq_in);

// ijkDualQuatGetMatTranslateDQ*m3
//	Convert dual quaternion's real part to 3D matrix and extract translation.
//		param m_out: output matrix
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: m_out
double3m ijkDualQuatGetMatTranslateDQdm3(double3x3 m_out, double3 translate_out, double2x4 const dq_in);

// ijkDualQuatUnitGetMatTranslateDQ*m3
//	Convert unit dual quaternion's real part to 3D matrix and extract 
//	translation.
//		param m_out: output matrix
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: m_out
double3m ijkDualQuatUnitGetMatTranslateDQdm3(double3x3 m_out, double3 translate_out, double2x4 const dq_in);

// ijkDualQuatGetMatTranslateRemScaleDQ*m3
//	Convert dual quaternion's real part to 3D matrix and extract translation 
//	with scale removed.
//		param m_out: output matrix
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: m_out
double3m ijkDualQuatGetMatTranslateRemScaleDQdm3(double3x3 m_out, double3 translate_out, double2x4 const dq_in);

// ijkDualQuatGetMatDQ*m4
//	Convert dual quaternion to 4D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
double4m ijkDualQuatGetMatDQdm4(double4x4 m_out, double2x4 const dq_in);

// ijkDualQuatUnitGetMatDQ*m4
//	Convert unit dual quaternion to 4D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
double4m ijkDualQuatUnitGetMatDQdm4(double4x4 m_out, double2x4 const dq_in);

// ijkDualQuatGetMatTranslateRemScaleDQ*m4
//	Convert dual quaternion to 4D matrix, scale removed from translation part.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
double4m ijkDualQuatGetMatTranslateRemScaleDQdm4(double4x4 m_out, double2x4 const dq_in);

// ijkDualQuatTransformScaleVecDQ*m3
//	Transform a 3D vector using a dual quaternion with scale; use when dual 
//	quaternion has scale to prevent translation part from being scaled.
//		param v_out: output vector
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: v_out
doublev ijkDualQuatTransformScaleVecDQdm3(double3 v_out, double2x4 const dq_in, double3 const v_in);

// ijkDualQuatUnitTransformVecDQ*m3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	unit-length for most optimized solution or when translation part should 
//	also be scaled.
//		param v_out: output vector
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: v_out
doublev ijkDualQuatUnitTransformVecDQdm3(double3 v_out, double2x4 const dq_in, double3 const v_in);

// ijkDualQuatTransformVecDQ*m3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	non-unit length to remove scale from all parts.
//		param v_out: output vector
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: v_out
doublev ijkDualQuatTransformVecDQdm3(double3 v_out, double2x4 const dq_in, double3 const v_in);

// ijkDualQuatLerpDQ*m
//	Calculate linear interpolation between two dual quaternions; yields uniform
//	rate of change but affects translation path and scale.
//		param dq_out: output dual quaternion, interpolated dual quaternion
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: dq_out
double4m ijkDualQuatLerpDQdm(double2x4 dq_out, double2x4 const dq0, double2x4 const dq1, f64 const u);

// ijkDualQuatNlerpDQ*m
//	Calculate normalized linear interpolation between two dual quaternions; 
//	keeps result at unit-length but yields a non-uniform rate of change.
//		param dq_out: output dual quaternion, interpolated dual quaternion
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: dq_out
double4m ijkDualQuatNlerpDQdm(double2x4 dq_out, double2x4 const dq0, double2x4 const dq1, f64 const u);

// ijkDualQuatSclerpDQ*m
//	Calculate screw linear interpolation between two unit dual quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param dq_out: output dual quaternion, interpolated dual quaternion
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: dq_out
double4m ijkDualQuatSclerpDQdm(double2x4 dq_out, double2x4 const dq0, double2x4 const dq1, f64 const u);

// ijkDualQuatDerivDQ*m
//	Calculate derivative of dual quaternion.
//		param dq1_out: output dual quaternion, derivative of dual quaternion
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param angularVelocity: angular velocity vector
//		return: dq1_out
double4m ijkDualQuatDerivDQdm(double2x4 dq1_out, double2x4 const dq_in, double3 const linearVelocity, double3 const angularVelocity);

// ijkDualQuatDeriv2DQ*m
//	Calculate second derivative of dual quaternion.
//		param dq2_out: output dual quaternion, second derivative of dual quaternion
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param linearAcceleration: linear acceleration vector
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: dq2_out
double4m ijkDualQuatDeriv2DQdm(double2x4 dq2_out, double2x4 const dq_in, double3 const linearVelocity, double3 const linearAcceleration, double3 const angularVelocity, double3 const angularAcceleration);


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkQuatInitQ*
//	Initialize identity quaternion (zero vector, one real).
//		return: identity quaternion
dquat ijkQuatInitQd();

// ijkQuatInitZeroQ*
//	Initialize zero quaternion.
//		return: zero quaternion
dquat ijkQuatInitZeroQd();

// ijkQuatInitElemsQ*
//	Initialize individual elements of quaternion.
//		params x, y, z, w: components
//		return: xyzw quaternion
dquat ijkQuatInitElemsQd(double const x, double const y, double const z, double const w);

// ijkQuatInitVecReQ*
//	Initialize quaternion with vector and real parts.
//		param vec: vector components (xyz)
//		param re: real component (w)
//		return: output quaternion
dquat ijkQuatInitVecReQd(dvec3 const vec, double const re);

// ijkQuatInitVecProductQ*
//	Initialize quaternion as product of two vectors.
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: output quaternion
dquat ijkQuatInitVecProductQd(dvec3 const v_lh, dvec3 const v_rh);

// ijkQuatInitVecProductSqrtQ*
//	Initialize quaternion as product square root of two vectors.
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: output quaternion
dquat ijkQuatInitVecProductSqrtQd(dvec3 const v_lh, dvec3 const v_rh);

// ijkQuatInitVecProductSqrtUnitQ*
//	Initialize quaternion as product square root of two unit vectors.
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: output quaternion
dquat ijkQuatInitVecProductSqrtUnitQd(dvec3 const v_lh, dvec3 const v_rh);

// ijkQuatInitMatQ*3
//	Initialize quaternion from 3D matrix.
//		param m_in: input matrix
//		return: output quaternion
dquat ijkQuatInitMatQd3(dmat3 const m_in);

// ijkQuatInitMatQ*4
//	Initialize quaternion from 4D matrix.
//		param m_in: input matrix
//		return: output quaternion
dquat ijkQuatInitMatQd4(dmat4 const m_in);

// ijkQuatCopyQ*
//	Copy quaternion.
//		param q_in: input quaternion
//		return: copy
dquat ijkQuatCopyQd(dquat const q_in);

// ijkQuatNegateQ*
//	Negate quaternion.
//		param q_in: input quaternion
//		return: negative quaternion
dquat ijkQuatNegateQd(dquat const q_in);

// ijkQuatConjugateQ*
//	Conjugate quaternion: negate vector part, copy real part.
//		param q_in: input quaternion
//		return: conjugate quaternion
dquat ijkQuatConjugateQd(dquat const q_in);

// ijkQuatConjugateMulQ*s
//	Conjugate quaternion: negate vector part, copy real part, multiply by 
//	scalar.
//		param q_in: input quaternion
//		return: scaled conjugate quaternion
dquat ijkQuatConjugateMulQds(dquat const q_in, double const s);

// ijkQuatNegateConjugateQ*
//	Negate and conjugate quaternion: negate real part, copy vector part.
//		param q_in: input quaternion
//		return: negative conjugate quaternion
dquat ijkQuatNegateConjugateQd(dquat const q_in);

// ijkQuatNegateConjugateMulQ*s
//	Negate and conjugate quaternion: negate real part, copy vector part, 
//	multiply by scalar.
//		param q_in: input quaternion
//		return: scaled negative conjugate quaternion
dquat ijkQuatNegateConjugateMulQds(dquat const q_in, double const s);

// ijkQuatAddQ*
//	Calculate sum of quaternions.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: sum quaternion
dquat ijkQuatAddQd(dquat const q_lh, dquat const q_rh);

// ijkQuatSubQ*
//	Calculate difference of quaternions.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: difference quaternion
dquat ijkQuatSubQd(dquat const q_lh, dquat const q_rh);

// ijkQuatMulQ*s
//	Calculate product of quaternion and scalar.
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: product quaternion
dquat ijkQuatMulQds(dquat const q_lh, double const s_rh);

// ijkQuatDivQ*s
//	Calculate quotient of quaternion and scalar.
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: quotient quaternion
dquat ijkQuatDivQds(dquat const q_lh, double const s_rh);

// ijkQuatDivSafeQ*s
//	Calculate quotient of quaternion and scalar; division-by-zero safety.
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: quotient quaternion
dquat ijkQuatDivSafeQds(dquat const q_lh, double const s_rh);

// ijkQuatLengthSqQ*
//	Calculate squared length of quaternion.
//		param q_in: input quaternion
//		return: squared length
double ijkQuatLengthSqQd(dquat const q_in);

// ijkQuatLengthQ*
//	Calculate length of quaternion.
//		param q_in: input quaternion
//		return: length
double ijkQuatLengthQd(dquat const q_in);

// ijkQuatLengthSqInvQ*
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
double ijkQuatLengthSqInvQd(dquat const q_in);

// ijkQuatLengthInvQ*
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
double ijkQuatLengthInvQd(dquat const q_in);

// ijkQuatLengthSqInvSafeQ*
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
double ijkQuatLengthSqInvSafeQd(dquat const q_in);

// ijkQuatLengthInvSafeQ*
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
double ijkQuatLengthInvSafeQd(dquat const q_in);

// ijkQuatNormalizeQ*
//	Normalize quaternion.
//		param q_in: input quaternion
//		return: unit quaternion
dquat ijkQuatNormalizeQd(dquat const q_in);

// ijkQuatNormalizeSafeQ*
//	Normalize quaternion; division-by-zero safety.
//		param q_in: input quaternion
//		return: unit quaternion
dquat ijkQuatNormalizeSafeQd(dquat const q_in);

// ijkQuatInverseQ*
//	Calculate inverse of quaternion: conjugate divided by squared length.
//		param q_in: input quaternion
//		return: inverse quaternion
dquat ijkQuatInverseQd(dquat const q_in);

// ijkQuatInverseSafeQ*
//	Calculate inverse of quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param q_in: input quaternion
//		return: inverse quaternion
dquat ijkQuatInverseSafeQd(dquat const q_in);

// ijkQuatMulVecQ*3
//	Calculate product of quaternion and 3D vector (result is quaternion).
//		param q_lh: left-hand quaternion
//		param v_rh: right-hand vector
//		return: product quaternion
dquat ijkQuatMulVecQd3(dquat const q_lh, dvec3 const v_rh);

// ijkQuatMulVecQ*3q
//	Calculate product of 3D vector and quaternion (result is quaternion).
//		param v_lh: left-hand vector
//		param q_rh: right-hand quaternion
//		return: product quaternion
dquat ijkQuatMulVecQd3q(dvec3 const v_lh, dquat const q_rh);

// ijkQuatMulQ*
//	Calculate product of quaternions.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: product quaternion
dquat ijkQuatMulQd(dquat const q_lh, dquat const q_rh);

// ijkQuatMulConjQ*
//	Calculate product of quaternion with quaternion conjugate.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion, conjugated before multiplying
//		return: product quaternion
dquat ijkQuatMulConjQd(dquat const q_lh, dquat const q_rh);

// ijkQuatConjMulQ*
//	Calculate product of quaternion conjugate with quaternion.
//		param q_lh: left-hand quaternion, conjugated before multiplying
//		param q_rh: right-hand quaternion
//		return: product quaternion
dquat ijkQuatConjMulQd(dquat const q_lh, dquat const q_rh);

// ijkQuatDivQ*
//	Calculate quotient of quaternions (multiply by rh inverse).
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: quotient quaternion
dquat ijkQuatDivQd(dquat const q_lh, dquat const q_rh);

// ijkQuatRotateXYZQ*
//	Make rotation quaternion with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
dquat ijkQuatRotateXYZQd(dvec3 const rotateDegXYZ);

// ijkQuatRotateYZXQ*
//	Make rotation quaternion with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
dquat ijkQuatRotateYZXQd(dvec3 const rotateDegXYZ);

// ijkQuatRotateZXYQ*
//	Make rotation quaternion with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
dquat ijkQuatRotateZXYQd(dvec3 const rotateDegXYZ);

// ijkQuatRotateYXZQ*
//	Make rotation quaternion with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
dquat ijkQuatRotateYXZQd(dvec3 const rotateDegXYZ);

// ijkQuatRotateXZYQ*
//	Make rotation quaternion with Euler angles in written order XZY, meaning 
//	the order of operations is X then Z then Y.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
dquat ijkQuatRotateXZYQd(dvec3 const rotateDegXYZ);

// ijkQuatRotateZYXQ*
//	Make rotation quaternion with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
dquat ijkQuatRotateZYXQd(dvec3 const rotateDegXYZ);

// ijkQuatGetRotateXYZQ*
//	Extract Euler angles from rotation quaternion; written order XYZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
dquat ijkQuatGetRotateXYZQd(dquat const q_in, dvec3* const rotateDegXYZ_out);

// ijkQuatGetRotateYZXQ*
//	Extract Euler angles from rotation quaternion; written order YZX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
dquat ijkQuatGetRotateYZXQd(dquat const q_in, dvec3* const rotateDegXYZ_out);

// ijkQuatGetRotateZXYQ*
//	Extract Euler angles from rotation quaternion; written order ZXY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
dquat ijkQuatGetRotateZXYQd(dquat const q_in, dvec3* const rotateDegXYZ_out);

// ijkQuatGetRotateYXZQ*
//	Extract Euler angles from rotation quaternion; written order YXZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
dquat ijkQuatGetRotateYXZQd(dquat const q_in, dvec3* const rotateDegXYZ_out);

// ijkQuatGetRotateXZYQ*
//	Extract Euler angles from rotation quaternion; written order XZY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
dquat ijkQuatGetRotateXZYQd(dquat const q_in, dvec3* const rotateDegXYZ_out);

// ijkQuatGetRotateZYXQ*
//	Extract Euler angles from rotation quaternion; written order ZYX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
dquat ijkQuatGetRotateZYXQd(dquat const q_in, dvec3* const rotateDegXYZ_out);

// ijkQuatRotateQ*
//	Make rotation quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
dquat ijkQuatRotateQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ);

// ijkQuatAxisAngleQ*
//	Make rotation quaternion with unit axis and angle in degrees.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation quaternion
dquat ijkQuatAxisAngleQd(dvec3 const axis_unit, double const angle_degrees);

// ijkQuatScaleQ*
//	Make rotation quaternion with uniform scale.
//		param scale_unif: uniform scale amount
//		return: scale quaternion
dquat ijkQuatScaleQd(double const scale_unif);

// ijkQuatRotateScaleQ*
//	Make rotation quaternion with Euler angles and uniform scale.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: rotation-scale quaternion
dquat ijkQuatRotateScaleQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ, double const scale_unif);

// ijkQuatAxisAngleScaleQ*
//	Make rotation quaternion with unit axis, angle in degrees and uniform scale.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: rotation-scale quaternion
dquat ijkQuatAxisAngleScaleQd(dvec3 const axis_unit, double const angle_degrees, double const scale_unif);

// ijkQuatGetRotateQ*
//	Extract Euler angles from rotation quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
dquat ijkQuatGetRotateQd(dquat const q_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out);

// ijkQuatGetAxisAngleQ*
//	Extract unit axis and angle in degrees from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: q_in
dquat ijkQuatGetAxisAngleQd(dquat const q_in, dvec3* const axis_unit_out, double* const angle_degrees_out);

// ijkQuatGetScaleQ*
//	Extract uniform scale from quaternion.
//		param q_in: input quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
dquat ijkQuatGetScaleQd(dquat const q_in, double* const scale_unif_out);

// ijkQuatGetRotateScaleQ*
//	Extract Euler angles and uniform scale from quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
dquat ijkQuatGetRotateScaleQd(dquat const q_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, double* const scale_unif_out);

// ijkQuatGetAxisAngleScaleQ*
//	Extract unit axis, angle in degrees and uniform scale from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
dquat ijkQuatGetAxisAngleScaleQd(dquat const q_in, dvec3* const axis_unit_out, double* const angle_degrees_out, double* const scale_unif_out);

// ijkQuatGetMatQ*3
//	Convert quaternion to 3D matrix.
//		param q_in: input quaternion
//		return: output matrix
dmat3 ijkQuatGetMatQd3(dquat const q_in);

// ijkQuatUnitGetMatQ*3
//	Convert unit quaternion to 3D matrix.
//		param q_in: input quaternion
//		return: output matrix
dmat3 ijkQuatUnitGetMatQd3(dquat const q_in);

// ijkQuatGetMatQ*4
//	Convert quaternion to 4D matrix.
//		param q_in: input quaternion
//		return: output matrix
dmat4 ijkQuatGetMatQd4(dquat const q_in);

// ijkQuatUnitGetMatQ*4
//	Convert unit quaternion to 4D matrix.
//		param q_in: input quaternion
//		return: output matrix
dmat4 ijkQuatUnitGetMatQd4(dquat const q_in);

// ijkQuatGetMatQ*4t
//	Convert quaternion to 4D matrix, with additional translation vector.
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: output matrix
dmat4 ijkQuatGetMatQd4t(dquat const q_in, dvec3 const translate);

// ijkQuatUnitGetMatQ*4t
//	Convert unit quaternion to 4D matrix, with additional translation vector.
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: output matrix
dmat4 ijkQuatUnitGetMatQd4t(dquat const q_in, dvec3 const translate);

// ijkQuatRotateScaleVecQ*3
//	Rotate and/or scale a 3D vector using a quaternion; result will not be 
//	divided by squared magnitude.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: rotated vector
dvec3 ijkQuatRotateScaleVecQd3(dquat const q_in, dvec3 const v_in);

// ijkQuatUnitRotateVecQ*3
//	Rotate a 3D vector using a quaternion; use with unit quaternion for most 
//	optimized solution.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: rotated vector
dvec3 ijkQuatUnitRotateVecQd3(dquat const q_in, dvec3 const v_in);

// ijkQuatRotateVecQ*3
//	Rotate a 3D vector using a quaternion; use this when the input quaternion 
//	is non-unit length so that the result will only be rotated.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: rotated vector
dvec3 ijkQuatRotateVecQd3(dquat const q_in, dvec3 const v_in);

// ijkQuatReflectScaleQ*
//	Reflect and/or scale a quaternion about an axis.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: reflected quaternion
dquat ijkQuatReflectScaleQd(dquat const q_in, dvec3 const v_in);

// ijkQuatUnitReflectQ*
//	Reflect a unit quaternion about an axis; optimized for unit quaternions.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: reflected quaternion
dquat ijkQuatUnitReflectQd(dquat const q_in, dvec3 const v_in);

// ijkQuatReflectQ*
//	Reflect a non-unit quaternion about an axis.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: reflected quaternion
dquat ijkQuatReflectQd(dquat const q_in, dvec3 const v_in);

// ijkQuatExpQ*
//	Calculate quaternion as natural exponent base (e) raised to vector power.
//		param v_in: input vector
//		return: exp
dquat ijkQuatExpQd(dvec3 const v_in);

// ijkQuatLnQ*
//	Calculate quaternion or vector as natural logarithm of quaternion.
//		param q_in: input quaternion
//		return: ln
dquat ijkQuatLnQd(dquat const q_in);

// ijkQuatPowQ*
//	Calculate quaternion raised to power of exponent.
//		param q_in: input quaternion
//		param u: exponent
//		return: pow
dquat ijkQuatPowQd(dquat const q_in, double const u);

// ijkQuatSqrtQ*
//	Calculate square root of quaternion.
//		param q_in: input quaternion
//		return: sqrt
dquat ijkQuatSqrtQd(dquat const q_in);

// ijkQuatLerpQ*
//	Calculate linear interpolation between two quaternions; yields a uniform 
//	rate of change but affects encoded scale.
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: interpolated quaternion
dquat ijkQuatLerpQd(dquat const q0, dquat const q1, double const u);

// ijkQuatNlerpQ*
//	Calculate normalized linear interpolation between two quaternions; keeps 
//	result at unit-length but yields a non-uniform rate of change.
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: interpolated quaternion
dquat ijkQuatNlerpQd(dquat const q0, dquat const q1, double const u);

// ijkQuatSlerpQ*
//	Calculate spherical linear interpolation between two unit quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: interpolated quaternion
dquat ijkQuatSlerpQd(dquat const q0, dquat const q1, double const u);

// ijkQuatDerivQ*
//	Calculate derivative of quaternion.
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		return: derivative of quaternion
dquat ijkQuatDerivQd(dquat const q_in, dvec3 const angularVelocity);

// ijkQuatDeriv2Q*
//	Calculate second derivative of quaternion.
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: second derivative of quaternion
dquat ijkQuatDeriv2Qd(dquat const q_in, dvec3 const angularVelocity, dvec3 const angularAcceleration);

// ijkQuatEncodeTranslateQ*
//	Encode translation offset vector using quaternion.
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: encoded translation
dquat ijkQuatEncodeTranslateQd(dvec3 const translate_in, dquat const q_encode);

// ijkQuatEncodeTranslateX2Q*
//	Encode double translation offset vector using quaternion.
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: encoded translation
dquat ijkQuatEncodeTranslateX2Qd(dvec3 const translate_in, dquat const q_encode);

// ijkQuatDecodeTranslateQ*
//	Decode translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
dvec3 ijkQuatDecodeTranslateQd(dquat const qt_in, dquat const q_decode);

// ijkQuatDecodeTranslateD2Q*s
//	Decode half translation offset vector from quaternion with scalar 
//	multiplier; use if encoding quaternion is unit or if decoded translation 
//	should have additional user-defined scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
dvec3 ijkQuatDecodeTranslateD2Qds(dquat const qt_in, dquat const q_decode, double const s);

// ijkQuatDecodeTranslateD2Q*
//	Decode half translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
dvec3 ijkQuatDecodeTranslateD2Qd(dquat const qt_in, dquat const q_decode);

// ijkQuatDecodeTranslateRemScaleQ*
//	Decode translation offset vector from quaternion, removing scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
dvec3 ijkQuatDecodeTranslateRemScaleQd(dquat const qt_in, dquat const q_decode);

// ijkQuatDecodeTranslateRemScaleD2Q*
//	Decode half translation offset vector from quaternion, removing scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
dvec3 ijkQuatDecodeTranslateRemScaleD2Qd(dquat const qt_in, dquat const q_decode);


//-----------------------------------------------------------------------------

// ijkDualQuatInitDQ*
//	Initialize identity dual quaternion (zero dual, identity real).
//		return: identity dual quaternion
ddualquat ijkDualQuatInitDQd();

// ijkDualQuatInitDualReDQ*
//	Initialize dual quaternion with dual and real parts.
//		param re: real component (qr)
//		param dual: dual component (E qd)
//		return: r+Ed dual quaternion
ddualquat ijkDualQuatInitDualReDQd(dquat const re, dquat const dual);

// ijkDualQuatInitMatDQ*3
//	Initialize dual quaternion from 3D matrix.
//		param m_in: input matrix
//		return: output dual quaternion
ddualquat ijkDualQuatInitMatDQd3(dmat3 const m_in);

// ijkDualQuatInitMatDQ*4
//	Initialize dual quaternion from 4D matrix.
//		param m_in: input matrix
//		return: output dual quaternion
ddualquat ijkDualQuatInitMatDQd4(dmat4 const m_in);

// ijkDualQuatCopyDQ*
//	Copy dual quaternion.
//		param dq_in: input dual quaternion
//		return: copy
ddualquat ijkDualQuatCopyDQd(ddualquat const dq_in);

// ijkDualQuatNegateDQ*
//	Negate dual quaternion.
//		param dq_in: input dual quaternion
//		return: negative dual quaternion
ddualquat ijkDualQuatNegateDQd(ddualquat const dq_in);

// ijkDualQuatConjugateDQ*
//	Conjugate dual quaternion: take conjugate of both components.
//		param dq_in: input dual quaternion
//		return: conjugate dual quaternion
ddualquat ijkDualQuatConjugateDQd(ddualquat const dq_in);

// ijkDualQuatNegateDualDQ*
//	Negate dual part: conjugate of dual number.
//		param dq_in: input dual quaternion
//		return: dual conjugate dual quaternion
ddualquat ijkDualQuatNegateDualDQd(ddualquat const dq_in);

// ijkDualQuatConjugateDualDQ*
//	Conjugate and negate dual part: conjugate of dual number and components.
//		param dq_in: input dual quaternion
//		return: full dual conjugate dual quaternion
ddualquat ijkDualQuatConjugateDualDQd(ddualquat const dq_in);

// ijkDualQuatAddDQ*
//	Calculate sum of dual quaternions.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: sum dual quaternion
ddualquat ijkDualQuatAddDQd(ddualquat const dq_lh, ddualquat const dq_rh);

// ijkDualQuatSubDQ*
//	Calculate difference of dual quaternions.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: difference dual quaternion
ddualquat ijkDualQuatSubDQd(ddualquat const dq_lh, ddualquat const dq_rh);

// ijkDualQuatMulDQ*s
//	Calculate product of dual quaternion and scalar.
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: product dual quaternion
ddualquat ijkDualQuatMulDQds(ddualquat const dq_lh, double const s_rh);

// ijkDualQuatDivDQ*s
//	Calculate quotient of dual quaternion and scalar.
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: quotient dual quaternion
ddualquat ijkDualQuatDivDQds(ddualquat const dq_lh, double const s_rh);

// ijkDualQuatDivSafeDQ*s
//	Calculate quotient of dual quaternion and scalar; division-by-zero safety.
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: quotient dual quaternion
ddualquat ijkDualQuatDivSafeDQds(ddualquat const dq_lh, double const s_rh);

// ijkDualQuatLengthSqDQ*
//	Calculate squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: squared length
double ijkDualQuatLengthSqDQd(ddualquat const dq_in);

// ijkDualQuatLengthDQ*
//	Calculate length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: length
double ijkDualQuatLengthDQd(ddualquat const dq_in);

// ijkDualQuatLengthSqInvDQ*
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
double ijkDualQuatLengthSqInvDQd(ddualquat const dq_in);

// ijkDualQuatLengthInvDQ*
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
double ijkDualQuatLengthInvDQd(ddualquat const dq_in);

// ijkDualQuatLengthSqInvSafeDQ*
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
double ijkDualQuatLengthSqInvSafeDQd(ddualquat const dq_in);

// ijkDualQuatLengthInvSafeDQ*
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
double ijkDualQuatLengthInvSafeDQd(ddualquat const dq_in);

// ijkDualQuatNormalizeDQ*
//	Normalize dual quaternion.
//		param dq_in: input dual quaternion
//		return: unit dual quaternion
ddualquat ijkDualQuatNormalizeDQd(ddualquat const dq_in);

// ijkDualQuatNormalizeSafeDQ*
//	Normalize dual quaternion; division-by-zero safety.
//		param dq_in: input dual quaternion
//		return: unit dual quaternion
ddualquat ijkDualQuatNormalizeSafeDQd(ddualquat const dq_in);

// ijkDualQuatInverseDQ*
//	Calculate inverse of dual quaternion: conjugate divided by squared length.
//		param dq_in: input dual quaternion
//		return: inverse dual quaternion
ddualquat ijkDualQuatInverseDQd(ddualquat const dq_in);

// ijkDualQuatInverseSafeDQ*
//	Calculate inverse of dual quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param dq_in: input dual quaternion
//		return: inverse dual quaternion
ddualquat ijkDualQuatInverseSafeDQd(ddualquat const dq_in);

// ijkDualQuatMulVecDQ*3
//	Calculate product of dual quaternion and 3D vector (result is dual quaternion).
//		param dq_lh: left-hand dual quaternion
//		param v_rh: right-hand vector
//		return: product dual quaternion
ddualquat ijkDualQuatMulVecDQd3(ddualquat const dq_lh, dvec3 const v_rh);

// ijkDualQuatMulVecDQ*3q
//	Calculate product of 3D vector and dual quaternion (result is dual quaternion).
//		param v_lh: left-hand vector
//		param dq_rh: right-hand dual quaternion
//		return: product dual quaternion
ddualquat ijkDualQuatMulVecDQd3q(dvec3 const v_lh, ddualquat const dq_rh);

// ijkDualQuatMulDQ*
//	Calculate product of dual quaternions, or concatenate unit dual quaternions
//	representing transformations.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: product dual quaternion
ddualquat ijkDualQuatMulDQd(ddualquat const dq_lh, ddualquat const dq_rh);

// ijkDualQuatMulScaleDQ*
//	Correctly concatenate dual quaternions that represent transformations such 
//	that the right-hand input's translation is correctly affected by the left-
//	hand input's scale, when used to transform a vector later.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: product dual quaternion
ddualquat ijkDualQuatMulScaleDQd(ddualquat const dq_lh, ddualquat const dq_rh);

// ijkDualQuatDivDQ*
//	Calculate quotient of dual quaternions (multiply by rh inverse).
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: quotient dual quaternion
ddualquat ijkDualQuatDivDQd(ddualquat const dq_lh, ddualquat const dq_rh);

// ijkDualQuatRotateDQ*
//	Make rotation dual quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation dual quaternion
ddualquat ijkDualQuatRotateDQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ);

// ijkDualQuatAxisAngleDQ*
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation dual quaternion
ddualquat ijkDualQuatAxisAngleDQd(dvec3 const axis_unit, double const angle_degrees);

// ijkDualQuatScaleDQ*
//	Make rotation dual quaternion with uniform scale.
//		param scale_unif: uniform scale amount
//		return: scale dual quaternion
ddualquat ijkDualQuatScaleDQd(double const scale_unif);

// ijkDualQuatRotateScaleDQ*
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: rotation-scale dual quaternion
ddualquat ijkDualQuatRotateScaleDQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ, double const scale_unif);

// ijkDualQuatAxisAngleScaleDQ*
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: rotation-scale dual quaternion
ddualquat ijkDualQuatAxisAngleScaleDQd(dvec3 const axis_unit, double const angle_degrees, double const scale_unif);

// ijkDualQuatTranslateDQ*
//	Make rotation dual quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param translate: translation offset vector
//		return: translation dual quaternion
ddualquat ijkDualQuatTranslateDQd(dvec3 const translate);

// ijkDualQuatRotateTranslateDQ*
//	Make rotation dual quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param translate: translation offset vector
//		return: rotation-translation dual quaternion
ddualquat ijkDualQuatRotateTranslateDQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ, dvec3 const translate);

// ijkDualQuatAxisAngleTranslateDQ*
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: rotation-translation dual quaternion
ddualquat ijkDualQuatAxisAngleTranslateDQd(dvec3 const axis_unit, double const angle_degrees, dvec3 const translate);

// ijkDualQuatScaleTranslateDQ*
//	Make rotation dual quaternion with uniform scale.
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: scale-translation dual quaternion
ddualquat ijkDualQuatScaleTranslateDQd(double const scale_unif, dvec3 const translate);

// ijkDualQuatRotateScaleTranslateDQ*
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: rotation-scale-translation dual quaternion
ddualquat ijkDualQuatRotateScaleTranslateDQd(ijkRotationOrder const order, dvec3 const rotateDegXYZ, double const scale_unif, dvec3 const translate);

// ijkDualQuatAxisAngleScaleTranslateDQ*
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: rotation-scale-translation dual quaternion
ddualquat ijkDualQuatAxisAngleScaleTranslateDQd(dvec3 const axis_unit, double const angle_degrees, double const scale_unif, dvec3 const translate);

// ijkDualQuatGetRotateDQ*
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: dq_in
ddualquat ijkDualQuatGetRotateDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out);

// ijkDualQuatGetAxisAngleDQ*
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: dq_in
ddualquat ijkDualQuatGetAxisAngleDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out);

// ijkDualQuatGetScaleDQ*
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
ddualquat ijkDualQuatGetScaleDQd(ddualquat const dq_in, double* const scale_unif_out);

// ijkDualQuatGetRotateScaleDQ*
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
ddualquat ijkDualQuatGetRotateScaleDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, double* const scale_unif_out);

// ijkDualQuatGetAxisAngleScaleDQ*
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
ddualquat ijkDualQuatGetAxisAngleScaleDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, double* const scale_unif_out);

// ijkDualQuatGetTranslateDQ*
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
ddualquat ijkDualQuatGetTranslateDQd(ddualquat const dq_in, dvec3* const translate_out);

// ijkDualQuatGetRotateTranslateDQ*
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
ddualquat ijkDualQuatGetRotateTranslateDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const translate_out);

// ijkDualQuatGetAxisAngleTranslateDQ*
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
ddualquat ijkDualQuatGetAxisAngleTranslateDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const translate_out);

// ijkDualQuatGetScaleTranslateDQ*
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
ddualquat ijkDualQuatGetScaleTranslateDQd(ddualquat const dq_in, double* const scale_unif_out, dvec3* const translate_out);

// ijkDualQuatGetRotateScaleTranslateDQ*
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
ddualquat ijkDualQuatGetRotateScaleTranslateDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, double* const scale_unif_out, dvec3* const translate_out);

// ijkDualQuatGetAxisAngleScaleTranslateDQ*
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
ddualquat ijkDualQuatGetAxisAngleScaleTranslateDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, double* const scale_unif_out, dvec3* const translate_out);

// ijkDualQuatGetTranslateRemScaleDQ*
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
ddualquat ijkDualQuatGetTranslateRemScaleDQd(ddualquat const dq_in, dvec3* const translate_out);

// ijkDualQuatGetRotateTranslateRemScaleDQ*
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
ddualquat ijkDualQuatGetRotateTranslateRemScaleDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, dvec3* const translate_out);

// ijkDualQuatGetAxisAngleTranslateRemScaleDQ*
//	Extract unit axis and angle in degrees from dual quaternion, removing 
//	scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
ddualquat ijkDualQuatGetAxisAngleTranslateRemScaleDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const translate_out);

// ijkDualQuatGetScaleTranslateRemScaleDQ*
//	Extract uniform scale from dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
ddualquat ijkDualQuatGetScaleTranslateRemScaleDQd(ddualquat const dq_in, double* const scale_unif_out, dvec3* const translate_out);

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
ddualquat ijkDualQuatGetRotateScaleTranslateRemScaleDQd(ddualquat const dq_in, ijkRotationOrder const order, dvec3* const rotateDegXYZ_out, double* const scale_unif_out, dvec3* const translate_out);

// ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQ*
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion,
//	removing scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
ddualquat ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, double* const scale_unif_out, dvec3* const translate_out);

// ijkDualQuatGetScrewParamsDQ*
//	Extract screw parameters from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		param momentArm_out: storage for moment arm
//		param screwDisplace_out: storage for screw displacement parameter
//		return: dq_in
ddualquat ijkDualQuatGetScrewParamsDQd(ddualquat const dq_in, dvec3* const axis_unit_out, double* const angle_degrees_out, dvec3* const translate_out, dvec3* const momentArm_out, double* const screwDisplace_out);

// ijkDualQuatGetMatDQ*3
//	Convert dual quaternion's real part to 3D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
dmat3 ijkDualQuatGetMatDQd3(ddualquat const dq_in);

// ijkDualQuatUnitGetMatDQ*3
//	Convert unit dual quaternion's real part to 3D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
dmat3 ijkDualQuatUnitGetMatDQd3(ddualquat const dq_in);

// ijkDualQuatGetMatTranslateDQ*3
//	Convert dual quaternion's real part to 3D matrix and extract translation.
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: output matrix
dmat3 ijkDualQuatGetMatTranslateDQd3(dvec3* const translate_out, ddualquat const dq_in);

// ijkDualQuatUnitGetMatTranslateDQ*3
//	Convert unit dual quaternion's real part to 3D matrix and extract 
//	translation.
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: output matrix
dmat3 ijkDualQuatUnitGetMatTranslateDQd3(dvec3* const translate_out, ddualquat const dq_in);

// ijkDualQuatGetMatTranslateRemScaleDQ*3
//	Convert dual quaternion's real part to 3D matrix and extract translation 
//	with scale removed.
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: output matrix
dmat3 ijkDualQuatGetMatTranslateRemScaleDQd3(dvec3* const translate_out, ddualquat const dq_in);

// ijkDualQuatGetMatDQ*4
//	Convert dual quaternion to 4D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
dmat4 ijkDualQuatGetMatDQd4(ddualquat const dq_in);

// ijkDualQuatUnitGetMatDQ*4
//	Convert unit dual quaternion to 4D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
dmat4 ijkDualQuatUnitGetMatDQd4(ddualquat const dq_in);

// ijkDualQuatGetMatTranslateRemScaleDQ*4
//	Convert dual quaternion to 4D matrix, scale removed from translation part.
//		param dq_in: input dual quaternion
//		return: output matrix
dmat4 ijkDualQuatGetMatTranslateRemScaleDQd4(ddualquat const dq_in);

// ijkDualQuatTransformScaleVecDQ*3
//	Transform a 3D vector using a dual quaternion with scale; use when dual 
//	quaternion has scale to prevent translation part from being scaled.
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: transformed vector
dvec3 ijkDualQuatTransformScaleVecDQd3(ddualquat const dq_in, dvec3 const v_in);

// ijkDualQuatUnitTransformVecDQ*3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	unit-length for most optimized solution or when translation part should 
//	also be scaled.
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: transformed vector
dvec3 ijkDualQuatUnitTransformVecDQd3(ddualquat const dq_in, dvec3 const v_in);

// ijkDualQuatTransformVecDQ*3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	non-unit length to remove scale from all parts.
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: transformed vector
dvec3 ijkDualQuatTransformVecDQd3(ddualquat const dq_in, dvec3 const v_in);

// ijkDualQuatLerpDQ*
//	Calculate linear interpolation between two dual quaternions; yields uniform
//	rate of change but affects translation path and scale.
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: interpolated dual quaternion
ddualquat ijkDualQuatLerpDQd(ddualquat const dq0, ddualquat const dq1, double const u);

// ijkDualQuatNlerpDQ*
//	Calculate normalized linear interpolation between two dual quaternions; 
//	keeps result at unit-length but yields a non-uniform rate of change.
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: interpolated dual quaternion
ddualquat ijkDualQuatNlerpDQd(ddualquat const dq0, ddualquat const dq1, double const u);

// ijkDualQuatSclerpDQ*
//	Calculate screw linear interpolation between two unit dual quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: interpolated dual quaternion
ddualquat ijkDualQuatSclerpDQd(ddualquat const dq0, ddualquat const dq1, double const u);

// ijkDualQuatDerivDQ*
//	Calculate derivative of dual quaternion.
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param angularVelocity: angular velocity vector
//		return: derivative of dual quaternion
ddualquat ijkDualQuatDerivDQd(ddualquat const dq_in, dvec3 const linearVelocity, dvec3 const angularVelocity);

// ijkDualQuatDeriv2DQ*
//	Calculate second derivative of dual quaternion.
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param linearAcceleration: linear acceleration vector
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: second derivative of dual quaternion
ddualquat ijkDualQuatDeriv2DQd(ddualquat const dq_in, dvec3 const linearVelocity, dvec3 const linearAcceleration, dvec3 const angularVelocity, dvec3 const angularAcceleration);


//-----------------------------------------------------------------------------


#include "_inl/ijkQuaternion_double.inl"


#endif	// !_IJK_QUATERNION_DOUBLE_H_
#endif	// _IJK_QUATERNION_H_