/*
   Copyright 2020-2021 Daniel S. Buckstein

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

	ijkQuaternion_real.h
	Declarations for real quaternion functions.
*/

#ifdef _IJK_QUATERNION_H_
#ifndef _IJK_QUATERNION_REAL_H_
#define _IJK_QUATERNION_REAL_H_


#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

//-----------------------------------------------------------------------------

// ijkQuatP*v
//	Pass-thru array-based quaternion (does nothing).
//		param q_out: output quaternion
//		return: q_out
//realv ijkQuatPrv(real4 q_out);
#define ijkQuatPrv ijk_declrealfs(ijkQuatP,v)

// ijkDualQuatP*v
//	Pass-thru array-based dual quaternion (does nothing).
//		param dq_out: output dual quaternion
//		return: dq_out
//real4m ijkDualQuatPrm(real2x4 dq_out);
#define ijkDualQuatPrm ijk_declrealfs(ijkDualQuatP,m)


//-----------------------------------------------------------------------------

// ijkQuatInitQ*v
//	Initialize identity quaternion (zero vector, one real).
//		param q_out: output quaternion
//		return: q_out
//realv ijkQuatInitQrv(real4 q_out);
#define ijkQuatInitQrv ijk_declrealfs(ijkQuatInitQ,v)

// ijkQuatInitZeroQ*v
//	Initialize zero quaternion.
//		param q_out: output quaternion
//		return: q_out
//realv ijkQuatInitZeroQrv(real4 q_out);
#define ijkQuatInitZeroQrv ijk_declrealfs(ijkQuatInitZeroQ,v)

// ijkQuatInitElemsQ*v
//	Initialize individual elements of quaternion.
//		param q_out: output quaternion
//		params x, y, z, w: components
//		return: q_out
//realv ijkQuatInitElemsQrv(real4 q_out, real const x, real const y, real const z, real const w);
#define ijkQuatInitElemsQrv ijk_declrealfs(ijkQuatInitElemsQ,v)

// ijkQuatInitVecReQ*v
//	Initialize quaternion with vector and real parts.
//		param q_out: output quaternion
//		param vec: vector components (xyz)
//		param re: real component (w)
//		return: q_out
//realv ijkQuatInitVecReQrv(real4 q_out, real3 const vec, real const re);
#define ijkQuatInitVecReQrv ijk_declrealfs(ijkQuatInitVecReQ,v)

// ijkQuatInitVecProductQ*v
//	Initialize quaternion as product of two vectors.
//		param q_out: output quaternion
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: q_out
//realv ijkQuatInitVecProductQrv(real4 q_out, real3 const v_lh, real3 const v_rh);
#define ijkQuatInitVecProductQrv ijk_declrealfs(ijkQuatInitVecProductQ,v)

// ijkQuatInitVecProductSqrtQ*v
//	Initialize quaternion as product square root of two vectors.
//		param q_out: output quaternion
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: q_out
//realv ijkQuatInitVecProductSqrtQrv(real4 q_out, real3 const v_lh, real3 const v_rh);
#define ijkQuatInitVecProductSqrtQrv ijk_declrealfs(ijkQuatInitVecProductSqrtQ,v)

// ijkQuatInitVecProductSqrtUnitQ*v
//	Initialize quaternion as product square root of two unit vectors.
//		param q_out: output quaternion
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: q_out
//realv ijkQuatInitVecProductSqrtUnitQrv(real4 q_out, real3 const v_lh, real3 const v_rh);
#define ijkQuatInitVecProductSqrtUnitQrv ijk_declrealfs(ijkQuatInitVecProductSqrtUnitQ,v)

// ijkQuatInitMatQ*v3
//	Initialize quaternion from 3D matrix.
//		param q_out: output quaternion
//		param m_in: input matrix
//		return: q_out
//realv ijkQuatInitMatQrv3(real4 q_out, real3x3 const m_in);
#define ijkQuatInitMatQrv3 ijk_declrealfs(ijkQuatInitMatQ,v3)

// ijkQuatInitMatQ*v4
//	Initialize quaternion from 4D matrix.
//		param q_out: output quaternion
//		param m_in: input matrix
//		return: q_out
//realv ijkQuatInitMatQrv4(real4 q_out, real4x4 const m_in);
#define ijkQuatInitMatQrv4 ijk_declrealfs(ijkQuatInitMatQ,v4)

// ijkQuatCopyQ*v
//	Copy quaternion.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatCopyQrv(real4 q_out, real4 const q_in);
#define ijkQuatCopyQrv ijk_declrealfs(ijkQuatCopyQ,v)

// ijkQuatNegateQ*v
//	Negate quaternion.
//		param q_out: output quaternion, negative
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatNegateQrv(real4 q_out, real4 const q_in);
#define ijkQuatNegateQrv ijk_declrealfs(ijkQuatNegateQ,v)

// ijkQuatConjugateQ*v
//	Conjugate quaternion: negate vector part, copy real part.
//		param q_out: output quaternion, conjugate
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatConjugateQrv(real4 q_out, real4 const q_in);
#define ijkQuatConjugateQrv ijk_declrealfs(ijkQuatConjugateQ,v)

// ijkQuatConjugateMulQ*vs
//	Conjugate quaternion: negate vector part, copy real part, multiply by 
//	scalar.
//		param q_out: output quaternion, conjugate
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatConjugateMulQrvs(real4 q_out, real4 const q_in, real const s);
#define ijkQuatConjugateMulQrvs ijk_declrealfs(ijkQuatConjugateMulQ,vs)

// ijkQuatNegateConjugateQ*v
//	Negate and conjugate quaternion: negate real part, copy vector part.
//		param q_out: output quaternion, negative conjugate
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatNegateConjugateQrv(real4 q_out, real4 const q_in);
#define ijkQuatNegateConjugateQrv ijk_declrealfs(ijkQuatNegateConjugateQ,v)

// ijkQuatNegateConjugateMulQ*vs
//	Negate and conjugate quaternion: negate real part, copy vector part, 
//	multiply by scalar.
//		param q_out: output quaternion, negative conjugate
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatNegateConjugateMulQrvs(real4 q_out, real4 const q_in, real const s);
#define ijkQuatNegateConjugateMulQrvs ijk_declrealfs(ijkQuatNegateConjugateMulQ,vs)

// ijkQuatAddQ*v
//	Calculate sum of quaternions.
//		param q_out: output quaternion, sum
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
//realv ijkQuatAddQrv(real4 q_out, real4 const q_lh, real4 const q_rh);
#define ijkQuatAddQrv ijk_declrealfs(ijkQuatAddQ,v)

// ijkQuatSubQ*v
//	Calculate difference of quaternions.
//		param q_out: output quaternion, difference
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
//realv ijkQuatSubQrv(real4 q_out, real4 const q_lh, real4 const q_rh);
#define ijkQuatSubQrv ijk_declrealfs(ijkQuatSubQ,v)

// ijkQuatMulQ*vs
//	Calculate product of quaternion and scalar.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: q_out
//realv ijkQuatMulQrvs(real4 q_out, real4 const q_lh, real const s_rh);
#define ijkQuatMulQrvs ijk_declrealfs(ijkQuatMulQ,vs)

// ijkQuatDivQ*vs
//	Calculate quotient of quaternion and scalar.
//		param q_out: output quaternion, quotient
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: q_out
//realv ijkQuatDivQrvs(real4 q_out, real4 const q_lh, real const s_rh);
#define ijkQuatDivQrvs ijk_declrealfs(ijkQuatDivQ,vs)

// ijkQuatDivSafeQ*vs
//	Calculate quotient of quaternion and scalar; division-by-zero safety.
//		param q_out: output quaternion, quotient
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: q_out
//realv ijkQuatDivSafeQrvs(real4 q_out, real4 const q_lh, real const s_rh);
#define ijkQuatDivSafeQrvs ijk_declrealfs(ijkQuatDivSafeQ,vs)

// ijkQuatLengthSqQ*v
//	Calculate squared length of quaternion.
//		param q_in: input quaternion
//		return: squared length
//real ijkQuatLengthSqQrv(real4 const q_in);
#define ijkQuatLengthSqQrv ijk_declrealfs(ijkQuatLengthSqQ,v)

// ijkQuatLengthQ*v
//	Calculate length of quaternion.
//		param q_in: input quaternion
//		return: length
//real ijkQuatLengthQrv(real4 const q_in);
#define ijkQuatLengthQrv ijk_declrealfs(ijkQuatLengthQ,v)

// ijkQuatLengthSqInvQ*v
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
//real ijkQuatLengthSqInvQrv(real4 const q_in);
#define ijkQuatLengthSqInvQrv ijk_declrealfs(ijkQuatLengthSqInvQ,v)

// ijkQuatLengthInvQ*v
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
//real ijkQuatLengthInvQrv(real4 const q_in);
#define ijkQuatLengthInvQrv ijk_declrealfs(ijkQuatLengthInvQ,v)

// ijkQuatLengthSqInvSafeQ*v
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
//real ijkQuatLengthSqInvSafeQrv(real4 const q_in);
#define ijkQuatLengthSqInvSafeQrv ijk_declrealfs(ijkQuatLengthSqInvSafeQ,v)

// ijkQuatLengthInvSafeQ*v
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
//real ijkQuatLengthInvSafeQrv(real4 const q_in);
#define ijkQuatLengthInvSafeQrv ijk_declrealfs(ijkQuatLengthInvSafeQ,v)

// ijkQuatNormalizeQ*v
//	Normalize quaternion.
//		param q_out: output quaternion, unit-length
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatNormalizeQrv(real4 q_out, real4 const q_in);
#define ijkQuatNormalizeQrv ijk_declrealfs(ijkQuatNormalizeQ,v)

// ijkQuatNormalizeSafeQ*v
//	Normalize quaternion; division-by-zero safety.
//		param q_out: output quaternion, unit-length
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatNormalizeSafeQrv(real4 q_out, real4 const q_in);
#define ijkQuatNormalizeSafeQrv ijk_declrealfs(ijkQuatNormalizeSafeQ,v)

// ijkQuatInverseQ*v
//	Calculate inverse of quaternion: conjugate divided by squared length.
//		param q_out: output quaternion, inverse
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatInverseQrv(real4 q_out, real4 const q_in);
#define ijkQuatInverseQrv ijk_declrealfs(ijkQuatInverseQ,v)

// ijkQuatInverseSafeQ*v
//	Calculate inverse of quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param q_out: output quaternion, inverse
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatInverseSafeQrv(real4 q_out, real4 const q_in);
#define ijkQuatInverseSafeQrv ijk_declrealfs(ijkQuatInverseSafeQ,v)

// ijkQuatMulVecQ*v3
//	Calculate product of quaternion and 3D vector (result is quaternion).
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param v_rh: right-hand vector
//		return: q_out
//realv ijkQuatMulVecQrv3(real4 q_out, real4 const q_lh, real3 const v_rh);
#define ijkQuatMulVecQrv3 ijk_declrealfs(ijkQuatMulVecQ,v3)

// ijkQuatMulVecQ*v3q
//	Calculate product of 3D vector and quaternion (result is quaternion).
//		param q_out: output quaternion, product
//		param v_lh: left-hand vector
//		param q_rh: right-hand quaternion
//		return: q_out
//realv ijkQuatMulVecQrv3q(real4 q_out, real3 const v_lh, real4 const q_rh);
#define ijkQuatMulVecQrv3q ijk_declrealfs(ijkQuatMulVecQ,v3q)

// ijkQuatMulQ*v
//	Calculate product of quaternions.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
//realv ijkQuatMulQrv(real4 q_out, real4 const q_lh, real4 const q_rh);
#define ijkQuatMulQrv ijk_declrealfs(ijkQuatMulQ,v)

// ijkQuatMulConjQ*v
//	Calculate product of quaternion with quaternion conjugate.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion, conjugated before multiplying
//		return: q_out
//realv ijkQuatMulConjQrv(real4 q_out, real4 const q_lh, real4 const q_rh);
#define ijkQuatMulConjQrv ijk_declrealfs(ijkQuatMulConjQ,v)

// ijkQuatConjMulQ*v
//	Calculate product of quaternion conjugate with quaternion.
//		param q_out: output quaternion, product
//		param q_lh: left-hand quaternion, conjugated before multiplying
//		param q_rh: right-hand quaternion
//		return: q_out
//realv ijkQuatConjMulQrv(real4 q_out, real4 const q_lh, real4 const q_rh);
#define ijkQuatConjMulQrv ijk_declrealfs(ijkQuatConjMulQ,v)

// ijkQuatDivQ*v
//	Calculate quotient of quaternions (multiply by rh inverse).
//		param q_out: output quaternion, quotient
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: q_out
//realv ijkQuatDivQrv(real4 q_out, real4 const q_lh, real4 const q_rh);
#define ijkQuatDivQrv ijk_declrealfs(ijkQuatDivQ,v)

// ijkQuatRotateXYZQ*v
//	Make rotation quaternion with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
//realv ijkQuatRotateXYZQrv(real4 q_out, real3 const rotateDegXYZ);
#define ijkQuatRotateXYZQrv ijk_declrealfs(ijkQuatRotateXYZQ,v)

// ijkQuatRotateYZXQ*v
//	Make rotation quaternion with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
//realv ijkQuatRotateYZXQrv(real4 q_out, real3 const rotateDegXYZ);
#define ijkQuatRotateYZXQrv ijk_declrealfs(ijkQuatRotateYZXQ,v)

// ijkQuatRotateZXYQ*v
//	Make rotation quaternion with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
//realv ijkQuatRotateZXYQrv(real4 q_out, real3 const rotateDegXYZ);
#define ijkQuatRotateZXYQrv ijk_declrealfs(ijkQuatRotateZXYQ,v)

// ijkQuatRotateYXZQ*v
//	Make rotation quaternion with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
//realv ijkQuatRotateYXZQrv(real4 q_out, real3 const rotateDegXYZ);
#define ijkQuatRotateYXZQrv ijk_declrealfs(ijkQuatRotateYXZQ,v)

// ijkQuatRotateXZYQ*v
//	Make rotation quaternion with Euler angles in written order XZY, meaning 
//	the order of operations is X then Z then Y.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
//realv ijkQuatRotateXZYQrv(real4 q_out, real3 const rotateDegXYZ);
#define ijkQuatRotateXZYQrv ijk_declrealfs(ijkQuatRotateXZYQ,v)

// ijkQuatRotateZYXQ*v
//	Make rotation quaternion with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param q_out: output quaternion, rotation
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
//realv ijkQuatRotateZYXQrv(real4 q_out, real3 const rotateDegXYZ);
#define ijkQuatRotateZYXQrv ijk_declrealfs(ijkQuatRotateZYXQ,v)

// ijkQuatGetRotateXYZQ*v
//	Extract Euler angles from rotation quaternion; written order XYZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//realkv ijkQuatGetRotateXYZQrv(real4 const q_in, real3 rotateDegXYZ_out);
#define ijkQuatGetRotateXYZQrv ijk_declrealfs(ijkQuatGetRotateXYZQ,v)

