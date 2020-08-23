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

	ijkVector_c.cpp
	C++ testing source definitions for vector types.
*/

#include "ijk/ijk-math/ijk-real/ijkVector.h"


//-----------------------------------------------------------------------------

extern "C" {
	void ijkVectorTestCPP_swizzle();
}

void ijkVectorTestCPP_swizzle()
{
	ivec2 test_ivec2(7, 13);
	ivec2 test_ivec2r = ivec2(42, 9001).yx;	// ivec2 ctor -> call swiz -> ivec2r ctor -> ivec2 ctor: test_ivec2r = (9001, 42)
	ivec2 const test_ivec2k = test_ivec2r.yx;	// call swiz -> ivec2r ctor -> ivec2 ctor: test_ivec2k = (42, 9001)

/*
	ivec3 test_ivec3;
	ivec4 test_ivec4;

	fvec2 test_fvec2;
	fvec3 test_fvec3;
	fvec4 test_fvec4;

	dvec2 test_dvec2;
	dvec3 test_dvec3;
	dvec4 test_dvec4;
*/

	test_ivec2r = test_ivec2.xx;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_ivec2r = (7, 7)
	test_ivec2r = test_ivec2.xy;	// call swiz -> ivec2r ctor -> ivec2 assign ivec2r: test_ivec2r = (7, 13)
	test_ivec2r = test_ivec2.yx;	// call swiz -> ivec2r ctor -> ivec2 assign ivec2r: test_ivec2r = (13, 7)
	test_ivec2r = test_ivec2.yy;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_ivec2r = (13, 13)

	test_ivec2r = test_ivec2k.xx;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_ivec2r = (42, 42)
	test_ivec2r = test_ivec2k.xy;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_ivec2r = (42, 9001)
	test_ivec2r = test_ivec2k.yx;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_ivec2r = (9001, 42)
	test_ivec2r = test_ivec2k.yy;	// call swiz -> ivec2 ctor -> ivec2 assign ivec2: test_ivec2r = (9001, 9001)

//	test_ivec2r = test_ivec2.xx = test_ivec2k;		// error: xx returns const
//	test_ivec2r = test_ivec2.yy = test_ivec2k;		// error: yy returns const
//	test_ivec2k.xy = test_ivec2;					// error: test_ivec2k is const
//	test_ivec2k.yx = test_ivec2;					// error: test_ivec2k is const
	test_ivec2r.yx = test_ivec2.yx = test_ivec2k;	// test_ivec2 call swiz -> ivec2r (test_ivec2) ctor -> ivec2r (test_ivec2) assign ivec2: test_ivec2 = (9001, 42) -> test_ivec2r call swiz -> ivec2r (test_ivec2r) ctor -> ivec2r (test_ivec2r) assign ivec2: test_ivec2r = (9001, 42)
	test_ivec2r = test_ivec2.xy = test_ivec2k;		// test_ivec2 call swiz -> ivec2r ctor -> ivec2r (test_ivec2) assign ivec2: test_ivec2 = (42, 9001) -> test_ivec2r ivec2 assign ivec2: test_ivec2r = (42, 9001)
	test_ivec2 = test_ivec2.yx;						// test_ivec2 call swiz -> ivec2r ctor -> ivec2 assign ivec2r -> ivec2 ctor ivec2r: test_ivec2 = (9001, 42)
	test_ivec2.yx = test_ivec2;						// test_ivec2 call swiz -> ivec2r ctor -> ivec2r assign ivec2: test_ivec2 = (42, 9001)
	test_ivec2r.xy = test_ivec2.xy;					// test_ivec2 call swiz -> ivec2r (test_ivec2) ctor -> test_ivec2r call swiz -> ivec2r (test_ivec2r) ctor -> ivec2r (test_ivec2r) assign ivec2r (test_ivec2) -> test_ivec2r = (42, 9001)
	test_ivec2r.xy = test_ivec2.yx;					// test_ivec2 call swiz -> ivec2r (test_ivec2) ctor -> test_ivec2r call swiz -> ivec2r (test_ivec2r) ctor -> ivec2r (test_ivec2r) assign ivec2r (test_ivec2) -> test_ivec2r = (9001, 42)
	test_ivec2r.yx = test_ivec2.xy;					// test_ivec2 call swiz -> ivec2r (test_ivec2) ctor -> test_ivec2r call swiz -> ivec2r (test_ivec2r) ctor -> ivec2r (test_ivec2r) assign ivec2r (test_ivec2) -> test_ivec2r = (9001, 42)
	test_ivec2r.yx = test_ivec2.yx;					// test_ivec2 call swiz -> ivec2r (test_ivec2) ctor -> test_ivec2r call swiz -> ivec2r (test_ivec2r) ctor -> ivec2r (test_ivec2r) assign ivec2r (test_ivec2) -> test_ivec2r = (42, 9001)
	test_ivec2.xy = test_ivec2.xy;					// test_ivec2 call swiz -> ivec2r ctor -> test_ivec2 call swiz -> ivec2r ctor -> ivec2r assign ivec2r -> test_ivec2r = (42, 9001)
	test_ivec2.xy = test_ivec2.yx;					// test_ivec2 call swiz -> ivec2r ctor -> test_ivec2 call swiz -> ivec2r ctor -> ivec2r assign ivec2r -> test_ivec2r = (9001, 42)
	test_ivec2.yx = test_ivec2.xy;					// test_ivec2 call swiz -> ivec2r ctor -> test_ivec2 call swiz -> ivec2r ctor -> ivec2r assign ivec2r -> test_ivec2r = (42, 9001)
	test_ivec2.yx = test_ivec2.yx;					// test_ivec2 call swiz -> ivec2r ctor -> test_ivec2 call swiz -> ivec2r ctor -> ivec2r assign ivec2r -> test_ivec2r = (42, 9001)

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
/*
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

	test_fvec2.xx;
	test_fvec2.xy;
	test_fvec2.yx;
	test_fvec2.yy;
	test_fvec2.xxx;
	test_fvec2.xxy;
	test_fvec2.xyx;
	test_fvec2.xyy;
	test_fvec2.yxx;
	test_fvec2.yxy;
	test_fvec2.yyx;
	test_fvec2.yyy;
	test_fvec2.xxxx;
	test_fvec2.xxxy;
	test_fvec2.xxyx;
	test_fvec2.xxyy;
	test_fvec2.xyxx;
	test_fvec2.xyxy;
	test_fvec2.xyyx;
	test_fvec2.xyyy;
	test_fvec2.yxxx;
	test_fvec2.yxxy;
	test_fvec2.yxyx;
	test_fvec2.yxyy;
	test_fvec2.yyxx;
	test_fvec2.yyxy;
	test_fvec2.yyyx;
	test_fvec2.yyyy;

	test_fvec3.xx;
	test_fvec3.xy;
	test_fvec3.xz;
	test_fvec3.yx;
	test_fvec3.yy;
	test_fvec3.yz;
	test_fvec3.zx;
	test_fvec3.zy;
	test_fvec3.zz;
	test_fvec3.xxx;
	test_fvec3.xxy;
	test_fvec3.xxz;
	test_fvec3.xyx;
	test_fvec3.xyy;
	test_fvec3.xyz;
	test_fvec3.xzx;
	test_fvec3.xzy;
	test_fvec3.xzz;
	test_fvec3.yxx;
	test_fvec3.yxy;
	test_fvec3.yxz;
	test_fvec3.yyx;
	test_fvec3.yyy;
	test_fvec3.yyz;
	test_fvec3.yzx;
	test_fvec3.yzy;
	test_fvec3.yzz;
	test_fvec3.zxx;
	test_fvec3.zxy;
	test_fvec3.zxz;
	test_fvec3.zyx;
	test_fvec3.zyy;
	test_fvec3.zyz;
	test_fvec3.zzx;
	test_fvec3.zzy;
	test_fvec3.zzz;
	test_fvec3.xxxx;
	test_fvec3.xxxy;
	test_fvec3.xxxz;
	test_fvec3.xxyx;
	test_fvec3.xxyy;
	test_fvec3.xxyz;
	test_fvec3.xxzx;
	test_fvec3.xxzy;
	test_fvec3.xxzz;
	test_fvec3.xyxx;
	test_fvec3.xyxy;
	test_fvec3.xyxz;
	test_fvec3.xyyx;
	test_fvec3.xyyy;
	test_fvec3.xyyz;
	test_fvec3.xyzx;
	test_fvec3.xyzy;
	test_fvec3.xyzz;
	test_fvec3.xzxx;
	test_fvec3.xzxy;
	test_fvec3.xzxz;
	test_fvec3.xzyx;
	test_fvec3.xzyy;
	test_fvec3.xzyz;
	test_fvec3.xzzx;
	test_fvec3.xzzy;
	test_fvec3.xzzz;
	test_fvec3.yxxx;
	test_fvec3.yxxy;
	test_fvec3.yxxz;
	test_fvec3.yxyx;
	test_fvec3.yxyy;
	test_fvec3.yxyz;
	test_fvec3.yxzx;
	test_fvec3.yxzy;
	test_fvec3.yxzz;
	test_fvec3.yyxx;
	test_fvec3.yyxy;
	test_fvec3.yyxz;
	test_fvec3.yyyx;
	test_fvec3.yyyy;
	test_fvec3.yyyz;
	test_fvec3.yyzx;
	test_fvec3.yyzy;
	test_fvec3.yyzz;
	test_fvec3.yzxx;
	test_fvec3.yzxy;
	test_fvec3.yzxz;
	test_fvec3.yzyx;
	test_fvec3.yzyy;
	test_fvec3.yzyz;
	test_fvec3.yzzx;
	test_fvec3.yzzy;
	test_fvec3.yzzz;
	test_fvec3.zxxx;
	test_fvec3.zxxy;
	test_fvec3.zxxz;
	test_fvec3.zxyx;
	test_fvec3.zxyy;
	test_fvec3.zxyz;
	test_fvec3.zxzx;
	test_fvec3.zxzy;
	test_fvec3.zxzz;
	test_fvec3.zyxx;
	test_fvec3.zyxy;
	test_fvec3.zyxz;
	test_fvec3.zyyx;
	test_fvec3.zyyy;
	test_fvec3.zyyz;
	test_fvec3.zyzx;
	test_fvec3.zyzy;
	test_fvec3.zyzz;
	test_fvec3.zzxx;
	test_fvec3.zzxy;
	test_fvec3.zzxz;
	test_fvec3.zzyx;
	test_fvec3.zzyy;
	test_fvec3.zzyz;
	test_fvec3.zzzx;
	test_fvec3.zzzy;
	test_fvec3.zzzz;

	test_fvec4.xx;
	test_fvec4.xy;
	test_fvec4.xz;
	test_fvec4.xw;
	test_fvec4.yx;
	test_fvec4.yy;
	test_fvec4.yz;
	test_fvec4.yw;
	test_fvec4.zx;
	test_fvec4.zy;
	test_fvec4.zz;
	test_fvec4.zw;
	test_fvec4.wx;
	test_fvec4.wy;
	test_fvec4.wz;
	test_fvec4.ww;
	test_fvec4.xxx;
	test_fvec4.xxy;
	test_fvec4.xxz;
	test_fvec4.xxw;
	test_fvec4.xyx;
	test_fvec4.xyy;
	test_fvec4.xyz;
	test_fvec4.xyw;
	test_fvec4.xzx;
	test_fvec4.xzy;
	test_fvec4.xzz;
	test_fvec4.xzw;
	test_fvec4.xwx;
	test_fvec4.xwy;
	test_fvec4.xwz;
	test_fvec4.xww;
	test_fvec4.yxx;
	test_fvec4.yxy;
	test_fvec4.yxz;
	test_fvec4.yxw;
	test_fvec4.yyx;
	test_fvec4.yyy;
	test_fvec4.yyz;
	test_fvec4.yyw;
	test_fvec4.yzx;
	test_fvec4.yzy;
	test_fvec4.yzz;
	test_fvec4.yzw;
	test_fvec4.ywx;
	test_fvec4.ywy;
	test_fvec4.ywz;
	test_fvec4.yww;
	test_fvec4.zxx;
	test_fvec4.zxy;
	test_fvec4.zxz;
	test_fvec4.zxw;
	test_fvec4.zyx;
	test_fvec4.zyy;
	test_fvec4.zyz;
	test_fvec4.zyw;
	test_fvec4.zzx;
	test_fvec4.zzy;
	test_fvec4.zzz;
	test_fvec4.zzw;
	test_fvec4.zwx;
	test_fvec4.zwy;
	test_fvec4.zwz;
	test_fvec4.zww;
	test_fvec4.wxx;
	test_fvec4.wxy;
	test_fvec4.wxz;
	test_fvec4.wxw;
	test_fvec4.wyx;
	test_fvec4.wyy;
	test_fvec4.wyz;
	test_fvec4.wyw;
	test_fvec4.wzx;
	test_fvec4.wzy;
	test_fvec4.wzz;
	test_fvec4.wzw;
	test_fvec4.wwx;
	test_fvec4.wwy;
	test_fvec4.wwz;
	test_fvec4.www;
	test_fvec4.xxxx;
	test_fvec4.xxxy;
	test_fvec4.xxxz;
	test_fvec4.xxxw;
	test_fvec4.xxyx;
	test_fvec4.xxyy;
	test_fvec4.xxyz;
	test_fvec4.xxyw;
	test_fvec4.xxzx;
	test_fvec4.xxzy;
	test_fvec4.xxzz;
	test_fvec4.xxzw;
	test_fvec4.xxwx;
	test_fvec4.xxwy;
	test_fvec4.xxwz;
	test_fvec4.xxww;
	test_fvec4.xyxx;
	test_fvec4.xyxy;
	test_fvec4.xyxz;
	test_fvec4.xyxw;
	test_fvec4.xyyx;
	test_fvec4.xyyy;
	test_fvec4.xyyz;
	test_fvec4.xyyw;
	test_fvec4.xyzx;
	test_fvec4.xyzy;
	test_fvec4.xyzz;
	test_fvec4.xyzw;
	test_fvec4.xywx;
	test_fvec4.xywy;
	test_fvec4.xywz;
	test_fvec4.xyww;
	test_fvec4.xzxx;
	test_fvec4.xzxy;
	test_fvec4.xzxz;
	test_fvec4.xzxw;
	test_fvec4.xzyx;
	test_fvec4.xzyy;
	test_fvec4.xzyz;
	test_fvec4.xzyw;
	test_fvec4.xzzx;
	test_fvec4.xzzy;
	test_fvec4.xzzz;
	test_fvec4.xzzw;
	test_fvec4.xzwx;
	test_fvec4.xzwy;
	test_fvec4.xzwz;
	test_fvec4.xzww;
	test_fvec4.xwxx;
	test_fvec4.xwxy;
	test_fvec4.xwxz;
	test_fvec4.xwxw;
	test_fvec4.xwyx;
	test_fvec4.xwyy;
	test_fvec4.xwyz;
	test_fvec4.xwyw;
	test_fvec4.xwzx;
	test_fvec4.xwzy;
	test_fvec4.xwzz;
	test_fvec4.xwzw;
	test_fvec4.xwwx;
	test_fvec4.xwwy;
	test_fvec4.xwwz;
	test_fvec4.xwww;
	test_fvec4.yxxx;
	test_fvec4.yxxy;
	test_fvec4.yxxz;
	test_fvec4.yxxw;
	test_fvec4.yxyx;
	test_fvec4.yxyy;
	test_fvec4.yxyz;
	test_fvec4.yxyw;
	test_fvec4.yxzx;
	test_fvec4.yxzy;
	test_fvec4.yxzz;
	test_fvec4.yxzw;
	test_fvec4.yxwx;
	test_fvec4.yxwy;
	test_fvec4.yxwz;
	test_fvec4.yxww;
	test_fvec4.yyxx;
	test_fvec4.yyxy;
	test_fvec4.yyxz;
	test_fvec4.yyxw;
	test_fvec4.yyyx;
	test_fvec4.yyyy;
	test_fvec4.yyyz;
	test_fvec4.yyyw;
	test_fvec4.yyzx;
	test_fvec4.yyzy;
	test_fvec4.yyzz;
	test_fvec4.yyzw;
	test_fvec4.yywx;
	test_fvec4.yywy;
	test_fvec4.yywz;
	test_fvec4.yyww;
	test_fvec4.yzxx;
	test_fvec4.yzxy;
	test_fvec4.yzxz;
	test_fvec4.yzxw;
	test_fvec4.yzyx;
	test_fvec4.yzyy;
	test_fvec4.yzyz;
	test_fvec4.yzyw;
	test_fvec4.yzzx;
	test_fvec4.yzzy;
	test_fvec4.yzzz;
	test_fvec4.yzzw;
	test_fvec4.yzwx;
	test_fvec4.yzwy;
	test_fvec4.yzwz;
	test_fvec4.yzww;
	test_fvec4.ywxx;
	test_fvec4.ywxy;
	test_fvec4.ywxz;
	test_fvec4.ywxw;
	test_fvec4.ywyx;
	test_fvec4.ywyy;
	test_fvec4.ywyz;
	test_fvec4.ywyw;
	test_fvec4.ywzx;
	test_fvec4.ywzy;
	test_fvec4.ywzz;
	test_fvec4.ywzw;
	test_fvec4.ywwx;
	test_fvec4.ywwy;
	test_fvec4.ywwz;
	test_fvec4.ywww;
	test_fvec4.zxxx;
	test_fvec4.zxxy;
	test_fvec4.zxxz;
	test_fvec4.zxxw;
	test_fvec4.zxyx;
	test_fvec4.zxyy;
	test_fvec4.zxyz;
	test_fvec4.zxyw;
	test_fvec4.zxzx;
	test_fvec4.zxzy;
	test_fvec4.zxzz;
	test_fvec4.zxzw;
	test_fvec4.zxwx;
	test_fvec4.zxwy;
	test_fvec4.zxwz;
	test_fvec4.zxww;
	test_fvec4.zyxx;
	test_fvec4.zyxy;
	test_fvec4.zyxz;
	test_fvec4.zyxw;
	test_fvec4.zyyx;
	test_fvec4.zyyy;
	test_fvec4.zyyz;
	test_fvec4.zyyw;
	test_fvec4.zyzx;
	test_fvec4.zyzy;
	test_fvec4.zyzz;
	test_fvec4.zyzw;
	test_fvec4.zywx;
	test_fvec4.zywy;
	test_fvec4.zywz;
	test_fvec4.zyww;
	test_fvec4.zzxx;
	test_fvec4.zzxy;
	test_fvec4.zzxz;
	test_fvec4.zzxw;
	test_fvec4.zzyx;
	test_fvec4.zzyy;
	test_fvec4.zzyz;
	test_fvec4.zzyw;
	test_fvec4.zzzx;
	test_fvec4.zzzy;
	test_fvec4.zzzz;
	test_fvec4.zzzw;
	test_fvec4.zzwx;
	test_fvec4.zzwy;
	test_fvec4.zzwz;
	test_fvec4.zzww;
	test_fvec4.zwxx;
	test_fvec4.zwxy;
	test_fvec4.zwxz;
	test_fvec4.zwxw;
	test_fvec4.zwyx;
	test_fvec4.zwyy;
	test_fvec4.zwyz;
	test_fvec4.zwyw;
	test_fvec4.zwzx;
	test_fvec4.zwzy;
	test_fvec4.zwzz;
	test_fvec4.zwzw;
	test_fvec4.zwwx;
	test_fvec4.zwwy;
	test_fvec4.zwwz;
	test_fvec4.zwww;
	test_fvec4.wxxx;
	test_fvec4.wxxy;
	test_fvec4.wxxz;
	test_fvec4.wxxw;
	test_fvec4.wxyx;
	test_fvec4.wxyy;
	test_fvec4.wxyz;
	test_fvec4.wxyw;
	test_fvec4.wxzx;
	test_fvec4.wxzy;
	test_fvec4.wxzz;
	test_fvec4.wxzw;
	test_fvec4.wxwx;
	test_fvec4.wxwy;
	test_fvec4.wxwz;
	test_fvec4.wxww;
	test_fvec4.wyxx;
	test_fvec4.wyxy;
	test_fvec4.wyxz;
	test_fvec4.wyxw;
	test_fvec4.wyyx;
	test_fvec4.wyyy;
	test_fvec4.wyyz;
	test_fvec4.wyyw;
	test_fvec4.wyzx;
	test_fvec4.wyzy;
	test_fvec4.wyzz;
	test_fvec4.wyzw;
	test_fvec4.wywx;
	test_fvec4.wywy;
	test_fvec4.wywz;
	test_fvec4.wyww;
	test_fvec4.wzxx;
	test_fvec4.wzxy;
	test_fvec4.wzxz;
	test_fvec4.wzxw;
	test_fvec4.wzyx;
	test_fvec4.wzyy;
	test_fvec4.wzyz;
	test_fvec4.wzyw;
	test_fvec4.wzzx;
	test_fvec4.wzzy;
	test_fvec4.wzzz;
	test_fvec4.wzzw;
	test_fvec4.wzwx;
	test_fvec4.wzwy;
	test_fvec4.wzwz;
	test_fvec4.wzww;
	test_fvec4.wwxx;
	test_fvec4.wwxy;
	test_fvec4.wwxz;
	test_fvec4.wwxw;
	test_fvec4.wwyx;
	test_fvec4.wwyy;
	test_fvec4.wwyz;
	test_fvec4.wwyw;
	test_fvec4.wwzx;
	test_fvec4.wwzy;
	test_fvec4.wwzz;
	test_fvec4.wwzw;
	test_fvec4.wwwx;
	test_fvec4.wwwy;
	test_fvec4.wwwz;
	test_fvec4.wwww;

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
*/
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
	vec1+	x/______xx______xxx_____xxxx*u1(x)+n1(x)			[ 1(x)	  ]	+	{ 1(xx)		+	  1(...)	+	  1			}	= 4 = 1 unique + 3


			vec1	vec2	vec3	vec4					NEW	vec1 from 1	+	vec2 from 1	+	vec3 from 1	+	vec4 from 1	+	vec2 from 2	+	vec3 from 2	+	vec4 from 2
																UNIQUE															UNIQUE
	vec2+						 ___xxxy**
	vec2+						|___xxyx**
	vec2+				 ___xxy_|___xxyy**
	vec2+				|		 ___xyxx**					
	vec2+				|___xyx_|___xyxy**					
	vec2+				|		 ___xyyx**
	vec2+			xy/_|___xyy_|___xyyy**u2(xy)+n2(xy)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(xy)	  ]	+	{	3		+	  3(2)+1	}	= 4 + 2(1 + 3 + 3(2)+1) = 26 = 3 unique + 23
	vec2+	 		yx/_____yxx_____yxxx**u2(yx)+n2(yx)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(yx)	  ]	+	{	3		+	  3(2)+1	}
	vec2+				|		|___yxxy**																					|
	vec2+				|___yxy_____yxyx**																					|
	vec2+				|		|___yxyy**																					|
	vec2+				|___yyx_____yyxx**																					|
	vec2+						|___yyxy**																					|
	vec2+						|___yyyx**																					|
	vec2+	y/______yy______yyy_____yyyy*u1(y)+n1(y)	--	--	[ 1(y)	  ]	+	{ 1(yy)		+	  1(...)	+	  1		}	+


			vec1	vec2	vec3	vec4					NEW	vec1 from 1	+	vec2 from 1	+	vec3 from 1	+	vec4 from 1	+	vec2 from 2	+	vec3 from 2	+	vec4 from 2	
																UNIQUE															UNIQUE
	vec3+						 ___xxxz**
	vec3+						|___xxzx**
	vec3+				 ___xxz_|___xxzz**
	vec3+				|		 ___xzxx**
	vec3+				|___xzx_|___xzxz**
	vec3+				|		 ___xzzx**
	vec3+			xz/_|___xzz_|___xzzz**u2(xz)+n2(xz)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(xz)	  ]	+	{	3		+	  3(2)+1	}
	vec3+			zx/_____zxx_____zxxx**u2(zx)+n2(zx)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(zx)	  ]	+	{	3		+	  3(2)+1	}
	vec3+				|		|___zxxz**																					|
	vec3+				|___zxz_____zxzx**																					|
	vec3+				|		|___zxzz**																					|
	vec3+				|___zzx_____zzxx**																					|
	vec3+						|___zzxz**																					|
	vec3+						|___zzzx**																					|

	vec3+							xxyz
	vec3+							xyxz
	vec3+							xyyz

	vec3+							xxzy
	vec3+							xzxy
	vec3+							xzyx
	vec3+							xzzy
	vec3+					xzy/____xzyz
	vec3+					zxy/____zxyz
	vec3+							zxzy
	vec3+							zxyx
	vec3+							zxxy

	vec3+							xzyy
	vec3+							zxyy


	vec3+							xyzx
	vec3+							xyzy
	vec3+					xyz/____xyzz
	vec3+					yxz/____yxzz
	vec3+							yxzy
	vec3+							yxzx

	vec3+							yzxx
	vec3+							zyxx

	vec3+							yyzx
	vec3+							yzzx
	vec3+							yzxz
	vec3+							yzyx
	vec3+					yzx/____yzxy
	vec3+					zyx/____zyxy
	vec3+							zyyx
	vec3+							zyxz
	vec3+							zyzx
	vec3+							zzxy
	vec3+				  			zzyx

	vec3+							yxxz
	vec3+							yxyz
	vec3+							yyxz

	vec3+						 ___yyyz**																					|
	vec3+						|___yyzy**																					|
	vec3+				 ___yyz_|___yyzz**																					|
	vec3+				|		 ___yzyy**																					|
	vec3+				|___yzy_|___yzyz**																					|
	vec3+				|		 ___yzzy**																					|
	vec3+			yz/_|___yzz_|___yzzz**u2(yz)+n2(yz)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(yz)	  ]	+	{	3		+	  3(2)+1	}
	vec3+			zy/_____zyy_____zyyy**u2(zy)+n2(zy)	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	--	+	[ 1(zy)	  ]	+	{	3		+	  3(2)+1	}
	vec3+				|		|___zyyz**																					|
	vec3+				|___zyz_____zyzy**																					|
	vec3+				|		|___zyzz**																					|
	vec3+				|___zzy_____zzyy**																					|
	vec3+						|___zzyz**																					|
	vec3+						|___zzzy**																					|
	vec3+	z/______zz______zzz_____zzzz*u1(z)+n1(z)	--	--	[ 1(z)	  ]	+	{ 1(zz)		+	  1(...)	+	  1		}	+



	vec4+							xxxw
	vec4+							xxyw
	vec4+							xxzw
	vec4+					xxw		xxwx
	vec4+							xxwy
	vec4+							xxwz
	vec4+							xxww
	vec4+							xyxw
	vec4+							xyyw
	vec4+							xyzw
	vec4+					xyw		xywx
	vec4+							xywy
	vec4+							xywz
	vec4+							xyww
	vec4+							xzxw
	vec4+							xzyw
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
	vec4+							yxxw
	vec4+							yxyw
	vec4+							yxzw
	vec4+					yxw		yxwx
	vec4+							yxwy
	vec4+							yxwz
	vec4+							yxww
	vec4+							yyxw
	vec4+							yyyw
	vec4+							yyzw
	vec4+					yyw		yywx
	vec4+							yywy
	vec4+							yywz
	vec4+							yyww
	vec4+							yzxw
	vec4+							yzyw
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
	vec4+							zxxw
	vec4+							zxyw
	vec4+							zxzw
	vec4+					zxw		zxwx
	vec4+							zxwy
	vec4+							zxwz
	vec4+							zxww
	vec4+							zyxw
	vec4+							zyyw
	vec4+							zyzw
	vec4+					zyw		zywx
	vec4+							zywy
	vec4+							zywz
	vec4+							zyww
	vec4+							zzxw
	vec4+							zzyw
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

