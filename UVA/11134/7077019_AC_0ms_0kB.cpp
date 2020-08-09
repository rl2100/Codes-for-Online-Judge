#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
using namespace std;
struct rookx{
	int xl,xr,num;
	bool operator < (const rookx & a)const
	{
		return xl>a.xl;
	}
	bool operator > (const rookx & a)const
	{
		return xl<a.xl;
	}
};
struct prex{
	int xl,xr,num;
	bool operator < (const prex & a)const
	{
		return xr>a.xr;
	}
	bool operator > (const prex & a)const
	{
		return xr<a.xr;
	}
};
struct rooky{
	int yl,yr,num;
	bool operator < (const rooky & a)const
	{
		return yl>a.yl;
	}
	bool operator > (const rooky & a)const
	{
		return yl<a.yl;
	}
};
struct prey{
	int yl,yr,num;
	bool operator < (const prey & a)const
	{
		return yr>a.yr;
	}
	bool operator > (const prey & a)const
	{
		return yr<a.yr;
	}
};
rookx a;
rooky b;
int x[5005],y[5005],n;
int main()
{

	while(scanf("%d",&n)&&n)
	{
priority_queue<rookx> qux;
priority_queue<rooky> quy;
priority_queue<prex> rex;
priority_queue<prey> rey;
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d%d",&a.xl,&b.yl,&a.xr,&b.yr);
			a.num=i;
			b.num=i;
			qux.push(a);
			quy.push(b);
		}
		for(int i=1;i<=n;i++)
		{
			while((!qux.empty())&&qux.top().xl<=i)
			{
				prex c;
				rookx d=qux.top();
				c.xl=d.xl,c.xr=d.xr,c.num=d.num;
				rex.push(c);
				qux.pop();
			}
			while((!rex.empty())&&rex.top().xr<i)
			{
				rex.pop();
			}
			if(rex.empty())
			{
				flag=true;
				break;
			}
			x[rex.top().num]=i;
			rex.pop();	
			while((!quy.empty())&&quy.top().yl<=i)
			{
				prey c;
				rooky d=quy.top();
				c.yl=d.yl,c.yr=d.yr,c.num=d.num;
				rey.push(c);
				quy.pop();
			}
			while((!rey.empty())&&rey.top().yr<i)
			{
				rey.pop();
			}
			if(rey.empty())
			{
				flag=true;
				break;
			}
			y[rey.top().num]=i;
			rey.pop();
		}
		if(flag==true)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			printf("%d %d\n",x[i],y[i]);
		}
	}
	return 0;
}
