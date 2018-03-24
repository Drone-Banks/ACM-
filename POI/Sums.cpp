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

#define MaxN 5005
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

int n,A[MaxN],q,B;
//不能处理负权图

typedef pair<int,int> pii;   //S集合，first保存到源点距离，second保存点序号。

struct cmp
{                        //将优先队列改为小根堆
    bool operator()(pii a,pii b)
    {
        return a.first>b.first;
    }
};
int vis[MaxM];
int dis[MaxM];   //存储起点到每一个点的最短路

int Dijkstra()
{
    CLR(vis);
    for(int i=0;i<A[0];i++) dis[i] = INF;
    dis[0] = 0;
    priority_queue<pii,vector<pii>,cmp> q;
    q.push(mp(dis[0],0));
    while(!q.empty())
    {
        pii tmp = q.top();
        q.pop();
        int u = tmp.second,d = tmp.first;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i=1;i<n;i++)
        {
            int v = (d+A[i])%A[0];
            if( dis[v] > d+A[i] )
            {
                dis[v] = d+A[i];
                q.push(mp(dis[v],v));
            }
        }
    }
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;i++) scanf("%d", &A[i]);
        Dijkstra();
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d", &B);
            if( dis[B%A[0]] <= B ) puts("TAK");
            else puts("NIE");
        }
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
