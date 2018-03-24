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
using namespace std;

#define MaxN 100001
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

int N,M;
int A[303][303];

int CNT[303];
int vis[303];
void solve()
{
    int ans = INF;
    CLR(vis);
    for(int i=1;i<=M;i++)
    {
        CLR(CNT);
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=M;k++)
            {
                if(vis[A[j][k]]) continue;
                CNT[A[j][k]]++;
                break;
            }
        }
        int mx = 0,loc;
        for(int j=1;j<=M;j++) if(CNT[j]>mx) mx = CNT[j], loc = j;
        ans = min(ans, mx);
        vis[loc] = 1;   
    }
    printf("%d\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &N, &M))
    {
        for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        scanf("%d", &A[i][j]);
        solve();
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
}
