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
int N;
char s1[60],s2[60];
LL dp[60];
void solve()
{
    for(int i=1;i<=N;i++)
    {
        if(i==1)
        {
            if(s1[i]==s2[i])
            {
                dp[1] = 3;
            }
            else
            {
                dp[1] = dp[2] = 6;
                i++;
            }
        }
        else
        {
            if(s1[i]==s2[i])
            {
                if(s1[i-1]==s2[i-1])
                {
                    dp[i] = 2LL*dp[i-1];
                    if(dp[i]>mod) dp[i]%=mod;
                }
                else
                {
                    dp[i] = dp[i-1];
                }
            }
            else
            {
                if(s1[i-1]==s2[i-1])
                {
                    dp[i] = dp[i+1] = 2LL*dp[i-1];
                    if(dp[i]>mod) dp[i]%=mod,dp[i+1]%=mod;
                }
                else
                {
                    dp[i] = dp[i+1] = dp[i-1]*3LL;
                    if(dp[i]>mod) dp[i]%=mod,dp[i+1]%=mod;
                }
                i++;
            }
        }
        
        // debug(i)
        // debug(dp[i])
    }
    LL ans = dp[N]%mod;
    out(ans);puts("");
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        scanf("%s%s", s1+1, s2+1);
        solve();
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
