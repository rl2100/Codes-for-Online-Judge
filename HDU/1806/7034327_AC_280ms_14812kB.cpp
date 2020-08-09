#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<set>
#include<list>
#include<vector>
using namespace std;
int bl[100005],r[100005],l[100005],part,counti[100005],val[100005],ql,qr,n,q,mul[100005][30],a[100005];
void Query(int le,int ri)
{
	int maxl=0;
	if(bl[le]+1<=bl[ri]-1)
	{
	int k=0;
	while((1<<(k+1))<=bl[ri]-1-bl[le])
	{
		k++;
	}
	maxl=max(mul[bl[le]+1][k],mul[bl[ri]-1-(1<<k)+1][k]);
	/*k--;
	int to=bl[le]+1;
	while(to!=bl[ri])
	{
		if((to+(1<<k))<=bl[ri])
		{
			maxl=max(maxl,mul[to][k]);
			to+=(1<<k);
		}
		else k--;
	}*/
	}
	maxl=max(maxl,r[bl[le]]-le+1);
	maxl=max(maxl,ri-l[bl[ri]]+1);
	printf("%d\n",maxl);
	return ;
}
int main()
{
	
	while(scanf("%d",&n)&&n)
	{
	scanf("%d",&q);
	int part=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=a[i-1])
		{
			r[part]=i-1;
			part++;
			bl[i]=part;
			val[part]=a[i];
			counti[part]=1;
			l[part]=i;
		}
		else
		{
			counti[part]++;
			bl[i]=part;
		}
	}
	r[part]=n;
	l[1]=1;
	for(int i=1;i<=part;i++)
		mul[i][0]=counti[i];
	for(int i=1;(1<<i)<=part;i++)
	{
		for(int j=1;j+(1<<(i-1))<=n;j++)
		mul[j][i]=max(mul[j][i-1],mul[j+(1<<(i-1))][i-1]);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&ql,&qr);
		if(bl[ql]==bl[qr])
			printf("%d\n",qr-ql+1);
		else Query(ql,qr);
	}
	
	}
	getchar();
	getchar();
	return 0;
}
