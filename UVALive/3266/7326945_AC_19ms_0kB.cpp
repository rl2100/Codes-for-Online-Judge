#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1005],b[1005],n;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		int al=1,bl=1;
		int ar=n,br=n;
		while(al<=ar&&bl<=br)
		{
			if(a[al]>b[bl])
			{
				tot+=200;
				al++;
				bl++;
				continue;
			}
			if(a[al]<b[bl])
			{
				tot-=200;
				ar--;
				bl++;
				continue;
			}
			/*if(a[ar]>b[br])
			{
				tot+=200;
				ar--;
				br--;
				continue;
			}
			if(a[ar]<b[br])
			{
				tot-=200;
				bl++;
				ar--;
				continue;
			}*/
			if(a[al]==b[bl])
			{
				if(a[ar]<=b[br])
				{
					if(a[ar]<b[bl])
					tot-=200;
					ar--;
					bl++;
				}
				else
				{
					tot+=200;
				//	al++,bl++;
					ar--,br--;
				}
			}
		}
		printf("%d\n",tot);
	}
return 0;
}
