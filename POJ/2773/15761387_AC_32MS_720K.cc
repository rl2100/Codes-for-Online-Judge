#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt=0;
long long p[100];
void find(long long m)
{	cnt=0;
	for(long long i=2;i<m;i++)
	{
		if(m%i==0)
		{
			p[cnt++]=i;
		while(m%i==0)
			m/=i;
		}
	}
	if(m!=1)p[cnt++]=m;
}
long long fu(long long n)
{
	long long res=0LL,sum;
	for(int i=1;i<1<<cnt;i++)
	{
		sum=1LL;
		int bit=0;
		for(int j=0;j<cnt;j++)
		{
			if(i&(1<<j)){
				bit++;
				sum*=p[j];
			}
		}
		if(bit&1)res+=n/sum;
		else res-=n/sum;
	}
	return n-res;
}
int main()
{
	long long m,k;
	while(cin>>m>>k)
	{
		if(m==1){
			cout<<k<<endl;
			continue;
		}
		
		memset(p,0,sizeof(p));
		long long l = 1, r = (1LL<<60), mid, tmp;
		find(m);
		while(r>l)
		{
			mid=(l+r)/2;
			long long x=fu(mid);
			if(x>=k)r=mid;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
}