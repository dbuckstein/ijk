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

	ijkVectorSwizzle.cpp
	C++ testing source definitions for vector types.
*/

#define IJK_VECTOR_SWIZZLE
#include "ijk/ijk-math/ijk-real/ijkVector.h"


//-----------------------------------------------------------------------------

extern "C" {
	void ijkMathTestVectorSwizzle();
}

void ijkMathTestVectorSwizzle()
{
	ivec2 test_ivec2(7, 13);
	ivec2 test_isvec2 = ivec2(42, 9001).yx;	// ivec2 ctor -> call swiz -> isvec2 ctor -> ivec2 ctor: test_isvec2 = (9001, 42)
	ivec2 const test_ivec2k = test_isvec2.yx;	// call swiz -> isvec2 ctor -> ivec2 ctor: test_ivec2k = (42, 9001)

	int test_ivec1 = 4;
	int test_ivec1r = test_ivec1;

	ivec3 test_ivec3x = ivec3_x, test_ivec3y = ivec3_y;

	ivec3 test_ivec3;
	ivec4 test_ivec4;

	uvec2 test_uvec2;
	uvec3 test_uvec3;
	uvec4 test_uvec4;

	vec2 test_vec2;
	vec3 test_vec3;
	vec4 test_vec4;

	dvec2 test_dvec2;
	dvec3 test_dvec3;
	dvec4 test_dvec4;

	i32 test_dot3iv = dot3iv(test_ivec3x.xyz, test_ivec3y.xyz);
	//i32 test_dot3iv = dot3iv(test_ivec3x.xyz, test_ivec3y.yxz);
	int test_dot3i = dot3i(test_ivec3x, test_ivec3y);
	//intv test_cross3iv = cross3iv(test_ivec3.xyz, test_ivec3x.xyz, test_ivec3y.xyz);
	intv test_cross3iv = cross3iv(test_ivec3.zyx, test_ivec3x.xyz, test_ivec3y.xyz);
	ivec3 test_cross3i = cross3i(test_ivec3x, test_ivec3y);

	//test_ivec3.zyx += 1;

	//(test_ivec2 + 7).x = 1;		// error: lhs is const
	test_ivec2.x = 1;				// call swiz -> assign

	test_isvec2 = test_ivec2.xx;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (7, 7)
	test_isvec2 = test_ivec2.xy;	// call swiz -> isvec2 ctor -> ivec2 assign isvec2: test_isvec2 = (7, 13)
	test_isvec2 = test_ivec2.yx;	// call swiz -> isvec2 ctor -> ivec2 assign isvec2: test_isvec2 = (13, 7)
	test_isvec2 = test_ivec2.yy;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (13, 13)

	test_isvec2 = test_ivec2k.xx;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (42, 42)
	test_isvec2 = test_ivec2k.xy;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (42, 9001)
	test_isvec2 = test_ivec2k.yx;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (9001, 42)
	test_isvec2 = test_ivec2k.yy;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (9001, 9001)

//	test_isvec2 = test_ivec2.xx = test_ivec2k;		// error: xx returns const
//	test_isvec2 = test_ivec2.yy = test_ivec2k;		// error: yy returns const
//	test_ivec2k.xy = test_ivec2;					// error: test_ivec2k is const
//	test_ivec2k.yx = test_ivec2;					// error: test_ivec2k is const
	test_isvec2.yx = test_ivec2.yx = test_ivec2k;	// test_ivec2 call swiz -> isvec2 (test_ivec2) ctor -> isvec2 (test_ivec2) assign ivec2: test_ivec2 = (9001, 42) -> test_isvec2 call swiz -> isvec2 (test_isvec2) ctor -> isvec2 (test_isvec2) assign ivec2: test_isvec2 = (9001, 42)
	test_isvec2 = test_ivec2.xy = test_ivec2k;		// test_ivec2 call swiz -> isvec2 ctor -> isvec2 (test_ivec2) assign ivec2: test_ivec2 = (42, 9001) -> test_isvec2 ivec2 assign ivec2: test_isvec2 = (42, 9001)
	test_ivec2 = test_ivec2.yx;						// test_ivec2 call swiz -> isvec2 ctor -> ivec2 assign isvec2 -> ivec2 ctor isvec2: test_ivec2 = (9001, 42)
	test_ivec2.yx = test_ivec2;						// test_ivec2 call swiz -> isvec2 ctor -> isvec2 assign ivec2: test_ivec2 = (42, 9001)
	test_isvec2.xy = test_ivec2.xy;					// test_ivec2 call swiz -> isvec2 (test_ivec2) ctor -> test_isvec2 call swiz -> isvec2 (test_isvec2) ctor -> isvec2 (test_isvec2) assign isvec2 (test_ivec2) -> test_isvec2 = (42, 9001)
	test_isvec2.xy = test_ivec2.yx;					// test_ivec2 call swiz -> isvec2 (test_ivec2) ctor -> test_isvec2 call swiz -> isvec2 (test_isvec2) ctor -> isvec2 (test_isvec2) assign isvec2 (test_ivec2) -> test_isvec2 = (9001, 42)
	test_isvec2.yx = test_ivec2.xy;					// test_ivec2 call swiz -> isvec2 (test_ivec2) ctor -> test_isvec2 call swiz -> isvec2 (test_isvec2) ctor -> isvec2 (test_isvec2) assign isvec2 (test_ivec2) -> test_isvec2 = (9001, 42)
	test_isvec2.yx = test_ivec2.yx;					// test_ivec2 call swiz -> isvec2 (test_ivec2) ctor -> test_isvec2 call swiz -> isvec2 (test_isvec2) ctor -> isvec2 (test_isvec2) assign isvec2 (test_ivec2) -> test_isvec2 = (42, 9001)
	test_ivec2.xy = test_ivec2.xy;					// test_ivec2 call swiz -> isvec2 ctor -> test_ivec2 call swiz -> isvec2 ctor -> isvec2 assign isvec2 -> test_isvec2 = (42, 9001)
	test_ivec2.xy = test_ivec2.yx;					// test_ivec2 call swiz -> isvec2 ctor -> test_ivec2 call swiz -> isvec2 ctor -> isvec2 assign isvec2 -> test_isvec2 = (9001, 42)
	test_ivec2.yx = test_ivec2.xy;					// test_ivec2 call swiz -> isvec2 ctor -> test_ivec2 call swiz -> isvec2 ctor -> isvec2 assign isvec2 -> test_isvec2 = (42, 9001)
	test_ivec2.yx = test_ivec2.yx;					// test_ivec2 call swiz -> isvec2 ctor -> test_ivec2 call swiz -> isvec2 ctor -> isvec2 assign isvec2 -> test_isvec2 = (42, 9001)

	test_ivec2.xxx;
	test_ivec2.xxy;
	test_ivec2.xyx;
	test_ivec2.xyy;
	test_ivec2.yxx;
	test_ivec2.yxy;
	test_ivec2.yyx;
	test_ivec2.yyy;
	test_ivec2.xxxx;
	test_ivec2.xxxy;
	test_ivec2.xxyx;
	test_ivec2.xxyy;
	test_ivec2.xyxx;
	test_ivec2.xyxy;
	test_ivec2.xyyx;
	test_ivec2.xyyy;
	test_ivec2.yxxx;
	test_ivec2.yxxy;
	test_ivec2.yxyx;
	test_ivec2.yxyy;
	test_ivec2.yyxx;
	test_ivec2.yyxy;
	test_ivec2.yyyx;
	test_ivec2.yyyy;

	test_ivec3.xx;
	test_ivec3.xy;
	test_ivec3.xz;
	test_ivec3.yx;
	test_ivec3.yy;
	test_ivec3.yz;
	test_ivec3.zx;
	test_ivec3.zy;
	test_ivec3.zz;
	test_ivec3.xxx;
	test_ivec3.xxy;
	test_ivec3.xxz;
	test_ivec3.xyx;
	test_ivec3.xyy;
	test_ivec3.xyz;
	test_ivec3.xzx;
	test_ivec3.xzy;
	test_ivec3.xzz;
	test_ivec3.yxx;
	test_ivec3.yxy;
	test_ivec3.yxz;
	test_ivec3.yyx;
	test_ivec3.yyy;
	test_ivec3.yyz;
	test_ivec3.yzx;
	test_ivec3.yzy;
	test_ivec3.yzz;
	test_ivec3.zxx;
	test_ivec3.zxy;
	test_ivec3.zxz;
	test_ivec3.zyx;
	test_ivec3.zyy;
	test_ivec3.zyz;
	test_ivec3.zzx;
	test_ivec3.zzy;
	test_ivec3.zzz;
	test_ivec3.xxxx;
	test_ivec3.xxxy;
	test_ivec3.xxxz;
	test_ivec3.xxyx;
	test_ivec3.xxyy;
	test_ivec3.xxyz;
	test_ivec3.xxzx;
	test_ivec3.xxzy;
	test_ivec3.xxzz;
	test_ivec3.xyxx;
	test_ivec3.xyxy;
	test_ivec3.xyxz;
	test_ivec3.xyyx;
	test_ivec3.xyyy;
	test_ivec3.xyyz;
	test_ivec3.xyzx;
	test_ivec3.xyzy;
	test_ivec3.xyzz;
	test_ivec3.xzxx;
	test_ivec3.xzxy;
	test_ivec3.xzxz;
	test_ivec3.xzyx;
	test_ivec3.xzyy;
	test_ivec3.xzyz;
	test_ivec3.xzzx;
	test_ivec3.xzzy;
	test_ivec3.xzzz;
	test_ivec3.yxxx;
	test_ivec3.yxxy;
	test_ivec3.yxxz;
	test_ivec3.yxyx;
	test_ivec3.yxyy;
	test_ivec3.yxyz;
	test_ivec3.yxzx;
	test_ivec3.yxzy;
	test_ivec3.yxzz;
	test_ivec3.yyxx;
	test_ivec3.yyxy;
	test_ivec3.yyxz;
	test_ivec3.yyyx;
	test_ivec3.yyyy;
	test_ivec3.yyyz;
	test_ivec3.yyzx;
	test_ivec3.yyzy;
	test_ivec3.yyzz;
	test_ivec3.yzxx;
	test_ivec3.yzxy;
	test_ivec3.yzxz;
	test_ivec3.yzyx;
	test_ivec3.yzyy;
	test_ivec3.yzyz;
	test_ivec3.yzzx;
	test_ivec3.yzzy;
	test_ivec3.yzzz;
	test_ivec3.zxxx;
	test_ivec3.zxxy;
	test_ivec3.zxxz;
	test_ivec3.zxyx;
	test_ivec3.zxyy;
	test_ivec3.zxyz;
	test_ivec3.zxzx;
	test_ivec3.zxzy;
	test_ivec3.zxzz;
	test_ivec3.zyxx;
	test_ivec3.zyxy;
	test_ivec3.zyxz;
	test_ivec3.zyyx;
	test_ivec3.zyyy;
	test_ivec3.zyyz;
	test_ivec3.zyzx;
	test_ivec3.zyzy;
	test_ivec3.zyzz;
	test_ivec3.zzxx;
	test_ivec3.zzxy;
	test_ivec3.zzxz;
	test_ivec3.zzyx;
	test_ivec3.zzyy;
	test_ivec3.zzyz;
	test_ivec3.zzzx;
	test_ivec3.zzzy;
	test_ivec3.zzzz;

	test_ivec4.xx;
	test_ivec4.xy;
	test_ivec4.xz;
	test_ivec4.xw;
	test_ivec4.yx;
	test_ivec4.yy;
	test_ivec4.yz;
	test_ivec4.yw;
	test_ivec4.zx;
	test_ivec4.zy;
	test_ivec4.zz;
	test_ivec4.zw;
	test_ivec4.wx;
	test_ivec4.wy;
	test_ivec4.wz;
	test_ivec4.ww;
	test_ivec4.xxx;
	test_ivec4.xxy;
	test_ivec4.xxz;
	test_ivec4.xxw;
	test_ivec4.xyx;
	test_ivec4.xyy;
	test_ivec4.xyz;
	test_ivec4.xyw;
	test_ivec4.xzx;
	test_ivec4.xzy;
	test_ivec4.xzz;
	test_ivec4.xzw;
	test_ivec4.xwx;
	test_ivec4.xwy;
	test_ivec4.xwz;
	test_ivec4.xww;
	test_ivec4.yxx;
	test_ivec4.yxy;
	test_ivec4.yxz;
	test_ivec4.yxw;
	test_ivec4.yyx;
	test_ivec4.yyy;
	test_ivec4.yyz;
	test_ivec4.yyw;
	test_ivec4.yzx;
	test_ivec4.yzy;
	test_ivec4.yzz;
	test_ivec4.yzw;
	test_ivec4.ywx;
	test_ivec4.ywy;
	test_ivec4.ywz;
	test_ivec4.yww;
	test_ivec4.zxx;
	test_ivec4.zxy;
	test_ivec4.zxz;
	test_ivec4.zxw;
	test_ivec4.zyx;
	test_ivec4.zyy;
	test_ivec4.zyz;
	test_ivec4.zyw;
	test_ivec4.zzx;
	test_ivec4.zzy;
	test_ivec4.zzz;
	test_ivec4.zzw;
	test_ivec4.zwx;
	test_ivec4.zwy;
	test_ivec4.zwz;
	test_ivec4.zww;
	test_ivec4.wxx;
	test_ivec4.wxy;
	test_ivec4.wxz;
	test_ivec4.wxw;
	test_ivec4.wyx;
	test_ivec4.wyy;
	test_ivec4.wyz;
	test_ivec4.wyw;
	test_ivec4.wzx;
	test_ivec4.wzy;
	test_ivec4.wzz;
	test_ivec4.wzw;
	test_ivec4.wwx;
	test_ivec4.wwy;
	test_ivec4.wwz;
	test_ivec4.www;
	test_ivec4.xxxx;
	test_ivec4.xxxy;
	test_ivec4.xxxz;
	test_ivec4.xxxw;
	test_ivec4.xxyx;
	test_ivec4.xxyy;
	test_ivec4.xxyz;
	test_ivec4.xxyw;
	test_ivec4.xxzx;
	test_ivec4.xxzy;
	test_ivec4.xxzz;
	test_ivec4.xxzw;
	test_ivec4.xxwx;
	test_ivec4.xxwy;
	test_ivec4.xxwz;
	test_ivec4.xxww;
	test_ivec4.xyxx;
	test_ivec4.xyxy;
	test_ivec4.xyxz;
	test_ivec4.xyxw;
	test_ivec4.xyyx;
	test_ivec4.xyyy;
	test_ivec4.xyyz;
	test_ivec4.xyyw;
	test_ivec4.xyzx;
	test_ivec4.xyzy;
	test_ivec4.xyzz;
	test_ivec4.xyzw;
	test_ivec4.xywx;
	test_ivec4.xywy;
	test_ivec4.xywz;
	test_ivec4.xyww;
	test_ivec4.xzxx;
	test_ivec4.xzxy;
	test_ivec4.xzxz;
	test_ivec4.xzxw;
	test_ivec4.xzyx;
	test_ivec4.xzyy;
	test_ivec4.xzyz;
	test_ivec4.xzyw;
	test_ivec4.xzzx;
	test_ivec4.xzzy;
	test_ivec4.xzzz;
	test_ivec4.xzzw;
	test_ivec4.xzwx;
	test_ivec4.xzwy;
	test_ivec4.xzwz;
	test_ivec4.xzww;
	test_ivec4.xwxx;
	test_ivec4.xwxy;
	test_ivec4.xwxz;
	test_ivec4.xwxw;
	test_ivec4.xwyx;
	test_ivec4.xwyy;
	test_ivec4.xwyz;
	test_ivec4.xwyw;
	test_ivec4.xwzx;
	test_ivec4.xwzy;
	test_ivec4.xwzz;
	test_ivec4.xwzw;
	test_ivec4.xwwx;
	test_ivec4.xwwy;
	test_ivec4.xwwz;
	test_ivec4.xwww;
	test_ivec4.yxxx;
	test_ivec4.yxxy;
	test_ivec4.yxxz;
	test_ivec4.yxxw;
	test_ivec4.yxyx;
	test_ivec4.yxyy;
	test_ivec4.yxyz;
	test_ivec4.yxyw;
	test_ivec4.yxzx;
	test_ivec4.yxzy;
	test_ivec4.yxzz;
	test_ivec4.yxzw;
	test_ivec4.yxwx;
	test_ivec4.yxwy;
	test_ivec4.yxwz;
	test_ivec4.yxww;
	test_ivec4.yyxx;
	test_ivec4.yyxy;
	test_ivec4.yyxz;
	test_ivec4.yyxw;
	test_ivec4.yyyx;
	test_ivec4.yyyy;
	test_ivec4.yyyz;
	test_ivec4.yyyw;
	test_ivec4.yyzx;
	test_ivec4.yyzy;
	test_ivec4.yyzz;
	test_ivec4.yyzw;
	test_ivec4.yywx;
	test_ivec4.yywy;
	test_ivec4.yywz;
	test_ivec4.yyww;
	test_ivec4.yzxx;
	test_ivec4.yzxy;
	test_ivec4.yzxz;
	test_ivec4.yzxw;
	test_ivec4.yzyx;
	test_ivec4.yzyy;
	test_ivec4.yzyz;
	test_ivec4.yzyw;
	test_ivec4.yzzx;
	test_ivec4.yzzy;
	test_ivec4.yzzz;
	test_ivec4.yzzw;
	test_ivec4.yzwx;
	test_ivec4.yzwy;
	test_ivec4.yzwz;
	test_ivec4.yzww;
	test_ivec4.ywxx;
	test_ivec4.ywxy;
	test_ivec4.ywxz;
	test_ivec4.ywxw;
	test_ivec4.ywyx;
	test_ivec4.ywyy;
	test_ivec4.ywyz;
	test_ivec4.ywyw;
	test_ivec4.ywzx;
	test_ivec4.ywzy;
	test_ivec4.ywzz;
	test_ivec4.ywzw;
	test_ivec4.ywwx;
	test_ivec4.ywwy;
	test_ivec4.ywwz;
	test_ivec4.ywww;
	test_ivec4.zxxx;
	test_ivec4.zxxy;
	test_ivec4.zxxz;
	test_ivec4.zxxw;
	test_ivec4.zxyx;
	test_ivec4.zxyy;
	test_ivec4.zxyz;
	test_ivec4.zxyw;
	test_ivec4.zxzx;
	test_ivec4.zxzy;
	test_ivec4.zxzz;
	test_ivec4.zxzw;
	test_ivec4.zxwx;
	test_ivec4.zxwy;
	test_ivec4.zxwz;
	test_ivec4.zxww;
	test_ivec4.zyxx;
	test_ivec4.zyxy;
	test_ivec4.zyxz;
	test_ivec4.zyxw;
	test_ivec4.zyyx;
	test_ivec4.zyyy;
	test_ivec4.zyyz;
	test_ivec4.zyyw;
	test_ivec4.zyzx;
	test_ivec4.zyzy;
	test_ivec4.zyzz;
	test_ivec4.zyzw;
	test_ivec4.zywx;
	test_ivec4.zywy;
	test_ivec4.zywz;
	test_ivec4.zyww;
	test_ivec4.zzxx;
	test_ivec4.zzxy;
	test_ivec4.zzxz;
	test_ivec4.zzxw;
	test_ivec4.zzyx;
	test_ivec4.zzyy;
	test_ivec4.zzyz;
	test_ivec4.zzyw;
	test_ivec4.zzzx;
	test_ivec4.zzzy;
	test_ivec4.zzzz;
	test_ivec4.zzzw;
	test_ivec4.zzwx;
	test_ivec4.zzwy;
	test_ivec4.zzwz;
	test_ivec4.zzww;
	test_ivec4.zwxx;
	test_ivec4.zwxy;
	test_ivec4.zwxz;
	test_ivec4.zwxw;
	test_ivec4.zwyx;
	test_ivec4.zwyy;
	test_ivec4.zwyz;
	test_ivec4.zwyw;
	test_ivec4.zwzx;
	test_ivec4.zwzy;
	test_ivec4.zwzz;
	test_ivec4.zwzw;
	test_ivec4.zwwx;
	test_ivec4.zwwy;
	test_ivec4.zwwz;
	test_ivec4.zwww;
	test_ivec4.wxxx;
	test_ivec4.wxxy;
	test_ivec4.wxxz;
	test_ivec4.wxxw;
	test_ivec4.wxyx;
	test_ivec4.wxyy;
	test_ivec4.wxyz;
	test_ivec4.wxyw;
	test_ivec4.wxzx;
	test_ivec4.wxzy;
	test_ivec4.wxzz;
	test_ivec4.wxzw;
	test_ivec4.wxwx;
	test_ivec4.wxwy;
	test_ivec4.wxwz;
	test_ivec4.wxww;
	test_ivec4.wyxx;
	test_ivec4.wyxy;
	test_ivec4.wyxz;
	test_ivec4.wyxw;
	test_ivec4.wyyx;
	test_ivec4.wyyy;
	test_ivec4.wyyz;
	test_ivec4.wyyw;
	test_ivec4.wyzx;
	test_ivec4.wyzy;
	test_ivec4.wyzz;
	test_ivec4.wyzw;
	test_ivec4.wywx;
	test_ivec4.wywy;
	test_ivec4.wywz;
	test_ivec4.wyww;
	test_ivec4.wzxx;
	test_ivec4.wzxy;
	test_ivec4.wzxz;
	test_ivec4.wzxw;
	test_ivec4.wzyx;
	test_ivec4.wzyy;
	test_ivec4.wzyz;
	test_ivec4.wzyw;
	test_ivec4.wzzx;
	test_ivec4.wzzy;
	test_ivec4.wzzz;
	test_ivec4.wzzw;
	test_ivec4.wzwx;
	test_ivec4.wzwy;
	test_ivec4.wzwz;
	test_ivec4.wzww;
	test_ivec4.wwxx;
	test_ivec4.wwxy;
	test_ivec4.wwxz;
	test_ivec4.wwxw;
	test_ivec4.wwyx;
	test_ivec4.wwyy;
	test_ivec4.wwyz;
	test_ivec4.wwyw;
	test_ivec4.wwzx;
	test_ivec4.wwzy;
	test_ivec4.wwzz;
	test_ivec4.wwzw;
	test_ivec4.wwwx;
	test_ivec4.wwwy;
	test_ivec4.wwwz;
	test_ivec4.wwww;

	test_uvec2.xxx;
	test_uvec2.xxy;
	test_uvec2.xyx;
	test_uvec2.xyy;
	test_uvec2.yxx;
	test_uvec2.yxy;
	test_uvec2.yyx;
	test_uvec2.yyy;
	test_uvec2.xxxx;
	test_uvec2.xxxy;
	test_uvec2.xxyx;
	test_uvec2.xxyy;
	test_uvec2.xyxx;
	test_uvec2.xyxy;
	test_uvec2.xyyx;
	test_uvec2.xyyy;
	test_uvec2.yxxx;
	test_uvec2.yxxy;
	test_uvec2.yxyx;
	test_uvec2.yxyy;
	test_uvec2.yyxx;
	test_uvec2.yyxy;
	test_uvec2.yyyx;
	test_uvec2.yyyy;

	test_uvec3.xx;
	test_uvec3.xy;
	test_uvec3.xz;
	test_uvec3.yx;
	test_uvec3.yy;
	test_uvec3.yz;
	test_uvec3.zx;
	test_uvec3.zy;
	test_uvec3.zz;
	test_uvec3.xxx;
	test_uvec3.xxy;
	test_uvec3.xxz;
	test_uvec3.xyx;
	test_uvec3.xyy;
	test_uvec3.xyz;
	test_uvec3.xzx;
	test_uvec3.xzy;
	test_uvec3.xzz;
	test_uvec3.yxx;
	test_uvec3.yxy;
	test_uvec3.yxz;
	test_uvec3.yyx;
	test_uvec3.yyy;
	test_uvec3.yyz;
	test_uvec3.yzx;
	test_uvec3.yzy;
	test_uvec3.yzz;
	test_uvec3.zxx;
	test_uvec3.zxy;
	test_uvec3.zxz;
	test_uvec3.zyx;
	test_uvec3.zyy;
	test_uvec3.zyz;
	test_uvec3.zzx;
	test_uvec3.zzy;
	test_uvec3.zzz;
	test_uvec3.xxxx;
	test_uvec3.xxxy;
	test_uvec3.xxxz;
	test_uvec3.xxyx;
	test_uvec3.xxyy;
	test_uvec3.xxyz;
	test_uvec3.xxzx;
	test_uvec3.xxzy;
	test_uvec3.xxzz;
	test_uvec3.xyxx;
	test_uvec3.xyxy;
	test_uvec3.xyxz;
	test_uvec3.xyyx;
	test_uvec3.xyyy;
	test_uvec3.xyyz;
	test_uvec3.xyzx;
	test_uvec3.xyzy;
	test_uvec3.xyzz;
	test_uvec3.xzxx;
	test_uvec3.xzxy;
	test_uvec3.xzxz;
	test_uvec3.xzyx;
	test_uvec3.xzyy;
	test_uvec3.xzyz;
	test_uvec3.xzzx;
	test_uvec3.xzzy;
	test_uvec3.xzzz;
	test_uvec3.yxxx;
	test_uvec3.yxxy;
	test_uvec3.yxxz;
	test_uvec3.yxyx;
	test_uvec3.yxyy;
	test_uvec3.yxyz;
	test_uvec3.yxzx;
	test_uvec3.yxzy;
	test_uvec3.yxzz;
	test_uvec3.yyxx;
	test_uvec3.yyxy;
	test_uvec3.yyxz;
	test_uvec3.yyyx;
	test_uvec3.yyyy;
	test_uvec3.yyyz;
	test_uvec3.yyzx;
	test_uvec3.yyzy;
	test_uvec3.yyzz;
	test_uvec3.yzxx;
	test_uvec3.yzxy;
	test_uvec3.yzxz;
	test_uvec3.yzyx;
	test_uvec3.yzyy;
	test_uvec3.yzyz;
	test_uvec3.yzzx;
	test_uvec3.yzzy;
	test_uvec3.yzzz;
	test_uvec3.zxxx;
	test_uvec3.zxxy;
	test_uvec3.zxxz;
	test_uvec3.zxyx;
	test_uvec3.zxyy;
	test_uvec3.zxyz;
	test_uvec3.zxzx;
	test_uvec3.zxzy;
	test_uvec3.zxzz;
	test_uvec3.zyxx;
	test_uvec3.zyxy;
	test_uvec3.zyxz;
	test_uvec3.zyyx;
	test_uvec3.zyyy;
	test_uvec3.zyyz;
	test_uvec3.zyzx;
	test_uvec3.zyzy;
	test_uvec3.zyzz;
	test_uvec3.zzxx;
	test_uvec3.zzxy;
	test_uvec3.zzxz;
	test_uvec3.zzyx;
	test_uvec3.zzyy;
	test_uvec3.zzyz;
	test_uvec3.zzzx;
	test_uvec3.zzzy;
	test_uvec3.zzzz;

	test_uvec4.xx;
	test_uvec4.xy;
	test_uvec4.xz;
	test_uvec4.xw;
	test_uvec4.yx;
	test_uvec4.yy;
	test_uvec4.yz;
	test_uvec4.yw;
	test_uvec4.zx;
	test_uvec4.zy;
	test_uvec4.zz;
	test_uvec4.zw;
	test_uvec4.wx;
	test_uvec4.wy;
	test_uvec4.wz;
	test_uvec4.ww;
	test_uvec4.xxx;
	test_uvec4.xxy;
	test_uvec4.xxz;
	test_uvec4.xxw;
	test_uvec4.xyx;
	test_uvec4.xyy;
	test_uvec4.xyz;
	test_uvec4.xyw;
	test_uvec4.xzx;
	test_uvec4.xzy;
	test_uvec4.xzz;
	test_uvec4.xzw;
	test_uvec4.xwx;
	test_uvec4.xwy;
	test_uvec4.xwz;
	test_uvec4.xww;
	test_uvec4.yxx;
	test_uvec4.yxy;
	test_uvec4.yxz;
	test_uvec4.yxw;
	test_uvec4.yyx;
	test_uvec4.yyy;
	test_uvec4.yyz;
	test_uvec4.yyw;
	test_uvec4.yzx;
	test_uvec4.yzy;
	test_uvec4.yzz;
	test_uvec4.yzw;
	test_uvec4.ywx;
	test_uvec4.ywy;
	test_uvec4.ywz;
	test_uvec4.yww;
	test_uvec4.zxx;
	test_uvec4.zxy;
	test_uvec4.zxz;
	test_uvec4.zxw;
	test_uvec4.zyx;
	test_uvec4.zyy;
	test_uvec4.zyz;
	test_uvec4.zyw;
	test_uvec4.zzx;
	test_uvec4.zzy;
	test_uvec4.zzz;
	test_uvec4.zzw;
	test_uvec4.zwx;
	test_uvec4.zwy;
	test_uvec4.zwz;
	test_uvec4.zww;
	test_uvec4.wxx;
	test_uvec4.wxy;
	test_uvec4.wxz;
	test_uvec4.wxw;
	test_uvec4.wyx;
	test_uvec4.wyy;
	test_uvec4.wyz;
	test_uvec4.wyw;
	test_uvec4.wzx;
	test_uvec4.wzy;
	test_uvec4.wzz;
	test_uvec4.wzw;
	test_uvec4.wwx;
	test_uvec4.wwy;
	test_uvec4.wwz;
	test_uvec4.www;
	test_uvec4.xxxx;
	test_uvec4.xxxy;
	test_uvec4.xxxz;
	test_uvec4.xxxw;
	test_uvec4.xxyx;
	test_uvec4.xxyy;
	test_uvec4.xxyz;
	test_uvec4.xxyw;
	test_uvec4.xxzx;
	test_uvec4.xxzy;
	test_uvec4.xxzz;
	test_uvec4.xxzw;
	test_uvec4.xxwx;
	test_uvec4.xxwy;
	test_uvec4.xxwz;
	test_uvec4.xxww;
	test_uvec4.xyxx;
	test_uvec4.xyxy;
	test_uvec4.xyxz;
	test_uvec4.xyxw;
	test_uvec4.xyyx;
	test_uvec4.xyyy;
	test_uvec4.xyyz;
	test_uvec4.xyyw;
	test_uvec4.xyzx;
	test_uvec4.xyzy;
	test_uvec4.xyzz;
	test_uvec4.xyzw;
	test_uvec4.xywx;
	test_uvec4.xywy;
	test_uvec4.xywz;
	test_uvec4.xyww;
	test_uvec4.xzxx;
	test_uvec4.xzxy;
	test_uvec4.xzxz;
	test_uvec4.xzxw;
	test_uvec4.xzyx;
	test_uvec4.xzyy;
	test_uvec4.xzyz;
	test_uvec4.xzyw;
	test_uvec4.xzzx;
	test_uvec4.xzzy;
	test_uvec4.xzzz;
	test_uvec4.xzzw;
	test_uvec4.xzwx;
	test_uvec4.xzwy;
	test_uvec4.xzwz;
	test_uvec4.xzww;
	test_uvec4.xwxx;
	test_uvec4.xwxy;
	test_uvec4.xwxz;
	test_uvec4.xwxw;
	test_uvec4.xwyx;
	test_uvec4.xwyy;
	test_uvec4.xwyz;
	test_uvec4.xwyw;
	test_uvec4.xwzx;
	test_uvec4.xwzy;
	test_uvec4.xwzz;
	test_uvec4.xwzw;
	test_uvec4.xwwx;
	test_uvec4.xwwy;
	test_uvec4.xwwz;
	test_uvec4.xwww;
	test_uvec4.yxxx;
	test_uvec4.yxxy;
	test_uvec4.yxxz;
	test_uvec4.yxxw;
	test_uvec4.yxyx;
	test_uvec4.yxyy;
	test_uvec4.yxyz;
	test_uvec4.yxyw;
	test_uvec4.yxzx;
	test_uvec4.yxzy;
	test_uvec4.yxzz;
	test_uvec4.yxzw;
	test_uvec4.yxwx;
	test_uvec4.yxwy;
	test_uvec4.yxwz;
	test_uvec4.yxww;
	test_uvec4.yyxx;
	test_uvec4.yyxy;
	test_uvec4.yyxz;
	test_uvec4.yyxw;
	test_uvec4.yyyx;
	test_uvec4.yyyy;
	test_uvec4.yyyz;
	test_uvec4.yyyw;
	test_uvec4.yyzx;
	test_uvec4.yyzy;
	test_uvec4.yyzz;
	test_uvec4.yyzw;
	test_uvec4.yywx;
	test_uvec4.yywy;
	test_uvec4.yywz;
	test_uvec4.yyww;
	test_uvec4.yzxx;
	test_uvec4.yzxy;
	test_uvec4.yzxz;
	test_uvec4.yzxw;
	test_uvec4.yzyx;
	test_uvec4.yzyy;
	test_uvec4.yzyz;
	test_uvec4.yzyw;
	test_uvec4.yzzx;
	test_uvec4.yzzy;
	test_uvec4.yzzz;
	test_uvec4.yzzw;
	test_uvec4.yzwx;
	test_uvec4.yzwy;
	test_uvec4.yzwz;
	test_uvec4.yzww;
	test_uvec4.ywxx;
	test_uvec4.ywxy;
	test_uvec4.ywxz;
	test_uvec4.ywxw;
	test_uvec4.ywyx;
	test_uvec4.ywyy;
	test_uvec4.ywyz;
	test_uvec4.ywyw;
	test_uvec4.ywzx;
	test_uvec4.ywzy;
	test_uvec4.ywzz;
	test_uvec4.ywzw;
	test_uvec4.ywwx;
	test_uvec4.ywwy;
	test_uvec4.ywwz;
	test_uvec4.ywww;
	test_uvec4.zxxx;
	test_uvec4.zxxy;
	test_uvec4.zxxz;
	test_uvec4.zxxw;
	test_uvec4.zxyx;
	test_uvec4.zxyy;
	test_uvec4.zxyz;
	test_uvec4.zxyw;
	test_uvec4.zxzx;
	test_uvec4.zxzy;
	test_uvec4.zxzz;
	test_uvec4.zxzw;
	test_uvec4.zxwx;
	test_uvec4.zxwy;
	test_uvec4.zxwz;
	test_uvec4.zxww;
	test_uvec4.zyxx;
	test_uvec4.zyxy;
	test_uvec4.zyxz;
	test_uvec4.zyxw;
	test_uvec4.zyyx;
	test_uvec4.zyyy;
	test_uvec4.zyyz;
	test_uvec4.zyyw;
	test_uvec4.zyzx;
	test_uvec4.zyzy;
	test_uvec4.zyzz;
	test_uvec4.zyzw;
	test_uvec4.zywx;
	test_uvec4.zywy;
	test_uvec4.zywz;
	test_uvec4.zyww;
	test_uvec4.zzxx;
	test_uvec4.zzxy;
	test_uvec4.zzxz;
	test_uvec4.zzxw;
	test_uvec4.zzyx;
	test_uvec4.zzyy;
	test_uvec4.zzyz;
	test_uvec4.zzyw;
	test_uvec4.zzzx;
	test_uvec4.zzzy;
	test_uvec4.zzzz;
	test_uvec4.zzzw;
	test_uvec4.zzwx;
	test_uvec4.zzwy;
	test_uvec4.zzwz;
	test_uvec4.zzww;
	test_uvec4.zwxx;
	test_uvec4.zwxy;
	test_uvec4.zwxz;
	test_uvec4.zwxw;
	test_uvec4.zwyx;
	test_uvec4.zwyy;
	test_uvec4.zwyz;
	test_uvec4.zwyw;
	test_uvec4.zwzx;
	test_uvec4.zwzy;
	test_uvec4.zwzz;
	test_uvec4.zwzw;
	test_uvec4.zwwx;
	test_uvec4.zwwy;
	test_uvec4.zwwz;
	test_uvec4.zwww;
	test_uvec4.wxxx;
	test_uvec4.wxxy;
	test_uvec4.wxxz;
	test_uvec4.wxxw;
	test_uvec4.wxyx;
	test_uvec4.wxyy;
	test_uvec4.wxyz;
	test_uvec4.wxyw;
	test_uvec4.wxzx;
	test_uvec4.wxzy;
	test_uvec4.wxzz;
	test_uvec4.wxzw;
	test_uvec4.wxwx;
	test_uvec4.wxwy;
	test_uvec4.wxwz;
	test_uvec4.wxww;
	test_uvec4.wyxx;
	test_uvec4.wyxy;
	test_uvec4.wyxz;
	test_uvec4.wyxw;
	test_uvec4.wyyx;
	test_uvec4.wyyy;
	test_uvec4.wyyz;
	test_uvec4.wyyw;
	test_uvec4.wyzx;
	test_uvec4.wyzy;
	test_uvec4.wyzz;
	test_uvec4.wyzw;
	test_uvec4.wywx;
	test_uvec4.wywy;
	test_uvec4.wywz;
	test_uvec4.wyww;
	test_uvec4.wzxx;
	test_uvec4.wzxy;
	test_uvec4.wzxz;
	test_uvec4.wzxw;
	test_uvec4.wzyx;
	test_uvec4.wzyy;
	test_uvec4.wzyz;
	test_uvec4.wzyw;
	test_uvec4.wzzx;
	test_uvec4.wzzy;
	test_uvec4.wzzz;
	test_uvec4.wzzw;
	test_uvec4.wzwx;
	test_uvec4.wzwy;
	test_uvec4.wzwz;
	test_uvec4.wzww;
	test_uvec4.wwxx;
	test_uvec4.wwxy;
	test_uvec4.wwxz;
	test_uvec4.wwxw;
	test_uvec4.wwyx;
	test_uvec4.wwyy;
	test_uvec4.wwyz;
	test_uvec4.wwyw;
	test_uvec4.wwzx;
	test_uvec4.wwzy;
	test_uvec4.wwzz;
	test_uvec4.wwzw;
	test_uvec4.wwwx;
	test_uvec4.wwwy;
	test_uvec4.wwwz;
	test_uvec4.wwww;

	test_vec2.xx;
	test_vec2.xy;
	test_vec2.yx;
	test_vec2.yy;
	test_vec2.xxx;
	test_vec2.xxy;
	test_vec2.xyx;
	test_vec2.xyy;
	test_vec2.yxx;
	test_vec2.yxy;
	test_vec2.yyx;
	test_vec2.yyy;
	test_vec2.xxxx;
	test_vec2.xxxy;
	test_vec2.xxyx;
	test_vec2.xxyy;
	test_vec2.xyxx;
	test_vec2.xyxy;
	test_vec2.xyyx;
	test_vec2.xyyy;
	test_vec2.yxxx;
	test_vec2.yxxy;
	test_vec2.yxyx;
	test_vec2.yxyy;
	test_vec2.yyxx;
	test_vec2.yyxy;
	test_vec2.yyyx;
	test_vec2.yyyy;

	test_vec3.xx;
	test_vec3.xy;
	test_vec3.xz;
	test_vec3.yx;
	test_vec3.yy;
	test_vec3.yz;
	test_vec3.zx;
	test_vec3.zy;
	test_vec3.zz;
	test_vec3.xxx;
	test_vec3.xxy;
	test_vec3.xxz;
	test_vec3.xyx;
	test_vec3.xyy;
	test_vec3.xyz;
	test_vec3.xzx;
	test_vec3.xzy;
	test_vec3.xzz;
	test_vec3.yxx;
	test_vec3.yxy;
	test_vec3.yxz;
	test_vec3.yyx;
	test_vec3.yyy;
	test_vec3.yyz;
	test_vec3.yzx;
	test_vec3.yzy;
	test_vec3.yzz;
	test_vec3.zxx;
	test_vec3.zxy;
	test_vec3.zxz;
	test_vec3.zyx;
	test_vec3.zyy;
	test_vec3.zyz;
	test_vec3.zzx;
	test_vec3.zzy;
	test_vec3.zzz;
	test_vec3.xxxx;
	test_vec3.xxxy;
	test_vec3.xxxz;
	test_vec3.xxyx;
	test_vec3.xxyy;
	test_vec3.xxyz;
	test_vec3.xxzx;
	test_vec3.xxzy;
	test_vec3.xxzz;
	test_vec3.xyxx;
	test_vec3.xyxy;
	test_vec3.xyxz;
	test_vec3.xyyx;
	test_vec3.xyyy;
	test_vec3.xyyz;
	test_vec3.xyzx;
	test_vec3.xyzy;
	test_vec3.xyzz;
	test_vec3.xzxx;
	test_vec3.xzxy;
	test_vec3.xzxz;
	test_vec3.xzyx;
	test_vec3.xzyy;
	test_vec3.xzyz;
	test_vec3.xzzx;
	test_vec3.xzzy;
	test_vec3.xzzz;
	test_vec3.yxxx;
	test_vec3.yxxy;
	test_vec3.yxxz;
	test_vec3.yxyx;
	test_vec3.yxyy;
	test_vec3.yxyz;
	test_vec3.yxzx;
	test_vec3.yxzy;
	test_vec3.yxzz;
	test_vec3.yyxx;
	test_vec3.yyxy;
	test_vec3.yyxz;
	test_vec3.yyyx;
	test_vec3.yyyy;
	test_vec3.yyyz;
	test_vec3.yyzx;
	test_vec3.yyzy;
	test_vec3.yyzz;
	test_vec3.yzxx;
	test_vec3.yzxy;
	test_vec3.yzxz;
	test_vec3.yzyx;
	test_vec3.yzyy;
	test_vec3.yzyz;
	test_vec3.yzzx;
	test_vec3.yzzy;
	test_vec3.yzzz;
	test_vec3.zxxx;
	test_vec3.zxxy;
	test_vec3.zxxz;
	test_vec3.zxyx;
	test_vec3.zxyy;
	test_vec3.zxyz;
	test_vec3.zxzx;
	test_vec3.zxzy;
	test_vec3.zxzz;
	test_vec3.zyxx;
	test_vec3.zyxy;
	test_vec3.zyxz;
	test_vec3.zyyx;
	test_vec3.zyyy;
	test_vec3.zyyz;
	test_vec3.zyzx;
	test_vec3.zyzy;
	test_vec3.zyzz;
	test_vec3.zzxx;
	test_vec3.zzxy;
	test_vec3.zzxz;
	test_vec3.zzyx;
	test_vec3.zzyy;
	test_vec3.zzyz;
	test_vec3.zzzx;
	test_vec3.zzzy;
	test_vec3.zzzz;

	test_vec4.xx;
	test_vec4.xy;
	test_vec4.xz;
	test_vec4.xw;
	test_vec4.yx;
	test_vec4.yy;
	test_vec4.yz;
	test_vec4.yw;
	test_vec4.zx;
	test_vec4.zy;
	test_vec4.zz;
	test_vec4.zw;
	test_vec4.wx;
	test_vec4.wy;
	test_vec4.wz;
	test_vec4.ww;
	test_vec4.xxx;
	test_vec4.xxy;
	test_vec4.xxz;
	test_vec4.xxw;
	test_vec4.xyx;
	test_vec4.xyy;
	test_vec4.xyz;
	test_vec4.xyw;
	test_vec4.xzx;
	test_vec4.xzy;
	test_vec4.xzz;
	test_vec4.xzw;
	test_vec4.xwx;
	test_vec4.xwy;
	test_vec4.xwz;
	test_vec4.xww;
	test_vec4.yxx;
	test_vec4.yxy;
	test_vec4.yxz;
	test_vec4.yxw;
	test_vec4.yyx;
	test_vec4.yyy;
	test_vec4.yyz;
	test_vec4.yyw;
	test_vec4.yzx;
	test_vec4.yzy;
	test_vec4.yzz;
	test_vec4.yzw;
	test_vec4.ywx;
	test_vec4.ywy;
	test_vec4.ywz;
	test_vec4.yww;
	test_vec4.zxx;
	test_vec4.zxy;
	test_vec4.zxz;
	test_vec4.zxw;
	test_vec4.zyx;
	test_vec4.zyy;
	test_vec4.zyz;
	test_vec4.zyw;
	test_vec4.zzx;
	test_vec4.zzy;
	test_vec4.zzz;
	test_vec4.zzw;
	test_vec4.zwx;
	test_vec4.zwy;
	test_vec4.zwz;
	test_vec4.zww;
	test_vec4.wxx;
	test_vec4.wxy;
	test_vec4.wxz;
	test_vec4.wxw;
	test_vec4.wyx;
	test_vec4.wyy;
	test_vec4.wyz;
	test_vec4.wyw;
	test_vec4.wzx;
	test_vec4.wzy;
	test_vec4.wzz;
	test_vec4.wzw;
	test_vec4.wwx;
	test_vec4.wwy;
	test_vec4.wwz;
	test_vec4.www;
	test_vec4.xxxx;
	test_vec4.xxxy;
	test_vec4.xxxz;
	test_vec4.xxxw;
	test_vec4.xxyx;
	test_vec4.xxyy;
	test_vec4.xxyz;
	test_vec4.xxyw;
	test_vec4.xxzx;
	test_vec4.xxzy;
	test_vec4.xxzz;
	test_vec4.xxzw;
	test_vec4.xxwx;
	test_vec4.xxwy;
	test_vec4.xxwz;
	test_vec4.xxww;
	test_vec4.xyxx;
	test_vec4.xyxy;
	test_vec4.xyxz;
	test_vec4.xyxw;
	test_vec4.xyyx;
	test_vec4.xyyy;
	test_vec4.xyyz;
	test_vec4.xyyw;
	test_vec4.xyzx;
	test_vec4.xyzy;
	test_vec4.xyzz;
	test_vec4.xyzw;
	test_vec4.xywx;
	test_vec4.xywy;
	test_vec4.xywz;
	test_vec4.xyww;
	test_vec4.xzxx;
	test_vec4.xzxy;
	test_vec4.xzxz;
	test_vec4.xzxw;
	test_vec4.xzyx;
	test_vec4.xzyy;
	test_vec4.xzyz;
	test_vec4.xzyw;
	test_vec4.xzzx;
	test_vec4.xzzy;
	test_vec4.xzzz;
	test_vec4.xzzw;
	test_vec4.xzwx;
	test_vec4.xzwy;
	test_vec4.xzwz;
	test_vec4.xzww;
	test_vec4.xwxx;
	test_vec4.xwxy;
	test_vec4.xwxz;
	test_vec4.xwxw;
	test_vec4.xwyx;
	test_vec4.xwyy;
	test_vec4.xwyz;
	test_vec4.xwyw;
	test_vec4.xwzx;
	test_vec4.xwzy;
	test_vec4.xwzz;
	test_vec4.xwzw;
	test_vec4.xwwx;
	test_vec4.xwwy;
	test_vec4.xwwz;
	test_vec4.xwww;
	test_vec4.yxxx;
	test_vec4.yxxy;
	test_vec4.yxxz;
	test_vec4.yxxw;
	test_vec4.yxyx;
	test_vec4.yxyy;
	test_vec4.yxyz;
	test_vec4.yxyw;
	test_vec4.yxzx;
	test_vec4.yxzy;
	test_vec4.yxzz;
	test_vec4.yxzw;
	test_vec4.yxwx;
	test_vec4.yxwy;
	test_vec4.yxwz;
	test_vec4.yxww;
	test_vec4.yyxx;
	test_vec4.yyxy;
	test_vec4.yyxz;
	test_vec4.yyxw;
	test_vec4.yyyx;
	test_vec4.yyyy;
	test_vec4.yyyz;
	test_vec4.yyyw;
	test_vec4.yyzx;
	test_vec4.yyzy;
	test_vec4.yyzz;
	test_vec4.yyzw;
	test_vec4.yywx;
	test_vec4.yywy;
	test_vec4.yywz;
	test_vec4.yyww;
	test_vec4.yzxx;
	test_vec4.yzxy;
	test_vec4.yzxz;
	test_vec4.yzxw;
	test_vec4.yzyx;
	test_vec4.yzyy;
	test_vec4.yzyz;
	test_vec4.yzyw;
	test_vec4.yzzx;
	test_vec4.yzzy;
	test_vec4.yzzz;
	test_vec4.yzzw;
	test_vec4.yzwx;
	test_vec4.yzwy;
	test_vec4.yzwz;
	test_vec4.yzww;
	test_vec4.ywxx;
	test_vec4.ywxy;
	test_vec4.ywxz;
	test_vec4.ywxw;
	test_vec4.ywyx;
	test_vec4.ywyy;
	test_vec4.ywyz;
	test_vec4.ywyw;
	test_vec4.ywzx;
	test_vec4.ywzy;
	test_vec4.ywzz;
	test_vec4.ywzw;
	test_vec4.ywwx;
	test_vec4.ywwy;
	test_vec4.ywwz;
	test_vec4.ywww;
	test_vec4.zxxx;
	test_vec4.zxxy;
	test_vec4.zxxz;
	test_vec4.zxxw;
	test_vec4.zxyx;
	test_vec4.zxyy;
	test_vec4.zxyz;
	test_vec4.zxyw;
	test_vec4.zxzx;
	test_vec4.zxzy;
	test_vec4.zxzz;
	test_vec4.zxzw;
	test_vec4.zxwx;
	test_vec4.zxwy;
	test_vec4.zxwz;
	test_vec4.zxww;
	test_vec4.zyxx;
	test_vec4.zyxy;
	test_vec4.zyxz;
	test_vec4.zyxw;
	test_vec4.zyyx;
	test_vec4.zyyy;
	test_vec4.zyyz;
	test_vec4.zyyw;
	test_vec4.zyzx;
	test_vec4.zyzy;
	test_vec4.zyzz;
	test_vec4.zyzw;
	test_vec4.zywx;
	test_vec4.zywy;
	test_vec4.zywz;
	test_vec4.zyww;
	test_vec4.zzxx;
	test_vec4.zzxy;
	test_vec4.zzxz;
	test_vec4.zzxw;
	test_vec4.zzyx;
	test_vec4.zzyy;
	test_vec4.zzyz;
	test_vec4.zzyw;
	test_vec4.zzzx;
	test_vec4.zzzy;
	test_vec4.zzzz;
	test_vec4.zzzw;
	test_vec4.zzwx;
	test_vec4.zzwy;
	test_vec4.zzwz;
	test_vec4.zzww;
	test_vec4.zwxx;
	test_vec4.zwxy;
	test_vec4.zwxz;
	test_vec4.zwxw;
	test_vec4.zwyx;
	test_vec4.zwyy;
	test_vec4.zwyz;
	test_vec4.zwyw;
	test_vec4.zwzx;
	test_vec4.zwzy;
	test_vec4.zwzz;
	test_vec4.zwzw;
	test_vec4.zwwx;
	test_vec4.zwwy;
	test_vec4.zwwz;
	test_vec4.zwww;
	test_vec4.wxxx;
	test_vec4.wxxy;
	test_vec4.wxxz;
	test_vec4.wxxw;
	test_vec4.wxyx;
	test_vec4.wxyy;
	test_vec4.wxyz;
	test_vec4.wxyw;
	test_vec4.wxzx;
	test_vec4.wxzy;
	test_vec4.wxzz;
	test_vec4.wxzw;
	test_vec4.wxwx;
	test_vec4.wxwy;
	test_vec4.wxwz;
	test_vec4.wxww;
	test_vec4.wyxx;
	test_vec4.wyxy;
	test_vec4.wyxz;
	test_vec4.wyxw;
	test_vec4.wyyx;
	test_vec4.wyyy;
	test_vec4.wyyz;
	test_vec4.wyyw;
	test_vec4.wyzx;
	test_vec4.wyzy;
	test_vec4.wyzz;
	test_vec4.wyzw;
	test_vec4.wywx;
	test_vec4.wywy;
	test_vec4.wywz;
	test_vec4.wyww;
	test_vec4.wzxx;
	test_vec4.wzxy;
	test_vec4.wzxz;
	test_vec4.wzxw;
	test_vec4.wzyx;
	test_vec4.wzyy;
	test_vec4.wzyz;
	test_vec4.wzyw;
	test_vec4.wzzx;
	test_vec4.wzzy;
	test_vec4.wzzz;
	test_vec4.wzzw;
	test_vec4.wzwx;
	test_vec4.wzwy;
	test_vec4.wzwz;
	test_vec4.wzww;
	test_vec4.wwxx;
	test_vec4.wwxy;
	test_vec4.wwxz;
	test_vec4.wwxw;
	test_vec4.wwyx;
	test_vec4.wwyy;
	test_vec4.wwyz;
	test_vec4.wwyw;
	test_vec4.wwzx;
	test_vec4.wwzy;
	test_vec4.wwzz;
	test_vec4.wwzw;
	test_vec4.wwwx;
	test_vec4.wwwy;
	test_vec4.wwwz;
	test_vec4.wwww;

	test_dvec2.xx;
	test_dvec2.xy;
	test_dvec2.yx;
	test_dvec2.yy;
	test_dvec2.xxx;
	test_dvec2.xxy;
	test_dvec2.xyx;
	test_dvec2.xyy;
	test_dvec2.yxx;
	test_dvec2.yxy;
	test_dvec2.yyx;
	test_dvec2.yyy;
	test_dvec2.xxxx;
	test_dvec2.xxxy;
	test_dvec2.xxyx;
	test_dvec2.xxyy;
	test_dvec2.xyxx;
	test_dvec2.xyxy;
	test_dvec2.xyyx;
	test_dvec2.xyyy;
	test_dvec2.yxxx;
	test_dvec2.yxxy;
	test_dvec2.yxyx;
	test_dvec2.yxyy;
	test_dvec2.yyxx;
	test_dvec2.yyxy;
	test_dvec2.yyyx;
	test_dvec2.yyyy;

	test_dvec3.xx;
	test_dvec3.xy;
	test_dvec3.xz;
	test_dvec3.yx;
	test_dvec3.yy;
	test_dvec3.yz;
	test_dvec3.zx;
	test_dvec3.zy;
	test_dvec3.zz;
	test_dvec3.xxx;
	test_dvec3.xxy;
	test_dvec3.xxz;
	test_dvec3.xyx;
	test_dvec3.xyy;
	test_dvec3.xyz;
	test_dvec3.xzx;
	test_dvec3.xzy;
	test_dvec3.xzz;
	test_dvec3.yxx;
	test_dvec3.yxy;
	test_dvec3.yxz;
	test_dvec3.yyx;
	test_dvec3.yyy;
	test_dvec3.yyz;
	test_dvec3.yzx;
	test_dvec3.yzy;
	test_dvec3.yzz;
	test_dvec3.zxx;
	test_dvec3.zxy;
	test_dvec3.zxz;
	test_dvec3.zyx;
	test_dvec3.zyy;
	test_dvec3.zyz;
	test_dvec3.zzx;
	test_dvec3.zzy;
	test_dvec3.zzz;
	test_dvec3.xxxx;
	test_dvec3.xxxy;
	test_dvec3.xxxz;
	test_dvec3.xxyx;
	test_dvec3.xxyy;
	test_dvec3.xxyz;
	test_dvec3.xxzx;
	test_dvec3.xxzy;
	test_dvec3.xxzz;
	test_dvec3.xyxx;
	test_dvec3.xyxy;
	test_dvec3.xyxz;
	test_dvec3.xyyx;
	test_dvec3.xyyy;
	test_dvec3.xyyz;
	test_dvec3.xyzx;
	test_dvec3.xyzy;
	test_dvec3.xyzz;
	test_dvec3.xzxx;
	test_dvec3.xzxy;
	test_dvec3.xzxz;
	test_dvec3.xzyx;
	test_dvec3.xzyy;
	test_dvec3.xzyz;
	test_dvec3.xzzx;
	test_dvec3.xzzy;
	test_dvec3.xzzz;
	test_dvec3.yxxx;
	test_dvec3.yxxy;
	test_dvec3.yxxz;
	test_dvec3.yxyx;
	test_dvec3.yxyy;
	test_dvec3.yxyz;
	test_dvec3.yxzx;
	test_dvec3.yxzy;
	test_dvec3.yxzz;
	test_dvec3.yyxx;
	test_dvec3.yyxy;
	test_dvec3.yyxz;
	test_dvec3.yyyx;
	test_dvec3.yyyy;
	test_dvec3.yyyz;
	test_dvec3.yyzx;
	test_dvec3.yyzy;
	test_dvec3.yyzz;
	test_dvec3.yzxx;
	test_dvec3.yzxy;
	test_dvec3.yzxz;
	test_dvec3.yzyx;
	test_dvec3.yzyy;
	test_dvec3.yzyz;
	test_dvec3.yzzx;
	test_dvec3.yzzy;
	test_dvec3.yzzz;
	test_dvec3.zxxx;
	test_dvec3.zxxy;
	test_dvec3.zxxz;
	test_dvec3.zxyx;
	test_dvec3.zxyy;
	test_dvec3.zxyz;
	test_dvec3.zxzx;
	test_dvec3.zxzy;
	test_dvec3.zxzz;
	test_dvec3.zyxx;
	test_dvec3.zyxy;
	test_dvec3.zyxz;
	test_dvec3.zyyx;
	test_dvec3.zyyy;
	test_dvec3.zyyz;
	test_dvec3.zyzx;
	test_dvec3.zyzy;
	test_dvec3.zyzz;
	test_dvec3.zzxx;
	test_dvec3.zzxy;
	test_dvec3.zzxz;
	test_dvec3.zzyx;
	test_dvec3.zzyy;
	test_dvec3.zzyz;
	test_dvec3.zzzx;
	test_dvec3.zzzy;
	test_dvec3.zzzz;

	test_dvec4.xx;
	test_dvec4.xy;
	test_dvec4.xz;
	test_dvec4.xw;
	test_dvec4.yx;
	test_dvec4.yy;
	test_dvec4.yz;
	test_dvec4.yw;
	test_dvec4.zx;
	test_dvec4.zy;
	test_dvec4.zz;
	test_dvec4.zw;
	test_dvec4.wx;
	test_dvec4.wy;
	test_dvec4.wz;
	test_dvec4.ww;
	test_dvec4.xxx;
	test_dvec4.xxy;
	test_dvec4.xxz;
	test_dvec4.xxw;
	test_dvec4.xyx;
	test_dvec4.xyy;
	test_dvec4.xyz;
	test_dvec4.xyw;
	test_dvec4.xzx;
	test_dvec4.xzy;
	test_dvec4.xzz;
	test_dvec4.xzw;
	test_dvec4.xwx;
	test_dvec4.xwy;
	test_dvec4.xwz;
	test_dvec4.xww;
	test_dvec4.yxx;
	test_dvec4.yxy;
	test_dvec4.yxz;
	test_dvec4.yxw;
	test_dvec4.yyx;
	test_dvec4.yyy;
	test_dvec4.yyz;
	test_dvec4.yyw;
	test_dvec4.yzx;
	test_dvec4.yzy;
	test_dvec4.yzz;
	test_dvec4.yzw;
	test_dvec4.ywx;
	test_dvec4.ywy;
	test_dvec4.ywz;
	test_dvec4.yww;
	test_dvec4.zxx;
	test_dvec4.zxy;
	test_dvec4.zxz;
	test_dvec4.zxw;
	test_dvec4.zyx;
	test_dvec4.zyy;
	test_dvec4.zyz;
	test_dvec4.zyw;
	test_dvec4.zzx;
	test_dvec4.zzy;
	test_dvec4.zzz;
	test_dvec4.zzw;
	test_dvec4.zwx;
	test_dvec4.zwy;
	test_dvec4.zwz;
	test_dvec4.zww;
	test_dvec4.wxx;
	test_dvec4.wxy;
	test_dvec4.wxz;
	test_dvec4.wxw;
	test_dvec4.wyx;
	test_dvec4.wyy;
	test_dvec4.wyz;
	test_dvec4.wyw;
	test_dvec4.wzx;
	test_dvec4.wzy;
	test_dvec4.wzz;
	test_dvec4.wzw;
	test_dvec4.wwx;
	test_dvec4.wwy;
	test_dvec4.wwz;
	test_dvec4.www;
	test_dvec4.xxxx;
	test_dvec4.xxxy;
	test_dvec4.xxxz;
	test_dvec4.xxxw;
	test_dvec4.xxyx;
	test_dvec4.xxyy;
	test_dvec4.xxyz;
	test_dvec4.xxyw;
	test_dvec4.xxzx;
	test_dvec4.xxzy;
	test_dvec4.xxzz;
	test_dvec4.xxzw;
	test_dvec4.xxwx;
	test_dvec4.xxwy;
	test_dvec4.xxwz;
	test_dvec4.xxww;
	test_dvec4.xyxx;
	test_dvec4.xyxy;
	test_dvec4.xyxz;
	test_dvec4.xyxw;
	test_dvec4.xyyx;
	test_dvec4.xyyy;
	test_dvec4.xyyz;
	test_dvec4.xyyw;
	test_dvec4.xyzx;
	test_dvec4.xyzy;
	test_dvec4.xyzz;
	test_dvec4.xyzw;
	test_dvec4.xywx;
	test_dvec4.xywy;
	test_dvec4.xywz;
	test_dvec4.xyww;
	test_dvec4.xzxx;
	test_dvec4.xzxy;
	test_dvec4.xzxz;
	test_dvec4.xzxw;
	test_dvec4.xzyx;
	test_dvec4.xzyy;
	test_dvec4.xzyz;
	test_dvec4.xzyw;
	test_dvec4.xzzx;
	test_dvec4.xzzy;
	test_dvec4.xzzz;
	test_dvec4.xzzw;
	test_dvec4.xzwx;
	test_dvec4.xzwy;
	test_dvec4.xzwz;
	test_dvec4.xzww;
	test_dvec4.xwxx;
	test_dvec4.xwxy;
	test_dvec4.xwxz;
	test_dvec4.xwxw;
	test_dvec4.xwyx;
	test_dvec4.xwyy;
	test_dvec4.xwyz;
	test_dvec4.xwyw;
	test_dvec4.xwzx;
	test_dvec4.xwzy;
	test_dvec4.xwzz;
	test_dvec4.xwzw;
	test_dvec4.xwwx;
	test_dvec4.xwwy;
	test_dvec4.xwwz;
	test_dvec4.xwww;
	test_dvec4.yxxx;
	test_dvec4.yxxy;
	test_dvec4.yxxz;
	test_dvec4.yxxw;
	test_dvec4.yxyx;
	test_dvec4.yxyy;
	test_dvec4.yxyz;
	test_dvec4.yxyw;
	test_dvec4.yxzx;
	test_dvec4.yxzy;
	test_dvec4.yxzz;
	test_dvec4.yxzw;
	test_dvec4.yxwx;
	test_dvec4.yxwy;
	test_dvec4.yxwz;
	test_dvec4.yxww;
	test_dvec4.yyxx;
	test_dvec4.yyxy;
	test_dvec4.yyxz;
	test_dvec4.yyxw;
	test_dvec4.yyyx;
	test_dvec4.yyyy;
	test_dvec4.yyyz;
	test_dvec4.yyyw;
	test_dvec4.yyzx;
	test_dvec4.yyzy;
	test_dvec4.yyzz;
	test_dvec4.yyzw;
	test_dvec4.yywx;
	test_dvec4.yywy;
	test_dvec4.yywz;
	test_dvec4.yyww;
	test_dvec4.yzxx;
	test_dvec4.yzxy;
	test_dvec4.yzxz;
	test_dvec4.yzxw;
	test_dvec4.yzyx;
	test_dvec4.yzyy;
	test_dvec4.yzyz;
	test_dvec4.yzyw;
	test_dvec4.yzzx;
	test_dvec4.yzzy;
	test_dvec4.yzzz;
	test_dvec4.yzzw;
	test_dvec4.yzwx;
	test_dvec4.yzwy;
	test_dvec4.yzwz;
	test_dvec4.yzww;
	test_dvec4.ywxx;
	test_dvec4.ywxy;
	test_dvec4.ywxz;
	test_dvec4.ywxw;
	test_dvec4.ywyx;
	test_dvec4.ywyy;
	test_dvec4.ywyz;
	test_dvec4.ywyw;
	test_dvec4.ywzx;
	test_dvec4.ywzy;
	test_dvec4.ywzz;
	test_dvec4.ywzw;
	test_dvec4.ywwx;
	test_dvec4.ywwy;
	test_dvec4.ywwz;
	test_dvec4.ywww;
	test_dvec4.zxxx;
	test_dvec4.zxxy;
	test_dvec4.zxxz;
	test_dvec4.zxxw;
	test_dvec4.zxyx;
	test_dvec4.zxyy;
	test_dvec4.zxyz;
	test_dvec4.zxyw;
	test_dvec4.zxzx;
	test_dvec4.zxzy;
	test_dvec4.zxzz;
	test_dvec4.zxzw;
	test_dvec4.zxwx;
	test_dvec4.zxwy;
	test_dvec4.zxwz;
	test_dvec4.zxww;
	test_dvec4.zyxx;
	test_dvec4.zyxy;
	test_dvec4.zyxz;
	test_dvec4.zyxw;
	test_dvec4.zyyx;
	test_dvec4.zyyy;
	test_dvec4.zyyz;
	test_dvec4.zyyw;
	test_dvec4.zyzx;
	test_dvec4.zyzy;
	test_dvec4.zyzz;
	test_dvec4.zyzw;
	test_dvec4.zywx;
	test_dvec4.zywy;
	test_dvec4.zywz;
	test_dvec4.zyww;
	test_dvec4.zzxx;
	test_dvec4.zzxy;
	test_dvec4.zzxz;
	test_dvec4.zzxw;
	test_dvec4.zzyx;
	test_dvec4.zzyy;
	test_dvec4.zzyz;
	test_dvec4.zzyw;
	test_dvec4.zzzx;
	test_dvec4.zzzy;
	test_dvec4.zzzz;
	test_dvec4.zzzw;
	test_dvec4.zzwx;
	test_dvec4.zzwy;
	test_dvec4.zzwz;
	test_dvec4.zzww;
	test_dvec4.zwxx;
	test_dvec4.zwxy;
	test_dvec4.zwxz;
	test_dvec4.zwxw;
	test_dvec4.zwyx;
	test_dvec4.zwyy;
	test_dvec4.zwyz;
	test_dvec4.zwyw;
	test_dvec4.zwzx;
	test_dvec4.zwzy;
	test_dvec4.zwzz;
	test_dvec4.zwzw;
	test_dvec4.zwwx;
	test_dvec4.zwwy;
	test_dvec4.zwwz;
	test_dvec4.zwww;
	test_dvec4.wxxx;
	test_dvec4.wxxy;
	test_dvec4.wxxz;
	test_dvec4.wxxw;
	test_dvec4.wxyx;
	test_dvec4.wxyy;
	test_dvec4.wxyz;
	test_dvec4.wxyw;
	test_dvec4.wxzx;
	test_dvec4.wxzy;
	test_dvec4.wxzz;
	test_dvec4.wxzw;
	test_dvec4.wxwx;
	test_dvec4.wxwy;
	test_dvec4.wxwz;
	test_dvec4.wxww;
	test_dvec4.wyxx;
	test_dvec4.wyxy;
	test_dvec4.wyxz;
	test_dvec4.wyxw;
	test_dvec4.wyyx;
	test_dvec4.wyyy;
	test_dvec4.wyyz;
	test_dvec4.wyyw;
	test_dvec4.wyzx;
	test_dvec4.wyzy;
	test_dvec4.wyzz;
	test_dvec4.wyzw;
	test_dvec4.wywx;
	test_dvec4.wywy;
	test_dvec4.wywz;
	test_dvec4.wyww;
	test_dvec4.wzxx;
	test_dvec4.wzxy;
	test_dvec4.wzxz;
	test_dvec4.wzxw;
	test_dvec4.wzyx;
	test_dvec4.wzyy;
	test_dvec4.wzyz;
	test_dvec4.wzyw;
	test_dvec4.wzzx;
	test_dvec4.wzzy;
	test_dvec4.wzzz;
	test_dvec4.wzzw;
	test_dvec4.wzwx;
	test_dvec4.wzwy;
	test_dvec4.wzwz;
	test_dvec4.wzww;
	test_dvec4.wwxx;
	test_dvec4.wwxy;
	test_dvec4.wwxz;
	test_dvec4.wwxw;
	test_dvec4.wwyx;
	test_dvec4.wwyy;
	test_dvec4.wwyz;
	test_dvec4.wwyw;
	test_dvec4.wwzx;
	test_dvec4.wwzy;
	test_dvec4.wwzz;
	test_dvec4.wwzw;
	test_dvec4.wwwx;
	test_dvec4.wwwy;
	test_dvec4.wwwz;
	test_dvec4.wwww;
}


