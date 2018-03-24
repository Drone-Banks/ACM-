/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
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

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

int T;
int N,M;
int S, E;

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


int main()
{
    cin >> T;
    while(T--)
    {
        init();
        scanf("%d%d", &N, &M);
        int S = 0;
        int E = N+M+1;

        for(int i=1;i<=M;i++)
        {
            int x;
            scanf("%d", &x);
            Add(N+i, E, x);
        }

        for(int i=1;i<=N;i++) 
        {
            int a;
            int b;
            scanf("%d%d", &a, &b);
            Add(S, i, a);
            while(b--)
            {
                int x;
                scanf("%d", &x);
                Add(i, N+x, 1);
            }
        }   
        ISAP(S, E, N+M+2);
        int flag = 0;
        for(int i=0;i<M;i++)
        {
            if(edge[i*2].flow )
            {
                flag = 1;
                break;
            }
        }
        if(flag) cout << "No\n";
        else cout << "Yes\n";
    }
    system("pause");
}