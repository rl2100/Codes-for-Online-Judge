#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define Maxin 4000005
#define Maxn 1005
int nxt[Maxin],head[Maxin],tov[Maxin],stack[Maxn*2],n1,N,M,num;
bool flag[Maxin];
void build(int u,int v)
{
    nxt[++num]=head[u];
    head[u]=num;
    tov[num]=v;
}
bool dfs(int u)
{
    if(flag[u]) return true;
    if(flag[u^1]) return false;
    flag[u]=true;
    stack[++n1]=u;
    int tmp=head[u];
    while(tmp)
    {
        if(!dfs(tov[tmp]))
        {
            return false;
        }
        tmp=nxt[tmp];
    }
    return true;
}
int main()
{
    char d[4];
    scanf("%d%d",&N,&M);
    for(int i=1;i<=M;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        scanf(" %s ",d);
        int ui=(a<<1);
        int uj=(ui|1);
        int vi=(b<<1);
        int vj=(vi|1);
        if(c)
        {
            build(ui,vj);
            build(vi,uj);
            if(d[0]=='A')
            {
                build(vj,uj);
                build(uj,vj);
                continue;
            }
            if(d[0]=='O')
            {
                continue;
            }
            if(d[0]=='X')
            {
                build(vj,ui);
                build(uj,vi);
                continue;
            }
        }
        if(d[0]=='A')
        {
            build(vj,ui);
            build(uj,vi);
            continue;
        }
        build(ui,vi);
        build(vi,ui);
        if(d[0]=='O')
        {
            build(uj,vi);
            build(vj,ui);
            continue;
        }
        build(uj,vj);
        build(vj,uj);
    }
    for(int i=0;i<N;i++)
    {
        n1=0;
        int ui=(i<<1);
        int uj=(ui|1);
        if(flag[ui]||flag[uj]) continue;
        if(dfs(ui)) continue;
        while(n1)
        {
            flag[stack[n1--]]=false;
        }
        if(dfs(uj)) continue;
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
}
