#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
#define Tmin 0.1
#define T_st 1536
#define dec 0.9
#define rd 1000
struct point{
	double x,y,ans;
	bool gen;
}a[1005];
point tmp[10];
int n;
double get_rand()
{
	return (double)((rand()%rd)*1.0)/rd;
}
double dist(point a,point b) { return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }
double get_sum(point u)
{
	double ans=0.0;
	for(int i=1;i<=n;i++)
	{
		ans+=dist(u,a[i]);
	}
	return ans;
}
bool cmp(point a, point b) { return a.ans<b.ans; }
int main()
{
	while(~scanf("%d",&n))
	{
		tmp[1].x=tmp[1].y=0;
		point p1,p2;
		p1.x=p1.y=1000000;
		p2.x=p2.y=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&a[i].x,&a[i].y);
			p1.x=min(a[i].x,p1.x), p1.y=min(a[i].y,p1.y);
			p2.x=max(a[i].x,p2.x), p2.y=max(a[i].y,p2.y);
			tmp[1].x+=a[i].x;
			tmp[1].y+=a[i].y;
		}
		tmp[1].x/=n;
		tmp[1].y/=n;
		for(int i=1;i<=2;i++)
		{
			tmp[i].x=p1.x+(int)rand()%(int)((int)p2.x-(int)p1.x);
			tmp[i].y=p1.y+(int)rand()%(int)((int)p2.y-(int)p1.y);			
		}
		for(int i=1;i<=3;i++)
			tmp[i].ans=get_sum(tmp[i]);
		double T=(double)T_st;
		while(T>Tmin)
		{
			for(int i=1;i<=3;i++)
			{
				double mx=0.0,my=0.0;
				for(int j=1;j<=n;j++)
				{
					mx+=(a[j].x-tmp[i].x)/dist(a[j],tmp[i]);
					my+=(a[j].y-tmp[i].y)/dist(a[j],tmp[i]);
				}
				tmp[i+3].x=tmp[i].x+mx*T;
				tmp[i+3].y=tmp[i].y+my*T;
				tmp[i+3].ans=get_sum(tmp[i+3]);
				tmp[i+3].gen=true;
				tmp[i].gen=false;
			}
			sort(tmp+1,tmp+7,cmp);
			int old=0,ant=0;
			for(int i=3;i>=1;i--)
			{
				if(tmp[i].gen==false)
				{
					old=i;
					break;
				}
			}
			for(int i=4;i<=6;i++)
			{
				if(tmp[i].gen==true)
				{
					ant=i;
					break;
				}
			}
			if((old&&ant)&&(exp((tmp[old].ans-tmp[ant].ans)/T))>get_rand())
				{
					point temp=tmp[old];
					tmp[old]=tmp[ant];
					tmp[ant]=temp;
				}
				T*=dec;
		}
		sort(tmp+1,tmp+7,cmp);
		printf("%d",(int)(tmp[1].ans+0.5));
	}
}
