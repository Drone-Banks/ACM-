/*************************************************************************
	> File Name: 1637.cpp
	> Author: Akira 
	> Mail: qaq.febr2.qaq@gmail.com 
	> Created Time: 2016年10月05日 星期三 14时44分24秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 233
#define MaxM MaxN*20
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int T;
int N,M;

struct Edge{
    int u,v,next;
    int flow;
}edge[MaxM];   //最大边数，一般都是实际边数的2倍甚至以上

int head[MaxN];
int cont;

void init(){        //记得init
    cont = 0;
    MST(head, -1);

}

void add(int u, int v, int flow){
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].flow = flow;
    edge[cont].next = head[u];
    head[u] = cont++;
}

void Add(int u, int v, int flow){    //建正反两条边，反向流量为0
    add(u, v, flow);
    add(v, u, 0);
}

int dis[MaxN];
int num[MaxN];
int cur[MaxN];
int pre[MaxN];

void BFS(int source,int sink)
{
    queue<int>q;
    CLR(num);
    MST(dis,-1);

    q.push(sink);
    dis[sink]=0;
    num[0]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                num[dis[v]]++;
                q.push(v);
            }
        }
    }
}

int ISAP(int source,int sink,int n)      //从源点到汇点，n为总点数，返回最大流
{
    memcpy(cur,head,sizeof(cur));
    int flow=0, u = pre[source] = source;
    BFS( source,sink);
    while( dis[source] < n )
    {
        if(u == sink)
        {
            int df = INF, pos;
            for(int i =source;i != sink;i = edge[cur[i]].v)
            {
                if(df > edge[cur[i]].flow)
                {
                    df = edge[cur[i]].flow;
                    pos = i;
                }
            }
            for(int i = source;i != sink;i = edge[cur[i]].v)
            {
                edge[cur[i]].flow -= df;
                edge[cur[i]^1].flow += df;
            }
            flow += df;
            //cout << flow << endl;
            u = pos;
        }
        int st;
        for(st = cur[u];st != -1;st = edge[st].next)
        {
            if(dis[edge[st].v] + 1 == dis[u] && edge[st].flow)
            {
                break;
            }
        }
        if(st != -1)
        {
            cur[u] = st;
            pre[edge[st].v] = u;
            u = edge[st].v;
        }
        else
        {
            if( (--num[dis[u]])==0 ) break;
            int mind = n;
            for(int id = head[u];id != -1;id = edge[id].next)
            {
                if(mind > dis[edge[id].v] && edge[id].flow != 0)
                {
                    cur[u] = id;
                    mind = dis[edge[id].v];
                }
            }
            dis[u] = mind+1;
            num[dis[u]]++;
            if(u!=source)
            u = pre[u];
        }
    }
    return flow;
}

int in[MaxN], out[MaxN];
int mp[MaxN][MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        init();
        CLR(in);
        CLR(out);
        CLR(mp);

        scanf("%d%d", &N, &M);
        int a,b,d;
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d", &a, &b, &d);
            out[a]++;
            in[b]++;
            if(!d) mp[a][b]++;
        }
        int flow = 0;
        int flag = 0;
        for(int i=1;i<=N;i++)
        {
            if( in[i] > out[i] ) flow += (in[i] - out[i]) >> 1;
            if( abs(out[i]-in[i])&1 )
            {
                flag = 1;
                break;
            }
        }

        if(flag)
        {
            cout << "impossible\n";
            continue;
        }
        else
        {
            int S = 0;
            int T = N+1;
            for(int i=1;i<=N;i++)
            {
                if( out[i] > in[i] ) Add(i, T, (out[i]-in[i])/2 );
                if( in[i] > out[i] ) Add(S, i, (in[i]-out[i])/2 );
                for(int j=1;j<=N;j++)
                {
                    if(mp[i][j]) Add(j, i, mp[i][j]);
                }
            }
            if(ISAP(S,T,N+2) == flow ) cout << "possible\n";
            else cout << "impossible\n";
        }
    }
}
