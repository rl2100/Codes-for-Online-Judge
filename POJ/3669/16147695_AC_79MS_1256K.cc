#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
const int dir1[5]={1,0,-1,0,0},dir2[5]={0,-1,0,1,0};
int f[305][305],a,b,c,m;
bool danger[305][305],use[305][305];
struct me{
	int t,px,py;
};
queue<me> qu;
void bfs()
{
	me ori;
	ori.t=0,ori.px=ori.py=0;
	qu.push(ori);
	while(!qu.empty())
	{
		me now=qu.front();
		qu.pop();
		for(int i=0;i<=3;i++)
		{
			int tmp1=dir1[i]+now.px;
			int tmp2=dir2[i]+now.py;
			if(tmp1<0||tmp2<0) continue;
			if(danger[tmp1][tmp2]==false)
			{
				printf("%d",now.t+1);
				exit(0);
			}
			if(now.t+1<f[tmp1][tmp2]&&now.t+1<=1000&&!use[tmp1][tmp2])
			{
				use[tmp1][tmp2]=true;
				me nex;
				nex.t=now.t+1;
				nex.px=tmp1;
				nex.py=tmp2;
				qu.push(nex);
			}

		}
	}
	printf("-1");
	exit(0);

}
int main()
{

	scanf("%d",&m);
	memset(f,63,sizeof(f));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		for(int i=0;i<=4;i++)
		{
			int tmp1=dir1[i]+a;
			int tmp2=dir2[i]+b;
			if(tmp1>=0&&tmp2>=0)
			{
				f[tmp1][tmp2]=min(c,f[tmp1][tmp2]);
				danger[tmp1][tmp2]=true;
			}
		}
	}
	bfs();
	return 0;	
}
