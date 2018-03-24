/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,n,b) memset(a,b,n*sizeof(a))
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

struct Edge
{
    int u, v, next;
    Edge(){}
    Edge(int u, int v, int n):u(u),v(v),next(n){}
}edge[MaxM];
int cont, head[MaxN];
void add(int u, int v)
{
    edge[cont] = Edge(u,v,head[u]); head[u] = cont++;
    edge[cont] = Edge(v,u,head[v]); head[v] = cont++;
}
void init(int n)
{
    cont = 0; MST(head,n+1,-1);
}

double DFS(int u, int fa, int d)
{
    double sum = 0;int sz=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==fa) continue;
        sum += DFS(v, u,d+1);
        sz++;
    }
    if(sz==0) return d;
    else return sum/(1.0*sz);
}   
void solve()
{
    double ans = DFS(1,1,0);
	debug(ans);
    printf("%.15f\n", ans);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    int n,u,v;
    read(n);
    init(n);
    for(int i=1;i<n;i++) read(u), read(v), add(u,v);  
    solve();   
    system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
