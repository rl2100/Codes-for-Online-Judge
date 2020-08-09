#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,T,a[5005],b[5005];
bool can(int nu)
{
	int sumE=0,sumW=0,canE=0,canW=0,cantot=0;
	for(int i=1;i<=n;i++)
	{
		sumE+=a[i];
		sumW+=b[i];
		if(a[i]>nu+1||b[i]>nu+1)
			return false;
		while(sumE>nu+1)
		{
			sumE--;
			if(canE==0||cantot==0)
				return false;
			cantot--;
			canE--;
		}
		while(sumW>nu+1)
		{
			sumW--;
			if(canW==0||cantot==0)
				return false;
			cantot--;
			canW--;
		}
		if(cantot<sumE+sumW)cantot++;
		if(canE<sumE)canE++;
		if(canW<sumW)canW++;

	}
	return true;
}
int main()
{
	
	scanf("%d",&T);
	while(T--)
	{
		int maxnu=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			maxnu+=max(a[i],b[i]);
		}
		int l=0,r=maxnu;
		if(can(0))
		{
			printf("0\n");
			continue;
		}
		while(l<r-1)
		{
			int mid=(l+r)/2;
			if(can(mid))
				r=mid;
			else
				l=mid;
		}
		printf("%d\n",r);
	}
}