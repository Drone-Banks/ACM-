/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

//#pragma comment(linker, "/STACK:102400000,102400000")
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
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

char str[202];
int vis[26];
inline bool check(char ch)
{
    if( ch >= 'a' && ch <= 'z') return true;
    else return false;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int n;
    while(~scanf("%d", &n))    
    {
        scanf("%s", str);
        int ans = 0;
        int tmp = 0;
        for(int i=0;i<n;i++)
        {
            if(!check(str[i]))
            {
                ans = max(ans, tmp);
                tmp = 0;CLR(vis);
            }
            else
            {
                int v = str[i]-'a';
                if(!vis[v]) vis[v] = 1, tmp++;
            }
        }
        ans = max(ans, tmp);
        printf("%d\n", ans);
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
