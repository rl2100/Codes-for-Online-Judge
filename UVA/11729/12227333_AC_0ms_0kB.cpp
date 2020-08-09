#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#ifdef WIN32
#define AUTO "%I64d"
#else
#define AUTO "%lld"
#endif
struct job{
    int b,d;
    bool operator < (const job &x)const {
	return d>x.d;
    }
}w[1005];
int n,T;
int main()
{
    while(true)
    {
	T++;
	scanf("%d",&n);
	if(n==0)break;
	int ans=-1;
	int tmp=0;
	for(int i=1;i<=n;i++)
	    scanf("%d%d",&w[i].b,&w[i].d);
	sort(w+1,w+1+n);
	for(int i=1;i<=n;i++)
	{
	    tmp+=w[i].b;
	    ans=max(ans,tmp+w[i].d);
	}
	printf("Case %d: %d\n",T,ans);
    }
    return 0;
}
