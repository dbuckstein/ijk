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

	ijkVectorSwizzle_macros.h
	Swizzling shortcut macro definitions.
*/

#ifdef _IJK_VECTORSWIZZLE_H_
#ifndef _IJK_VECTORSWIZZLE_MACRO_H_
#define _IJK_VECTORSWIZZLE_MACRO_H_


//-----------------------------------------------------------------------------

#ifdef __cplusplus
#ifdef IJK_VECTOR_SWIZZLE

// IJK_SWIZZLE_MACRO_IMPL
#pragma region IJK_SWIZZLE_MACRO_IMPL

// Swizzle shorthand macros.
///
#define x		__swiz__x()
#define y		__swiz__y()
#define z		__swiz__z()
#define w		__swiz__w()
#define xx		__swiz__xx()
#define xy		__swiz__xy()
#define xz		__swiz__xz()
#define xw		__swiz__xw()
#define yx		__swiz__yx()
#define yy		__swiz__yy()
#define yz		__swiz__yz()
#define yw		__swiz__yw()
#define zx		__swiz__zx()
#define zy		__swiz__zy()
#define zz		__swiz__zz()
#define zw		__swiz__zw()
#define wx		__swiz__wx()
#define wy		__swiz__wy()
#define wz		__swiz__wz()
#define ww		__swiz__ww()
#define xxx		__swiz__xxx()
#define xxy		__swiz__xxy()
#define xxz		__swiz__xxz()
#define xxw		__swiz__xxw()
#define xyx		__swiz__xyx()
#define xyy		__swiz__xyy()
#define xyz		__swiz__xyz()
#define xyw		__swiz__xyw()
#define xzx		__swiz__xzx()
#define xzy		__swiz__xzy()
#define xzz		__swiz__xzz()
#define xzw		__swiz__xzw()
#define xwx		__swiz__xwx()
#define xwy		__swiz__xwy()
#define xwz		__swiz__xwz()
#define xww		__swiz__xww()
#define yxx		__swiz__yxx()
#define yxy		__swiz__yxy()
#define yxz		__swiz__yxz()
#define yxw		__swiz__yxw()
#define yyx		__swiz__yyx()
#define yyy		__swiz__yyy()
#define yyz		__swiz__yyz()
#define yyw		__swiz__yyw()
#define yzx		__swiz__yzx()
#define yzy		__swiz__yzy()
#define yzz		__swiz__yzz()
#define yzw		__swiz__yzw()
#define ywx		__swiz__ywx()
#define ywy		__swiz__ywy()
#define ywz		__swiz__ywz()
#define yww		__swiz__yww()
#define zxx		__swiz__zxx()
#define zxy		__swiz__zxy()
#define zxz		__swiz__zxz()
#define zxw		__swiz__zxw()
#define zyx		__swiz__zyx()
#define zyy		__swiz__zyy()
#define zyz		__swiz__zyz()
#define zyw		__swiz__zyw()
#define zzx		__swiz__zzx()
#define zzy		__swiz__zzy()
#define zzz		__swiz__zzz()
#define zzw		__swiz__zzw()
#define zwx		__swiz__zwx()
#define zwy		__swiz__zwy()
#define zwz		__swiz__zwz()
#define zww		__swiz__zww()
#define wxx		__swiz__wxx()
#define wxy		__swiz__wxy()
#define wxz		__swiz__wxz()
#define wxw		__swiz__wxw()
#define wyx		__swiz__wyx()
#define wyy		__swiz__wyy()
#define wyz		__swiz__wyz()
#define wyw		__swiz__wyw()
#define wzx		__swiz__wzx()
#define wzy		__swiz__wzy()
#define wzz		__swiz__wzz()
#define wzw		__swiz__wzw()
#define wwx		__swiz__wwx()
#define wwy		__swiz__wwy()
#define wwz		__swiz__wwz()
#define www		__swiz__www()
#define xxxx	__swiz__xxxx()
#define xxxy	__swiz__xxxy()
#define xxxz	__swiz__xxxz()
#define xxxw	__swiz__xxxw()
#define xxyx	__swiz__xxyx()
#define xxyy	__swiz__xxyy()
#define xxyz	__swiz__xxyz()
#define xxyw	__swiz__xxyw()
#define xxzx	__swiz__xxzx()
#define xxzy	__swiz__xxzy()
#define xxzz	__swiz__xxzz()
#define xxzw	__swiz__xxzw()
#define xxwx	__swiz__xxwx()
#define xxwy	__swiz__xxwy()
#define xxwz	__swiz__xxwz()
#define xxww	__swiz__xxww()
#define xyxx	__swiz__xyxx()
#define xyxy	__swiz__xyxy()
#define xyxz	__swiz__xyxz()
#define xyxw	__swiz__xyxw()
#define xyyx	__swiz__xyyx()
#define xyyy	__swiz__xyyy()
#define xyyz	__swiz__xyyz()
#define xyyw	__swiz__xyyw()
#define xyzx	__swiz__xyzx()
#define xyzy	__swiz__xyzy()
#define xyzz	__swiz__xyzz()
#define xyzw	__swiz__xyzw()
#define xywx	__swiz__xywx()
#define xywy	__swiz__xywy()
#define xywz	__swiz__xywz()
#define xyww	__swiz__xyww()
#define xzxx	__swiz__xzxx()
#define xzxy	__swiz__xzxy()
#define xzxz	__swiz__xzxz()
#define xzxw	__swiz__xzxw()
#define xzyx	__swiz__xzyx()
#define xzyy	__swiz__xzyy()
#define xzyz	__swiz__xzyz()
#define xzyw	__swiz__xzyw()
#define xzzx	__swiz__xzzx()
#define xzzy	__swiz__xzzy()
#define xzzz	__swiz__xzzz()
#define xzzw	__swiz__xzzw()
#define xzwx	__swiz__xzwx()
#define xzwy	__swiz__xzwy()
#define xzwz	__swiz__xzwz()
#define xzww	__swiz__xzww()
#define xwxx	__swiz__xwxx()
#define xwxy	__swiz__xwxy()
#define xwxz	__swiz__xwxz()
#define xwxw	__swiz__xwxw()
#define xwyx	__swiz__xwyx()
#define xwyy	__swiz__xwyy()
#define xwyz	__swiz__xwyz()
#define xwyw	__swiz__xwyw()
#define xwzx	__swiz__xwzx()
#define xwzy	__swiz__xwzy()
#define xwzz	__swiz__xwzz()
#define xwzw	__swiz__xwzw()
#define xwwx	__swiz__xwwx()
#define xwwy	__swiz__xwwy()
#define xwwz	__swiz__xwwz()
#define xwww	__swiz__xwww()
#define yxxx	__swiz__yxxx()
#define yxxy	__swiz__yxxy()
#define yxxz	__swiz__yxxz()
#define yxxw	__swiz__yxxw()
#define yxyx	__swiz__yxyx()
#define yxyy	__swiz__yxyy()
#define yxyz	__swiz__yxyz()
#define yxyw	__swiz__yxyw()
#define yxzx	__swiz__yxzx()
#define yxzy	__swiz__yxzy()
#define yxzz	__swiz__yxzz()
#define yxzw	__swiz__yxzw()
#define yxwx	__swiz__yxwx()
#define yxwy	__swiz__yxwy()
#define yxwz	__swiz__yxwz()
#define yxww	__swiz__yxww()
#define yyxx	__swiz__yyxx()
#define yyxy	__swiz__yyxy()
#define yyxz	__swiz__yyxz()
#define yyxw	__swiz__yyxw()
#define yyyx	__swiz__yyyx()
#define yyyy	__swiz__yyyy()
#define yyyz	__swiz__yyyz()
#define yyyw	__swiz__yyyw()
#define yyzx	__swiz__yyzx()
#define yyzy	__swiz__yyzy()
#define yyzz	__swiz__yyzz()
#define yyzw	__swiz__yyzw()
#define yywx	__swiz__yywx()
#define yywy	__swiz__yywy()
#define yywz	__swiz__yywz()
#define yyww	__swiz__yyww()
#define yzxx	__swiz__yzxx()
#define yzxy	__swiz__yzxy()
#define yzxz	__swiz__yzxz()
#define yzxw	__swiz__yzxw()
#define yzyx	__swiz__yzyx()
#define yzyy	__swiz__yzyy()
#define yzyz	__swiz__yzyz()
#define yzyw	__swiz__yzyw()
#define yzzx	__swiz__yzzx()
#define yzzy	__swiz__yzzy()
#define yzzz	__swiz__yzzz()
#define yzzw	__swiz__yzzw()
#define yzwx	__swiz__yzwx()
#define yzwy	__swiz__yzwy()
#define yzwz	__swiz__yzwz()
#define yzww	__swiz__yzww()
#define ywxx	__swiz__ywxx()
#define ywxy	__swiz__ywxy()
#define ywxz	__swiz__ywxz()
#define ywxw	__swiz__ywxw()
#define ywyx	__swiz__ywyx()
#define ywyy	__swiz__ywyy()
#define ywyz	__swiz__ywyz()
#define ywyw	__swiz__ywyw()
#define ywzx	__swiz__ywzx()
#define ywzy	__swiz__ywzy()
#define ywzz	__swiz__ywzz()
#define ywzw	__swiz__ywzw()
#define ywwx	__swiz__ywwx()
#define ywwy	__swiz__ywwy()
#define ywwz	__swiz__ywwz()
#define ywww	__swiz__ywww()
#define zxxx	__swiz__zxxx()
#define zxxy	__swiz__zxxy()
#define zxxz	__swiz__zxxz()
#define zxxw	__swiz__zxxw()
#define zxyx	__swiz__zxyx()
#define zxyy	__swiz__zxyy()
#define zxyz	__swiz__zxyz()
#define zxyw	__swiz__zxyw()
#define zxzx	__swiz__zxzx()
#define zxzy	__swiz__zxzy()
#define zxzz	__swiz__zxzz()
#define zxzw	__swiz__zxzw()
#define zxwx	__swiz__zxwx()
#define zxwy	__swiz__zxwy()
#define zxwz	__swiz__zxwz()
#define zxww	__swiz__zxww()
#define zyxx	__swiz__zyxx()
#define zyxy	__swiz__zyxy()
#define zyxz	__swiz__zyxz()
#define zyxw	__swiz__zyxw()
#define zyyx	__swiz__zyyx()
#define zyyy	__swiz__zyyy()
#define zyyz	__swiz__zyyz()
#define zyyw	__swiz__zyyw()
#define zyzx	__swiz__zyzx()
#define zyzy	__swiz__zyzy()
#define zyzz	__swiz__zyzz()
#define zyzw	__swiz__zyzw()
#define zywx	__swiz__zywx()
#define zywy	__swiz__zywy()
#define zywz	__swiz__zywz()
#define zyww	__swiz__zyww()
#define zzxx	__swiz__zzxx()
#define zzxy	__swiz__zzxy()
#define zzxz	__swiz__zzxz()
#define zzxw	__swiz__zzxw()
#define zzyx	__swiz__zzyx()
#define zzyy	__swiz__zzyy()
#define zzyz	__swiz__zzyz()
#define zzyw	__swiz__zzyw()
#define zzzx	__swiz__zzzx()
#define zzzy	__swiz__zzzy()
#define zzzz	__swiz__zzzz()
#define zzzw	__swiz__zzzw()
#define zzwx	__swiz__zzwx()
#define zzwy	__swiz__zzwy()
#define zzwz	__swiz__zzwz()
#define zzww	__swiz__zzww()
#define zwxx	__swiz__zwxx()
#define zwxy	__swiz__zwxy()
#define zwxz	__swiz__zwxz()
#define zwxw	__swiz__zwxw()
#define zwyx	__swiz__zwyx()
#define zwyy	__swiz__zwyy()
#define zwyz	__swiz__zwyz()
#define zwyw	__swiz__zwyw()
#define zwzx	__swiz__zwzx()
#define zwzy	__swiz__zwzy()
#define zwzz	__swiz__zwzz()
#define zwzw	__swiz__zwzw()
#define zwwx	__swiz__zwwx()
#define zwwy	__swiz__zwwy()
#define zwwz	__swiz__zwwz()
#define zwww	__swiz__zwww()
#define wxxx	__swiz__wxxx()
#define wxxy	__swiz__wxxy()
#define wxxz	__swiz__wxxz()
#define wxxw	__swiz__wxxw()
#define wxyx	__swiz__wxyx()
#define wxyy	__swiz__wxyy()
#define wxyz	__swiz__wxyz()
#define wxyw	__swiz__wxyw()
#define wxzx	__swiz__wxzx()
#define wxzy	__swiz__wxzy()
#define wxzz	__swiz__wxzz()
#define wxzw	__swiz__wxzw()
#define wxwx	__swiz__wxwx()
#define wxwy	__swiz__wxwy()
#define wxwz	__swiz__wxwz()
#define wxww	__swiz__wxww()
#define wyxx	__swiz__wyxx()
#define wyxy	__swiz__wyxy()
#define wyxz	__swiz__wyxz()
#define wyxw	__swiz__wyxw()
#define wyyx	__swiz__wyyx()
#define wyyy	__swiz__wyyy()
#define wyyz	__swiz__wyyz()
#define wyyw	__swiz__wyyw()
#define wyzx	__swiz__wyzx()
#define wyzy	__swiz__wyzy()
#define wyzz	__swiz__wyzz()
#define wyzw	__swiz__wyzw()
#define wywx	__swiz__wywx()
#define wywy	__swiz__wywy()
#define wywz	__swiz__wywz()
#define wyww	__swiz__wyww()
#define wzxx	__swiz__wzxx()
#define wzxy	__swiz__wzxy()
#define wzxz	__swiz__wzxz()
#define wzxw	__swiz__wzxw()
#define wzyx	__swiz__wzyx()
#define wzyy	__swiz__wzyy()
#define wzyz	__swiz__wzyz()
#define wzyw	__swiz__wzyw()
#define wzzx	__swiz__wzzx()
#define wzzy	__swiz__wzzy()
#define wzzz	__swiz__wzzz()
#define wzzw	__swiz__wzzw()
#define wzwx	__swiz__wzwx()
#define wzwy	__swiz__wzwy()
#define wzwz	__swiz__wzwz()
#define wzww	__swiz__wzww()
#define wwxx	__swiz__wwxx()
#define wwxy	__swiz__wwxy()
#define wwxz	__swiz__wwxz()
#define wwxw	__swiz__wwxw()
#define wwyx	__swiz__wwyx()
#define wwyy	__swiz__wwyy()
#define wwyz	__swiz__wwyz()
#define wwyw	__swiz__wwyw()
#define wwzx	__swiz__wwzx()
#define wwzy	__swiz__wwzy()
#define wwzz	__swiz__wwzz()
#define wwzw	__swiz__wwzw()
#define wwwx	__swiz__wwwx()
#define wwwy	__swiz__wwwy()
#define wwwz	__swiz__wwwz()
#define wwww	__swiz__wwww()

