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
#define ps push_back
using namespace std;

#define MaxN 110
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

int n,w;
struct Node
{
    int id, val, ans;
}node[MaxN];
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &w))
    {
        for(int i=1;i<=n;i++) scanf("%d", &node[i].val), node[i].ans = 0, node[i].id = i;
        sort(node+1, node+1+n, [](Node a, Node b){return a.val<b.val;});

        bool flag = false;
        for(int i=1;i<=n;i++)
        {
            node[i].ans = (node[i].val+1)/2;
            w -= node[i].ans;
            if(w<0)
            {
                flag = true;
                break;
            }
        }
        if(flag) puts("-1");
        else
        {
            for(int i=n;i>=1;i--)
            {
                int add = min(w, node[i].val-node[i].ans);
                w -= add;
                node[i].ans += add;
                if(w==0) break;
            }
            sort(node+1, node+1+n, [](Node a, Node b){return a.id<b.id;});
            for(int i=1;i<=n;i++) printf("%d%c", node[i].ans, i==n?'\n':' ');
        }
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