//-----------------------------------------------------------------------------
/*
	OWNER	RETURN
	(MIN)
			vec1	vec2	vec3	vec4L
	vec1+	x		xx		xxx		xxxx
	vec2+							xxxy
	vec3+							xxxz
	vec4+							xxxw
	vec2+					xxy		xxyx
	vec2+							xxyy
	vec3+							xxyz
	vec4+							xxyw
	vec3+					xxz		xxzx
	vec3+							xxzy
	vec3+							xxzz
	vec4+							xxzw
	vec4+					xxw		xxwx
	vec4+							xxwy
	vec4+							xxwz
	vec4+							xxww
	vec2+			xy		xyx		xyxx
	vec2+							xyxy
	vec3+							xyxz
	vec4+							xyxw
	vec2+					xyy		xyyx
	vec2+							xyyy
	vec3+							xyyz
	vec4+							xyyw
	vec3+					xyz		xyzx
	vec3+							xyzy
	vec3+							xyzz
	vec4+							xyzw
	vec4+					xyw		xywx
	vec4+							xywy
	vec4+							xywz
	vec4+							xyww
	vec3+			xz		xzx		xzxx
	vec3+							xzxy
	vec3+							xzxz
	vec4+							xzxw
	vec3+					xzy		xzyx
	vec3+							xzyy
	vec3+							xzyz
	vec4+							xzyw
	vec3+					xzz		xzzx
	vec3+							xzzy
	vec3+							xzzz
	vec4+							xzzw
	vec4+					xzw		xzwx
	vec4+							xzwy
	vec4+							xzwz
	vec4+							xzww
	vec4+			xw		xwx		xwxx
	vec4+							xwxy
	vec4+							xwxz
	vec4+							xwxw
	vec4+					xwy		xwyx
	vec4+							xwyy
	vec4+							xwyz
	vec4+							xwyw
	vec4+					xwz		xwzx
	vec4+							xwzy
	vec4+							xwzz
	vec4+							xwzw
	vec4+					xww		xwwx
	vec4+							xwwy
	vec4+							xwwz
	vec4+							xwww
	vec2+	y		yx		yxx		yxxx
	vec2+							yxxy
	vec3+							yxxz
	vec4+							yxxw
	vec2+					yxy		yxyx
	vec2+							yxyy
	vec3+							yxyz
	vec4+							yxyw
	vec3+					yxz		yxzx
	vec3+							yxzy
	vec3+							yxzz
	vec4+							yxzw
	vec4+					yxw		yxwx
	vec4+							yxwy
	vec4+							yxwz
	vec4+							yxww
	vec2+			yy		yyx		yyxx
	vec2+							yyxy
	vec3+							yyxz
	vec4+							yyxw
	vec2+					yyy		yyyx
	vec2+							yyyy
	vec3+							yyyz
	vec4+							yyyw
	vec3+					yyz		yyzx
	vec3+							yyzy
	vec3+							yyzz
	vec4+							yyzw
	vec4+					yyw		yywx
	vec4+							yywy
	vec4+							yywz
	vec4+							yyww
	vec3+			yz		yzx		yzxx
	vec3+							yzxy
	vec3+							yzxz
	vec4+							yzxw
	vec3+					yzy		yzyx
	vec3+							yzyy
	vec3+							yzyz
	vec4+							yzyw
	vec3+					yzz		yzzx
	vec3+							yzzy
	vec3+							yzzz
	vec4+							yzzw
	vec4+					yzw		yzwx
	vec4+							yzwy
	vec4+							yzwz
	vec4+							yzww
	vec4+			yw		ywx		ywxx
	vec4+							ywxy
	vec4+							ywxz
	vec4+							ywxw
	vec4+					ywy		ywyx
	vec4+							ywyy
	vec4+							ywyz
	vec4+							ywyw
	vec4+					ywz		ywzx
	vec4+							ywzy
	vec4+							ywzz
	vec4+							ywzw
	vec4+					yww		ywwx
	vec4+							ywwy
	vec4+							ywwz
	vec4+							ywww
	vec3+	z		zx		zxx		zxxx
	vec3+							zxxy
	vec3+							zxxz
	vec4+							zxxw
	vec3+					zxy		zxyx
	vec3+							zxyy
	vec3+							zxyz
	vec4+							zxyw
	vec3+					zxz		zxzx
	vec3+							zxzy
	vec3+							zxzz
	vec4+							zxzw
	vec4+					zxw		zxwx
	vec4+							zxwy
	vec4+							zxwz
	vec4+							zxww
	vec3+			zy		zyx		zyxx
	vec3+							zyxy
	vec3+							zyxz
	vec4+							zyxw
	vec3+					zyy		zyyx
	vec3+							zyyy
	vec3+							zyyz
	vec4+							zyyw
	vec3+					zyz		zyzx
	vec3+							zyzy
	vec3+							zyzz
	vec4+							zyzw
	vec4+					zyw		zywx
	vec4+							zywy
	vec4+							zywz
	vec4+							zyww
	vec3+			zz		zzx		zzxx
	vec3+							zzxy
	vec3+							zzxz
	vec4+							zzxw
	vec3+					zzy		zzyx
	vec3+							zzyy
	vec3+							zzyz
	vec4+							zzyw
	vec3+					zzz		zzzx
	vec3+							zzzy
	vec3+							zzzz
	vec4+							zzzw
	vec4+					zzw		zzwx
	vec4+							zzwy
	vec4+							zzwz
	vec4+							zzww
	vec4+			zw		zwx		zwxx
	vec4+							zwxy
	vec4+							zwxz
	vec4+							zwxw
	vec4+					zwy		zwyx
	vec4+							zwyy
	vec4+							zwyz
	vec4+							zwyw
	vec4+					zwz		zwzx
	vec4+							zwzy
	vec4+							zwzz
	vec4+							zwzw
	vec4+					zww		zwwx
	vec4+							zwwy
	vec4+							zwwz
	vec4+							zwww
	vec4+	w		wx		wxx		wxxx
	vec4+							wxxy
	vec4+							wxxz
	vec4+							wxxw
	vec4+					wxy		wxyx
	vec4+							wxyy
	vec4+							wxyz
	vec4+							wxyw
	vec4+					wxz		wxzx
	vec4+							wxzy
	vec4+							wxzz
	vec4+							wxzw
	vec4+					wxw		wxwx
	vec4+							wxwy
	vec4+							wxwz
	vec4+							wxww
	vec4+			wy		wyx		wyxx
	vec4+							wyxy
	vec4+							wyxz
	vec4+							wyxw
	vec4+					wyy		wyyx
	vec4+							wyyy
	vec4+							wyyz
	vec4+							wyyw
	vec4+					wyz		wyzx
	vec4+							wyzy
	vec4+							wyzz
	vec4+							wyzw
	vec4+					wyw		wywx
	vec4+							wywy
	vec4+							wywz
	vec4+							wyww
	vec4+			wz		wzx		wzxx
	vec4+							wzxy
	vec4+							wzxz
	vec4+							wzxw
	vec4+					wzy		wzyx
	vec4+							wzyy
	vec4+							wzyz
	vec4+							wzyw
	vec4+					wzz		wzzx
	vec4+							wzzy
	vec4+							wzzz
	vec4+							wzzw
	vec4+					wzw		wzwx
	vec4+							wzwy
	vec4+							wzwz
	vec4+							wzww
	vec4+			ww		wwx		wwxx
	vec4+							wwxy
	vec4+							wwxz
	vec4+							wwxw
	vec4+					wwy		wwyx
	vec4+							wwyy
	vec4+							wwyz
	vec4+							wwyw
	vec4+					wwz		wwzx
	vec4+							wwzy
	vec4+							wwzz
	vec4+							wwzw
	vec4+					www		wwwx
	vec4+							wwwy
	vec4+							wwwz
	vec4+							wwww
*/