// ijkQuatGetRotateYZXQ*v
//	Extract Euler angles from rotation quaternion; written order YZX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//realkv ijkQuatGetRotateYZXQrv(real4 const q_in, real3 rotateDegXYZ_out);
#define ijkQuatGetRotateYZXQrv ijk_declrealfs(ijkQuatGetRotateYZXQ,v)

// ijkQuatGetRotateZXYQ*v
//	Extract Euler angles from rotation quaternion; written order ZXY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//realkv ijkQuatGetRotateZXYQrv(real4 const q_in, real3 rotateDegXYZ_out);
#define ijkQuatGetRotateZXYQrv ijk_declrealfs(ijkQuatGetRotateZXYQ,v)

// ijkQuatGetRotateYXZQ*v
//	Extract Euler angles from rotation quaternion; written order YXZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//realkv ijkQuatGetRotateYXZQrv(real4 const q_in, real3 rotateDegXYZ_out);
#define ijkQuatGetRotateYXZQrv ijk_declrealfs(ijkQuatGetRotateYXZQ,v)

// ijkQuatGetRotateXZYQ*v
//	Extract Euler angles from rotation quaternion; written order XZY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//realkv ijkQuatGetRotateXZYQrv(real4 const q_in, real3 rotateDegXYZ_out);
#define ijkQuatGetRotateXZYQrv ijk_declrealfs(ijkQuatGetRotateXZYQ,v)

// ijkQuatGetRotateZYXQ*v
//	Extract Euler angles from rotation quaternion; written order ZYX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//realkv ijkQuatGetRotateZYXQrv(real4 const q_in, real3 rotateDegXYZ_out);
#define ijkQuatGetRotateZYXQrv ijk_declrealfs(ijkQuatGetRotateZYXQ,v)

// ijkQuatRotateQ*v
//	Make rotation quaternion with Euler angles.
//		param q_out: output quaternion, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: q_out
//realv ijkQuatRotateQrv(real4 q_out, ijkRotationOrder const order, real3 const rotateDegXYZ);
#define ijkQuatRotateQrv ijk_declrealfs(ijkQuatRotateQ,v)

// ijkQuatAxisAngleQ*v
//	Make rotation quaternion with unit axis and angle in degrees.
//		param q_out: output quaternion, rotation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: q_out
//realv ijkQuatAxisAngleQrv(real4 q_out, real3 const axis_unit, real const angle_degrees);
#define ijkQuatAxisAngleQrv ijk_declrealfs(ijkQuatAxisAngleQ,v)

// ijkQuatScaleQ*v
//	Make rotation quaternion with uniform scale.
//		param q_out: output quaternion, scale
//		param scale_unif: uniform scale amount
//		return: q_out
//realv ijkQuatScaleQrv(real4 q_out, real const scale_unif);
#define ijkQuatScaleQrv ijk_declrealfs(ijkQuatScaleQ,v)

// ijkQuatRotateScaleQ*v
//	Make rotation quaternion with Euler angles and uniform scale.
//		param q_out: output quaternion, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: q_out
//realv ijkQuatRotateScaleQrv(real4 q_out, ijkRotationOrder const order, real3 const rotateDegXYZ, real const scale_unif);
#define ijkQuatRotateScaleQrv ijk_declrealfs(ijkQuatRotateScaleQ,v)

// ijkQuatAxisAngleScaleQ*v
//	Make rotation quaternion with unit axis, angle in degrees and uniform scale.
//		param q_out: output quaternion, rotation-scale
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: q_out
//realv ijkQuatAxisAngleScaleQrv(real4 q_out, real3 const axis_unit, real const angle_degrees, real const scale_unif);
#define ijkQuatAxisAngleScaleQrv ijk_declrealfs(ijkQuatAxisAngleScaleQ,v)

// ijkQuatGetRotateQ*v
//	Extract Euler angles from rotation quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//realkv ijkQuatGetRotateQrv(real4 const q_in, ijkRotationOrder const order, real3 rotateDegXYZ_out);
#define ijkQuatGetRotateQrv ijk_declrealfs(ijkQuatGetRotateQ,v)

// ijkQuatGetAxisAngleQ*v
//	Extract unit axis and angle in degrees from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: q_in
//realkv ijkQuatGetAxisAngleQrv(real4 const q_in, real3 axis_unit_out, real* const angle_degrees_out);
#define ijkQuatGetAxisAngleQrv ijk_declrealfs(ijkQuatGetAxisAngleQ,v)

// ijkQuatGetScaleQ*v
//	Extract uniform scale from quaternion.
//		param q_in: input quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
//realkv ijkQuatGetScaleQrv(real4 const q_in, real* const scale_unif_out);
#define ijkQuatGetScaleQrv ijk_declrealfs(ijkQuatGetScaleQ,v)

// ijkQuatGetRotateScaleQ*v
//	Extract Euler angles and uniform scale from quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
//realkv ijkQuatGetRotateScaleQrv(real4 const q_in, ijkRotationOrder const order, real3 rotateDegXYZ_out, real* const scale_unif_out);
#define ijkQuatGetRotateScaleQrv ijk_declrealfs(ijkQuatGetRotateScaleQ,v)

// ijkQuatGetAxisAngleScaleQ*v
//	Extract unit axis, angle in degrees and uniform scale from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
//realkv ijkQuatGetAxisAngleScaleQrv(real4 const q_in, real3 axis_unit_out, real* const angle_degrees_out, real* const scale_unif_out);
#define ijkQuatGetAxisAngleScaleQrv ijk_declrealfs(ijkQuatGetAxisAngleScaleQ,v)

// ijkQuatGetMatQ*v3
//	Convert quaternion to 3D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
//real3m ijkQuatGetMatQrv3(real3x3 m_out, real4 const q_in);
#define ijkQuatGetMatQrv3 ijk_declrealfs(ijkQuatGetMatQ,v3)

// ijkQuatUnitGetMatQ*v3
//	Convert unit quaternion to 3D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
//real3m ijkQuatUnitGetMatQrv3(real3x3 m_out, real4 const q_in);
#define ijkQuatUnitGetMatQrv3 ijk_declrealfs(ijkQuatUnitGetMatQ,v3)

// ijkQuatGetMatQ*v4
//	Convert quaternion to 4D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
//real4m ijkQuatGetMatQrv4(real4x4 m_out, real4 const q_in);
#define ijkQuatGetMatQrv4 ijk_declrealfs(ijkQuatGetMatQ,v4)

// ijkQuatUnitGetMatQ*v4
//	Convert unit quaternion to 4D matrix.
//		param m_out: output matrix
//		param q_in: input quaternion
//		return: m_out
//real4m ijkQuatUnitGetMatQrv4(real4x4 m_out, real4 const q_in);
#define ijkQuatUnitGetMatQrv4 ijk_declrealfs(ijkQuatUnitGetMatQ,v4)

// ijkQuatGetMatQ*v4t
//	Convert quaternion to 4D matrix, with additional translation vector.
//		param m_out: output matrix
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: m_out
//real4m ijkQuatGetMatQrv4t(real4x4 m_out, real4 const q_in, real3 const translate);
#define ijkQuatGetMatQrv4t ijk_declrealfs(ijkQuatGetMatQ,v4t)

// ijkQuatUnitGetMatQ*v4t
//	Convert unit quaternion to 4D matrix, with additional translation vector.
//		param m_out: output matrix
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: m_out
//real4m ijkQuatUnitGetMatQrv4t(real4x4 m_out, real4 const q_in, real3 const translate);
#define ijkQuatUnitGetMatQrv4t ijk_declrealfs(ijkQuatUnitGetMatQ,v4t)

// ijkQuatRotateScaleVecQ*v3
//	Rotate and/or scale a 3D vector using a quaternion; result will not be 
//	divided by squared magnitude.
//		param v_out: output vector
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
//realv ijkQuatRotateScaleVecQrv3(real3 v_out, real4 const q_in, real3 const v_in);
#define ijkQuatRotateScaleVecQrv3 ijk_declrealfs(ijkQuatRotateScaleVecQ,v3)

// ijkQuatUnitRotateVecQ*v3
//	Rotate a 3D vector using a quaternion; use with unit quaternion for most 
//	optimized solution.
//		param v_out: output vector
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
//realv ijkQuatUnitRotateVecQrv3(real3 v_out, real4 const q_in, real3 const v_in);
#define ijkQuatUnitRotateVecQrv3 ijk_declrealfs(ijkQuatUnitRotateVecQ,v3)

// ijkQuatRotateVecQ*v3
//	Rotate a 3D vector using a quaternion; use this when the input quaternion 
//	is non-unit length so that the result will only be rotated.
//		param v_out: output vector
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
//realv ijkQuatRotateVecQrv3(real3 v_out, real4 const q_in, real3 const v_in);
#define ijkQuatRotateVecQrv3 ijk_declrealfs(ijkQuatRotateVecQ,v3)

// ijkQuatReflectScaleQ*v
//	Reflect and/or scale a quaternion about an axis.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
//realv ijkQuatReflectScaleQrv(real4 q_out, real4 const q_in, real3 const v_in);
#define ijkQuatReflectScaleQrv ijk_declrealfs(ijkQuatReflectScaleQ,v)

// ijkQuatUnitReflectQ*v
//	Reflect a unit quaternion about an axis; optimized for unit quaternions.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
//realv ijkQuatUnitReflectQrv(real4 q_out, real4 const q_in, real3 const v_in);
#define ijkQuatUnitReflectQrv ijk_declrealfs(ijkQuatUnitReflectQ,v)

// ijkQuatReflectQ*v
//	Reflect a non-unit quaternion about an axis.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param v_in: input vector
//		return: v_out
//realv ijkQuatReflectQrv(real4 q_out, real4 const q_in, real3 const v_in);
#define ijkQuatReflectQrv ijk_declrealfs(ijkQuatReflectQ,v)

// ijkQuatExpQ*v
//	Calculate quaternion as natural exponent base (e) raised to vector power.
//		param q_out: output quaternion
//		param v_in: input vector
//		return: q_out
//realv ijkQuatExpQrv(real4 q_out, real3 const v_in);
#define ijkQuatExpQrv ijk_declrealfs(ijkQuatExpQ,v)

// ijkQuatLnQ*v
//	Calculate quaternion or vector as natural logarithm of quaternion.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatLnQrv(real4 q_out, real4 const q_in);
#define ijkQuatLnQrv ijk_declrealfs(ijkQuatLnQ,v)

// ijkQuatPowQ*v
//	Calculate quaternion raised to power of exponent.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		param u: exponent
//		return: q_out
//realv ijkQuatPowQrv(real4 q_out, real4 const q_in, real const u);
#define ijkQuatPowQrv ijk_declrealfs(ijkQuatPowQ,v)

// ijkQuatSqrtQ*v
//	Calculate square root of quaternion.
//		param q_out: output quaternion
//		param q_in: input quaternion
//		return: q_out
//realv ijkQuatSqrtQrv(real4 q_out, real4 const q_in);
#define ijkQuatSqrtQrv ijk_declrealfs(ijkQuatSqrtQ,v)

// ijkQuatLerpQ*v
//	Calculate linear interpolation between two quaternions; yields a uniform 
//	rate of change but affects encoded scale.
//		param q_out: output quaternion, interpolated quaternion
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: q_out
//realv ijkQuatLerpQrv(real4 q_out, real4 const q0, real4 const q1, real const u);
#define ijkQuatLerpQrv ijk_declrealfs(ijkQuatLerpQ,v)

// ijkQuatNlerpQ*v
//	Calculate normalized linear interpolation between two quaternions; keeps 
//	result at unit-length but yields a non-uniform rate of change.
//		param q_out: output quaternion, interpolated quaternion
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: q_out
//realv ijkQuatNlerpQrv(real4 q_out, real4 const q0, real4 const q1, real const u);
#define ijkQuatNlerpQrv ijk_declrealfs(ijkQuatNlerpQ,v)

// ijkQuatSlerpQ*v
//	Calculate spherical linear interpolation between two unit quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param q_out: output quaternion, interpolated quaternion
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: q_out
//realv ijkQuatSlerpQrv(real4 q_out, real4 const q0, real4 const q1, real const u);
#define ijkQuatSlerpQrv ijk_declrealfs(ijkQuatSlerpQ,v)

// ijkQuatDerivQ*v
//	Calculate derivative of quaternion.
//		param q1_out: output quaternion, derivative of quaternion
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		return: q1_out
//realv ijkQuatDerivQrv(real4 q1_out, real4 const q_in, real3 const angularVelocity);
#define ijkQuatDerivQrv ijk_declrealfs(ijkQuatDerivQ,v)

// ijkQuatDeriv2Q*v
//	Calculate second derivative of quaternion.
//		param q2_out: output quaternion, second derivative of quaternion
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: q2_out
//realv ijkQuatDeriv2Qrv(real4 q2_out, real4 const q_in, real3 const angularVelocity, real3 const angularAcceleration);
#define ijkQuatDeriv2Qrv ijk_declrealfs(ijkQuatDeriv2Q,v)

// ijkQuatEncodeTranslateQ*v
//	Encode translation offset vector using quaternion.
//		param qt_out: output quaternion, encoded translation
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: qt_out
//realv ijkQuatEncodeTranslateQrv(real4 qt_out, real3 const translate_in, real4 const q_encode);
#define ijkQuatEncodeTranslateQrv ijk_declrealfs(ijkQuatEncodeTranslateQ,v)

// ijkQuatEncodeTranslateX2Q*v
//	Encode double translation offset vector using quaternion.
//		param qt_out: output quaternion, encoded translation
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: qt_out
//realv ijkQuatEncodeTranslateX2Qrv(real4 qt_out, real3 const translate_in, real4 const q_encode);
#define ijkQuatEncodeTranslateX2Qrv ijk_declrealfs(ijkQuatEncodeTranslateX2Q,v)

// ijkQuatDecodeTranslateQ*v
//	Decode translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
//realv ijkQuatDecodeTranslateQrv(real3 translate_out, real4 const qt_in, real4 const q_decode);
#define ijkQuatDecodeTranslateQrv ijk_declrealfs(ijkQuatDecodeTranslateQ,v)

// ijkQuatDecodeTranslateD2Q*vs
//	Decode half translation offset vector from quaternion with scalar 
//	multiplier; use if encoding quaternion is unit or if decoded translation 
//	should have additional user-defined scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
//realv ijkQuatDecodeTranslateD2Qrvs(real3 translate_out, real4 const qt_in, real4 const q_decode, real const s);
#define ijkQuatDecodeTranslateD2Qrvs ijk_declrealfs(ijkQuatDecodeTranslateD2Q,vs)

// ijkQuatDecodeTranslateD2Q*v
//	Decode half translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
//realv ijkQuatDecodeTranslateD2Qrv(real3 translate_out, real4 const qt_in, real4 const q_decode);
#define ijkQuatDecodeTranslateD2Qrv ijk_declrealfs(ijkQuatDecodeTranslateD2Q,v)

// ijkQuatDecodeTranslateRemScaleQ*v
//	Decode translation offset vector from quaternion, removing scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
//realv ijkQuatDecodeTranslateRemScaleQrv(real3 translate_out, real4 const qt_in, real4 const q_decode);
#define ijkQuatDecodeTranslateRemScaleQrv ijk_declrealfs(ijkQuatDecodeTranslateRemScaleQ,v)

