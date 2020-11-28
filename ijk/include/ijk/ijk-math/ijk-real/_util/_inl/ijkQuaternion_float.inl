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

ijk_inl floatv ijkQuatPfv(float4 q_out)
{
	return q_out;
}

ijk_inl float4m ijkDualQuatPfm(float2x4 dq_out)
{
	return dq_out;
}


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

ijk_inl floatv ijkQuatRotateVecQfv3(float3 v_out, float4 const q_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatRotateVecQfv4(float4 v_out, float4 const q_in, float4 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatRotateScaleVecQfv3(float3 v_out, float4 const q_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatRotateScaleVecQfv4(float4 v_out, float4 const q_in, float4 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatReflectVecQfv3(float3 v_out, float4 const q_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatReflectVecQfv4(float4 v_out, float4 const q_in, float4 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatReflectScaleVecQfv3(float3 v_out, float4 const q_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkQuatReflectScaleVecQfv4(float4 v_out, float4 const q_in, float4 const v_in)
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

ijk_inl floatv ijkQuatLerpQfv(float4 q_out, float4 const q0, float4 const q1, f32 const u)
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

ijk_inl floatv ijkQuatEncodeTranslateRemScaleQfv(float4 qt_out, float3 const translate_in, float4 const q_encode)
{

	return qt_out;
}

ijk_inl floatv ijkQuatDecodeTranslateQfv(float3 translate_out, float4 const qt_in, float4 const q_decode)
{

	return translate_out;
}

ijk_inl floatv ijkQuatDecodeTranslateRemScaleQfv(float3 translate_out, float4 const qt_in, float4 const q_decode)
{

	return translate_out;
}


//-----------------------------------------------------------------------------

ijk_inl float4m ijkDualQuatInitDQfm(float2x4 dq_out)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInitDualReDQfm(float2x4 dq_out, float4 const dual, float4 const re)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInitMatDQfm3(float2x4 dq_out, float3x3 const m_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInitMatDQfm4(float2x4 dq_out, float4x4 const m_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatCopyDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatNegateDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatConjugateDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatNegateDualDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatConjugateDualDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAddDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatSubDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDivDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDivSafeDQfms(float2x4 dq_out, float2x4 const dq_lh, f32 const s_rh)
{

	return dq_out;
}

ijk_inl f32 ijkDualQuatLengthSqDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthSqInvDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthInvDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthSqInvSafeDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl f32 ijkDualQuatLengthInvSafeDQfm(float2x4 const dq_in)
{

	return flt_zero;
}

ijk_inl float4m ijkDualQuatNormalizeDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatNormalizeSafeDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInverseDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatInverseSafeDQfm(float2x4 dq_out, float2x4 const dq_in)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulVecDQfm3(float2x4 dq_out, float2x4 const dq_lh, float3 const v_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulVecDQfm3q(float2x4 dq_out, float3 const v_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatMulScaleDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDivDQfm(float2x4 dq_out, float2x4 const dq_lh, float2x4 const dq_rh)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatScaleDQfm(float2x4 dq_out, f32 const scale_unif)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateScaleDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleScaleDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatTranslateDQfm(float2x4 dq_out, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateTranslateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleTranslateDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatScaleTranslateDQfm(float2x4 dq_out, f32 const scale_unif, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatRotateScaleTranslateDQfm(float2x4 dq_out, ijkRotationOrder const order, float3 const rotateDegXYZ, f32 const scale_unif, float3 const translate)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatAxisAngleScaleTranslateDQfm(float2x4 dq_out, float3 const axis_unit, f32 const angle_degrees, f32 const scale_unif, float3 const translate)
{

	return dq_out;
}

ijk_inl float4km ijkDualQuatGetRotateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScaleDQfm(float2x4 const dq_in, f32* const scale_unif_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateScaleDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleScaleDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetTranslateDQfm(float2x4 const dq_in, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateTranslateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleTranslateDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScaleTranslateDQfm(float2x4 const dq_in, f32* const scale_unif_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetRotateScaleTranslateDQfm(float2x4 const dq_in, ijkRotationOrder const order, float3 rotateDegXYZ_out, f32* const scale_unif_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetAxisAngleScaleTranslateDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, f32* const scale_unif_out, float3 translate_out)
{

	return dq_in;
}

ijk_inl float4km ijkDualQuatGetScrewParamsDQfm(float2x4 const dq_in, float3 axis_unit_out, f32* const angle_degrees_out, float3 translate_out, float3 momentArm_out, f32* const screwDisplace_out)
{

	return dq_in;
}

ijk_inl float3m ijkDualQuatGetMatDQfm3(float3x3 m_out, float2x4 const dq_in)
{

	return m_out;
}

ijk_inl float4m ijkDualQuatGetMatDQfm4(float4x4 m_out, float2x4 const dq_in)
{

	return m_out;
}

ijk_inl floatv ijkDualQuatTransformVecDQfm3(float3 v_out, float2x4 const dq_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkDualQuatTransformVecDQfm4(float4 v_out, float2x4 const dq_in, float4 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkDualQuatTransformScaleVecDQfm3(float3 v_out, float2x4 const dq_in, float3 const v_in)
{

	return v_out;
}

ijk_inl floatv ijkDualQuatTransformScaleVecDQfm4(float4 v_out, float2x4 const dq_in, float4 const v_in)
{

	return v_out;
}

ijk_inl float4m ijkDualQuatLerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatNlerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatSclerpDQfm(float2x4 dq_out, float2x4 const dq0, float2x4 const dq1, f32 const u)
{

	return dq_out;
}

ijk_inl float4m ijkDualQuatDerivDQfm(float2x4 dq1_out, float2x4 const dq_in, float3 const linearVelocity, float3 const angularVelocity)
{

	return dq1_out;
}

ijk_inl float4m ijkDualQuatDeriv2DQfm(float2x4 dq2_out, float2x4 dq1_out, float2x4 const dq_in, float3 const linearVelocity, float3 const linearAcceleration, float3 const angularVelocity, float3 const angularAcceleration)
{

	return dq2_out;
}


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


#endif	// !_IJK_QUATERNION_FLOAT_INL_
#endif	// _IJK_QUATERNION_FLOAT_H_