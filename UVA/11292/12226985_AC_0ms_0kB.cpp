#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#ifdef WIN32 
#define AUTO "%I64d"
#else 
#define AUTO "%lld"
#endif
int d[20005],k[20005],m,n;
int main()
{
    while(true)
    {
	scanf("%d%d",&n,&m);
	if(n==0&&m==0) break;
	for(int i=1;i<=n;i++)
	    scanf("%d",&d[i]);
	for(int i=1;i<=m;i++)
	    scanf("%d",&k[i]);
	sort(d+1,d+n+1);
	sort(k+1,k+m+1);
	int st=0,tot=0;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
	    if(st==m) 
	    {
		printf("Loowater is doomed!\n");
		flag=false;
		break;
	    }
	    while(k[++st]<d[i]);
	    tot+=k[st];
	}
	if(flag) printf("%d\n",tot);
    }
    return 0;
}