// ijkQuatDecodeTranslateRemScaleD2Q*v
//	Decode half translation offset vector from quaternion, removing scale.
//		param translate_out: output vector, translation offset
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translate_out
//realv ijkQuatDecodeTranslateRemScaleD2Qrv(real3 translate_out, real4 const qt_in, real4 const q_decode);
#define ijkQuatDecodeTranslateRemScaleD2Qrv ijk_declrealfs(ijkQuatDecodeTranslateRemScaleD2Q,v)


//-----------------------------------------------------------------------------

// ijkDualQuatInitDQ*m
//	Initialize identity dual quaternion (zero dual, identity real).
//		param dq_out: output dual quaternion
//		return: dq_out
//real4m ijkDualQuatInitDQrm(real2x4 dq_out);
#define ijkDualQuatInitDQrm ijk_declrealfs(ijkDualQuatInitDQ,m)

// ijkDualQuatInitDualReDQ*m
//	Initialize dual quaternion with dual and real parts.
//		param dq_out: output dual quaternion
//		param re: real component (qr)
//		param dual: dual component (E qd)
//		return: dq_out
//real4m ijkDualQuatInitDualReDQrm(real2x4 dq_out, real4 const re, real4 const dual);
#define ijkDualQuatInitDualReDQrm ijk_declrealfs(ijkDualQuatInitDualReDQ,m)

// ijkDualQuatInitMatDQ*m3
//	Initialize dual quaternion from 3D matrix.
//		param dq_out: output dual quaternion
//		param m_in: input matrix
//		return: dq_out
//real4m ijkDualQuatInitMatDQrm3(real2x4 dq_out, real3x3 const m_in);
#define ijkDualQuatInitMatDQrm3 ijk_declrealfs(ijkDualQuatInitMatDQ,m3)

// ijkDualQuatInitMatDQ*m4
//	Initialize dual quaternion from 4D matrix.
//		param dq_out: output dual quaternion
//		param m_in: input matrix
//		return: dq_out
//real4m ijkDualQuatInitMatDQrm4(real2x4 dq_out, real4x4 const m_in);
#define ijkDualQuatInitMatDQrm4 ijk_declrealfs(ijkDualQuatInitMatDQ,m4)

// ijkDualQuatCopyDQ*m
//	Copy dual quaternion.
//		param dq_out: output dual quaternion
//		param dq_in: input dual quaternion
//		return: dq_out
//real4m ijkDualQuatCopyDQrm(real2x4 dq_out, real2x4 const dq_in);
#define ijkDualQuatCopyDQrm ijk_declrealfs(ijkDualQuatCopyDQ,m)

// ijkDualQuatNegateDQ*m
//	Negate dual quaternion.
//		param dq_out: output dual quaternion, negative
//		param dq_in: input dual quaternion
//		return: dq_out
//real4m ijkDualQuatNegateDQrm(real2x4 dq_out, real2x4 const dq_in);
#define ijkDualQuatNegateDQrm ijk_declrealfs(ijkDualQuatNegateDQ,m)

// ijkDualQuatConjugateDQ*m
//	Conjugate dual quaternion: take conjugate of both components.
//		param dq_out: output dual quaternion, conjugate
//		param dq_in: input dual quaternion
//		return: dq_out
//real4m ijkDualQuatConjugateDQrm(real2x4 dq_out, real2x4 const dq_in);
#define ijkDualQuatConjugateDQrm ijk_declrealfs(ijkDualQuatConjugateDQ,m)

// ijkDualQuatNegateDualDQ*m
//	Negate dual part: conjugate of dual number.
//		param dq_out: output dual quaternion, dual conjugate
//		param dq_in: input dual quaternion
//		return: dq_out
//real4m ijkDualQuatNegateDualDQrm(real2x4 dq_out, real2x4 const dq_in);
#define ijkDualQuatNegateDualDQrm ijk_declrealfs(ijkDualQuatNegateDualDQ,m)

// ijkDualQuatConjugateDualDQ*m
//	Conjugate and negate dual part: conjugate of dual number and components.
//		param dq_out: output dual quaternion, complete dual conjugate
//		param dq_in: input dual quaternion
//		return: dq_out
//real4m ijkDualQuatConjugateDualDQrm(real2x4 dq_out, real2x4 const dq_in);
#define ijkDualQuatConjugateDualDQrm ijk_declrealfs(ijkDualQuatConjugateDualDQ,m)

// ijkDualQuatAddDQ*m
//	Calculate sum of dual quaternions.
//		param dq_out: output dual quaternion, sum
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
//real4m ijkDualQuatAddDQrm(real2x4 dq_out, real2x4 const dq_lh, real2x4 const dq_rh);
#define ijkDualQuatAddDQrm ijk_declrealfs(ijkDualQuatAddDQ,m)

// ijkDualQuatSubDQ*m
//	Calculate difference of dual quaternions.
//		param dq_out: output dual quaternion, difference
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
//real4m ijkDualQuatSubDQrm(real2x4 dq_out, real2x4 const dq_lh, real2x4 const dq_rh);
#define ijkDualQuatSubDQrm ijk_declrealfs(ijkDualQuatSubDQ,m)

// ijkDualQuatMulDQ*ms
//	Calculate product of dual quaternion and scalar.
//		param dq_out: output dual quaternion, product
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: dq_out
//real4m ijkDualQuatMulDQrms(real2x4 dq_out, real2x4 const dq_lh, real const s_rh);
#define ijkDualQuatMulDQrms ijk_declrealfs(ijkDualQuatMulDQ,ms)

// ijkDualQuatDivDQ*ms
//	Calculate quotient of dual quaternion and scalar.
//		param dq_out: output dual quaternion, quotient
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: dq_out
//real4m ijkDualQuatDivDQrms(real2x4 dq_out, real2x4 const dq_lh, real const s_rh);
#define ijkDualQuatDivDQrms ijk_declrealfs(ijkDualQuatDivDQ,ms)

// ijkDualQuatDivSafeDQ*ms
//	Calculate quotient of dual quaternion and scalar; division-by-zero safety.
//		param dq_out: output dual quaternion, quotient
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: dq_out
//real4m ijkDualQuatDivSafeDQrms(real2x4 dq_out, real2x4 const dq_lh, real const s_rh);
#define ijkDualQuatDivSafeDQrms ijk_declrealfs(ijkDualQuatDivSafeDQ,ms)

// ijkDualQuatLengthSqDQ*m
//	Calculate squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: squared length
//real ijkDualQuatLengthSqDQrm(real2x4 const dq_in);
#define ijkDualQuatLengthSqDQrm ijk_declrealfs(ijkDualQuatLengthSqDQ,m)

// ijkDualQuatLengthDQ*m
//	Calculate length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: length
//real ijkDualQuatLengthDQrm(real2x4 const dq_in);
#define ijkDualQuatLengthDQrm ijk_declrealfs(ijkDualQuatLengthDQ,m)

// ijkDualQuatLengthSqInvDQ*m
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
//real ijkDualQuatLengthSqInvDQrm(real2x4 const dq_in);
#define ijkDualQuatLengthSqInvDQrm ijk_declrealfs(ijkDualQuatLengthSqInvDQ,m)

// ijkDualQuatLengthInvDQ*m
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
//real ijkDualQuatLengthInvDQrm(real2x4 const dq_in);
#define ijkDualQuatLengthInvDQrm ijk_declrealfs(ijkDualQuatLengthInvDQ,m)

// ijkDualQuatLengthSqInvSafeDQ*m
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
//real ijkDualQuatLengthSqInvSafeDQrm(real2x4 const dq_in);
#define ijkDualQuatLengthSqInvSafeDQrm ijk_declrealfs(ijkDualQuatLengthSqInvSafeDQ,m)

// ijkDualQuatLengthInvSafeDQ*m
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
//real ijkDualQuatLengthInvSafeDQrm(real2x4 const dq_in);
#define ijkDualQuatLengthInvSafeDQrm ijk_declrealfs(ijkDualQuatLengthInvSafeDQ,m)

// ijkDualQuatNormalizeDQ*m
//	Normalize dual quaternion.
//		param dq_out: output dual quaternion, unit-length
//		param dq_in: input dual quaternion
//		return: dq_out
//real4m ijkDualQuatNormalizeDQrm(real2x4 dq_out, real2x4 const dq_in);
#define ijkDualQuatNormalizeDQrm ijk_declrealfs(ijkDualQuatNormalizeDQ,m)

// ijkDualQuatNormalizeSafeDQ*m
//	Normalize dual quaternion; division-by-zero safety.
//		param dq_out: output dual quaternion, unit-length
//		param dq_in: input dual quaternion
//		return: dq_out
//real4m ijkDualQuatNormalizeSafeDQrm(real2x4 dq_out, real2x4 const dq_in);
#define ijkDualQuatNormalizeSafeDQrm ijk_declrealfs(ijkDualQuatNormalizeSafeDQ,m)

// ijkDualQuatInverseDQ*m
//	Calculate inverse of dual quaternion: conjugate divided by squared length.
//		param dq_out: output dual quaternion, inverse
//		param dq_in: input dual quaternion
//		return: dq_out
//real4m ijkDualQuatInverseDQrm(real2x4 dq_out, real2x4 const dq_in);
#define ijkDualQuatInverseDQrm ijk_declrealfs(ijkDualQuatInverseDQ,m)

// ijkDualQuatInverseSafeDQ*m
//	Calculate inverse of dual quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param dq_out: output dual quaternion, inverse
//		param dq_in: input dual quaternion
//		return: dq_out
//real4m ijkDualQuatInverseSafeDQrm(real2x4 dq_out, real2x4 const dq_in);
#define ijkDualQuatInverseSafeDQrm ijk_declrealfs(ijkDualQuatInverseSafeDQ,m)

// ijkDualQuatMulVecDQ*m3
//	Calculate product of dual quaternion and 3D vector (result is dual quaternion).
//		param dq_out: output dual quaternion, product
//		param dq_lh: left-hand dual quaternion
//		param v_rh: right-hand vector
//		return: dq_out
//real4m ijkDualQuatMulVecDQrm3(real2x4 dq_out, real2x4 const dq_lh, real3 const v_rh);
#define ijkDualQuatMulVecDQrm3 ijk_declrealfs(ijkDualQuatMulVecDQ,m3)

// ijkDualQuatMulVecDQ*m3q
//	Calculate product of 3D vector and dual quaternion (result is dual quaternion).
//		param dq_out: output dual quaternion, product
//		param v_lh: left-hand vector
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
//real4m ijkDualQuatMulVecDQrm3q(real2x4 dq_out, real3 const v_lh, real2x4 const dq_rh);
#define ijkDualQuatMulVecDQrm3q ijk_declrealfs(ijkDualQuatMulVecDQ,m3q)

// ijkDualQuatMulDQ*m
//	Calculate product of dual quaternions, or concatenate unit dual quaternions
//	representing transformations.
//		param dq_out: output dual quaternion, product
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
//real4m ijkDualQuatMulDQrm(real2x4 dq_out, real2x4 const dq_lh, real2x4 const dq_rh);
#define ijkDualQuatMulDQrm ijk_declrealfs(ijkDualQuatMulDQ,m)

// ijkDualQuatMulScaleDQ*m
//	Correctly concatenate dual quaternions that represent transformations such 
//	that the right-hand input's translation is correctly affected by the left-
//	hand input's scale, when used to transform a vector later.
//		param dq_out: output dual quaternion
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
//real4m ijkDualQuatMulScaleDQrm(real2x4 dq_out, real2x4 const dq_lh, real2x4 const dq_rh);
#define ijkDualQuatMulScaleDQrm ijk_declrealfs(ijkDualQuatMulScaleDQ,m)

// ijkDualQuatDivDQ*m
//	Calculate quotient of dual quaternions (multiply by rh inverse).
//		param dq_out: output dual quaternion, quotient
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: dq_out
//real4m ijkDualQuatDivDQrm(real2x4 dq_out, real2x4 const dq_lh, real2x4 const dq_rh);
#define ijkDualQuatDivDQrm ijk_declrealfs(ijkDualQuatDivDQ,m)

// ijkDualQuatRotateDQ*m
//	Make rotation dual quaternion with Euler angles.
//		param dq_out: output dual quaternion, rotation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: dq_out
//real4m ijkDualQuatRotateDQrm(real2x4 dq_out, ijkRotationOrder const order, real3 const rotateDegXYZ);
#define ijkDualQuatRotateDQrm ijk_declrealfs(ijkDualQuatRotateDQ,m)

// ijkDualQuatAxisAngleDQ*m
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param dq_out: output dual quaternion, rotation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: dq_out
//real4m ijkDualQuatAxisAngleDQrm(real2x4 dq_out, real3 const axis_unit, real const angle_degrees);
#define ijkDualQuatAxisAngleDQrm ijk_declrealfs(ijkDualQuatAxisAngleDQ,m)

// ijkDualQuatScaleDQ*m
//	Make rotation dual quaternion with uniform scale.
//		param dq_out: output dual quaternion, scale
//		param scale_unif: uniform scale amount
//		return: dq_out
//real4m ijkDualQuatScaleDQrm(real2x4 dq_out, real const scale_unif);
#define ijkDualQuatScaleDQrm ijk_declrealfs(ijkDualQuatScaleDQ,m)

// ijkDualQuatRotateScaleDQ*m
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: dq_out
//real4m ijkDualQuatRotateScaleDQrm(real2x4 dq_out, ijkRotationOrder const order, real3 const rotateDegXYZ, real const scale_unif);
#define ijkDualQuatRotateScaleDQrm ijk_declrealfs(ijkDualQuatRotateScaleDQ,m)

// ijkDualQuatAxisAngleScaleDQ*m
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: dq_out
//real4m ijkDualQuatAxisAngleScaleDQrm(real2x4 dq_out, real3 const axis_unit, real const angle_degrees, real const scale_unif);
#define ijkDualQuatAxisAngleScaleDQrm ijk_declrealfs(ijkDualQuatAxisAngleScaleDQ,m)

// ijkDualQuatTranslateDQ*m
//	Make rotation dual quaternion with Euler angles.
//		param dq_out: output dual quaternion, translation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param translate: translation offset vector
//		return: dq_out
//real4m ijkDualQuatTranslateDQrm(real2x4 dq_out, real3 const translate);
#define ijkDualQuatTranslateDQrm ijk_declrealfs(ijkDualQuatTranslateDQ,m)

// ijkDualQuatRotateTranslateDQ*m
//	Make rotation dual quaternion with Euler angles.
//		param dq_out: output dual quaternion, rotation-translation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param translate: translation offset vector
//		return: dq_out
//real4m ijkDualQuatRotateTranslateDQrm(real2x4 dq_out, ijkRotationOrder const order, real3 const rotateDegXYZ, real3 const translate);
#define ijkDualQuatRotateTranslateDQrm ijk_declrealfs(ijkDualQuatRotateTranslateDQ,m)