#define r		__swiz__x()
#define g		__swiz__y()
#define b		__swiz__z()
#define a		__swiz__w()
#define rr		__swiz__xx()
#define rg		__swiz__xy()
#define rb		__swiz__xz()
#define ra		__swiz__xw()
#define gr		__swiz__yx()
#define gg		__swiz__yy()
#define gb		__swiz__yz()
#define ga		__swiz__yw()
#define br		__swiz__zx()
#define bg		__swiz__zy()
#define bb		__swiz__zz()
#define ba		__swiz__zw()
#define ar		__swiz__wx()
#define ag		__swiz__wy()
#define ab		__swiz__wz()
#define aa		__swiz__ww()
#define rrr		__swiz__xxx()
#define rrg		__swiz__xxy()
#define rrb		__swiz__xxz()
#define rra		__swiz__xxw()
#define rgr		__swiz__xyx()
#define rgg		__swiz__xyy()
#define rgb		__swiz__xyz()
#define rga		__swiz__xyw()
#define rbr		__swiz__xzx()
#define rbg		__swiz__xzy()
#define rbb		__swiz__xzz()
#define rba		__swiz__xzw()
#define rar		__swiz__xwx()
#define rag		__swiz__xwy()
#define rab		__swiz__xwz()
#define raa		__swiz__xww()
#define grr		__swiz__yxx()
#define grg		__swiz__yxy()
#define grb		__swiz__yxz()
#define gra		__swiz__yxw()
#define ggr		__swiz__yyx()
#define ggg		__swiz__yyy()
#define ggb		__swiz__yyz()
#define gga		__swiz__yyw()
#define gbr		__swiz__yzx()
#define gbg		__swiz__yzy()
#define gbb		__swiz__yzz()
#define gba		__swiz__yzw()
#define gar		__swiz__ywx()
#define gag		__swiz__ywy()
#define gab		__swiz__ywz()
#define gaa		__swiz__yww()
#define brr		__swiz__zxx()
#define brg		__swiz__zxy()
#define brb		__swiz__zxz()
#define bra		__swiz__zxw()
#define bgr		__swiz__zyx()
#define bgg		__swiz__zyy()
#define bgb		__swiz__zyz()
#define bga		__swiz__zyw()
#define bbr		__swiz__zzx()
#define bbg		__swiz__zzy()
#define bbb		__swiz__zzz()
#define bba		__swiz__zzw()
#define bar		__swiz__zwx()
#define bag		__swiz__zwy()
#define bab		__swiz__zwz()
#define baa		__swiz__zww()
#define arr		__swiz__wxx()
#define arg		__swiz__wxy()
#define arb		__swiz__wxz()
#define ara		__swiz__wxw()
#define agr		__swiz__wyx()
#define agg		__swiz__wyy()
#define agb		__swiz__wyz()
#define aga		__swiz__wyw()
#define abr		__swiz__wzx()
#define abg		__swiz__wzy()
#define abb		__swiz__wzz()
#define aba		__swiz__wzw()
#define aar		__swiz__wwx()
#define aag		__swiz__wwy()
#define aab		__swiz__wwz()
#define aaa		__swiz__www()
#define rrrr	__swiz__xxxx()
#define rrrg	__swiz__xxxy()
#define rrrb	__swiz__xxxz()
#define rrra	__swiz__xxxw()
#define rrgr	__swiz__xxyx()
#define rrgg	__swiz__xxyy()
#define rrgb	__swiz__xxyz()
#define rrga	__swiz__xxyw()
#define rrbr	__swiz__xxzx()
#define rrbg	__swiz__xxzy()
#define rrbb	__swiz__xxzz()
#define rrba	__swiz__xxzw()
#define rrar	__swiz__xxwx()
#define rrag	__swiz__xxwy()
#define rrab	__swiz__xxwz()
#define rraa	__swiz__xxww()
#define rgrr	__swiz__xyxx()
#define rgrg	__swiz__xyxy()
#define rgrb	__swiz__xyxz()
#define rgra	__swiz__xyxw()
#define rggr	__swiz__xyyx()
#define rggg	__swiz__xyyy()
#define rggb	__swiz__xyyz()
#define rgga	__swiz__xyyw()
#define rgbr	__swiz__xyzx()
#define rgbg	__swiz__xyzy()
#define rgbb	__swiz__xyzz()
#define rgba	__swiz__xyzw()
#define rgar	__swiz__xywx()
#define rgag	__swiz__xywy()
#define rgab	__swiz__xywz()
#define rgaa	__swiz__xyww()
#define rbrr	__swiz__xzxx()
#define rbrg	__swiz__xzxy()
#define rbrb	__swiz__xzxz()
#define rbra	__swiz__xzxw()
#define rbgr	__swiz__xzyx()
#define rbgg	__swiz__xzyy()
#define rbgb	__swiz__xzyz()
#define rbga	__swiz__xzyw()
#define rbbr	__swiz__xzzx()
#define rbbg	__swiz__xzzy()
#define rbbb	__swiz__xzzz()
#define rbba	__swiz__xzzw()
#define rbar	__swiz__xzwx()
#define rbag	__swiz__xzwy()
#define rbab	__swiz__xzwz()
#define rbaa	__swiz__xzww()
#define rarr	__swiz__xwxx()
#define rarg	__swiz__xwxy()
#define rarb	__swiz__xwxz()
#define rara	__swiz__xwxw()
#define ragr	__swiz__xwyx()
#define ragg	__swiz__xwyy()
#define ragb	__swiz__xwyz()
#define raga	__swiz__xwyw()
#define rabr	__swiz__xwzx()
#define rabg	__swiz__xwzy()
#define rabb	__swiz__xwzz()
#define raba	__swiz__xwzw()
#define raar	__swiz__xwwx()
#define raag	__swiz__xwwy()
#define raab	__swiz__xwwz()
#define raaa	__swiz__xwww()
#define grrr	__swiz__yxxx()
#define grrg	__swiz__yxxy()
#define grrb	__swiz__yxxz()
#define grra	__swiz__yxxw()
#define grgr	__swiz__yxyx()
#define grgg	__swiz__yxyy()
#define grgb	__swiz__yxyz()
#define grga	__swiz__yxyw()
#define grbr	__swiz__yxzx()
#define grbg	__swiz__yxzy()
#define grbb	__swiz__yxzz()
#define grba	__swiz__yxzw()
#define grar	__swiz__yxwx()
#define grag	__swiz__yxwy()
#define grab	__swiz__yxwz()
#define graa	__swiz__yxww()
#define ggrr	__swiz__yyxx()
#define ggrg	__swiz__yyxy()
#define ggrb	__swiz__yyxz()
#define ggra	__swiz__yyxw()
#define gggr	__swiz__yyyx()
#define gggg	__swiz__yyyy()
#define gggb	__swiz__yyyz()
#define ggga	__swiz__yyyw()
#define ggbr	__swiz__yyzx()
#define ggbg	__swiz__yyzy()
#define ggbb	__swiz__yyzz()
#define ggba	__swiz__yyzw()
#define ggar	__swiz__yywx()
#define ggag	__swiz__yywy()
#define ggab	__swiz__yywz()
#define ggaa	__swiz__yyww()
#define gbrr	__swiz__yzxx()
#define gbrg	__swiz__yzxy()
#define gbrb	__swiz__yzxz()
#define gbra	__swiz__yzxw()
#define gbgr	__swiz__yzyx()
#define gbgg	__swiz__yzyy()
#define gbgb	__swiz__yzyz()
#define gbga	__swiz__yzyw()
#define gbbr	__swiz__yzzx()
#define gbbg	__swiz__yzzy()
#define gbbb	__swiz__yzzz()
#define gbba	__swiz__yzzw()
#define gbar	__swiz__yzwx()
#define gbag	__swiz__yzwy()
#define gbab	__swiz__yzwz()
#define gbaa	__swiz__yzww()
#define garr	__swiz__ywxx()
#define garg	__swiz__ywxy()
#define garb	__swiz__ywxz()
#define gara	__swiz__ywxw()
#define gagr	__swiz__ywyx()
#define gagg	__swiz__ywyy()
#define gagb	__swiz__ywyz()
#define gaga	__swiz__ywyw()
#define gabr	__swiz__ywzx()
#define gabg	__swiz__ywzy()
#define gabb	__swiz__ywzz()
#define gaba	__swiz__ywzw()
#define gaar	__swiz__ywwx()
#define gaag	__swiz__ywwy()
#define gaab	__swiz__ywwz()
#define gaaa	__swiz__ywww()
#define brrr	__swiz__zxxx()
#define brrg	__swiz__zxxy()
#define brrb	__swiz__zxxz()
#define brra	__swiz__zxxw()
#define brgr	__swiz__zxyx()
#define brgg	__swiz__zxyy()
#define brgb	__swiz__zxyz()
#define brga	__swiz__zxyw()
#define brbr	__swiz__zxzx()
#define brbg	__swiz__zxzy()
#define brbb	__swiz__zxzz()
#define brba	__swiz__zxzw()
#define brar	__swiz__zxwx()
#define brag	__swiz__zxwy()
#define brab	__swiz__zxwz()
#define braa	__swiz__zxww()
#define bgrr	__swiz__zyxx()
#define bgrg	__swiz__zyxy()
#define bgrb	__swiz__zyxz()
#define bgra	__swiz__zyxw()
#define bggr	__swiz__zyyx()
#define bggg	__swiz__zyyy()
#define bggb	__swiz__zyyz()
#define bgga	__swiz__zyyw()
#define bgbr	__swiz__zyzx()
#define bgbg	__swiz__zyzy()
#define bgbb	__swiz__zyzz()
#define bgba	__swiz__zyzw()
#define bgar	__swiz__zywx()
#define bgag	__swiz__zywy()
#define bgab	__swiz__zywz()
#define bgaa	__swiz__zyww()
#define bbrr	__swiz__zzxx()
#define bbrg	__swiz__zzxy()
#define bbrb	__swiz__zzxz()
#define bbra	__swiz__zzxw()
#define bbgr	__swiz__zzyx()
#define bbgg	__swiz__zzyy()
#define bbgb	__swiz__zzyz()
#define bbga	__swiz__zzyw()
#define bbbr	__swiz__zzzx()
#define bbbg	__swiz__zzzy()
#define bbbb	__swiz__zzzz()
#define bbba	__swiz__zzzw()
#define bbar	__swiz__zzwx()
#define bbag	__swiz__zzwy()
#define bbab	__swiz__zzwz()
#define bbaa	__swiz__zzww()
#define barr	__swiz__zwxx()
#define barg	__swiz__zwxy()
#define barb	__swiz__zwxz()
#define bara	__swiz__zwxw()
#define bagr	__swiz__zwyx()
#define bagg	__swiz__zwyy()
#define bagb	__swiz__zwyz()
#define baga	__swiz__zwyw()
#define babr	__swiz__zwzx()
#define babg	__swiz__zwzy()
#define babb	__swiz__zwzz()
#define baba	__swiz__zwzw()
#define baar	__swiz__zwwx()
#define baag	__swiz__zwwy()
#define baab	__swiz__zwwz()
#define baaa	__swiz__zwww()
#define arrr	__swiz__wxxx()
#define arrg	__swiz__wxxy()
#define arrb	__swiz__wxxz()
#define arra	__swiz__wxxw()
#define argr	__swiz__wxyx()
#define argg	__swiz__wxyy()
#define argb	__swiz__wxyz()
#define arga	__swiz__wxyw()
#define arbr	__swiz__wxzx()
#define arbg	__swiz__wxzy()
#define arbb	__swiz__wxzz()
#define arba	__swiz__wxzw()
#define arar	__swiz__wxwx()
#define arag	__swiz__wxwy()
#define arab	__swiz__wxwz()
#define araa	__swiz__wxww()
#define agrr	__swiz__wyxx()
#define agrg	__swiz__wyxy()
#define agrb	__swiz__wyxz()
#define agra	__swiz__wyxw()
#define aggr	__swiz__wyyx()
#define aggg	__swiz__wyyy()
#define aggb	__swiz__wyyz()
#define agga	__swiz__wyyw()
#define agbr	__swiz__wyzx()
#define agbg	__swiz__wyzy()
#define agbb	__swiz__wyzz()
#define agba	__swiz__wyzw()
#define agar	__swiz__wywx()
#define agag	__swiz__wywy()
#define agab	__swiz__wywz()
#define agaa	__swiz__wyww()
#define abrr	__swiz__wzxx()
#define abrg	__swiz__wzxy()
#define abrb	__swiz__wzxz()
#define abra	__swiz__wzxw()
#define abgr	__swiz__wzyx()
#define abgg	__swiz__wzyy()
#define abgb	__swiz__wzyz()
#define abga	__swiz__wzyw()
#define abbr	__swiz__wzzx()
#define abbg	__swiz__wzzy()
#define abbb	__swiz__wzzz()
#define abba	__swiz__wzzw()
#define abar	__swiz__wzwx()
#define abag	__swiz__wzwy()
#define abab	__swiz__wzwz()
#define abaa	__swiz__wzww()
#define aarr	__swiz__wwxx()
#define aarg	__swiz__wwxy()
#define aarb	__swiz__wwxz()
#define aara	__swiz__wwxw()
#define aagr	__swiz__wwyx()
#define aagg	__swiz__wwyy()
#define aagb	__swiz__wwyz()
#define aaga	__swiz__wwyw()
#define aabr	__swiz__wwzx()
#define aabg	__swiz__wwzy()
#define aabb	__swiz__wwzz()
#define aaba	__swiz__wwzw()
#define aaar	__swiz__wwwx()
#define aaag	__swiz__wwwy()
#define aaab	__swiz__wwwz()
#define aaaa	__swiz__wwww()

