#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define L(u) u<<1
#define R(u) (u<<1)+1
#define maxn 1000005
struct nod{
	int l,r;
}tre[25][maxn*4];
struct ans{
	int s,ma,mi;
	ans operator +(const ans &a)const{
		ans b;
		b.s=s+a.s;
		b.ma=max(a.ma,ma);
		b.mi=min(a.mi,mi);
		return b;
	}
}vo;
int maxl[25][maxn],sum[25][maxn],minl[25][maxn],se[25][maxn],ad[25][maxn],op,x1,x2,y1,y2,c,r,m;//mem se -1
const int inf=1000000000;
void pushdown(int u,int row)
{
	if(se[row][u]!=-1)
	{
		sum[row][L(u)]=(tre[row][L(u)].r-tre[row][L(u)].l+1)*se[row][u];
		minl[row][L(u)]=se[row][u];
		maxl[row][L(u)]=se[row][u];
		se[row][L(u)]=se[row][u];
		sum[row][R(u)]=(tre[row][R(u)].r-tre[row][R(u)].l+1)*se[row][u];
		minl[row][R(u)]=se[row][u];
		maxl[row][R(u)]=se[row][u];
		se[row][R(u)]=se[row][u];
		se[row][u]=-1;
		ad[row][L(u)]=ad[row][R(u)]=0;
	}
	if(ad[row][u])
	{
		sum[row][L(u)]+=(tre[row][L(u)].r-tre[row][L(u)].l+1)*ad[row][u];
		minl[row][L(u)]+=ad[row][u];
		maxl[row][L(u)]+=ad[row][u];
		ad[row][L(u)]+=ad[row][u];
		sum[row][R(u)]+=(tre[row][R(u)].r-tre[row][R(u)].l+1)*ad[row][u];
		minl[row][R(u)]+=ad[row][u];
		maxl[row][R(u)]+=ad[row][u];
		ad[row][R(u)]+=ad[row][u];
		ad[row][u]=0;		
	}
}
void build(int u,int le,int ri,int row)
{
	tre[row][u].l=le;
	tre[row][u].r=ri;
	sum[row][u]=minl[row][u]=maxl[row][u]=0;
	if(le==ri)
	{
		return;
	}
	int mid=(le+ri)/2;
	build(L(u),le,mid,row);
	build(R(u),mid+1,ri,row);
}
void update(int u,int le,int ri,int val,int row)
{
	if(tre[row][u].l>=le&&tre[row][u].r<=ri)
	{
		if(op==1)
		{
			sum[row][u]+=(tre[row][u].r-tre[row][u].l+1)*val;
			maxl[row][u]+=val;
			minl[row][u]+=val;
			ad[row][u]+=val;
		}
		else
		{
			sum[row][u]=(tre[row][u].r-tre[row][u].l+1)*val;
			maxl[row][u]=val;
			minl[row][u]=val;
			se[row][u]=val;
			ad[row][u]=0;
		//	pushdown(u,row);
		}
		return;
	}
	if((se[row][u]!=-1)||ad[row][u])pushdown(u,row);
	int mid=(tre[row][u].l+tre[row][u].r)/2;
	if(le>mid) update(R(u),le,ri,val,row);
	else if(ri<=mid) update(L(u),le,ri,val,row);
	else
	{
		update(L(u),le,mid,val,row);
		update(R(u),mid+1,ri,val,row);
	}
	sum[row][u]=sum[row][L(u)]+sum[row][R(u)]+ad[row][u];
	minl[row][u]=min(minl[row][R(u)],minl[row][L(u)])+ad[row][u];
	maxl[row][u]=max(maxl[row][R(u)],maxl[row][L(u)])+ad[row][u];
}
ans query(int u,int le,int ri,int row)
{
	if(tre[row][u].l==le&&tre[row][u].r==ri)
	{
		ans a;
		a.s=sum[row][u],a.ma=maxl[row][u],a.mi=minl[row][u];
		return a;
	}
	if((se[row][u]!=-1)||ad[row][u])pushdown(u,row);
	int mid=(tre[row][u].l+tre[row][u].r)/2;
	if(le>mid) return query(R(u),le,ri,row);
	else if(ri<=mid) return query(L(u),le,ri,row);
	else
	{
		ans a=query(L(u),le,mid,row);
		ans b=query(R(u),mid+1,ri,row);
		ans c;
		c.s=a.s+b.s,c.ma=max(a.ma,b.ma),c.mi=min(a.mi,b.mi);
		return c;
	}	
}
int main()
{
	vo.mi=inf;
	while(scanf("%d%d%d",&r,&c,&m)!=EOF)
	{
		memset(se,-1,sizeof(se));
		memset(ad,0,sizeof(ad));
		for(int i=1;i<=r;i++)
			build(1,1,c,i);
		for(int tmp=1;tmp<=m;tmp++)
		{
					scanf("%d",&op);
		if(op<3)
		{
			int val;
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&val);
			for(int i=x1;i<=x2;i++)
			{
				update(1,y1,y2,val,i);
			}
		}
		else
		{
			ans tot=vo;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for(int i=x1;i<=x2;i++)
			{
				tot=tot+query(1,y1,y2,i);
			}
			printf("%d %d %d\n",tot.s,tot.mi,tot.ma);
		}

		}
	}
}