// ijkDualQuatAxisAngleTranslateDQ*m
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param dq_out: output dual quaternion, rotation-translation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: dq_out
//real4m ijkDualQuatAxisAngleTranslateDQrm(real2x4 dq_out, real3 const axis_unit, real const angle_degrees, real3 const translate);
#define ijkDualQuatAxisAngleTranslateDQrm ijk_declrealfs(ijkDualQuatAxisAngleTranslateDQ,m)

// ijkDualQuatScaleTranslateDQ*m
//	Make rotation dual quaternion with uniform scale.
//		param dq_out: output dual quaternion, scale-translation
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: dq_out
//real4m ijkDualQuatScaleTranslateDQrm(real2x4 dq_out, real const scale_unif, real3 const translate);
#define ijkDualQuatScaleTranslateDQrm ijk_declrealfs(ijkDualQuatScaleTranslateDQ,m)

// ijkDualQuatRotateScaleTranslateDQ*m
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale-translation
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: dq_out
//real4m ijkDualQuatRotateScaleTranslateDQrm(real2x4 dq_out, ijkRotationOrder const order, real3 const rotateDegXYZ, real const scale_unif, real3 const translate);
#define ijkDualQuatRotateScaleTranslateDQrm ijk_declrealfs(ijkDualQuatRotateScaleTranslateDQ,m)

// ijkDualQuatAxisAngleScaleTranslateDQ*m
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param dq_out: output dual quaternion, rotation-scale-translation
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: dq_out
//real4m ijkDualQuatAxisAngleScaleTranslateDQrm(real2x4 dq_out, real3 const axis_unit, real const angle_degrees, real const scale_unif, real3 const translate);
#define ijkDualQuatAxisAngleScaleTranslateDQrm ijk_declrealfs(ijkDualQuatAxisAngleScaleTranslateDQ,m)

// ijkDualQuatGetRotateDQ*m
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: dq_in
//real4km ijkDualQuatGetRotateDQrm(real2x4 const dq_in, ijkRotationOrder const order, real3 rotateDegXYZ_out);
#define ijkDualQuatGetRotateDQrm ijk_declrealfs(ijkDualQuatGetRotateDQ,m)

// ijkDualQuatGetAxisAngleDQ*m
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: dq_in
//real4km ijkDualQuatGetAxisAngleDQrm(real2x4 const dq_in, real3 axis_unit_out, real* const angle_degrees_out);
#define ijkDualQuatGetAxisAngleDQrm ijk_declrealfs(ijkDualQuatGetAxisAngleDQ,m)

// ijkDualQuatGetScaleDQ*m
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
//real4km ijkDualQuatGetScaleDQrm(real2x4 const dq_in, real* const scale_unif_out);
#define ijkDualQuatGetScaleDQrm ijk_declrealfs(ijkDualQuatGetScaleDQ,m)

// ijkDualQuatGetRotateScaleDQ*m
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
//real4km ijkDualQuatGetRotateScaleDQrm(real2x4 const dq_in, ijkRotationOrder const order, real3 rotateDegXYZ_out, real* const scale_unif_out);
#define ijkDualQuatGetRotateScaleDQrm ijk_declrealfs(ijkDualQuatGetRotateScaleDQ,m)

// ijkDualQuatGetAxisAngleScaleDQ*m
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
//real4km ijkDualQuatGetAxisAngleScaleDQrm(real2x4 const dq_in, real3 axis_unit_out, real* const angle_degrees_out, real* const scale_unif_out);
#define ijkDualQuatGetAxisAngleScaleDQrm ijk_declrealfs(ijkDualQuatGetAxisAngleScaleDQ,m)

// ijkDualQuatGetTranslateDQ*m
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
//real4km ijkDualQuatGetTranslateDQrm(real2x4 const dq_in, real3 translate_out);
#define ijkDualQuatGetTranslateDQrm ijk_declrealfs(ijkDualQuatGetTranslateDQ,m)

// ijkDualQuatGetRotateTranslateDQ*m
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
//real4km ijkDualQuatGetRotateTranslateDQrm(real2x4 const dq_in, ijkRotationOrder const order, real3 rotateDegXYZ_out, real3 translate_out);
#define ijkDualQuatGetRotateTranslateDQrm ijk_declrealfs(ijkDualQuatGetRotateTranslateDQ,m)

// ijkDualQuatGetAxisAngleTranslateDQ*m
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
//real4km ijkDualQuatGetAxisAngleTranslateDQrm(real2x4 const dq_in, real3 axis_unit_out, real* const angle_degrees_out, real3 translate_out);
#define ijkDualQuatGetAxisAngleTranslateDQrm ijk_declrealfs(ijkDualQuatGetAxisAngleTranslateDQ,m)

// ijkDualQuatGetScaleTranslateDQ*m
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
//real4km ijkDualQuatGetScaleTranslateDQrm(real2x4 const dq_in, real* const scale_unif_out, real3 translate_out);
#define ijkDualQuatGetScaleTranslateDQrm ijk_declrealfs(ijkDualQuatGetScaleTranslateDQ,m)

// ijkDualQuatGetRotateScaleTranslateDQ*m
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
//real4km ijkDualQuatGetRotateScaleTranslateDQrm(real2x4 const dq_in, ijkRotationOrder const order, real3 rotateDegXYZ_out, real* const scale_unif_out, real3 translate_out);
#define ijkDualQuatGetRotateScaleTranslateDQrm ijk_declrealfs(ijkDualQuatGetRotateScaleTranslateDQ,m)

// ijkDualQuatGetAxisAngleScaleTranslateDQ*m
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
//real4km ijkDualQuatGetAxisAngleScaleTranslateDQrm(real2x4 const dq_in, real3 axis_unit_out, real* const angle_degrees_out, real* const scale_unif_out, real3 translate_out);
#define ijkDualQuatGetAxisAngleScaleTranslateDQrm ijk_declrealfs(ijkDualQuatGetAxisAngleScaleTranslateDQ,m)

// ijkDualQuatGetTranslateRemScaleDQ*m
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
//real4km ijkDualQuatGetTranslateRemScaleDQrm(real2x4 const dq_in, real3 translate_out);
#define ijkDualQuatGetTranslateRemScaleDQrm ijk_declrealfs(ijkDualQuatGetTranslateRemScaleDQ,m)

// ijkDualQuatGetRotateTranslateRemScaleDQ*m
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
//real4km ijkDualQuatGetRotateTranslateRemScaleDQrm(real2x4 const dq_in, ijkRotationOrder const order, real3 rotateDegXYZ_out, real3 translate_out);
#define ijkDualQuatGetRotateTranslateRemScaleDQrm ijk_declrealfs(ijkDualQuatGetRotateTranslateRemScaleDQ,m)

// ijkDualQuatGetAxisAngleTranslateRemScaleDQ*m
//	Extract unit axis and angle in degrees from dual quaternion, removing 
//	scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
//real4km ijkDualQuatGetAxisAngleTranslateRemScaleDQrm(real2x4 const dq_in, real3 axis_unit_out, real* const angle_degrees_out, real3 translate_out);
#define ijkDualQuatGetAxisAngleTranslateRemScaleDQrm ijk_declrealfs(ijkDualQuatGetAxisAngleTranslateRemScaleDQ,m)

// ijkDualQuatGetScaleTranslateRemScaleDQ*m
//	Extract uniform scale from dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
//real4km ijkDualQuatGetScaleTranslateRemScaleDQrm(real2x4 const dq_in, real* const scale_unif_out, real3 translate_out);
#define ijkDualQuatGetScaleTranslateRemScaleDQrm ijk_declrealfs(ijkDualQuatGetScaleTranslateRemScaleDQ,m)

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
//real4km ijkDualQuatGetRotateScaleTranslateRemScaleDQrm(real2x4 const dq_in, ijkRotationOrder const order, real3 rotateDegXYZ_out, real* const scale_unif_out, real3 translate_out);
#define ijkDualQuatGetRotateScaleTranslateRemScaleDQrm ijk_declrealfs(ijkDualQuatGetRotateScaleTranslateRemScaleDQ,m)

// ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQ*m
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion,
//	removing scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
//real4km ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQrm(real2x4 const dq_in, real3 axis_unit_out, real* const angle_degrees_out, real* const scale_unif_out, real3 translate_out);
#define ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQrm ijk_declrealfs(ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQ,m)

// ijkDualQuatGetScrewParamsDQ*m
//	Extract screw parameters from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		param momentArm_out: storage for moment arm
//		param screwDisplace_out: storage for screw displacement parameter
//		return: dq_in
//real4km ijkDualQuatGetScrewParamsDQrm(real2x4 const dq_in, real3 axis_unit_out, real* const angle_degrees_out, real3 translate_out, real3 momentArm_out, real* const screwDisplace_out);
#define ijkDualQuatGetScrewParamsDQrm ijk_declrealfs(ijkDualQuatGetScrewParamsDQ,m)

// ijkDualQuatGetMatDQ*m3
//	Convert dual quaternion's real part to 3D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
//real3m ijkDualQuatGetMatDQrm3(real3x3 m_out, real2x4 const dq_in);
#define ijkDualQuatGetMatDQrm3 ijk_declrealfs(ijkDualQuatGetMatDQ,m3)

// ijkDualQuatUnitGetMatDQ*m3
//	Convert unit dual quaternion's real part to 3D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
//real3m ijkDualQuatUnitGetMatDQrm3(real3x3 m_out, real2x4 const dq_in);
#define ijkDualQuatUnitGetMatDQrm3 ijk_declrealfs(ijkDualQuatUnitGetMatDQ,m3)

// ijkDualQuatGetMatTranslateDQ*m3
//	Convert dual quaternion's real part to 3D matrix and extract translation.
//		param m_out: output matrix
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: m_out
//real3m ijkDualQuatGetMatTranslateDQrm3(real3x3 m_out, real3 translate_out, real2x4 const dq_in);
#define ijkDualQuatGetMatTranslateDQrm3 ijk_declrealfs(ijkDualQuatGetMatTranslateDQ,m3)

// ijkDualQuatUnitGetMatTranslateDQ*m3
//	Convert unit dual quaternion's real part to 3D matrix and extract 
//	translation.
//		param m_out: output matrix
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: m_out
//real3m ijkDualQuatUnitGetMatTranslateDQrm3(real3x3 m_out, real3 translate_out, real2x4 const dq_in);
#define ijkDualQuatUnitGetMatTranslateDQrm3 ijk_declrealfs(ijkDualQuatUnitGetMatTranslateDQ,m3)

// ijkDualQuatGetMatTranslateRemScaleDQ*m3
//	Convert dual quaternion's real part to 3D matrix and extract translation 
//	with scale removed.
//		param m_out: output matrix
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: m_out
//real3m ijkDualQuatGetMatTranslateRemScaleDQrm3(real3x3 m_out, real3 translate_out, real2x4 const dq_in);
#define ijkDualQuatGetMatTranslateRemScaleDQrm3 ijk_declrealfs(ijkDualQuatGetMatTranslateRemScaleDQ,m3)

// ijkDualQuatGetMatDQ*m4
//	Convert dual quaternion to 4D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
//real4m ijkDualQuatGetMatDQrm4(real4x4 m_out, real2x4 const dq_in);
#define ijkDualQuatGetMatDQrm4 ijk_declrealfs(ijkDualQuatGetMatDQ,m4)

// ijkDualQuatUnitGetMatDQ*m4
//	Convert unit dual quaternion to 4D matrix.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
//real4m ijkDualQuatUnitGetMatDQrm4(real4x4 m_out, real2x4 const dq_in);
#define ijkDualQuatUnitGetMatDQrm4 ijk_declrealfs(ijkDualQuatUnitGetMatDQ,m4)

// ijkDualQuatGetMatTranslateRemScaleDQ*m4
//	Convert dual quaternion to 4D matrix, scale removed from translation part.
//		param m_out: output matrix
//		param dq_in: input dual quaternion
//		return: m_out
//real4m ijkDualQuatGetMatTranslateRemScaleDQrm4(real4x4 m_out, real2x4 const dq_in);
#define ijkDualQuatGetMatTranslateRemScaleDQrm4 ijk_declrealfs(ijkDualQuatGetMatTranslateRemScaleDQ,m4)

// ijkDualQuatTransformScaleVecDQ*m3
//	Transform a 3D vector using a dual quaternion with scale; use when dual 
//	quaternion has scale to prevent translation part from being scaled.
//		param v_out: output vector
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: v_out
//realv ijkDualQuatTransformScaleVecDQrm3(real3 v_out, real2x4 const dq_in, real3 const v_in);
#define ijkDualQuatTransformScaleVecDQrm3 ijk_declrealfs(ijkDualQuatTransformScaleVecDQ,m3)

// ijkDualQuatUnitTransformVecDQ*m3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	unit-length for most optimized solution or when translation part should 
//	also be scaled.
//		param v_out: output vector
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: v_out
//realv ijkDualQuatUnitTransformVecDQrm3(real3 v_out, real2x4 const dq_in, real3 const v_in);
#define ijkDualQuatUnitTransformVecDQrm3 ijk_declrealfs(ijkDualQuatUnitTransformVecDQ,m3)

// ijkDualQuatTransformVecDQ*m3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	non-unit length to remove scale from all parts.
//		param v_out: output vector
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: v_out
//realv ijkDualQuatTransformVecDQrm3(real3 v_out, real2x4 const dq_in, real3 const v_in);
#define ijkDualQuatTransformVecDQrm3 ijk_declrealfs(ijkDualQuatTransformVecDQ,m3)

// ijkDualQuatLerpDQ*m
//	Calculate linear interpolation between two dual quaternions; yields uniform
//	rate of change but affects translation path and scale.
//		param dq_out: output dual quaternion, interpolated dual quaternion
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: dq_out
//real4m ijkDualQuatLerpDQrm(real2x4 dq_out, real2x4 const dq0, real2x4 const dq1, real const u);
#define ijkDualQuatLerpDQrm ijk_declrealfs(ijkDualQuatLerpDQ,m)

// ijkDualQuatNlerpDQ*m
//	Calculate normalized linear interpolation between two dual quaternions; 
//	keeps result at unit-length but yields a non-uniform rate of change.
//		param dq_out: output dual quaternion, interpolated dual quaternion
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: dq_out
//real4m ijkDualQuatNlerpDQrm(real2x4 dq_out, real2x4 const dq0, real2x4 const dq1, real const u);
#define ijkDualQuatNlerpDQrm ijk_declrealfs(ijkDualQuatNlerpDQ,m)

// ijkDualQuatSclerpDQ*m
//	Calculate screw linear interpolation between two unit dual quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param dq_out: output dual quaternion, interpolated dual quaternion
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: dq_out
//real4m ijkDualQuatSclerpDQrm(real2x4 dq_out, real2x4 const dq0, real2x4 const dq1, real const u);
#define ijkDualQuatSclerpDQrm ijk_declrealfs(ijkDualQuatSclerpDQ,m)

// ijkDualQuatDerivDQ*m
//	Calculate derivative of dual quaternion.
//		param dq1_out: output dual quaternion, derivative of dual quaternion
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param angularVelocity: angular velocity vector
//		return: dq1_out
//real4m ijkDualQuatDerivDQrm(real2x4 dq1_out, real2x4 const dq_in, real3 const linearVelocity, real3 const angularVelocity);
#define ijkDualQuatDerivDQrm ijk_declrealfs(ijkDualQuatDerivDQ,m)

