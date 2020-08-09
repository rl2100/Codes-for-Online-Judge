#include<iostream>
#include<cstring>
using namespace std;
int sum,m,n,x,y;
int match[205];
bool map[205][205],visit[205];
bool dfs(int k)
{
	for(int i=1;i<=m;i++)
	{
		if(!visit[i]&&map[k][i])
		{
		visit[i]=true;
			if(match[i]==-1||dfs(match[i]))
			{
				
				match[i]=k;
				return true;
			}
			
		}
	}
	return false;
}
int main()
{
	
	while(cin>>n>>m)
	{
		sum=0;
		memset(map,false,sizeof(map));
	memset(match,-1,sizeof(match));
			for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>y;
			map[i][y]=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(visit,0,sizeof(visit));
		if(dfs(i))sum++;
	}
	cout<<sum<<endl;
	}

}