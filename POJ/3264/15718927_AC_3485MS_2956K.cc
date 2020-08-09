#include<iostream>
#include<cstdio>
#include<cstring>
#define l(u) u*2
#define r(u) u*2+1
using namespace std;
struct node{
	int l,r;
	int maxl,minl;
}a[200040];
int m,n,h[2000005],e,b;
struct maxmi{
	int maxl;
	int minl;
};
void build(int u,int le,int ri)
{
	a[u].l=le;
	a[u].r=ri;
	a[u].maxl=0;
	a[u].minl=100000;
	if(le==ri)
	{
		a[u].maxl=a[u].minl=h[le];
		return;
	}
	int mid=(le+ri)/2;
	build(l(u),le,mid);
	build(r(u),mid+1,ri);
	a[u].minl=min(a[l(u)].minl,a[r(u)].minl);
	a[u].maxl=max(a[l(u)].maxl,a[r(u)].maxl);
	return;
}
maxmi qu(int u,int le,int ri)
{
	if(a[u].r==ri&&a[u].l==le)
	{
		maxmi k;
		k.maxl=a[u].maxl;
		k.minl=a[u].minl;
		return k;
	}
	int mid=(a[u].r+a[u].l)/2;
	if(ri<=mid)
	return qu(l(u),le,ri);	
	else if(le>mid)
	return qu(r(u),le,ri);
	else
	{
		maxmi k1,k2;
		k1=qu(l(u),le,mid);
		k2=qu(r(u),mid+1,ri);
		k1.maxl=max(k1.maxl,k2.maxl);
		k1.minl=min(k1.minl,k2.minl);
		return k1;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&e,&b);
		maxmi q=qu(1,e,b);
		printf("%d\n",q.maxl-q.minl); 
	}
}