// ijkDualQuatDeriv2DQ*m
//	Calculate second derivative of dual quaternion.
//		param dq2_out: output dual quaternion, second derivative of dual quaternion
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param linearAcceleration: linear acceleration vector
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: dq2_out
//real4m ijkDualQuatDeriv2DQrm(real2x4 dq2_out, real2x4 const dq_in, real3 const linearVelocity, real3 const linearAcceleration, real3 const angularVelocity, real3 const angularAcceleration);
#define ijkDualQuatDeriv2DQrm ijk_declrealfs(ijkDualQuatDeriv2DQ,m)


//-----------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif	// __cplusplus


//-----------------------------------------------------------------------------

// ijkQuatInitQ*
//	Initialize identity quaternion (zero vector, one real).
//		return: identity quaternion
//rquat ijkQuatInitQr();
#define ijkQuatInitQr ijk_declrealfs(ijkQuatInitQ,)

// ijkQuatInitZeroQ*
//	Initialize zero quaternion.
//		return: zero quaternion
//rquat ijkQuatInitZeroQr();
#define ijkQuatInitZeroQr ijk_declrealfs(ijkQuatInitZeroQ,)

// ijkQuatInitElemsQ*
//	Initialize individual elements of quaternion.
//		params x, y, z, w: components
//		return: xyzw quaternion
//rquat ijkQuatInitElemsQr(real const x, real const y, real const z, real const w);
#define ijkQuatInitElemsQr ijk_declrealfs(ijkQuatInitElemsQ,)

// ijkQuatInitVecReQ*
//	Initialize quaternion with vector and real parts.
//		param vec: vector components (xyz)
//		param re: real component (w)
//		return: output quaternion
//rquat ijkQuatInitVecReQr(rvec3 const vec, real const re);
#define ijkQuatInitVecReQr ijk_declrealfs(ijkQuatInitVecReQ,)

// ijkQuatInitVecProductQ*
//	Initialize quaternion as product of two vectors.
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: output quaternion
//rquat ijkQuatInitVecProductQr(rvec3 const v_lh, rvec3 const v_rh);
#define ijkQuatInitVecProductQr ijk_declrealfs(ijkQuatInitVecProductQ,)

// ijkQuatInitVecProductSqrtQ*
//	Initialize quaternion as product square root of two vectors.
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: output quaternion
//rquat ijkQuatInitVecProductSqrtQr(rvec3 const v_lh, rvec3 const v_rh);
#define ijkQuatInitVecProductSqrtQr ijk_declrealfs(ijkQuatInitVecProductSqrtQ,)

// ijkQuatInitVecProductSqrtUnitQ*
//	Initialize quaternion as product square root of two unit vectors.
//		param v_lh: left-hand vector
//		param v_rh: left-hand vector
//		return: output quaternion
//rquat ijkQuatInitVecProductSqrtUnitQr(rvec3 const v_lh, rvec3 const v_rh);
#define ijkQuatInitVecProductSqrtUnitQr ijk_declrealfs(ijkQuatInitVecProductSqrtUnitQ,)

// ijkQuatInitMatQ*3
//	Initialize quaternion from 3D matrix.
//		param m_in: input matrix
//		return: output quaternion
//rquat ijkQuatInitMatQr3(rmat3 const m_in);
#define ijkQuatInitMatQr3 ijk_declrealfs(ijkQuatInitMatQ,3)

// ijkQuatInitMatQ*4
//	Initialize quaternion from 4D matrix.
//		param m_in: input matrix
//		return: output quaternion
//rquat ijkQuatInitMatQr4(rmat4 const m_in);
#define ijkQuatInitMatQr4 ijk_declrealfs(ijkQuatInitMatQ,4)

// ijkQuatCopyQ*
//	Copy quaternion.
//		param q_in: input quaternion
//		return: copy
//rquat ijkQuatCopyQr(rquat const q_in);
#define ijkQuatCopyQr ijk_declrealfs(ijkQuatCopyQ,)

// ijkQuatNegateQ*
//	Negate quaternion.
//		param q_in: input quaternion
//		return: negative quaternion
//rquat ijkQuatNegateQr(rquat const q_in);
#define ijkQuatNegateQr ijk_declrealfs(ijkQuatNegateQ,)

// ijkQuatConjugateQ*
//	Conjugate quaternion: negate vector part, copy real part.
//		param q_in: input quaternion
//		return: conjugate quaternion
//rquat ijkQuatConjugateQr(rquat const q_in);
#define ijkQuatConjugateQr ijk_declrealfs(ijkQuatConjugateQ,)

// ijkQuatConjugateMulQ*s
//	Conjugate quaternion: negate vector part, copy real part, multiply by 
//	scalar.
//		param q_in: input quaternion
//		return: scaled conjugate quaternion
//rquat ijkQuatConjugateMulQrs(rquat const q_in, real const s);
#define ijkQuatConjugateMulQrs ijk_declrealfs(ijkQuatConjugateMulQ,s)

// ijkQuatNegateConjugateQ*
//	Negate and conjugate quaternion: negate real part, copy vector part.
//		param q_in: input quaternion
//		return: negative conjugate quaternion
//rquat ijkQuatNegateConjugateQr(rquat const q_in);
#define ijkQuatNegateConjugateQr ijk_declrealfs(ijkQuatNegateConjugateQ,)

// ijkQuatNegateConjugateMulQ*s
//	Negate and conjugate quaternion: negate real part, copy vector part, 
//	multiply by scalar.
//		param q_in: input quaternion
//		return: scaled negative conjugate quaternion
//rquat ijkQuatNegateConjugateMulQrs(rquat const q_in, real const s);
#define ijkQuatNegateConjugateMulQrs ijk_declrealfs(ijkQuatNegateConjugateMulQ,s)

// ijkQuatAddQ*
//	Calculate sum of quaternions.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: sum quaternion
//rquat ijkQuatAddQr(rquat const q_lh, rquat const q_rh);
#define ijkQuatAddQr ijk_declrealfs(ijkQuatAddQ,)

// ijkQuatSubQ*
//	Calculate difference of quaternions.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: difference quaternion
//rquat ijkQuatSubQr(rquat const q_lh, rquat const q_rh);
#define ijkQuatSubQr ijk_declrealfs(ijkQuatSubQ,)

// ijkQuatMulQ*s
//	Calculate product of quaternion and scalar.
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: product quaternion
//rquat ijkQuatMulQrs(rquat const q_lh, real const s_rh);
#define ijkQuatMulQrs ijk_declrealfs(ijkQuatMulQ,s)

// ijkQuatDivQ*s
//	Calculate quotient of quaternion and scalar.
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: quotient quaternion
//rquat ijkQuatDivQrs(rquat const q_lh, real const s_rh);
#define ijkQuatDivQrs ijk_declrealfs(ijkQuatDivQ,s)

// ijkQuatDivSafeQ*s
//	Calculate quotient of quaternion and scalar; division-by-zero safety.
//		param q_lh: left-hand quaternion
//		param s_rh: right-hand scalar
//		return: quotient quaternion
//rquat ijkQuatDivSafeQrs(rquat const q_lh, real const s_rh);
#define ijkQuatDivSafeQrs ijk_declrealfs(ijkQuatDivSafeQ,s)

// ijkQuatLengthSqQ*
//	Calculate squared length of quaternion.
//		param q_in: input quaternion
//		return: squared length
//real ijkQuatLengthSqQr(rquat const q_in);
#define ijkQuatLengthSqQr ijk_declrealfs(ijkQuatLengthSqQ,)

// ijkQuatLengthQ*
//	Calculate length of quaternion.
//		param q_in: input quaternion
//		return: length
//real ijkQuatLengthQr(rquat const q_in);
#define ijkQuatLengthQr ijk_declrealfs(ijkQuatLengthQ,)

// ijkQuatLengthSqInvQ*
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
//real ijkQuatLengthSqInvQr(rquat const q_in);
#define ijkQuatLengthSqInvQr ijk_declrealfs(ijkQuatLengthSqInvQ,)

// ijkQuatLengthInvQ*
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
//real ijkQuatLengthInvQr(rquat const q_in);
#define ijkQuatLengthInvQr ijk_declrealfs(ijkQuatLengthInvQ,)

// ijkQuatLengthSqInvSafeQ*
//	Calculate inverse squared length of quaternion.
//		param q_in: input quaternion
//		return: inverse squared length
//real ijkQuatLengthSqInvSafeQr(rquat const q_in);
#define ijkQuatLengthSqInvSafeQr ijk_declrealfs(ijkQuatLengthSqInvSafeQ,)

// ijkQuatLengthInvSafeQ*
//	Calculate inverse length of quaternion.
//		param q_in: input quaternion
//		return: inverse length
//real ijkQuatLengthInvSafeQr(rquat const q_in);
#define ijkQuatLengthInvSafeQr ijk_declrealfs(ijkQuatLengthInvSafeQ,)

// ijkQuatNormalizeQ*
//	Normalize quaternion.
//		param q_in: input quaternion
//		return: unit quaternion
//rquat ijkQuatNormalizeQr(rquat const q_in);
#define ijkQuatNormalizeQr ijk_declrealfs(ijkQuatNormalizeQ,)

// ijkQuatNormalizeSafeQ*
//	Normalize quaternion; division-by-zero safety.
//		param q_in: input quaternion
//		return: unit quaternion
//rquat ijkQuatNormalizeSafeQr(rquat const q_in);
#define ijkQuatNormalizeSafeQr ijk_declrealfs(ijkQuatNormalizeSafeQ,)

// ijkQuatInverseQ*
//	Calculate inverse of quaternion: conjugate divided by squared length.
//		param q_in: input quaternion
//		return: inverse quaternion
//rquat ijkQuatInverseQr(rquat const q_in);
#define ijkQuatInverseQr ijk_declrealfs(ijkQuatInverseQ,)

// ijkQuatInverseSafeQ*
//	Calculate inverse of quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param q_in: input quaternion
//		return: inverse quaternion
//rquat ijkQuatInverseSafeQr(rquat const q_in);
#define ijkQuatInverseSafeQr ijk_declrealfs(ijkQuatInverseSafeQ,)

// ijkQuatMulVecQ*3
//	Calculate product of quaternion and 3D vector (result is quaternion).
//		param q_lh: left-hand quaternion
//		param v_rh: right-hand vector
//		return: product quaternion
//rquat ijkQuatMulVecQr3(rquat const q_lh, rvec3 const v_rh);
#define ijkQuatMulVecQr3 ijk_declrealfs(ijkQuatMulVecQ,3)

// ijkQuatMulVecQ*3q
//	Calculate product of 3D vector and quaternion (result is quaternion).
//		param v_lh: left-hand vector
//		param q_rh: right-hand quaternion
//		return: product quaternion
//rquat ijkQuatMulVecQr3q(rvec3 const v_lh, rquat const q_rh);
#define ijkQuatMulVecQr3q ijk_declrealfs(ijkQuatMulVecQ,3q)

// ijkQuatMulQ*
//	Calculate product of quaternions.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: product quaternion
//rquat ijkQuatMulQr(rquat const q_lh, rquat const q_rh);
#define ijkQuatMulQr ijk_declrealfs(ijkQuatMulQ,)

// ijkQuatMulConjQ*
//	Calculate product of quaternion with quaternion conjugate.
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion, conjugated before multiplying
//		return: product quaternion
//rquat ijkQuatMulConjQr(rquat const q_lh, rquat const q_rh);
#define ijkQuatMulConjQr ijk_declrealfs(ijkQuatMulConjQ,)

// ijkQuatConjMulQ*
//	Calculate product of quaternion conjugate with quaternion.
//		param q_lh: left-hand quaternion, conjugated before multiplying
//		param q_rh: right-hand quaternion
//		return: product quaternion
//rquat ijkQuatConjMulQr(rquat const q_lh, rquat const q_rh);
#define ijkQuatConjMulQr ijk_declrealfs(ijkQuatConjMulQ,)

// ijkQuatDivQ*
//	Calculate quotient of quaternions (multiply by rh inverse).
//		param q_lh: left-hand quaternion
//		param q_rh: right-hand quaternion
//		return: quotient quaternion
//rquat ijkQuatDivQr(rquat const q_lh, rquat const q_rh);
#define ijkQuatDivQr ijk_declrealfs(ijkQuatDivQ,)

// ijkQuatRotateXYZQ*
//	Make rotation quaternion with Euler angles in written order XYZ, meaning 
//	the order of operations is Z then Y then X.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
//rquat ijkQuatRotateXYZQr(rvec3 const rotateDegXYZ);
#define ijkQuatRotateXYZQr ijk_declrealfs(ijkQuatRotateXYZQ,)

// ijkQuatRotateYZXQ*
//	Make rotation quaternion with Euler angles in written order YZX, meaning 
//	the order of operations is X then Z then Y.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
//rquat ijkQuatRotateYZXQr(rvec3 const rotateDegXYZ);
#define ijkQuatRotateYZXQr ijk_declrealfs(ijkQuatRotateYZXQ,)

// ijkQuatRotateZXYQ*
//	Make rotation quaternion with Euler angles in written order ZXY, meaning 
//	the order of operations is Y then X then Z.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
//rquat ijkQuatRotateZXYQr(rvec3 const rotateDegXYZ);
#define ijkQuatRotateZXYQr ijk_declrealfs(ijkQuatRotateZXYQ,)

// ijkQuatRotateYXZQ*
//	Make rotation quaternion with Euler angles in written order YXZ, meaning 
//	the order of operations is Z then X then Y.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
//rquat ijkQuatRotateYXZQr(rvec3 const rotateDegXYZ);
#define ijkQuatRotateYXZQr ijk_declrealfs(ijkQuatRotateYXZQ,)

// ijkQuatRotateXZYQ*
//	Make rotation quaternion with Euler angles in written order XZY, meaning 
//	the order of operations is X then Z then Y.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
//rquat ijkQuatRotateXZYQr(rvec3 const rotateDegXYZ);
#define ijkQuatRotateXZYQr ijk_declrealfs(ijkQuatRotateXZYQ,)

// ijkQuatRotateZYXQ*
//	Make rotation quaternion with Euler angles in written order ZYX, meaning 
//	the order of operations is X then Y then Z.
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
//rquat ijkQuatRotateZYXQr(rvec3 const rotateDegXYZ);
#define ijkQuatRotateZYXQr ijk_declrealfs(ijkQuatRotateZYXQ,)

// ijkQuatGetRotateXYZQ*
//	Extract Euler angles from rotation quaternion; written order XYZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//rquat ijkQuatGetRotateXYZQr(rquat const q_in, rvec3* const rotateDegXYZ_out);
#define ijkQuatGetRotateXYZQr ijk_declrealfs(ijkQuatGetRotateXYZQ,)

// ijkQuatGetRotateYZXQ*
//	Extract Euler angles from rotation quaternion; written order YZX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//rquat ijkQuatGetRotateYZXQr(rquat const q_in, rvec3* const rotateDegXYZ_out);
#define ijkQuatGetRotateYZXQr ijk_declrealfs(ijkQuatGetRotateYZXQ,)

