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

#define MaxN 500005
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
int mu[MaxN],prime[MaxN],num[MaxN],sum[MaxN][22];
bool not_prime[MaxN];

void Mobius()
{
    int tot = 0;
    mu[1] = 1;
    for(int i=2;i<=5E5;i++)
    {
        if(!not_prime[i])
        {
            prime[++tot] = i;
            mu[i] = -1;
            num[i] = 1;
        }
        for(int j=1;prime[j]*i<=5E5;j++)
        {
            num[i*prime[j]] = num[i]+1;
            not_prime[i*prime[j]] = 1;
            if(i%prime[j] == 0)
            {
                mu[prime[j]*i] = 0;
                break;
            }
            mu[prime[j]*i] = -mu[i];
        }
    }
    // deal with the factor
    for(int i=1;i<=5E5;i++)
    {
        for(int j=1;j*i<=5E5;j++)
        {
            sum[j*i][num[i]] += mu[j];
        }
    }
    for(int i=1;i<=5E5;i++)
    {
        sum[i][0] += sum[i-1][0];
        for(int j=1;j<=19;j++)
        {
            sum[i][j]  += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    }
}

LL cal(int n, int m, int P)
{
    P = min(P, 19);
    if(n>m) swap(n,m);
    LL ans = 0;
    for(int i=1,last=1;i<=n;i=last+1)
    {
        last = min( n/(n/i), m/(m/i));
        ans += 1LL * (sum[last][P] - sum[i-1][P]) * (n/i) *(m/i);
    }
    return ans;
}
int main()
{
    Mobius();
    int T,n,m,P;
    read(T);
    while(T--)
    {
        read(n);read(m);read(P);
        if(P>=20) 
        {
            LL ans = (LL)n*m;
            out(ans);puts("");
        }
        else 
        {
            LL ans = cal(n, m, P);
            out(ans);puts("");            
        }
    }
}