#define s		__swiz__x()
#define t		__swiz__y()
#define p		__swiz__z()
#define q		__swiz__w()
#define ss		__swiz__xx()
#define st		__swiz__xy()
#define sp		__swiz__xz()
#define sq		__swiz__xw()
#define ts		__swiz__yx()
#define tt		__swiz__yy()
#define tp		__swiz__yz()
#define tq		__swiz__yw()
#define ps		__swiz__zx()
#define pt		__swiz__zy()
#define pp		__swiz__zz()
#define pq		__swiz__zw()
#define qs		__swiz__wx()
#define qt		__swiz__wy()
#define qp		__swiz__wz()
#define qq		__swiz__ww()
#define sss		__swiz__xxx()
#define sst		__swiz__xxy()
#define ssp		__swiz__xxz()
#define ssq		__swiz__xxw()
#define sts		__swiz__xyx()
#define stt		__swiz__xyy()
#define stp		__swiz__xyz()
#define stq		__swiz__xyw()
#define sps		__swiz__xzx()
#define spt		__swiz__xzy()
#define spp		__swiz__xzz()
#define spq		__swiz__xzw()
#define sqs		__swiz__xwx()
#define sqt		__swiz__xwy()
#define sqp		__swiz__xwz()
#define sqq		__swiz__xww()
#define tss		__swiz__yxx()
#define tst		__swiz__yxy()
#define tsp		__swiz__yxz()
#define tsq		__swiz__yxw()
#define tts		__swiz__yyx()
#define ttt		__swiz__yyy()
#define ttp		__swiz__yyz()
#define ttq		__swiz__yyw()
#define tps		__swiz__yzx()
#define tpt		__swiz__yzy()
#define tpp		__swiz__yzz()
#define tpq		__swiz__yzw()
#define tqs		__swiz__ywx()
#define tqt		__swiz__ywy()
#define tqp		__swiz__ywz()
#define tqq		__swiz__yww()
#define pss		__swiz__zxx()
#define pst		__swiz__zxy()
#define psp		__swiz__zxz()
#define psq		__swiz__zxw()
#define pts		__swiz__zyx()
#define ptt		__swiz__zyy()
#define ptp		__swiz__zyz()
#define ptq		__swiz__zyw()
#define pps		__swiz__zzx()
#define ppt		__swiz__zzy()
#define ppp		__swiz__zzz()
#define ppq		__swiz__zzw()
#define pqs		__swiz__zwx()
#define pqt		__swiz__zwy()
#define pqp		__swiz__zwz()
#define pqq		__swiz__zww()
#define qss		__swiz__wxx()
#define qst		__swiz__wxy()
#define qsp		__swiz__wxz()
#define qsq		__swiz__wxw()
#define qts		__swiz__wyx()
#define qtt		__swiz__wyy()
#define qtp		__swiz__wyz()
#define qtq		__swiz__wyw()
#define qps		__swiz__wzx()
#define qpt		__swiz__wzy()
#define qpp		__swiz__wzz()
#define qpq		__swiz__wzw()
#define qqs		__swiz__wwx()
#define qqt		__swiz__wwy()
#define qqp		__swiz__wwz()
#define qqq		__swiz__www()
#define ssss	__swiz__xxxx()
#define ssst	__swiz__xxxy()
#define sssp	__swiz__xxxz()
#define sssq	__swiz__xxxw()
#define ssts	__swiz__xxyx()
#define sstt	__swiz__xxyy()
#define sstp	__swiz__xxyz()
#define sstq	__swiz__xxyw()
#define ssps	__swiz__xxzx()
#define sspt	__swiz__xxzy()
#define sspp	__swiz__xxzz()
#define sspq	__swiz__xxzw()
#define ssqs	__swiz__xxwx()
#define ssqt	__swiz__xxwy()
#define ssqp	__swiz__xxwz()
#define ssqq	__swiz__xxww()
#define stss	__swiz__xyxx()
#define stst	__swiz__xyxy()
#define stsp	__swiz__xyxz()
#define stsq	__swiz__xyxw()
#define stts	__swiz__xyyx()
#define sttt	__swiz__xyyy()
#define sttp	__swiz__xyyz()
#define sttq	__swiz__xyyw()
#define stps	__swiz__xyzx()
#define stpt	__swiz__xyzy()
#define stpp	__swiz__xyzz()
#define stpq	__swiz__xyzw()
#define stqs	__swiz__xywx()
#define stqt	__swiz__xywy()
#define stqp	__swiz__xywz()
#define stqq	__swiz__xyww()
#define spss	__swiz__xzxx()
#define spst	__swiz__xzxy()
#define spsp	__swiz__xzxz()
#define spsq	__swiz__xzxw()
#define spts	__swiz__xzyx()
#define sptt	__swiz__xzyy()
#define sptp	__swiz__xzyz()
#define sptq	__swiz__xzyw()
#define spps	__swiz__xzzx()
#define sppt	__swiz__xzzy()
#define sppp	__swiz__xzzz()
#define sppq	__swiz__xzzw()
#define spqs	__swiz__xzwx()
#define spqt	__swiz__xzwy()
#define spqp	__swiz__xzwz()
#define spqq	__swiz__xzww()
#define sqss	__swiz__xwxx()
#define sqst	__swiz__xwxy()
#define sqsp	__swiz__xwxz()
#define sqsq	__swiz__xwxw()
#define sqts	__swiz__xwyx()
#define sqtt	__swiz__xwyy()
#define sqtp	__swiz__xwyz()
#define sqtq	__swiz__xwyw()
#define sqps	__swiz__xwzx()
#define sqpt	__swiz__xwzy()
#define sqpp	__swiz__xwzz()
#define sqpq	__swiz__xwzw()
#define sqqs	__swiz__xwwx()
#define sqqt	__swiz__xwwy()
#define sqqp	__swiz__xwwz()
#define sqqq	__swiz__xwww()
#define tsss	__swiz__yxxx()
#define tsst	__swiz__yxxy()
#define tssp	__swiz__yxxz()
#define tssq	__swiz__yxxw()
#define tsts	__swiz__yxyx()
#define tstt	__swiz__yxyy()
#define tstp	__swiz__yxyz()
#define tstq	__swiz__yxyw()
#define tsps	__swiz__yxzx()
#define tspt	__swiz__yxzy()
#define tspp	__swiz__yxzz()
#define tspq	__swiz__yxzw()
#define tsqs	__swiz__yxwx()
#define tsqt	__swiz__yxwy()
#define tsqp	__swiz__yxwz()
#define tsqq	__swiz__yxww()
#define ttss	__swiz__yyxx()
#define ttst	__swiz__yyxy()
#define ttsp	__swiz__yyxz()
#define ttsq	__swiz__yyxw()
#define ttts	__swiz__yyyx()
#define tttt	__swiz__yyyy()
#define tttp	__swiz__yyyz()
#define tttq	__swiz__yyyw()
#define ttps	__swiz__yyzx()
#define ttpt	__swiz__yyzy()
#define ttpp	__swiz__yyzz()
#define ttpq	__swiz__yyzw()
#define ttqs	__swiz__yywx()
#define ttqt	__swiz__yywy()
#define ttqp	__swiz__yywz()
#define ttqq	__swiz__yyww()
#define tpss	__swiz__yzxx()
#define tpst	__swiz__yzxy()
#define tpsp	__swiz__yzxz()
#define tpsq	__swiz__yzxw()
#define tpts	__swiz__yzyx()
#define tptt	__swiz__yzyy()
#define tptp	__swiz__yzyz()
#define tptq	__swiz__yzyw()
#define tpps	__swiz__yzzx()
#define tppt	__swiz__yzzy()
#define tppp	__swiz__yzzz()
#define tppq	__swiz__yzzw()
#define tpqs	__swiz__yzwx()
#define tpqt	__swiz__yzwy()
#define tpqp	__swiz__yzwz()
#define tpqq	__swiz__yzww()
#define tqss	__swiz__ywxx()
#define tqst	__swiz__ywxy()
#define tqsp	__swiz__ywxz()
#define tqsq	__swiz__ywxw()
#define tqts	__swiz__ywyx()
#define tqtt	__swiz__ywyy()
#define tqtp	__swiz__ywyz()
#define tqtq	__swiz__ywyw()
#define tqps	__swiz__ywzx()
#define tqpt	__swiz__ywzy()
#define tqpp	__swiz__ywzz()
#define tqpq	__swiz__ywzw()
#define tqqs	__swiz__ywwx()
#define tqqt	__swiz__ywwy()
#define tqqp	__swiz__ywwz()
#define tqqq	__swiz__ywww()
#define psss	__swiz__zxxx()
#define psst	__swiz__zxxy()
#define pssp	__swiz__zxxz()
#define pssq	__swiz__zxxw()
#define psts	__swiz__zxyx()
#define pstt	__swiz__zxyy()
#define pstp	__swiz__zxyz()
#define pstq	__swiz__zxyw()
#define psps	__swiz__zxzx()
#define pspt	__swiz__zxzy()
#define pspp	__swiz__zxzz()
#define pspq	__swiz__zxzw()
#define psqs	__swiz__zxwx()
#define psqt	__swiz__zxwy()
#define psqp	__swiz__zxwz()
#define psqq	__swiz__zxww()
#define ptss	__swiz__zyxx()
#define ptst	__swiz__zyxy()
#define ptsp	__swiz__zyxz()
#define ptsq	__swiz__zyxw()
#define ptts	__swiz__zyyx()
#define pttt	__swiz__zyyy()
#define pttp	__swiz__zyyz()
#define pttq	__swiz__zyyw()
#define ptps	__swiz__zyzx()
#define ptpt	__swiz__zyzy()
#define ptpp	__swiz__zyzz()
#define ptpq	__swiz__zyzw()
#define ptqs	__swiz__zywx()
#define ptqt	__swiz__zywy()
#define ptqp	__swiz__zywz()
#define ptqq	__swiz__zyww()
#define ppss	__swiz__zzxx()
#define ppst	__swiz__zzxy()
#define ppsp	__swiz__zzxz()
#define ppsq	__swiz__zzxw()
#define ppts	__swiz__zzyx()
#define pptt	__swiz__zzyy()
#define pptp	__swiz__zzyz()
#define pptq	__swiz__zzyw()
#define ppps	__swiz__zzzx()
#define pppt	__swiz__zzzy()
#define pppp	__swiz__zzzz()
#define pppq	__swiz__zzzw()
#define ppqs	__swiz__zzwx()
#define ppqt	__swiz__zzwy()
#define ppqp	__swiz__zzwz()
#define ppqq	__swiz__zzww()
#define pqss	__swiz__zwxx()
#define pqst	__swiz__zwxy()
#define pqsp	__swiz__zwxz()
#define pqsq	__swiz__zwxw()
#define pqts	__swiz__zwyx()
#define pqtt	__swiz__zwyy()
#define pqtp	__swiz__zwyz()
#define pqtq	__swiz__zwyw()
#define pqps	__swiz__zwzx()
#define pqpt	__swiz__zwzy()
#define pqpp	__swiz__zwzz()
#define pqpq	__swiz__zwzw()
#define pqqs	__swiz__zwwx()
#define pqqt	__swiz__zwwy()
#define pqqp	__swiz__zwwz()
#define pqqq	__swiz__zwww()
#define qsss	__swiz__wxxx()
#define qsst	__swiz__wxxy()
#define qssp	__swiz__wxxz()
#define qssq	__swiz__wxxw()
#define qsts	__swiz__wxyx()
#define qstt	__swiz__wxyy()
#define qstp	__swiz__wxyz()
#define qstq	__swiz__wxyw()
#define qsps	__swiz__wxzx()
#define qspt	__swiz__wxzy()
#define qspp	__swiz__wxzz()
#define qspq	__swiz__wxzw()
#define qsqs	__swiz__wxwx()
#define qsqt	__swiz__wxwy()
#define qsqp	__swiz__wxwz()
#define qsqq	__swiz__wxww()
#define qtss	__swiz__wyxx()
#define qtst	__swiz__wyxy()
#define qtsp	__swiz__wyxz()
#define qtsq	__swiz__wyxw()
#define qtts	__swiz__wyyx()
#define qttt	__swiz__wyyy()
#define qttp	__swiz__wyyz()
#define qttq	__swiz__wyyw()
#define qtps	__swiz__wyzx()
#define qtpt	__swiz__wyzy()
#define qtpp	__swiz__wyzz()
#define qtpq	__swiz__wyzw()
#define qtqs	__swiz__wywx()
#define qtqt	__swiz__wywy()
#define qtqp	__swiz__wywz()
#define qtqq	__swiz__wyww()
#define qpss	__swiz__wzxx()
#define qpst	__swiz__wzxy()
#define qpsp	__swiz__wzxz()
#define qpsq	__swiz__wzxw()
#define qpts	__swiz__wzyx()
#define qptt	__swiz__wzyy()
#define qptp	__swiz__wzyz()
#define qptq	__swiz__wzyw()
#define qpps	__swiz__wzzx()
#define qppt	__swiz__wzzy()
#define qppp	__swiz__wzzz()
#define qppq	__swiz__wzzw()
#define qpqs	__swiz__wzwx()
#define qpqt	__swiz__wzwy()
#define qpqp	__swiz__wzwz()
#define qpqq	__swiz__wzww()
#define qqss	__swiz__wwxx()
#define qqst	__swiz__wwxy()
#define qqsp	__swiz__wwxz()
#define qqsq	__swiz__wwxw()
#define qqts	__swiz__wwyx()
#define qqtt	__swiz__wwyy()
#define qqtp	__swiz__wwyz()
#define qqtq	__swiz__wwyw()
#define qqps	__swiz__wwzx()
#define qqpt	__swiz__wwzy()
#define qqpp	__swiz__wwzz()
#define qqpq	__swiz__wwzw()
#define qqqs	__swiz__wwwx()
#define qqqt	__swiz__wwwy()
#define qqqp	__swiz__wwwz()
#define qqqq	__swiz__wwww()


//-----------------------------------------------------------------------------

#pragma endregion
// IJK_SWIZZLE_MACRO_IMPL

#endif	// IJK_VECTOR_SWIZZLE
#endif	// __cplusplus


//-----------------------------------------------------------------------------


#endif	// !_IJK_VECTORSWIZZLE_MACRO_H_
#endif	// _IJK_VECTORSWIZZLE_H_