// ijkQuatGetRotateZXYQ*
//	Extract Euler angles from rotation quaternion; written order ZXY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//rquat ijkQuatGetRotateZXYQr(rquat const q_in, rvec3* const rotateDegXYZ_out);
#define ijkQuatGetRotateZXYQr ijk_declrealfs(ijkQuatGetRotateZXYQ,)

// ijkQuatGetRotateYXZQ*
//	Extract Euler angles from rotation quaternion; written order YXZ.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//rquat ijkQuatGetRotateYXZQr(rquat const q_in, rvec3* const rotateDegXYZ_out);
#define ijkQuatGetRotateYXZQr ijk_declrealfs(ijkQuatGetRotateYXZQ,)

// ijkQuatGetRotateXZYQ*
//	Extract Euler angles from rotation quaternion; written order XZY.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//rquat ijkQuatGetRotateXZYQr(rquat const q_in, rvec3* const rotateDegXYZ_out);
#define ijkQuatGetRotateXZYQr ijk_declrealfs(ijkQuatGetRotateXZYQ,)

// ijkQuatGetRotateZYXQ*
//	Extract Euler angles from rotation quaternion; written order ZYX.
//		param q_in: input quaternion
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//rquat ijkQuatGetRotateZYXQr(rquat const q_in, rvec3* const rotateDegXYZ_out);
#define ijkQuatGetRotateZYXQr ijk_declrealfs(ijkQuatGetRotateZYXQ,)

// ijkQuatRotateQ*
//	Make rotation quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation quaternion
//rquat ijkQuatRotateQr(ijkRotationOrder const order, rvec3 const rotateDegXYZ);
#define ijkQuatRotateQr ijk_declrealfs(ijkQuatRotateQ,)

// ijkQuatAxisAngleQ*
//	Make rotation quaternion with unit axis and angle in degrees.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation quaternion
//rquat ijkQuatAxisAngleQr(rvec3 const axis_unit, real const angle_degrees);
#define ijkQuatAxisAngleQr ijk_declrealfs(ijkQuatAxisAngleQ,)

// ijkQuatScaleQ*
//	Make rotation quaternion with uniform scale.
//		param scale_unif: uniform scale amount
//		return: scale quaternion
//rquat ijkQuatScaleQr(real const scale_unif);
#define ijkQuatScaleQr ijk_declrealfs(ijkQuatScaleQ,)

// ijkQuatRotateScaleQ*
//	Make rotation quaternion with Euler angles and uniform scale.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: rotation-scale quaternion
//rquat ijkQuatRotateScaleQr(ijkRotationOrder const order, rvec3 const rotateDegXYZ, real const scale_unif);
#define ijkQuatRotateScaleQr ijk_declrealfs(ijkQuatRotateScaleQ,)

// ijkQuatAxisAngleScaleQ*
//	Make rotation quaternion with unit axis, angle in degrees and uniform scale.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: rotation-scale quaternion
//rquat ijkQuatAxisAngleScaleQr(rvec3 const axis_unit, real const angle_degrees, real const scale_unif);
#define ijkQuatAxisAngleScaleQr ijk_declrealfs(ijkQuatAxisAngleScaleQ,)

// ijkQuatGetRotateQ*
//	Extract Euler angles from rotation quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: q_in
//rquat ijkQuatGetRotateQr(rquat const q_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out);
#define ijkQuatGetRotateQr ijk_declrealfs(ijkQuatGetRotateQ,)

// ijkQuatGetAxisAngleQ*
//	Extract unit axis and angle in degrees from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: q_in
//rquat ijkQuatGetAxisAngleQr(rquat const q_in, rvec3* const axis_unit_out, real* const angle_degrees_out);
#define ijkQuatGetAxisAngleQr ijk_declrealfs(ijkQuatGetAxisAngleQ,)

// ijkQuatGetScaleQ*
//	Extract uniform scale from quaternion.
//		param q_in: input quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
//rquat ijkQuatGetScaleQr(rquat const q_in, real* const scale_unif_out);
#define ijkQuatGetScaleQr ijk_declrealfs(ijkQuatGetScaleQ,)

// ijkQuatGetRotateScaleQ*
//	Extract Euler angles and uniform scale from quaternion.
//		param q_in: input quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
//rquat ijkQuatGetRotateScaleQr(rquat const q_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out, real* const scale_unif_out);
#define ijkQuatGetRotateScaleQr ijk_declrealfs(ijkQuatGetRotateScaleQ,)

// ijkQuatGetAxisAngleScaleQ*
//	Extract unit axis, angle in degrees and uniform scale from quaternion.
//		param q_in: input quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: q_in
//rquat ijkQuatGetAxisAngleScaleQr(rquat const q_in, rvec3* const axis_unit_out, real* const angle_degrees_out, real* const scale_unif_out);
#define ijkQuatGetAxisAngleScaleQr ijk_declrealfs(ijkQuatGetAxisAngleScaleQ,)

// ijkQuatGetMatQ*3
//	Convert quaternion to 3D matrix.
//		param q_in: input quaternion
//		return: output matrix
//rmat3 ijkQuatGetMatQr3(rquat const q_in);
#define ijkQuatGetMatQr3 ijk_declrealfs(ijkQuatGetMatQ,3)

// ijkQuatUnitGetMatQ*3
//	Convert unit quaternion to 3D matrix.
//		param q_in: input quaternion
//		return: output matrix
//rmat3 ijkQuatUnitGetMatQr3(rquat const q_in);
#define ijkQuatUnitGetMatQr3 ijk_declrealfs(ijkQuatUnitGetMatQ,3)

// ijkQuatGetMatQ*4
//	Convert quaternion to 4D matrix.
//		param q_in: input quaternion
//		return: output matrix
//rmat4 ijkQuatGetMatQr4(rquat const q_in);
#define ijkQuatGetMatQr4 ijk_declrealfs(ijkQuatGetMatQ,4)

// ijkQuatUnitGetMatQ*4
//	Convert unit quaternion to 4D matrix.
//		param q_in: input quaternion
//		return: output matrix
//rmat4 ijkQuatUnitGetMatQr4(rquat const q_in);
#define ijkQuatUnitGetMatQr4 ijk_declrealfs(ijkQuatUnitGetMatQ,4)

// ijkQuatGetMatQ*4t
//	Convert quaternion to 4D matrix, with additional translation vector.
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: output matrix
//rmat4 ijkQuatGetMatQr4t(rquat const q_in, rvec3 const translate);
#define ijkQuatGetMatQr4t ijk_declrealfs(ijkQuatGetMatQ,4t)

// ijkQuatUnitGetMatQ*4t
//	Convert unit quaternion to 4D matrix, with additional translation vector.
//		param q_in: input quaternion
//		param translate: translation offset vector
//		return: output matrix
//rmat4 ijkQuatUnitGetMatQr4t(rquat const q_in, rvec3 const translate);
#define ijkQuatUnitGetMatQr4t ijk_declrealfs(ijkQuatUnitGetMatQ,4t)

// ijkQuatRotateScaleVecQ*3
//	Rotate and/or scale a 3D vector using a quaternion; result will not be 
//	divided by squared magnitude.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: rotated vector
//rvec3 ijkQuatRotateScaleVecQr3(rquat const q_in, rvec3 const v_in);
#define ijkQuatRotateScaleVecQr3 ijk_declrealfs(ijkQuatRotateScaleVecQ,3)

// ijkQuatUnitRotateVecQ*3
//	Rotate a 3D vector using a quaternion; use with unit quaternion for most 
//	optimized solution.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: rotated vector
//rvec3 ijkQuatUnitRotateVecQr3(rquat const q_in, rvec3 const v_in);
#define ijkQuatUnitRotateVecQr3 ijk_declrealfs(ijkQuatUnitRotateVecQ,3)

// ijkQuatRotateVecQ*3
//	Rotate a 3D vector using a quaternion; use this when the input quaternion 
//	is non-unit length so that the result will only be rotated.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: rotated vector
//rvec3 ijkQuatRotateVecQr3(rquat const q_in, rvec3 const v_in);
#define ijkQuatRotateVecQr3 ijk_declrealfs(ijkQuatRotateVecQ,3)

// ijkQuatReflectScaleQ*
//	Reflect and/or scale a quaternion about an axis.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: reflected quaternion
//rquat ijkQuatReflectScaleQr(rquat const q_in, rvec3 const v_in);
#define ijkQuatReflectScaleQr ijk_declrealfs(ijkQuatReflectScaleQ,)

// ijkQuatUnitReflectQ*
//	Reflect a unit quaternion about an axis; optimized for unit quaternions.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: reflected quaternion
//rquat ijkQuatUnitReflectQr(rquat const q_in, rvec3 const v_in);
#define ijkQuatUnitReflectQr ijk_declrealfs(ijkQuatUnitReflectQ,)

// ijkQuatReflectQ*
//	Reflect a non-unit quaternion about an axis.
//		param q_in: input quaternion
//		param v_in: input vector
//		return: reflected quaternion
//rquat ijkQuatReflectQr(rquat const q_in, rvec3 const v_in);
#define ijkQuatReflectQr ijk_declrealfs(ijkQuatReflectQ,)

// ijkQuatExpQ*
//	Calculate quaternion as natural exponent base (e) raised to vector power.
//		param v_in: input vector
//		return: exp
//rquat ijkQuatExpQr(rvec3 const v_in);
#define ijkQuatExpQr ijk_declrealfs(ijkQuatExpQ,)

// ijkQuatLnQ*
//	Calculate quaternion or vector as natural logarithm of quaternion.
//		param q_in: input quaternion
//		return: ln
//rquat ijkQuatLnQr(rquat const q_in);
#define ijkQuatLnQr ijk_declrealfs(ijkQuatLnQ,)

// ijkQuatPowQ*
//	Calculate quaternion raised to power of exponent.
//		param q_in: input quaternion
//		param u: exponent
//		return: pow
//rquat ijkQuatPowQr(rquat const q_in, real const u);
#define ijkQuatPowQr ijk_declrealfs(ijkQuatPowQ,)

// ijkQuatSqrtQ*
//	Calculate square root of quaternion.
//		param q_in: input quaternion
//		return: sqrt
//rquat ijkQuatSqrtQr(rquat const q_in);
#define ijkQuatSqrtQr ijk_declrealfs(ijkQuatSqrtQ,)

// ijkQuatLerpQ*
//	Calculate linear interpolation between two quaternions; yields a uniform 
//	rate of change but affects encoded scale.
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: interpolated quaternion
//rquat ijkQuatLerpQr(rquat const q0, rquat const q1, real const u);
#define ijkQuatLerpQr ijk_declrealfs(ijkQuatLerpQ,)

// ijkQuatNlerpQ*
//	Calculate normalized linear interpolation between two quaternions; keeps 
//	result at unit-length but yields a non-uniform rate of change.
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: interpolated quaternion
//rquat ijkQuatNlerpQr(rquat const q0, rquat const q1, real const u);
#define ijkQuatNlerpQr ijk_declrealfs(ijkQuatNlerpQ,)

// ijkQuatSlerpQ*
//	Calculate spherical linear interpolation between two unit quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param q0: input initial control quaternion, result when param is 0
//		param q1: input terminal control quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [q0,q1], others result in extrapolation
//		return: interpolated quaternion
//rquat ijkQuatSlerpQr(rquat const q0, rquat const q1, real const u);
#define ijkQuatSlerpQr ijk_declrealfs(ijkQuatSlerpQ,)

// ijkQuatDerivQ*
//	Calculate derivative of quaternion.
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		return: derivative of quaternion
//rquat ijkQuatDerivQr(rquat const q_in, rvec3 const angularVelocity);
#define ijkQuatDerivQr ijk_declrealfs(ijkQuatDerivQ,)

// ijkQuatDeriv2Q*
//	Calculate second derivative of quaternion.
//		param q_in: input quaternion
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: second derivative of quaternion
//rquat ijkQuatDeriv2Qr(rquat const q_in, rvec3 const angularVelocity, rvec3 const angularAcceleration);
#define ijkQuatDeriv2Qr ijk_declrealfs(ijkQuatDeriv2Q,)

// ijkQuatEncodeTranslateQ*
//	Encode translation offset vector using quaternion.
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: encoded translation
//rquat ijkQuatEncodeTranslateQr(rvec3 const translate_in, rquat const q_encode);
#define ijkQuatEncodeTranslateQr ijk_declrealfs(ijkQuatEncodeTranslateQ,)

// ijkQuatEncodeTranslateX2Q*
//	Encode double translation offset vector using quaternion.
//		param translate_in: input vector, translation offset
//		param q_encode: encoding quaternion
//		return: encoded translation
//rquat ijkQuatEncodeTranslateX2Qr(rvec3 const translate_in, rquat const q_encode);
#define ijkQuatEncodeTranslateX2Qr ijk_declrealfs(ijkQuatEncodeTranslateX2Q,)

// ijkQuatDecodeTranslateQ*
//	Decode translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
//rvec3 ijkQuatDecodeTranslateQr(rquat const qt_in, rquat const q_decode);
#define ijkQuatDecodeTranslateQr ijk_declrealfs(ijkQuatDecodeTranslateQ,)

// ijkQuatDecodeTranslateD2Q*s
//	Decode half translation offset vector from quaternion with scalar 
//	multiplier; use if encoding quaternion is unit or if decoded translation 
//	should have additional user-defined scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
//rvec3 ijkQuatDecodeTranslateD2Qrs(rquat const qt_in, rquat const q_decode, real const s);
#define ijkQuatDecodeTranslateD2Qrs ijk_declrealfs(ijkQuatDecodeTranslateD2Q,s)

// ijkQuatDecodeTranslateD2Q*
//	Decode half translation offset vector from quaternion; use if encoding 
//	quaternion is unit or if decoded translation should have scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
//rvec3 ijkQuatDecodeTranslateD2Qr(rquat const qt_in, rquat const q_decode);
#define ijkQuatDecodeTranslateD2Qr ijk_declrealfs(ijkQuatDecodeTranslateD2Q,)

// ijkQuatDecodeTranslateRemScaleQ*
//	Decode translation offset vector from quaternion, removing scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
//rvec3 ijkQuatDecodeTranslateRemScaleQr(rquat const qt_in, rquat const q_decode);
#define ijkQuatDecodeTranslateRemScaleQr ijk_declrealfs(ijkQuatDecodeTranslateRemScaleQ,)

// ijkQuatDecodeTranslateRemScaleD2Q*
//	Decode half translation offset vector from quaternion, removing scale.
//		param qt_in: input quaternion, encoded translation
//		param q_decode: decoding quaternion
//		return: translation offset
//rvec3 ijkQuatDecodeTranslateRemScaleD2Qr(rquat const qt_in, rquat const q_decode);
#define ijkQuatDecodeTranslateRemScaleD2Qr ijk_declrealfs(ijkQuatDecodeTranslateRemScaleD2Q,)


//-----------------------------------------------------------------------------

