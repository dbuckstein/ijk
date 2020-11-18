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

	ijkQuaternion_float.inl
	Inline definitions for float quaternion types.
*/

#ifdef _IJK_QUATERNION_FLOAT_H_
#ifndef _IJK_QUATERNION_FLOAT_INL_
#define _IJK_QUATERNION_FLOAT_INL_


//-----------------------------------------------------------------------------

ijk_inl floatv ijkQuatInitQfv(float4 q_out)
{

	return q_out;
}

ijk_inl floatv ijkQuatInitElemsQfv(float4 q_out, f32 const x, f32 const y, f32 const z, f32 const w)
{

	return q_out;
}

ijk_inl floatv ijkQuatInitVecReQfv(float4 q_out, float3 const vec, f32 const re)
{

	return q_out;
}

ijk_inl floatv ijkQuatInitMatQfv3(float4 q_out, float3x3 const m_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatInitMatQfv4(float4 q_out, float4x4 const m_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatCopyQfv(float4 q_out, float4 const q_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatNegateQfv(float4 q_out, float4 const q_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatConjugateQfv(float4 q_out, float4 const q_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatAddQfv(float4 q_out, float4 const q_lh, float4 const q_rh)
{

	return q_out;
}

ijk_inl floatv ijkQuatSubQfv(float4 q_out, float4 const q_lh, float4 const q_rh)
{

	return q_out;
}

ijk_inl floatv ijkQuatMulQfvs(float4 q_out, float4 const q_lh, f32 const s_rh)
{

	return q_out;
}

ijk_inl floatv ijkQuatDivQfvs(float4 q_out, float4 const q_lh, f32 const s_rh)
{

	return q_out;
}

ijk_inl floatv ijkQuatDivSafeQfvs(float4 q_out, float4 const q_lh, f32 const s_rh)
{

	return q_out;
}

ijk_inl f32 ijkQuatLengthSqQfv(float4 const q_in)
{

	return flt_zero;
}

ijk_inl f32 ijkQuatLengthQfv(float4 const q_in)
{

	return flt_zero;
}

ijk_inl f32 ijkQuatLengthSqInvQfv(float4 const q_in)
{

	return flt_zero;
}

ijk_inl f32 ijkQuatLengthInvQfv(float4 const q_in)
{

	return flt_zero;
}

ijk_inl f32 ijkQuatLengthSqInvSafeQfv(float4 const q_in)
{

	return flt_zero;
}

ijk_inl f32 ijkQuatLengthInvSafeQfv(float4 const q_in)
{

	return flt_zero;
}

ijk_inl floatv ijkQuatNormalizeQfv(float4 q_out, float4 const q_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatNormalizeSafeQfv(float4 q_out, float4 const q_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatInverseQfv(float4 q_out, float4 const q_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatInverseSafeQfv(float4 q_out, float4 const q_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatMulVecQfv3(float4 q_out, float4 const q_lh, float3 const v_rh)
{

	return q_out;
}

ijk_inl floatv ijkQuatMulVecQfv3q(float4 q_out, float3 const v_lh, float4 const q_rh)
{

	return q_out;
}

ijk_inl floatv ijkQuatMulQfv(float4 q_out, float4 const q_lh, float4 const q_rh)
{

	return q_out;
}

ijk_inl floatv ijkQuatDivQfv(float4 q_out, float4 const q_lh, float4 const q_rh)
{

	return q_out;
}

ijk_inl floatv ijkQuatRotateXYZQfv(float4 q_out, float3 const rotateDegXYZ)
{

	return q_out;
}

ijk_inl floatv ijkQuatRotateYZXQfv(float4 q_out, float3 const rotateDegXYZ)
{

	return q_out;
}

ijk_inl floatv ijkQuatRotateZXYQfv(float4 q_out, float3 const rotateDegXYZ)
{

	return q_out;
}

ijk_inl floatv ijkQuatRotateYXZQfv(float4 q_out, float3 const rotateDegXYZ)
{

	return q_out;
}

ijk_inl floatv ijkQuatRotateXZYQfv(float4 q_out, float3 const rotateDegXYZ)
{

	return q_out;
}

ijk_inl floatv ijkQuatRotateZYXQfv(float4 q_out, float3 const rotateDegXYZ)
{

	return q_out;
}

ijk_inl floatkv ijkQuatGetRotateXYZQfv(float4 const q_in, float3 rotateDegXYZ_out)
{

	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateYZXQfv(float4 const q_in, float3 rotateDegXYZ_out)
{

	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateZXYQfv(float4 const q_in, float3 rotateDegXYZ_out)
{

	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateYXZQfv(float4 const q_in, float3 rotateDegXYZ_out)
{

	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateXZYQfv(float4 const q_in, float3 rotateDegXYZ_out)
{

	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateZYXQfv(float4 const q_in, float3 rotateDegXYZ_out)
{

	return q_in;
}

ijk_inl floatv ijkQuatRotateQfv(float4 q_out, ijkRotationOrder const order, float3 const rotateDegXYZ)
{

	return q_out;
}

ijk_inl floatv ijkQuatAxisAngleQfv(float4 q_out, float3 const axis_unit, f32 const angle_degrees)
{

	return q_out;
}

ijk_inl floatv ijkQuatScaleQfv(float4 q_out, f32 const scale_unif)
{

	return q_out;
}

ijk_inl floatv ijkQuatRotateScaleQfv(float4 q_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif)
{

	return q_out;
}

ijk_inl floatv ijkQuatAxisAngleScaleQfv(float4 q_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif)
{

	return q_out;
}

ijk_inl floatkv ijkQuatGetRotateQfv(float4 const q_in, ijkRotationOrder const order, float3 rotateDegXYZ_out)
{

	return q_in;
}

ijk_inl floatkv ijkQuatGetAxisAngleQfv(float4 const q_in, float3 axis_unit_out, f32* const angle_degrees_out)
{

	return q_in;
}

ijk_inl floatkv ijkQuatGetScaleQfv(float4 const q_in, f32* const scale_unif_out)
{

	return q_in;
}

ijk_inl floatkv ijkQuatGetRotateScaleQfv(float4 const q_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out)
{

	return q_in;
}

ijk_inl floatkv ijkQuatGetAxisAngleScaleQfv(float4 const q_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out)
{

	return q_in;
}

ijk_inl float3m ijkQuatGetMatQfv3(float3x3 m_out, float4 const q_in)
{

	return m_out;
}

ijk_inl float4m ijkQuatGetMatQfv4(float4x4 m_out, float4 const q_in)
{

	return m_out;
}

ijk_inl float4m ijkQuatGetMatQfv4t(float4x4 m_out, float4 const q_in, float3 const translate)
{

	return m_out;
}

ijk_inl floatv ijkQuatRotateVecQfv3(float3 v_out, float4 const q_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatRotateVecQfv4(float4 v_out, float4 const q_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatRotateScaleVecQfv3(float3 v_out, float4 const q_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatRotateScaleVecQfv4(float4 v_out, float4 const q_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatReflectVecQfv3(float3 v_out, float4 const q_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatReflectVecQfv4(float4 v_out, float4 const q_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatExpQfv(float4 q_out, float3 const v_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatLnQfv(float4 q_out, float4 const q_in)
{

	return q_out;
}

ijk_inl floatv ijkQuatNlerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u)
{

	return q_out;
}

ijk_inl floatv ijkQuatSlerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u)
{

	return q_out;
}

ijk_inl floatv ijkQuatDerivQfv(float4 q1_out, float4 const q_in, float3 const angularVelocity)
{

	return q1_out;
}

ijk_inl floatv ijkQuatDeriv2Qfv(float4 q2_out, float4 q1_out, float4 const q_in, float3 const angularVelocity, float3 const angularAcceleration)
{

	return q2_out;
}

ijk_inl floatv ijkQuatEncodeTranslateQfv(float4 qt_out, float3 const translate_in, float4 const q_encode)
{

	return qt_out;
}

ijk_inl floatv ijkQuatDecodeTranslateQfv(float3 translate_out, float4 const qt_in, float4 const q_decode)
{

	return translate_out;
}


//-----------------------------------------------------------------------------

ijk_inl float4m ijkDualQuatInitDQfv(float2x4 dq_out)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInitDualReDQfv(float2x4 dq_out, float4 const dual, float4 const re)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInitMatDQfv3(float2x4 dq_out, float3x3 const m_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInitMatDQfv4(float2x4 dq_out, float4x4 const m_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatCopyDQfv(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatNegateDQfv(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatConjugateDQfv(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatNegateDualDQfv(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatConjugateDualDQfv(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAddDQfv(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatSubDQfv(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulDQfvs(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDivDQfvs(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDivSafeDQfvs(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{

	return dq_out;
}

ijk_inl f32 ijkDualQuatLengthSqDQfv(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthDQfv(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthSqInvDQfv(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthInvDQfv(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthSqInvSafeDQfv(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthInvSafeDQfv(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl float4m ijkDualQuatNormalizeDQfv(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatNormalizeSafeDQfv(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInverseDQfv(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInverseSafeDQfv(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulVecDQfv3(float2x4 dq_out, float2x4 const dq_lh, float3 const v_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulVecDQfv3q(float2x4 dq_out, float3 const v_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulDQfv(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDivDQfv(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateDQfv(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleDQfv(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatScaleDQfv(float2x4 dq_out, f32 const scale_unif)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateScaleDQfv(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleScaleDQfv(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatTranslateDQfv(float2x4 dq_out, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateTranslateDQfv(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleTranslateDQfv(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatScaleTranslateDQfv(float2x4 dq_out, f32 const scale_unif, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateScaleTranslateDQfv(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleScaleTranslateDQfv(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif, float3 const translate)
{

	return dq_out;
}

ijk_inl float4km ijkDualQuatGetRotateDQfv(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleDQfv(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScaleDQfv(float2x4 const dq_in, f32* const scale_unif_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateScaleDQfv(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleScaleDQfv(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetTranslateDQfv(float2x4 const dq_in, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateTranslateDQfv(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleTranslateDQfv(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScaleTranslateDQfv(float2x4 const dq_in, f32* const scale_unif_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateScaleTranslateDQfv(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleScaleTranslateDQfv(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScrewParamsDQfv(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out, float3 momentArm_out, f32* const screwDisplace_out)
{

	return dq_in;
}

ijk_inl float3m ijkDualQuatGetMatDQfv3(float3x3 m_out, float2x4 const dq_in)
{

	return m_out;
}

ijk_inl float4m ijkDualQuatGetMatDQfv4(float4x4 m_out, float2x4 const dq_in)
{

	return m_out;
}

ijk_inl floatv ijkDualQuatTransformVecDQfv3(float3 v_out, float2x4 const dq_in)
{

	return v_out;
}

ijk_inl floatv ijkDualQuatTransformVecDQfv4(float4 v_out, float2x4 const dq_in)
{

	return v_out;
}

ijk_inl floatv ijkDualQuatTransformScaleVecDQfv3(float3 v_out, float2x4 const dq_in)
{

	return v_out;
}

ijk_inl floatv ijkDualQuatTransformScaleVecDQfv4(float4 v_out, float2x4 const dq_in)
{

	return v_out;
}

ijk_inl float4m ijkDualQuatNlerpDQfv(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatSclerpDQfv(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDerivDQfv(float2x4 dq1_out, float2x4 const dq_in, float3 const linearVelocity, float3 const angularVelocity)
{

	return dq1_out;
}

ijk_inl float4m ijkDualQuatDeriv2DQfv(float2x4 dq2_out, float2x4 dq1_out, float2x4 const dq_in, float3 const linearVelocity, float3 const linearAcceleration, float3 const angularVelocity, float3 const angularAcceleration)
{

	return dq2_out;
}


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#endif	// !_IJK_QUATERNION_FLOAT_INL_
#endif	// _IJK_QUATERNION_FLOAT_H_