/*
	OWNER	RETURN												
	(MIN)													
			vec1	vec2	vec3	vec4					NEW	vec1 from 1	+	vec2 from 1	+	vec3 from 1	+	vec4 from 1
																UNIQUE
	vec1+	x+______xx______xxx_____xxxx*u1(x)+n1(x)			[ 1(x)	  ]	+	{ 1(xx)		+	  1(...)	+	  1		}
	u1(x) =		x;
	n1(x) =		xx;
				xxx;
				xxxx;
	F1(x) =		f1(x);


			vec1	vec2	vec3	vec4					NEW	vec1 from 1	+	vec2 from 1	+	vec3 from 1	+	vec4 from 1	+	vec2 from 2	+	vec3 from 2	+	vec4 from 2
																UNIQUE															UNIQUE
	vec2+	y+______yy______yyy_____yyyy*u1(y)+n1(y)	--	--	[ 1(y)	  ]	+	{ 1(yy)		+	  1(...)	+	  1		}
	vec2+			xy+_____xxy_____xxxy**u2(xy)+n2(xy)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(xy)	  ]	+	{	3		+	  3(2)+1  }
	vec2+			||\		   \___/xxyx**																					|
	vec2+			|| \		   \xxyy**																					|
	vec2+			||	\___xyx____/xyxx**																					|
	vec2+			||	 \		   \xyxy**																					|
	vec2+			||	  \_xyy____/xyyx**																					|
	vec2+			||			   \xyyy**																					|
	vec2+	 		yx+_____yyx_____yyyx**u2(yx)+n2(yx)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(yx)	  ]	+	{	3		+	  3(2)+1  }
	vec2+			  \		   \___/yyxy**
	vec2+			   \		   \yyxx**
	vec2+				\___yxy____/yxyy**
	vec2+				 \		   \yxyx**
	vec2+				  \_yxx____/yxxy**
	vec2+						   \yxxx**
	u2(xy) =	xy;
	n2(xy) =	xxy, xyx, xyy;
				xxxy, xxyx, xxyy, xyxx, xyxy, xyyx, xyyy;
	F2(xy) =	f1(y);
				f2(xy), f2(yx);


			vec1	vec2	vec3	vec4					NEW	vec1 from 1	+	vec2 from 1	+	vec3 from 1	+	vec4 from 1	+	vec2 from 2	+	vec3 from 2	+	vec4 from 2	+	vec3 from 3	+	vec4 from 3	
																UNIQUE															UNIQUE											UNIQUE
	vec3+	z+______zz______zzz_____zzzz*u1(z)+n1(z)	--	--	[ 1(z)	  ]	+	{ 1(zz)		+	  1(...)	+	  1		}	+
	vec3+			xz+_____xxz_____xxxz**u2(xz)+n2(xz)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(xz)	  ]	+	{	3		+	  3(2)+1  }
	vec3+			||\		   \___/xxzx**																					|
	vec3+			|| \		   \xxzz**																					|
	vec3+			||	\___xzx____/xzxx**																					|
	vec3+			||	 \		   \xzxz**																					|
	vec3+			||	  \_xzz____/xzzx**																					|
	vec3+			||			   \xzzz**																					|
	vec3+			zx+_____zzx_____zzzx**u2(zx)+n2(zx)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(zx)	  ]	+	{	3		+	  3(2)+1  }
	vec3+			  \		   \___/zzxz**																					|
	vec3+			   \		   \zzxx**																					|
	vec3+				\___zxz____/zxzz**																					|
	vec3+				 \		   \zxzx**																					|
	vec3+				  \_zxx____/zxxz**																					|
	vec3+						   \zxxx**																					|
	vec3+			yz+_____yyz_____yyyz**u2(yz)+n2(yz)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(yz)	  ]	+	{	3		+	  3(2)+1  }
	vec3+			||\		   \___/yyzy**																					|
	vec3+			|| \		   \yyzz**																					|
	vec3+			||	\___yzy____/yzyy**																					|
	vec3+			||	 \		   \yzyz**																					|
	vec3+			||	  \_yzz____/yzzy**																					|
	vec3+			||			   \yzzz**																					|
	vec3+			zy+_____zzy_____zzzy**u2(zy)+n2(zy)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(zy)	  ]	+	{	3		+	  3(2)+1  }	+
	vec3+			  \		   \___/zzyz**																																	|
	vec3+			   \		   \zzyy**																																	|
	vec3+				\___zyz____/zyzz**																																	|
	vec3+				 \		   \zyzy**																																	|
	vec3+				  \_zyy____/zyyz**																																	|
	vec3+						   \zyyy**																																	|
	vec3+						   /xxyz***u3(xyz)+n3(xyz)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(xyz)  ]	+	{	2(3)  }
	vec3+					xyz+__/ xyxz***																																	|
	vec3+					|||\  \_xyyz***																																	|
	vec3+					|||	\  /xyzz***																																	|
	vec3+					|||  \/ xyzy***																																	|
	vec3+					|||	  \_xyzx***																																	|
	vec3+					|||	   /yyxz***u3(yxz)+n3(yxz)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(yxz)  ]	+	{	2(3)  }
	vec3+					yxz+__/ yxyz***																																	|
	vec3+					   \  \_yxxz***																																	|
	vec3+						\  /yxzz***																																	|
	vec3+						 \/	yxzy***																																	|
	vec3+						  \_yxzx***																																	|
	vec3+						   /xxzy***u3(xzy)+n3(xzy)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(xzy)  ]	+	{	2(3)  }
	vec3+					xzy+__/ xzxy***																																	|
	vec3+					|||\  \_xzzy***																																	|
	vec3+					||| \  /xzyy***																																	|
	vec3+					|||	 \/ xzyz***																																	|
	vec3+					|||	  \_xzyx***																																	|
	vec3+					|||	   /zzxy***u3(zxy)+n3(zxy)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(zxy)  ]	+	{	2(3)  }
	vec3+					zxy+__/ zxzy***																																	|
	vec3+					   \  \_zxxy***																																	|
	vec3+						\  /zxyy***																																	|
	vec3+						 \/ zxyx***																																	|
	vec3+						  \_zxyz***																																	|
	vec3+						   /yyzx***u3(yzx)+n3(yzx)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(yzx)  ]	+	{	2(3)  }
	vec3+					yzx+__/ yzyx***																																	|
	vec3+					|||\  \_yzzx***																																	|
	vec3+					||| \  /yzxx***																																	|
	vec3+					|||	 \/ yzxz***																																	|
	vec3+					|||	  \_yzxy***																																	|
	vec3+					|||	   /zzyx***u3(zyx)+n3(zyx)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(zyx)  ]	+	{	2(3)  }
	vec3+					zyx+__/ zyzx***
	vec3+					   \  \_zyyx***
	vec3+						\  /zyxx***
	vec3+						 \/ zyxy***
	vec3+						  \_zyxz***
	u3(xyz) =	xyz;
	n3(xyz) =	xxyz, xyxz, xyyz, xyzz, xyzy, xyzx;
	F3(xyz) =	f1(z);
				f2(xz), f2(zx), f2(yz), f2(zy);
				f3(xyz), f3(yzx), f3(zxy), f3(yxz), f3(xzy), f3(zyx);


			vec1	vec2	vec3	vec4					NEW	vec1 from 1	+	vec2 from 1	+	vec3 from 1	+	vec4 from 1	+	vec2 from 2	+	vec3 from 2	+	vec4 from 2	+	vec3 from 3	+	vec4 from 3	+	vec4 from 4
																UNIQUE															UNIQUE											UNIQUE							UNIQUE
	vec4+	w+______ww______www_____wwww*u1(w)+n1(w)	--	--	[ 1(w)	  ]	+	{ 1(ww)		+	  1(...)	+	  1		}	+
	vec4+			xw+_____xxw_____xxxw**u2(xw)+n2(xw)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(xw)	  ]	+	{	3		+	  3(2)+1  }
	vec4+			||\		   \___/xxwx**																					|
	vec4+			|| \		   \xxww**																					|
	vec4+			||	\___xwx____/xwxx**																					|
	vec4+			||	 \		   \xwxw**																					|
	vec4+			||	  \_xww____/xwwx**																					|
	vec4+			||			   \xwww**																					|
	vec4+			wx+_____wwx_____wwwx**u2(wx)+n2(wx)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(wx)	  ]	+	{	3		+	  3(2)+1  }
	vec4+			  \		   \___/wwxw**																					|
	vec4+			   \		   \wwxx**																					|
	vec4+				\___wxw____/wxww**																					|
	vec4+				 \		   \wxwx**																					|
	vec4+				  \_wxx____/wxxw**																					|
	vec4+						   \wxxx**																					|
	vec4+			yw+_____yyw_____yyyw**u2(yw)+n2(yw)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(yw)	  ]	+	{	3		+	  3(2)+1  }
	vec4+			||\		   \___/yywy**																					|
	vec4+			|| \		   \yyww**																					|
	vec4+			||	\___ywy____/ywyy**																					|
	vec4+			||	 \		   \ywyw**																					|
	vec4+			||	  \_yww____/ywwy**																					|
	vec4+			||			   \ywww**																					|
	vec4+			wy+_____wwy_____wwwy**u2(wy)+n2(wy)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(wy)	  ]	+	{	3		+	  3(2)+1  }
	vec4+			  \		   \___/wwyw**																					|
	vec4+			   \		   \wwyy**																					|
	vec4+				\___wyw____/wyww**																					|
	vec4+				 \		   \wywy**																					|
	vec4+				  \_wyy____/wyyw**																					|
	vec4+						   \wyyy**																					|
	vec4+			zw+_____zzw_____zzzw**u2(zw)+n2(zw)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(zw)	  ]	+	{	3		+	  3(2)+1  }
	vec4+			||\		   \___/zzwz**			   																		|
	vec4+			|| \		   \zzww**			   																		|
	vec4+			||	\___zwz____/zwzz**			   																		|
	vec4+			||	 \		   \zwzw**			   																		|
	vec4+			||	  \_zww____/zwwz**			   																		|
	vec4+			||			   \zwww**			   																		|
	vec4+			wz+_____wwz_____wwwz**u2(wz)+n2(wz)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(wz)	  ]	+	{	3		+	  3(2)+1  }	+
	vec4+			  \		   \___/wwzw**																																	|
	vec4+			   \		   \wwzz**																																	|
	vec4+				\___wzw____/wzww**																																	|
	vec4+				 \		   \wzwz**																																	|
	vec4+				  \_wzz____/wzzw**																																	|
	vec4+						   \wzzz**																																	|
	vec4+						   /xxyw***u3(xyw)+n3(xyw)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(xyw)  ]	+	{	2(3)  }
	vec4+					xyw+__/ xyxw***																																	|
	vec4+					|||\  \_xyyw***																																	|
	vec4+					|||	\  /xyww***																																	|
	vec4+					|||  \/ xywy***																																	|
	vec4+					|||	  \_xywx***																																	|
	vec4+					|||	   /yyxw***u3(yxw)+n3(yxw)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(yxw)  ]	+	{	2(3)  }
	vec4+					yxw+__/ yxyw***																																	|
	vec4+					   \  \_yxxw***																																	|
	vec4+						\  /yxww***																																	|
	vec4+						 \/	yxwy***																																	|
	vec4+						  \_yxwx***																																	|
	vec4+						   /xxzw***u3(xzw)+n3(xzw)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(xzw)  ]	+	{	2(3)  }
	vec4+					xzw+__/ xzxw***																																	|
	vec4+					|||\  \_xzzw***																																	|
	vec4+					||| \  /xzww***																																	|
	vec4+					|||	 \/ xzwz***																																	|
	vec4+					|||	  \_xzwx***																																	|
	vec4+					|||	   /zzxw***u3(zxw)+n3(zxw)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(zxw)  ]	+	{	2(3)  }
	vec4+					zxw+__/ zxzw***																																	|
	vec4+					   \  \_zxxw***																																	|
	vec4+						\  /zxww***																																	|
	vec4+						 \/ zxwx***																																	|
	vec4+						  \_zxwz***																																	|
	vec4+						   /xxwy***u3(xwy)+n3(xwy)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(xwy)  ]	+	{	2(3)  }
	vec4+					xwy+__/ xwxy***																																	|
	vec4+					|||\  \_xwwy***																																	|
	vec4+					||| \  /xwyy***																																	|
	vec4+					|||	 \/ xwyw***																																	|
	vec4+					|||	  \_xwyx***																																	|
	vec4+					|||	   /wwxy***u3(wxy)+n3(wxy)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(wxy)  ]	+	{	2(3)  }
	vec4+					wxy+__/ wxwy***																																	|
	vec4+					   \  \_wxxy***																																	|
	vec4+						\  /wxyy***																																	|
	vec4+						 \/ wxyx***																																	|
	vec4+						  \_wxyw***																																	|
	vec4+						   /yyzw***u3(yzw)+n3(yzw)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(yzw)  ]	+	{	2(3)  }
	vec4+					yzw+__/ yzyw***																																	|
	vec4+					|||\  \_yzzw***																																	|
	vec4+					||| \  /yzww***																																	|
	vec4+					|||	 \/ yzwz***																																	|
	vec4+					|||	  \_yzwy***																																	|
	vec4+					|||	   /zzyw***u3(zyw)+n3(zyw)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(zyw)  ]	+	{	2(3)  }
	vec4+					zyw+__/ zyzw***																																	|
	vec4+					   \  \_zyyw***																																	|
	vec4+						\  /zyww***																																	|
	vec4+						 \/ zywy***																																	|
	vec4+						  \_zywz***																																	|
	vec4+						   /yywx***u3(ywx)+n3(ywx)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(ywx)  ]	+	{	2(3)  }
	vec4+					ywx+__/ ywyx***																																	|
	vec4+					|||\  \_ywwx***																																	|
	vec4+					||| \  /ywxx***																																	|
	vec4+					|||	 \/ ywxw***																																	|
	vec4+					|||	  \_ywxy***																																	|
	vec4+					|||	   /wwyx***u3(wyx)+n3(wyx)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(wyx)  ]	+	{	2(3)  }
	vec4+					wyx+__/ wywx***																																	|
	vec4+					   \  \_wyyx***																																	|
	vec4+						\  /wyxx***																																	|
	vec4+						 \/ wyxy***																																	|
	vec4+						  \_wyxw***																																	|
	vec4+						   /xxwz***u3(xwz)+n3(xwz)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(xwz)  ]	+	{	2(3)  }
	vec4+					xwz+__/ xwxz***																																	|
	vec4+					|||\  \_xwwz***																																	|
	vec4+					|||	\  /xwzz***																																	|
	vec4+					|||  \/ xwzw***																																	|
	vec4+					|||	  \_xwzx***																																	|
	vec4+					|||	   /wwxz***u3(wxz)+n3(wxz)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(wxz)  ]	+	{	2(3)  }
	vec4+					wxz+__/ wxwz***																																	|
	vec4+					   \  \_wxxz***																																	|
	vec4+						\  /wxzz***																																	|
	vec4+						 \/	wxzw***																																	|
	vec4+						  \_wxzx***																																	|
	vec4+						   /yywz***u3(ywz)+n3(ywz)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(ywz)  ]	+	{	2(3)  }
	vec4+					ywz+__/ ywyz***																																	|
	vec4+					|||\  \_ywwz***																																	|
	vec4+					|||	\  /ywzz***																																	|
	vec4+					|||  \/	ywzy***																																	|
	vec4+					|||	  \_ywzw***																																	|
	vec4+					|||	   /wwyz***u3(wyz)+n3(wyz)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(wyz)  ]	+	{	2(3)  }
	vec4+					wyz+__/ wywz***																																	|
	vec4+					   \  \_wyyz***																																	|
	vec4+						\  /wyzz***																																	|
	vec4+						 \/ wyzy***																																	|
	vec4+						  \_wyzw***																																	|
	vec4+						   /zzwx***u3(zwx)+n3(zwx)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(zwx)  ]	+	{	2(3)  }
	vec4+					zwx+__/ zwzx***																																	|
	vec4+					|||\  \_zwwx***																																	|
	vec4+					||| \  /zwxx***																																	|
	vec4+					|||	 \/ zwxw***																																	|
	vec4+					|||	  \_zwxz***																																	|
	vec4+					|||	   /wwzx***u3(wzx)+n3(wzx)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(wzx)  ]	+	{	2(3)  }
	vec4+					wzx+__/ wzwx***																																	|
	vec4+					   \  \_wzzx***																																	|
	vec4+						\  /wzxx***																																	|
	vec4+						 \/ wzxz***																																	|
	vec4+						  \_wzxw***																																	|
	vec4+						   /wwzy***u3(wzy)+n3(wzy)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(wzy)  ]	+	{	2(3)  }
	vec4+					wzy+__/ wzwy***																																	|
	vec4+					|||\  \_wzzy***																																	|
	vec4+					||| \  /wzyy***																																	|
	vec4+					|||	 \/ wzyz***																																	|
	vec4+					|||	  \_wzyw***																																	|
	vec4+					|||	   /zzwy***u3(zwy)+n3(zwy)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(zwy)  ]	+	{	2(3)  }	+
	vec4+					zwy+__/ zwzy***																																									|
	vec4+					   \  \_zwwy***																																									|
	vec4+						\  /zwyy***																																									|
	vec4+						 \/ zwyw***																																									|
	vec4+						  \_zwyz***																																									|
	vec4+						   /xyzw****u4(x...)+n4(x...)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 6(x...) ]
	vec4+						  /	xywz****																																								|
	vec4+						 /	xzyw****																																								|
	vec4+						 \	xzwy****																																								|
	vec4+						  \	xwyz****																																								|
	vec4+						   \xwzy****																																								|
	vec4+						   /yxzw****u4(y...)+n4(y...)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 6(y...) ]
	vec4+						  /	yxwz****																																								|
	vec4+						 /	yzxw****																																								|
	vec4+						 \	yzwx****																																								|
	vec4+						  \	ywxz****																																								|
	vec4+						   \ywzx****																																								|
	vec4+						   /zxyw****u4(z...)+n4(z...)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 6(z...) ]
	vec4+						  /	zxwy****																																								|
	vec4+						 /	zyxw****																																								|
	vec4+						 \	zywx****																																								|
	vec4+						  \	zwxy****																																								|
	vec4+						   \zwyx****																																								|
	vec4+						   /wxyz****u4(w...)+n4(w...)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 6(w...) ]
	vec4+						  /	wxzy****
	vec4+						 /	wyxz****
	vec4+						 \	wyzx****
	vec4+						  \	wzxy****
	vec4+						   \wzyx****
	u4(xyzw) =	xyzw;
	n4(xyzw)	<empty set>
	F4(xyzw) =	f1(w);
				f2(xw), f2(wx), f2(yw), f2(wy), f2(zw), f2(wz);
				f3(xyw), f3(yxw), f3(xzw), f3(zxw), f3(xwy), f3(wxy), f3(yzw), f3(zyw), f3(ywx), f3(wyx), f3(xwz), f3(wxz), f3(ywz), f3(wyz), f3(zwx), f3(wzx), f3(wzy), f3(zwy);
				f4(xyzw), f4(xywz), f4(xzyw), f4(xzwy), f4(xwyz), f4(xwzy), f4(yxzw), f4(yxwz), f4(yzxw), f4(yzwx), f4(ywxz), f4(ywzx), f4(zxyw), f4(zxwy), f4(zyxw), f4(zywx), f4(zwxy), f4(zwyx), f4(wxyz), f4(wxzy), f4(wyxz), f4(wyzx), f4(wzxy), f4(wzyx);
*/

