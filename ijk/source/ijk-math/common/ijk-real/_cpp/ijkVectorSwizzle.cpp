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

	ijkVectorSwizzle.cpp
	C++ testing source definitions for vector types.
*/

#define IJK_VECTOR_SWIZZLE
#include "ijk/ijk-math/ijk-real/ijkVector.h"
#include "ijk/ijk-math/ijk-real/_util/ijkVectorSwizzle_macros.h"


//-----------------------------------------------------------------------------

extern "C" {
	void ijkMathTestVectorSwizzle();
}

void ijkMathTestVectorSwizzle()
{
	typedef i32 base, * basev;
	typedef int type;
	typedef ivec2 tvec2;
	typedef ivec3 tvec3;
	typedef ivec4 tvec4;

	tvec2 test_vec2(7, 13);
	tvec2 test_svec2 = tvec2(42, 9001).yx;	// ivec2 ctor -> call swiz -> isvec2 ctor -> ivec2 ctor: test_isvec2 = (9001, 42)
	tvec2 const test_vec2k = test_svec2.yx;	// call swiz -> isvec2 ctor -> ivec2 ctor: test_ivec2k = (42, 9001)

	type test_vec1 = 4;
	type test_vec1r = test_vec1;

	tvec3 test_vec3x = ivec3_x, test_vec3y = ivec3_y;

	tvec3 test_vec3;
	tvec4 test_vec4;

	base test_dot3v = ijkVecDot3iv(test_vec3x.xyz, test_vec3y.xyz);
	//base test_dot3v = ijkVecDot3iv(test_vec3x.xyz, test_vec3y.yxz);
	type test_dot3 = ijkVecDot3i(test_vec3x, test_vec3y);
	//basev test_cross3v = ijkVecCross3iv(test_vec3.xyz, test_vec3x.xyz, test_vec3y.xyz);
	basev test_cross3v = ijkVecCross3iv(test_vec3.zyx, test_vec3x.xyz, test_vec3y.xyz);
	tvec3 test_cross3 = ijkVecCross3i(test_vec3x, test_vec3y);

	test_vec3.x += 1;
	test_vec3.xyz += 1;

	//(test_vec2 + 7).x = 1;		// error: lhs is const
	test_vec2.x = 1;				// call swiz -> assign

	test_svec2 = test_vec2.xx;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (7, 7)
	test_svec2 = test_vec2.xy;	// call swiz -> isvec2 ctor -> ivec2 assign isvec2: test_isvec2 = (7, 13)
	test_svec2 = test_vec2.yx;	// call swiz -> isvec2 ctor -> ivec2 assign isvec2: test_isvec2 = (13, 7)
	test_svec2 = test_vec2.yy;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (13, 13)

	test_svec2 = test_vec2k.xx;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (42, 42)
	test_svec2 = test_vec2k.xy;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (42, 9001)
	test_svec2 = test_vec2k.yx;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (9001, 42)
	test_svec2 = test_vec2k.yy;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_isvec2 = (9001, 9001)

//	test_svec2 = test_vec2.xx = test_vec2k;		// error: xx returns const
//	test_svec2 = test_vec2.yy = test_vec2k;		// error: yy returns const
//	test_vec2k.xy = test_vec2;					// error: test_ivec2k is const
//	test_vec2k.yx = test_vec2;					// error: test_ivec2k is const
	test_svec2.yx = test_vec2.yx = test_vec2k;	// test_ivec2 call swiz -> isvec2 (test_ivec2) ctor -> isvec2 (test_ivec2) assign ivec2: test_ivec2 = (9001, 42) -> test_isvec2 call swiz -> isvec2 (test_isvec2) ctor -> isvec2 (test_isvec2) assign ivec2: test_isvec2 = (9001, 42)
	test_svec2 = test_vec2.xy = test_vec2k;		// test_ivec2 call swiz -> isvec2 ctor -> isvec2 (test_ivec2) assign ivec2: test_ivec2 = (42, 9001) -> test_isvec2 ivec2 assign ivec2: test_isvec2 = (42, 9001)
	test_vec2 = test_vec2.yx;					// test_ivec2 call swiz -> isvec2 ctor -> ivec2 assign isvec2 -> ivec2 ctor isvec2: test_ivec2 = (9001, 42)
	test_vec2.yx = test_vec2;					// test_ivec2 call swiz -> isvec2 ctor -> isvec2 assign ivec2: test_ivec2 = (42, 9001)
	test_svec2.xy = test_vec2.xy;				// test_ivec2 call swiz -> isvec2 (test_ivec2) ctor -> test_isvec2 call swiz -> isvec2 (test_isvec2) ctor -> isvec2 (test_isvec2) assign isvec2 (test_ivec2) -> test_isvec2 = (42, 9001)
	test_svec2.xy = test_vec2.yx;				// test_ivec2 call swiz -> isvec2 (test_ivec2) ctor -> test_isvec2 call swiz -> isvec2 (test_isvec2) ctor -> isvec2 (test_isvec2) assign isvec2 (test_ivec2) -> test_isvec2 = (9001, 42)
	test_svec2.yx = test_vec2.xy;				// test_ivec2 call swiz -> isvec2 (test_ivec2) ctor -> test_isvec2 call swiz -> isvec2 (test_isvec2) ctor -> isvec2 (test_isvec2) assign isvec2 (test_ivec2) -> test_isvec2 = (9001, 42)
	test_svec2.yx = test_vec2.yx;				// test_ivec2 call swiz -> isvec2 (test_ivec2) ctor -> test_isvec2 call swiz -> isvec2 (test_isvec2) ctor -> isvec2 (test_isvec2) assign isvec2 (test_ivec2) -> test_isvec2 = (42, 9001)
	test_vec2.xy = test_vec2.xy;				// test_ivec2 call swiz -> isvec2 ctor -> test_ivec2 call swiz -> isvec2 ctor -> isvec2 assign isvec2 -> test_isvec2 = (42, 9001)
	test_vec2.xy = test_vec2.yx;				// test_ivec2 call swiz -> isvec2 ctor -> test_ivec2 call swiz -> isvec2 ctor -> isvec2 assign isvec2 -> test_isvec2 = (9001, 42)
	test_vec2.yx = test_vec2.xy;				// test_ivec2 call swiz -> isvec2 ctor -> test_ivec2 call swiz -> isvec2 ctor -> isvec2 assign isvec2 -> test_isvec2 = (42, 9001)
	test_vec2.yx = test_vec2.yx;				// test_ivec2 call swiz -> isvec2 ctor -> test_ivec2 call swiz -> isvec2 ctor -> isvec2 assign isvec2 -> test_isvec2 = (42, 9001)

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

