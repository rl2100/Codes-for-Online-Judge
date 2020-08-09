#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define Maxn 205
#define INF 0x3f3f3f3f
struct Edge {
    int fr,to,c,f;
}edge[2*Maxn];
int m,n,nxt[2*Maxn],head[2*Maxn],mini[2*Maxn],la[2*Maxn];
queue<int> q;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(nxt,0,sizeof(nxt));
        memset(head,0,sizeof(head));
        for(int i=1;i<=n;i++)
        {
            int x=(i<<1);
            int y=((i<<1)|1);
            scanf("%d%d%d",&edge[x].fr,&edge[x].to,&edge[x].c);
            edge[x].f=edge[y].f=0;
            edge[y].fr=edge[x].to;
            edge[y].to=edge[x].fr;
            edge[y].c=0;
            nxt[x]=head[edge[x].fr];
            head[edge[x].fr]=x;
            nxt[y]=head[edge[y].fr];
            head[edge[y].fr]=y;
        }
        int flow=0;
        while(true)
        {
            while(!q.empty()) q.pop();
            memset(mini,0,sizeof(mini)); //invoke min
            mini[1]=INF;
            q.push(1);
            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                int tmp=head[x];
                while(tmp)
                {
                    if(!mini[edge[tmp].to]&&edge[tmp].c>edge[tmp].f)
                    {
                        la[edge[tmp].to]=tmp;
                        mini[edge[tmp].to]=min(mini[x],edge[tmp].c-edge[tmp].f);
                        q.push(edge[tmp].to);
                    }
                    tmp=nxt[tmp];
                }
                if(mini[m]) break;
            }
            if(!mini[m]) break;
            for(int i=m;i!=1;i=edge[la[i]].fr)
            {
                edge[la[i]].f+=mini[m];
                edge[la[i]^1].f-=mini[m];
            }
            flow+=mini[m];
        }
        printf("%d\n",flow);
    }
}