// ijkDualQuatInitDQ*
//	Initialize identity dual quaternion (zero dual, identity real).
//		return: identity dual quaternion
//rdualquat ijkDualQuatInitDQr();
#define ijkDualQuatInitDQr ijk_declrealfs(ijkDualQuatInitDQ,)

// ijkDualQuatInitDualReDQ*
//	Initialize dual quaternion with dual and real parts.
//		param re: real component (qr)
//		param dual: dual component (E qd)
//		return: r+Ed dual quaternion
//rdualquat ijkDualQuatInitDualReDQr(rquat const re, rquat const dual);
#define ijkDualQuatInitDualReDQr ijk_declrealfs(ijkDualQuatInitDualReDQ,)

// ijkDualQuatInitMatDQ*3
//	Initialize dual quaternion from 3D matrix.
//		param m_in: input matrix
//		return: output dual quaternion
//rdualquat ijkDualQuatInitMatDQr3(rmat3 const m_in);
#define ijkDualQuatInitMatDQr3 ijk_declrealfs(ijkDualQuatInitMatDQ,3)

// ijkDualQuatInitMatDQ*4
//	Initialize dual quaternion from 4D matrix.
//		param m_in: input matrix
//		return: output dual quaternion
//rdualquat ijkDualQuatInitMatDQr4(rmat4 const m_in);
#define ijkDualQuatInitMatDQr4 ijk_declrealfs(ijkDualQuatInitMatDQ,4)

// ijkDualQuatCopyDQ*
//	Copy dual quaternion.
//		param dq_in: input dual quaternion
//		return: copy
//rdualquat ijkDualQuatCopyDQr(rdualquat const dq_in);
#define ijkDualQuatCopyDQr ijk_declrealfs(ijkDualQuatCopyDQ,)

// ijkDualQuatNegateDQ*
//	Negate dual quaternion.
//		param dq_in: input dual quaternion
//		return: negative dual quaternion
//rdualquat ijkDualQuatNegateDQr(rdualquat const dq_in);
#define ijkDualQuatNegateDQr ijk_declrealfs(ijkDualQuatNegateDQ,)

// ijkDualQuatConjugateDQ*
//	Conjugate dual quaternion: take conjugate of both components.
//		param dq_in: input dual quaternion
//		return: conjugate dual quaternion
//rdualquat ijkDualQuatConjugateDQr(rdualquat const dq_in);
#define ijkDualQuatConjugateDQr ijk_declrealfs(ijkDualQuatConjugateDQ,)

// ijkDualQuatNegateDualDQ*
//	Negate dual part: conjugate of dual number.
//		param dq_in: input dual quaternion
//		return: dual conjugate dual quaternion
//rdualquat ijkDualQuatNegateDualDQr(rdualquat const dq_in);
#define ijkDualQuatNegateDualDQr ijk_declrealfs(ijkDualQuatNegateDualDQ,)

// ijkDualQuatConjugateDualDQ*
//	Conjugate and negate dual part: conjugate of dual number and components.
//		param dq_in: input dual quaternion
//		return: full dual conjugate dual quaternion
//rdualquat ijkDualQuatConjugateDualDQr(rdualquat const dq_in);
#define ijkDualQuatConjugateDualDQr ijk_declrealfs(ijkDualQuatConjugateDualDQ,)

// ijkDualQuatAddDQ*
//	Calculate sum of dual quaternions.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: sum dual quaternion
//rdualquat ijkDualQuatAddDQr(rdualquat const dq_lh, rdualquat const dq_rh);
#define ijkDualQuatAddDQr ijk_declrealfs(ijkDualQuatAddDQ,)

// ijkDualQuatSubDQ*
//	Calculate difference of dual quaternions.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: difference dual quaternion
//rdualquat ijkDualQuatSubDQr(rdualquat const dq_lh, rdualquat const dq_rh);
#define ijkDualQuatSubDQr ijk_declrealfs(ijkDualQuatSubDQ,)

// ijkDualQuatMulDQ*s
//	Calculate product of dual quaternion and scalar.
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: product dual quaternion
//rdualquat ijkDualQuatMulDQrs(rdualquat const dq_lh, real const s_rh);
#define ijkDualQuatMulDQrs ijk_declrealfs(ijkDualQuatMulDQ,s)

// ijkDualQuatDivDQ*s
//	Calculate quotient of dual quaternion and scalar.
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: quotient dual quaternion
//rdualquat ijkDualQuatDivDQrs(rdualquat const dq_lh, real const s_rh);
#define ijkDualQuatDivDQrs ijk_declrealfs(ijkDualQuatDivDQ,s)

// ijkDualQuatDivSafeDQ*s
//	Calculate quotient of dual quaternion and scalar; division-by-zero safety.
//		param dq_lh: left-hand dual quaternion
//		param s_rh: right-hand scalar
//		return: quotient dual quaternion
//rdualquat ijkDualQuatDivSafeDQrs(rdualquat const dq_lh, real const s_rh);
#define ijkDualQuatDivSafeDQrs ijk_declrealfs(ijkDualQuatDivSafeDQ,s)

// ijkDualQuatLengthSqDQ*
//	Calculate squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: squared length
//real ijkDualQuatLengthSqDQr(rdualquat const dq_in);
#define ijkDualQuatLengthSqDQr ijk_declrealfs(ijkDualQuatLengthSqDQ,)

// ijkDualQuatLengthDQ*
//	Calculate length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: length
//real ijkDualQuatLengthDQr(rdualquat const dq_in);
#define ijkDualQuatLengthDQr ijk_declrealfs(ijkDualQuatLengthDQ,)

// ijkDualQuatLengthSqInvDQ*
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
//real ijkDualQuatLengthSqInvDQr(rdualquat const dq_in);
#define ijkDualQuatLengthSqInvDQr ijk_declrealfs(ijkDualQuatLengthSqInvDQ,)

// ijkDualQuatLengthInvDQ*
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
//real ijkDualQuatLengthInvDQr(rdualquat const dq_in);
#define ijkDualQuatLengthInvDQr ijk_declrealfs(ijkDualQuatLengthInvDQ,)

// ijkDualQuatLengthSqInvSafeDQ*
//	Calculate inverse squared length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse squared length
//real ijkDualQuatLengthSqInvSafeDQr(rdualquat const dq_in);
#define ijkDualQuatLengthSqInvSafeDQr ijk_declrealfs(ijkDualQuatLengthSqInvSafeDQ,)

// ijkDualQuatLengthInvSafeDQ*
//	Calculate inverse length of dual quaternion.
//		param dq_in: input dual quaternion
//		return: inverse length
//real ijkDualQuatLengthInvSafeDQr(rdualquat const dq_in);
#define ijkDualQuatLengthInvSafeDQr ijk_declrealfs(ijkDualQuatLengthInvSafeDQ,)

// ijkDualQuatNormalizeDQ*
//	Normalize dual quaternion.
//		param dq_in: input dual quaternion
//		return: unit dual quaternion
//rdualquat ijkDualQuatNormalizeDQr(rdualquat const dq_in);
#define ijkDualQuatNormalizeDQr ijk_declrealfs(ijkDualQuatNormalizeDQ,)

// ijkDualQuatNormalizeSafeDQ*
//	Normalize dual quaternion; division-by-zero safety.
//		param dq_in: input dual quaternion
//		return: unit dual quaternion
//rdualquat ijkDualQuatNormalizeSafeDQr(rdualquat const dq_in);
#define ijkDualQuatNormalizeSafeDQr ijk_declrealfs(ijkDualQuatNormalizeSafeDQ,)

// ijkDualQuatInverseDQ*
//	Calculate inverse of dual quaternion: conjugate divided by squared length.
//		param dq_in: input dual quaternion
//		return: inverse dual quaternion
//rdualquat ijkDualQuatInverseDQr(rdualquat const dq_in);
#define ijkDualQuatInverseDQr ijk_declrealfs(ijkDualQuatInverseDQ,)

// ijkDualQuatInverseSafeDQ*
//	Calculate inverse of dual quaternion: conjugate divided by squared length; 
//	division-by-zero safety.
//		param dq_in: input dual quaternion
//		return: inverse dual quaternion
//rdualquat ijkDualQuatInverseSafeDQr(rdualquat const dq_in);
#define ijkDualQuatInverseSafeDQr ijk_declrealfs(ijkDualQuatInverseSafeDQ,)

// ijkDualQuatMulVecDQ*3
//	Calculate product of dual quaternion and 3D vector (result is dual quaternion).
//		param dq_lh: left-hand dual quaternion
//		param v_rh: right-hand vector
//		return: product dual quaternion
//rdualquat ijkDualQuatMulVecDQr3(rdualquat const dq_lh, rvec3 const v_rh);
#define ijkDualQuatMulVecDQr3 ijk_declrealfs(ijkDualQuatMulVecDQ,3)

// ijkDualQuatMulVecDQ*3q
//	Calculate product of 3D vector and dual quaternion (result is dual quaternion).
//		param v_lh: left-hand vector
//		param dq_rh: right-hand dual quaternion
//		return: product dual quaternion
//rdualquat ijkDualQuatMulVecDQr3q(rvec3 const v_lh, rdualquat const dq_rh);
#define ijkDualQuatMulVecDQr3q ijk_declrealfs(ijkDualQuatMulVecDQ,3q)

// ijkDualQuatMulDQ*
//	Calculate product of dual quaternions, or concatenate unit dual quaternions
//	representing transformations.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: product dual quaternion
//rdualquat ijkDualQuatMulDQr(rdualquat const dq_lh, rdualquat const dq_rh);
#define ijkDualQuatMulDQr ijk_declrealfs(ijkDualQuatMulDQ,)

// ijkDualQuatMulScaleDQ*
//	Correctly concatenate dual quaternions that represent transformations such 
//	that the right-hand input's translation is correctly affected by the left-
//	hand input's scale, when used to transform a vector later.
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: product dual quaternion
//rdualquat ijkDualQuatMulScaleDQr(rdualquat const dq_lh, rdualquat const dq_rh);
#define ijkDualQuatMulScaleDQr ijk_declrealfs(ijkDualQuatMulScaleDQ,)

// ijkDualQuatDivDQ*
//	Calculate quotient of dual quaternions (multiply by rh inverse).
//		param dq_lh: left-hand dual quaternion
//		param dq_rh: right-hand dual quaternion
//		return: quotient dual quaternion
//rdualquat ijkDualQuatDivDQr(rdualquat const dq_lh, rdualquat const dq_rh);
#define ijkDualQuatDivDQr ijk_declrealfs(ijkDualQuatDivDQ,)

// ijkDualQuatRotateDQ*
//	Make rotation dual quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		return: rotation dual quaternion
//rdualquat ijkDualQuatRotateDQr(ijkRotationOrder const order, rvec3 const rotateDegXYZ);
#define ijkDualQuatRotateDQr ijk_declrealfs(ijkDualQuatRotateDQ,)

// ijkDualQuatAxisAngleDQ*
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		return: rotation dual quaternion
//rdualquat ijkDualQuatAxisAngleDQr(rvec3 const axis_unit, real const angle_degrees);
#define ijkDualQuatAxisAngleDQr ijk_declrealfs(ijkDualQuatAxisAngleDQ,)

// ijkDualQuatScaleDQ*
//	Make rotation dual quaternion with uniform scale.
//		param scale_unif: uniform scale amount
//		return: scale dual quaternion
//rdualquat ijkDualQuatScaleDQr(real const scale_unif);
#define ijkDualQuatScaleDQr ijk_declrealfs(ijkDualQuatScaleDQ,)

// ijkDualQuatRotateScaleDQ*
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		return: rotation-scale dual quaternion
//rdualquat ijkDualQuatRotateScaleDQr(ijkRotationOrder const order, rvec3 const rotateDegXYZ, real const scale_unif);
#define ijkDualQuatRotateScaleDQr ijk_declrealfs(ijkDualQuatRotateScaleDQ,)

// ijkDualQuatAxisAngleScaleDQ*
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		return: rotation-scale dual quaternion
//rdualquat ijkDualQuatAxisAngleScaleDQr(rvec3 const axis_unit, real const angle_degrees, real const scale_unif);
#define ijkDualQuatAxisAngleScaleDQr ijk_declrealfs(ijkDualQuatAxisAngleScaleDQ,)

// ijkDualQuatTranslateDQ*
//	Make rotation dual quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param translate: translation offset vector
//		return: translation dual quaternion
//rdualquat ijkDualQuatTranslateDQr(rvec3 const translate);
#define ijkDualQuatTranslateDQr ijk_declrealfs(ijkDualQuatTranslateDQ,)

// ijkDualQuatRotateTranslateDQ*
//	Make rotation dual quaternion with Euler angles.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param translate: translation offset vector
//		return: rotation-translation dual quaternion
//rdualquat ijkDualQuatRotateTranslateDQr(ijkRotationOrder const order, rvec3 const rotateDegXYZ, rvec3 const translate);
#define ijkDualQuatRotateTranslateDQr ijk_declrealfs(ijkDualQuatRotateTranslateDQ,)

// ijkDualQuatAxisAngleTranslateDQ*
//	Make rotation dual quaternion with unit axis and angle in degrees.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param translate: translation offset vector
//		return: rotation-translation dual quaternion
//rdualquat ijkDualQuatAxisAngleTranslateDQr(rvec3 const axis_unit, real const angle_degrees, rvec3 const translate);
#define ijkDualQuatAxisAngleTranslateDQr ijk_declrealfs(ijkDualQuatAxisAngleTranslateDQ,)

// ijkDualQuatScaleTranslateDQ*
//	Make rotation dual quaternion with uniform scale.
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: scale-translation dual quaternion
//rdualquat ijkDualQuatScaleTranslateDQr(real const scale_unif, rvec3 const translate);
#define ijkDualQuatScaleTranslateDQr ijk_declrealfs(ijkDualQuatScaleTranslateDQ,)

// ijkDualQuatRotateScaleTranslateDQ*
//	Make rotation dual quaternion with Euler angles and uniform scale.
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ: Euler angles in degrees (component order XYZ)
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: rotation-scale-translation dual quaternion
//rdualquat ijkDualQuatRotateScaleTranslateDQr(ijkRotationOrder const order, rvec3 const rotateDegXYZ, real const scale_unif, rvec3 const translate);
#define ijkDualQuatRotateScaleTranslateDQr ijk_declrealfs(ijkDualQuatRotateScaleTranslateDQ,)

// ijkDualQuatAxisAngleScaleTranslateDQ*
//	Make rotation dual quaternion with unit axis, angle in degrees and uniform scale.
//		param axis_unit: unit axis of rotation
//		param angle_degrees: angle of rotation in degrees
//		param scale_unif: uniform scale amount
//		param translate: translation offset vector
//		return: rotation-scale-translation dual quaternion
//rdualquat ijkDualQuatAxisAngleScaleTranslateDQr(rvec3 const axis_unit, real const angle_degrees, real const scale_unif, rvec3 const translate);
#define ijkDualQuatAxisAngleScaleTranslateDQr ijk_declrealfs(ijkDualQuatAxisAngleScaleTranslateDQ,)

// ijkDualQuatGetRotateDQ*
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		return: dq_in
//rdualquat ijkDualQuatGetRotateDQr(rdualquat const dq_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out);
#define ijkDualQuatGetRotateDQr ijk_declrealfs(ijkDualQuatGetRotateDQ,)

