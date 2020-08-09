#include<iostream>
#include<cstdio>
using namespace std;
int s[32005],tot[15005],d,n,x,y;
int lowbit(int i)
{
	return i&(-i);
}
int getsum(int i)
{
	int sum=0;
	while(i>0)
	{
		sum+=s[i];
		i=i-lowbit(i);
	}
	return sum;
}
void update(int i,int j )
{
	while(i<=32001)
	{
		s[i]+=j;
		i=i+lowbit(i);
	}
}


int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		d=getsum(x+1);
		tot[d]++;
		update(x+1,1);
	}
	for(int i=0;i<n;i++)
	printf("%d\n",tot[i]);

}