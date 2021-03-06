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

#define MaxN 1000001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {
	return ((a > b)? a : b);
}
inline int min2(int a, int b) {
	return ((a < b)? a : b);
}
inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}
inline int min3(int a, int b, int c) {
	return min2(a, min2(b, c));
}
int n;
int P[MaxN];

void solve()
{
    bit.init(n);
    for(int i=1;i<=n;i++)
    {
        if(i==P[i]) bit.update(1,1), bit.update(n,-1);
		else if(i<P[i]) 
		{
			bit.update(1,-1), bit.update(P[i]-i+1,1);
			bit.update(P[i]-i+1,1), bit.update(n-i+1,-1);
			bit.update(n-i+1,-1), bit.update(n,1);
		}
		else
		{
			bit.update(1,1), bit.update(n-i+1,-1);
			bit.update(n-i+1,-1), bit.update(n-i+P[i],1);
			bit.update(n-i+P[i],1), bit.update(n,-1);
		}
    }
	int ans = 0;
	for(int i=1;i<=n;i++) ans+=(P[i]-i);
	int loc,mn = INF;
    for(int i=1;i<=n;i++)
    {
		int x = bit.sum(i);
		if( x< mn)
		{
			mn = x, loc = i;
		}
    }
	if(mn>0) loc = 0;
	else ans+=mn;
	printf("%d %d\n", ans, loc);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++) scanf("%d", P+i);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}