// ijkDualQuatGetAxisAngleDQ*
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		return: dq_in
//rdualquat ijkDualQuatGetAxisAngleDQr(rdualquat const dq_in, rvec3* const axis_unit_out, real* const angle_degrees_out);
#define ijkDualQuatGetAxisAngleDQr ijk_declrealfs(ijkDualQuatGetAxisAngleDQ,)

// ijkDualQuatGetScaleDQ*
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
//rdualquat ijkDualQuatGetScaleDQr(rdualquat const dq_in, real* const scale_unif_out);
#define ijkDualQuatGetScaleDQr ijk_declrealfs(ijkDualQuatGetScaleDQ,)

// ijkDualQuatGetRotateScaleDQ*
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
//rdualquat ijkDualQuatGetRotateScaleDQr(rdualquat const dq_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out, real* const scale_unif_out);
#define ijkDualQuatGetRotateScaleDQr ijk_declrealfs(ijkDualQuatGetRotateScaleDQ,)

// ijkDualQuatGetAxisAngleScaleDQ*
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		return: dq_in
//rdualquat ijkDualQuatGetAxisAngleScaleDQr(rdualquat const dq_in, rvec3* const axis_unit_out, real* const angle_degrees_out, real* const scale_unif_out);
#define ijkDualQuatGetAxisAngleScaleDQr ijk_declrealfs(ijkDualQuatGetAxisAngleScaleDQ,)

// ijkDualQuatGetTranslateDQ*
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
//rdualquat ijkDualQuatGetTranslateDQr(rdualquat const dq_in, rvec3* const translate_out);
#define ijkDualQuatGetTranslateDQr ijk_declrealfs(ijkDualQuatGetTranslateDQ,)

// ijkDualQuatGetRotateTranslateDQ*
//	Extract Euler angles from rotation dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
//rdualquat ijkDualQuatGetRotateTranslateDQr(rdualquat const dq_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out, rvec3* const translate_out);
#define ijkDualQuatGetRotateTranslateDQr ijk_declrealfs(ijkDualQuatGetRotateTranslateDQ,)

// ijkDualQuatGetAxisAngleTranslateDQ*
//	Extract unit axis and angle in degrees from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
//rdualquat ijkDualQuatGetAxisAngleTranslateDQr(rdualquat const dq_in, rvec3* const axis_unit_out, real* const angle_degrees_out, rvec3* const translate_out);
#define ijkDualQuatGetAxisAngleTranslateDQr ijk_declrealfs(ijkDualQuatGetAxisAngleTranslateDQ,)

// ijkDualQuatGetScaleTranslateDQ*
//	Extract uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
//rdualquat ijkDualQuatGetScaleTranslateDQr(rdualquat const dq_in, real* const scale_unif_out, rvec3* const translate_out);
#define ijkDualQuatGetScaleTranslateDQr ijk_declrealfs(ijkDualQuatGetScaleTranslateDQ,)

// ijkDualQuatGetRotateScaleTranslateDQ*
//	Extract Euler angles and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
//rdualquat ijkDualQuatGetRotateScaleTranslateDQr(rdualquat const dq_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out, real* const scale_unif_out, rvec3* const translate_out);
#define ijkDualQuatGetRotateScaleTranslateDQr ijk_declrealfs(ijkDualQuatGetRotateScaleTranslateDQ,)

// ijkDualQuatGetAxisAngleScaleTranslateDQ*
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
//rdualquat ijkDualQuatGetAxisAngleScaleTranslateDQr(rdualquat const dq_in, rvec3* const axis_unit_out, real* const angle_degrees_out, real* const scale_unif_out, rvec3* const translate_out);
#define ijkDualQuatGetAxisAngleScaleTranslateDQr ijk_declrealfs(ijkDualQuatGetAxisAngleScaleTranslateDQ,)

// ijkDualQuatGetTranslateRemScaleDQ*
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param translate_out: storage for translation offset vector
//		return: dq_in
//rdualquat ijkDualQuatGetTranslateRemScaleDQr(rdualquat const dq_in, rvec3* const translate_out);
#define ijkDualQuatGetTranslateRemScaleDQr ijk_declrealfs(ijkDualQuatGetTranslateRemScaleDQ,)

// ijkDualQuatGetRotateTranslateRemScaleDQ*
//	Extract Euler angles from rotation dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param order: written order of Euler angles (functional order of 
//			operations is right-to-left)
//		param rotateDegXYZ_out: storage for Euler angles in component order XYZ
//		param translate_out: storage for translation offset vector
//		return: dq_in
//rdualquat ijkDualQuatGetRotateTranslateRemScaleDQr(rdualquat const dq_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out, rvec3* const translate_out);
#define ijkDualQuatGetRotateTranslateRemScaleDQr ijk_declrealfs(ijkDualQuatGetRotateTranslateRemScaleDQ,)

// ijkDualQuatGetAxisAngleTranslateRemScaleDQ*
//	Extract unit axis and angle in degrees from dual quaternion, removing 
//	scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		return: dq_in
//rdualquat ijkDualQuatGetAxisAngleTranslateRemScaleDQr(rdualquat const dq_in, rvec3* const axis_unit_out, real* const angle_degrees_out, rvec3* const translate_out);
#define ijkDualQuatGetAxisAngleTranslateRemScaleDQr ijk_declrealfs(ijkDualQuatGetAxisAngleTranslateRemScaleDQ,)

// ijkDualQuatGetScaleTranslateRemScaleDQ*
//	Extract uniform scale from dual quaternion, removing scale from 
//	translation part.
//		param dq_in: input dual quaternion
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
//rdualquat ijkDualQuatGetScaleTranslateRemScaleDQr(rdualquat const dq_in, real* const scale_unif_out, rvec3* const translate_out);
#define ijkDualQuatGetScaleTranslateRemScaleDQr ijk_declrealfs(ijkDualQuatGetScaleTranslateRemScaleDQ,)

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
//rdualquat ijkDualQuatGetScaleTranslateRemScaleDQr(rdualquat const dq_in, ijkRotationOrder const order, rvec3* const rotateDegXYZ_out, real* const scale_unif_out, rvec3* const translate_out);
#define ijkDualQuatGetScaleTranslateRemScaleDQr ijk_declrealfs(ijkDualQuatGetScaleTranslateRemScaleDQ,)

// ijkDualQuatGetAxisAngleScaleTranslateRemScaleDQ*
//	Extract unit axis, angle in degrees and uniform scale from dual quaternion,
//	removing scale from translation part.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param scale_unif_out: storage for uniform scale amount
//		param translate_out: storage for translation offset vector
//		return: dq_in
//rdualquat ijkDualQuatGetScaleTranslateRemScaleDQr(rdualquat const dq_in, rvec3* const axis_unit_out, real* const angle_degrees_out, real* const scale_unif_out, rvec3* const translate_out);
#define ijkDualQuatGetScaleTranslateRemScaleDQr ijk_declrealfs(ijkDualQuatGetScaleTranslateRemScaleDQ,)

// ijkDualQuatGetScrewParamsDQ*
//	Extract screw parameters from dual quaternion.
//		param dq_in: input dual quaternion
//		param axis_unit_out: storage for unit axis of rotation
//		param angle_degrees_out: storage for rotation angle in degrees
//		param translate_out: storage for translation offset vector
//		param momentArm_out: storage for moment arm
//		param screwDisplace_out: storage for screw displacement parameter
//		return: dq_in
//rdualquat ijkDualQuatGetScrewParamsDQr(rdualquat const dq_in, rvec3* const axis_unit_out, real* const angle_degrees_out, rvec3* const translate_out, rvec3* const momentArm_out, real* const screwDisplace_out);
#define ijkDualQuatGetScrewParamsDQr ijk_declrealfs(ijkDualQuatGetScrewParamsDQ,)

// ijkDualQuatGetMatDQ*3
//	Convert dual quaternion's real part to 3D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
//rmat3 ijkDualQuatGetMatDQr3(rdualquat const dq_in);
#define ijkDualQuatGetMatDQr3 ijk_declrealfs(ijkDualQuatGetMatDQ,3)

// ijkDualQuatUnitGetMatDQ*3
//	Convert unit dual quaternion's real part to 3D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
//rmat3 ijkDualQuatUnitGetMatDQr3(rdualquat const dq_in);
#define ijkDualQuatUnitGetMatDQr3 ijk_declrealfs(ijkDualQuatUnitGetMatDQ,3)

// ijkDualQuatGetMatTranslateDQ*3
//	Convert dual quaternion's real part to 3D matrix and extract translation.
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: output matrix
//rmat3 ijkDualQuatGetMatTranslateDQr3(rvec3* const translate_out, rdualquat const dq_in);
#define ijkDualQuatGetMatTranslateDQr3 ijk_declrealfs(ijkDualQuatGetMatTranslateDQ,3)

// ijkDualQuatUnitGetMatTranslateDQ*3
//	Convert unit dual quaternion's real part to 3D matrix and extract 
//	translation.
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: output matrix
//rmat3 ijkDualQuatUnitGetMatTranslateDQr3(rvec3* const translate_out, rdualquat const dq_in);
#define ijkDualQuatUnitGetMatTranslateDQr3 ijk_declrealfs(ijkDualQuatUnitGetMatTranslateDQ,3)

// ijkDualQuatGetMatTranslateRemScaleDQ*3
//	Convert dual quaternion's real part to 3D matrix and extract translation 
//	with scale removed.
//		param translate_out: output translation vector
//		param dq_in: input dual quaternion
//		return: output matrix
//rmat3 ijkDualQuatGetMatTranslateRemScaleDQr3(rvec3* const translate_out, rdualquat const dq_in);
#define ijkDualQuatGetMatTranslateRemScaleDQr3 ijk_declrealfs(ijkDualQuatGetMatTranslateRemScaleDQ,3)

// ijkDualQuatGetMatDQ*4
//	Convert dual quaternion to 4D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
//rmat4 ijkDualQuatGetMatDQr4(rdualquat const dq_in);
#define ijkDualQuatGetMatDQr4 ijk_declrealfs(ijkDualQuatGetMatDQ,4)

// ijkDualQuatUnitGetMatDQ*4
//	Convert unit dual quaternion to 4D matrix.
//		param dq_in: input dual quaternion
//		return: output matrix
//rmat4 ijkDualQuatUnitGetMatDQr4(rdualquat const dq_in);
#define ijkDualQuatUnitGetMatDQr4 ijk_declrealfs(ijkDualQuatUnitGetMatDQ,4)

// ijkDualQuatGetMatTranslateRemScaleDQ*4
//	Convert dual quaternion to 4D matrix, scale removed from translation part.
//		param dq_in: input dual quaternion
//		return: output matrix
//rmat4 ijkDualQuatGetMatTranslateRemScaleDQr4(rdualquat const dq_in);
#define ijkDualQuatGetMatTranslateRemScaleDQr4 ijk_declrealfs(ijkDualQuatGetMatTranslateRemScaleDQ,4)

// ijkDualQuatTransformScaleVecDQ*3
//	Transform a 3D vector using a dual quaternion with scale; use when dual 
//	quaternion has scale to prevent translation part from being scaled.
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: transformed vector
//rvec3 ijkDualQuatTransformScaleVecDQr3(rdualquat const dq_in, rvec3 const v_in);
#define ijkDualQuatTransformScaleVecDQr3 ijk_declrealfs(ijkDualQuatTransformScaleVecDQ,3)

// ijkDualQuatUnitTransformVecDQ*3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	unit-length for most optimized solution or when translation part should 
//	also be scaled.
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: transformed vector
//rvec3 ijkDualQuatUnitTransformVecDQr3(rdualquat const dq_in, rvec3 const v_in);
#define ijkDualQuatUnitTransformVecDQr3 ijk_declrealfs(ijkDualQuatUnitTransformVecDQ,3)

// ijkDualQuatTransformVecDQ*3
//	Transform a 3D vector using a dual quaternion; use when dual quaternion is 
//	non-unit length to remove scale from all parts.
//		param dq_in: input dual quaternion
//		param v_in: input vector
//		return: transformed vector
//rvec3 ijkDualQuatTransformVecDQr3(rdualquat const dq_in, rvec3 const v_in);
#define ijkDualQuatTransformVecDQr3 ijk_declrealfs(ijkDualQuatTransformVecDQ,3)

// ijkDualQuatLerpDQ*
//	Calculate linear interpolation between two dual quaternions; yields uniform
//	rate of change but affects translation path and scale.
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: interpolated dual quaternion
//rdualquat ijkDualQuatLerpDQr(rdualquat const dq0, rdualquat const dq1, real const u);
#define ijkDualQuatLerpDQr ijk_declrealfs(ijkDualQuatLerpDQ,)

// ijkDualQuatNlerpDQ*
//	Calculate normalized linear interpolation between two dual quaternions; 
//	keeps result at unit-length but yields a non-uniform rate of change.
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: interpolated dual quaternion
//rdualquat ijkDualQuatNlerpDQr(rdualquat const dq0, rdualquat const dq1, real const u);
#define ijkDualQuatNlerpDQr ijk_declrealfs(ijkDualQuatNlerpDQ,)

// ijkDualQuatSclerpDQ*
//	Calculate screw linear interpolation between two unit dual quaternions; 
//	keeps result at unit-length and yields a uniform rate of change.
//		param dq0: input initial control dual quaternion, result when param is 0
//		param dq1: input terminal control dual quaternion, result when param is 1
//		param u: interpolation parameter; values in domain [0,1] result in 
//			interpolation in range [dq0,dq1], others result in extrapolation
//		return: interpolated dual quaternion
//rdualquat ijkDualQuatSclerpDQr(rdualquat const dq0, rdualquat const dq1, real const u);
#define ijkDualQuatSclerpDQr ijk_declrealfs(ijkDualQuatSclerpDQ,)

// ijkDualQuatDerivDQ*
//	Calculate derivative of dual quaternion.
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param angularVelocity: angular velocity vector
//		return: derivative of dual quaternion
//rdualquat ijkDualQuatDerivDQr(rdualquat const dq_in, rvec3 const linearVelocity, rvec3 const angularVelocity);
#define ijkDualQuatDerivDQr ijk_declrealfs(ijkDualQuatDerivDQ,)

// ijkDualQuatDeriv2DQ*
//	Calculate second derivative of dual quaternion.
//		param dq_in: input dual quaternion
//		param linearVelocity: linear velocity vector
//		param linearAcceleration: linear acceleration vector
//		param angularVelocity: angular velocity vector
//		param angularAcceleration: angular acceleration vector
//		return: second derivative of dual quaternion
//rdualquat ijkDualQuatDeriv2DQr(rdualquat const dq_in, rvec3 const linearVelocity, rvec3 const linearAcceleration, rvec3 const angularVelocity, rvec3 const angularAcceleration);
#define ijkDualQuatDeriv2DQr ijk_declrealfs(ijkDualQuatDeriv2DQ,)


//-----------------------------------------------------------------------------


#endif	// !_IJK_QUATERNION_REAL_H_
#endif	// _IJK_QUATERNION_H_