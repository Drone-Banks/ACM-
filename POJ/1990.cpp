/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 20001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

struct Node
{
    int val, pos;
    bool operator < (const Node &a )const  
    {
        return val < a.val;
    }
}node[MaxN];
struct BIT{
	int n;
	int tree[MaxN];
	void init( int n ){
		this->n = n ;
		CLR(tree);
	}
	
	int lowbit( int x ){
		return x & ( -x );
	}
	
	int sum( int n ){
		int ans = 0;
		for( int i = n; i ; i -= lowbit(i) ){
			ans = ( ans + tree[i] ) % mod ;
		}
		return ans;
	}
	
	void update( int x, int val ){
		for( int i = x; i <= n; i += lowbit( i ) ){
			tree[i] = ( tree[i] + val ) % mod ;
		}
	}
}num,dis;
int N,a,b;
void solve()
{
    LL ans = 0;
    num.init(20000);
    dis.init(20000);
    for(int i=1;i<=N;i++)
    {
        int a = num.sum(node[i].pos), b = i-1-a;
        int dis_1 = dis.sum(node[i].pos), dis_2 = dis.sum(20000) - dis_1;
        //debug(a) debug(dis_1) debug(b) debug(dis_2)
        ans += (LL)node[i].val*((LL)a*node[i].pos-dis_1 + dis_2-(LL)b*node[i].pos);
        num.update(node[i].pos, 1);
        dis.update(node[i].pos, node[i].pos);
        //debug(ans);
    }
    cout << ans << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> N)
    {
        for(int i=1;i<=N;i++)
        {
            cin >> node[i].val >> node[i].pos;
        }
        sort(node+1, node+1+N);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}
