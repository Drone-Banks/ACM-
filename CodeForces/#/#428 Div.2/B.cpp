/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back
using namespace std;

#define MaxN 100005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int a[110];
int main()
{
    //std::ios::sync_with_stdio(false);
    int n,k;
    read(n);read(k);
    int two = n*2, four = n, one = 0, res = 0;
    for(int i=1;i<=k;i++) 
    {
        read(a[i]);
        if(a[i]>=4 && four)
        {
            int cost = min(a[i]/4,four);
            four -= cost;
            a[i] = a[i]-cost*4;
        }
        if(a[i]>=2 && two)
        {
            int cost = min(a[i]/2, two);
            two -= cost;
            a[i] = a[i]-cost*2;
        }
        if(a[i]>=2 && four)
        {
            int cost = min(a[i]/2, four);
            four -= cost;
            a[i] = a[i]-cost*2;
            one += cost;
        }
        res += a[i];
    }
    one += (two+four*2);
    if(one>=res) puts("YES");
    else puts("NO");
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}