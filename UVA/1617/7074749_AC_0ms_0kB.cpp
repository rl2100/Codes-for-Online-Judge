#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
struct se{
	int l,r;
	bool operator< (const se & a)const
	{
		if(l==a.l)
		return r>a.r;
		return l>a.l;
	}
	bool operator> (const se & a)const
	{	
		if(l==a.l)
		return r<a.r;
		return l<a.l;
	}
};
int n,b;
se a;
priority_queue<se>qu;
int main()
{

	int kase;
	scanf("%d",&kase);
	while(kase--)
	{
		int d=-1;
		int tot=-1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a.l,&a.r);
			qu.push(a);
		}
		while(!qu.empty())
		{
			if(d<qu.top().l)
			{
				tot++;
				d=qu.top().r;
			}
			if(d!=qu.top().r)
			d=min(d+1,qu.top().r);
			qu.pop();
		}
		printf("%d\n",tot);
	}
}
