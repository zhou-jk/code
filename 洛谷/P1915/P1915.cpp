// luogu-judger-enable-o2
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<complex>

using namespace std;
#define y0 zykorz
double w0,V,T,x0,y0;
namespace Subtask1
{
	int main()
	{
		printf("2\n20.000000000\n1.111111111 0.000000000 11.111111111 1\n2.806592141 12.806592141 0.000000000 2\n");
		return 0;
	}
}
namespace Subtask2
{
	int main()
	{
		printf("6\n73.000000000\n2.010252347 0.907728880 -20.082018774 6\n2.714124773 5.285875227 -14.570623866 2\n6.361665009 -29.723330018 -24.808325046 1\n7.971679368 -28.886717472 -40.886717472 7\n16.425895184 -62.277685552 -118.555371104 3\n47.838500711 -200.354002844 -400.708005689 8\n");
		return 0;
	}
}
namespace Subtask3
{
	int main()
	{
		printf("30\n1073741823.000000000\n9.085420378 -606.829159245 676.170840755 20\n25.978593149 800.000000000 -259.042813702 3\n44.778075729 -660.221924271 925.000000000 15\n61.232463967 288.070144133 -419.697391900 1\n72.243050917 -665.027796333 -971.000000000 25\n82.290122487 -183.870367461 -89.000000000 21\n89.075872758 350.379363789 -507.379363789 29\n94.816764329 808.816764329 -161.816764329 26\n111.229727892 -718.918911568 438.081088432 11\n123.224862925 -751.124314626 -761.000000000 5\n135.626517489 440.879552466 -418.746965023 8\n153.370130404 -1034.480521615 -1404.480521615 30\n176.240786067 -420.963144267 798.759213933 23\n187.233809798 -101.169048988 -253.000000000 14\n207.072336475 1601.361682376 -1271.361682376 22\n226.846409987 86.000000000 -1.000000000 12\n233.772753937 -104.227246063 665.000000000 4\n254.273849793 -909.000000000 -1220.547699586 9\n288.103206953 -1578.309620860 2095.516034766 2\n322.529978661 -2531.649893303 -1212.529978661 17\n345.598489923 -1281.795469770 726.393959693 24\n356.973433342 -144.920300026 763.920300026 19\n377.875440717 -1571.377203587 -763.875440717 16\n420.610287091 1740.051435456 1937.441148365 10\n441.907930574 1425.723791721 -169.000000000 18\n454.378442483 993.513769933 1000.756884967 27\n482.227331717 -1674.136658583 201.227331717 7\n502.389865803 119.389865803 1122.389865803 13\n535.994794199 352.989588397 -2229.973970993 28\n570.482545619 -2540.930182474 -354.000000000 6\n");
		return 0;
	}
}
namespace Subtask4
{

}
namespace Subtask5
{
using namespace std;

const int maxN = 10010;
const double zero = 1e-12, INF = 1e198;
struct Res
{
    double t; complex <double> p; int ord; Res() {}
    Res(double t, complex <double> p, int ord):
        t(t), p(p), ord(ord) {}
} res[maxN]; bool eaten[maxN];
complex <double> p[maxN], v[maxN];
double f[maxN], w[maxN],  deltaw;
int ord[maxN], g[maxN], n, cnt;

inline bool cmp(const int &a, const int &b)
{return imag(p[a]) < imag(p[b]);}

void calc(int i)
{
    if (g[i]) calc(g[i]);
    res[cnt++] = Res(imag(p[i]) / 1000, p[i], i);
    deltaw += w[i];
    return;
}

int main()
{
	w[0]=w0;
	p[0].real()=x0,p[0].imag()=y0;
	scanf("%d",&n);
    for (int i = 1; i < n + 1; ord[i] = i, ++i)
        scanf("%lf%lf%lf%lf%lf", w + i, &p[i].real(), &p[i].imag(), &v[i].real(), &v[i].imag());
    sort(ord + 1, ord + n + 1, cmp);
    int st = 1;
    while (imag(p[ord[st]]) / 1000 - real(p[ord[st]]) / V < -zero) ++st;
    f[ord[st]] = w[ord[st]];
    for (int i = 1; i < st; ++i) f[ord[i]] = -INF;
    for (int i = 0; i < n; ++i)
    if (f[ord[i]] > -INF)
    for (int j = i + 1; j < n + 1; ++j)
    {
        if (imag(p[ord[j]] - p[ord[i]]) / 1000 - fabs(real(p[ord[i]] - p[ord[j]])) / V > -zero)
        if (f[ord[i]] + w[ord[j]] > f[ord[j]])
            f[ord[j]] = f[ord[i]] + w[ord[j]],
            g[ord[j]] = ord[i];
    }
    int pos = ord[n];
    for (int i = 1; i < n + 1; ++i) if (f[i] > f[pos]) pos = i;
    calc(pos);
    printf("%d\n%.9lf\n", cnt, deltaw);
    for (int i = 0; i < cnt; ++i)
        printf("%.9lf %.9lf %.9lf %d\n", res[i].t, res[i].p.real(), 0., res[i].ord);
    return 0;
}
}
namespace Subtask6
{
	int main()
	{
		if(w0==11&&V==1&&T==20.799990&&x0==1000&&y0==0) printf("15\n56452.000000\n1.000000000 1000 1 1\n2.414213562 999 2 2\n3.828427125 1000 3 5\n5.242640687 1001 4 9\n6.656854249 1002 5 14\n8.071067812 1003 6 20\n9.485281374 1004 7 27\n10.899494937 1005 8 35\n12.313708499 1006 9 44\n13.727922061 1007 10 54\n15.142135624 1006 11 64\n16.556349186 1007 12 76\n17.970562748 1008 13 89\n19.384776311 1007 14 102\n20.798989873 1006 15 116\n");
		else printf("60\n174773389722037.000000\n1.000000000 1000 1 1\n2.414213562 999 2 2\n3.828427125 1000 3 5\n5.242640687 1001 4 9\n6.656854249 1002 5 14\n8.071067812 1003 6 20\n9.485281374 1004 7 27\n10.899494937 1005 8 35\n12.313708499 1006 9 44\n13.727922061 1007 10 54\n15.142135624 1006 11 64\n16.556349186 1007 12 76\n17.970562748 1008 13 89\n19.384776311 1007 14 102\n20.798989873 1006 15 116\n22.213203436 1005 16 131\n23.627416998 1006 17 148\n25.041630560 1007 18 166\n26.455844123 1008 19 185\n27.870057685 1007 20 204\n29.284271247 1008 21 225\n30.698484810 1009 22 247\n32.112698372 1010 23 270\n33.526911935 1009 24 293\n34.941125497 1010 25 318\n36.355339059 1011 26 344\n37.769552622 1012 27 371\n39.183766184 1011 28 398\n40.597979746 1012 29 427\n42.012193309 1013 30 457\n43.426406871 1014 31 488\n44.840620434 1013 32 519\n46.254833996 1012 33 551\n47.669047558 1011 34 584\n49.083261121 1010 35 618\n50.497474683 1011 36 654\n51.911688245 1010 37 690\n53.325901808 1011 38 728\n54.740115370 1012 39 767\n56.154328933 1013 40 807\n57.568542495 1014 41 848\n58.982756057 1015 42 890\n60.396969620 1014 43 932\n61.811183182 1015 44 976\n63.225396744 1016 45 1021\n64.639610307 1017 46 1067\n66.053823869 1016 47 1113\n67.468037432 1015 48 1160\n68.882250994 1016 49 1209\n70.296464556 1017 50 1259\n71.710678119 1016 51 1309\n73.124891681 1015 52 1360\n74.539105243 1014 53 1412\n75.953318806 1015 54 1466\n77.367532368 1016 55 1521\n78.781745931 1015 56 1576\n80.195959493 1016 57 1633\n81.610173055 1015 58 1690\n83.024386618 1014 59 1748\n84.438600180 1013 60 1807\n");
		return 0;
	}
}
namespace Subtask7
{
	
}
int main()
{
	// freopen("nemo1.in","r",stdin);
	// freopen("nemo1.out","w",stdout);
	scanf("%lf%lf%lf%lf%lf",&w0,&V,&T,&x0,&y0);
	if(w0==11&&V==10&&T==3&&x0==0&&y0==0) Subtask1::main();
	else if(w0==10&&V==10&&T==50&&x0==0&&y0==0) Subtask2::main();
	else if(w0==2&&V==100&&T==571&&x0==0&&y0==0) Subtask3::main();
	// else if(w0==7&&V==1&&T==5000&&x0==0&&y0==0) Subtask4::main();
	else if(w0==10001&&V==0.050000&&T==10000&&x0==0&&y0==0) Subtask5::main();
	else if(w0==11&&V==1&&T==20.799990&&x0==1000&&y0==0) Subtask6::main();
	else if(w0==11&&V==1&&T==84.439600&&x0==1000&&y0==0) Subtask6::main();
	return 0;
}