#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
#define Tmin 0.1
#define T_st 10000
#define dec 0.9
#define rd 1000
struct point{
	double x,y;
}a[1005];
int n;
double ans,now;
double get_rand()
{
	return (double)((rand()%rd)*1.0)/rd;
}
double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double get_sum(point u)
{
	double ans=0.0;
	for(int i=1;i<=n;i++)
	{
		ans+=dist(u,a[i]);
	}
	return ans;
}
int main()
{

	while(~scanf("%d",&n))
	{
		point p1,p2,tmp,cur;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&a[i].x,&a[i].y);
			p1.x=min(a[i].x,p1.x), p1.y=min(a[i].y,p1.y);
			p2.x=max(a[i].x,p2.x), p2.y=max(a[i].y,p2.y);
			tmp.x+=a[i].x;
			tmp.y+=a[i].y;
		}
		tmp.x/=n;
		tmp.y/=n;
		ans=get_sum(tmp);
		double T=(double)T_st;
		while(T>Tmin)
		{
			double mx=0.0,my=0.0;
				for(int i=1;i<=n;i++)
				{
					mx+=(a[i].x-tmp.x)/dist(a[i],tmp);
					my+=(a[i].y-tmp.y)/dist(a[i],tmp);
				}
				cur.x=tmp.x+mx*T;
				cur.y=tmp.y+my*T;
				now=get_sum(cur);
				if(now<ans||(exp(ans-now)/T)>get_rand())
				{
					ans=now;
					tmp=cur;
				}
				T*=dec;
		}
		printf("%d",(int)(ans+0.5));
	}
}