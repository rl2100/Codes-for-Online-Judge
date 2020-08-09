#include<iostream>
#include<cstdio>
#include<cstring>
#define l(u) u*2
#define r(u) u*2+1
using namespace std;
struct Node{
	int r,l;
	long long add,sum;
}a[400006];
long long v[100005],c;
int m,n;
void pushup(int u)
{
	a[u].sum=a[r(u)].sum+a[l(u)].sum;
	return;
}
void pushdown(int u)
{
	a[l(u)].add+=a[u].add;
	a[l(u)].sum+=(a[l(u)].r-a[l(u)].l+1)*a[u].add;
	a[r(u)].add+=a[u].add;
	a[r(u)].sum+=(a[r(u)].r-a[r(u)].l+1)*a[u].add;
	a[u].add=0;
	return;
}
void build(int u,int le,int ri)
{
	a[u].l=le;
	a[u].r=ri;
	a[u].add=0;
	if(le==ri)
	{
		a[u].sum=v[le];
		return;
	}
	int mid=(le+ri)/2;
	build(l(u),le,mid);
	build(r(u),mid+1,ri);
	pushup(u);
	return;
}
void update(int u,int le,int ri,long long val)
{
	if(le<=a[u].l&&ri>=a[u].r)
	{
		a[u].add+=val;
		a[u].sum+=val*(a[u].r-a[u].l+1);
		return;
	}
	a[u].sum+=val*(ri-le+1);//mis
	int mid=(a[u].l+a[u].r)/2;
	if(mid>=ri)
	update(l(u),le,ri,val);
	else if(mid<le)
	update(r(u),le,ri,val);
	else
	{
		update(l(u),le,mid,val);//
		update(r(u),mid+1,ri,val);//
	}
}
long long qu(int u,int le,int ri)
{
	if(le==a[u].l&&ri==a[u].r)
	{
		return a[u].sum;
	}
	if(a[u].add)pushdown(u);//get 
	int mid=(a[u].l+a[u].r)/2;
	if(ri<=mid)
	{
		return qu(l(u),le,ri);//
	}
	else if(le>mid)
	{
		return qu(r(u),le,ri);
	}
	else{
		return qu(l(u),le,mid)+qu(r(u),mid+1,ri);
	}
}
int main()
{
	cin>>n>>m;
	int e,b;
	char d;
	for(int i=1;i<=n;i++)
	scanf("%lld",&v[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
	cin>>d;
	if(d=='Q')
		{
			scanf("%d%d",&e,&b);
			cout<<qu(1,e,b)<<endl;
		}
		else 
		{
			scanf("%d %d %lld",&e,&b,&c);
			update(1,e,b,c);
		}
	}
	
	}