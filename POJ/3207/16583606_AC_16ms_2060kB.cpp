#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define Maxin 250005
#define Maxm 505
struct Point {
    int s,l;
}p[Maxm];
bool flag[2*Maxin];
int tov[2*Maxin],head[2*Maxin],nxt[2*Maxin],n,m;
bool dfs(int u)
{
    if(flag[u]==true) return true;
    if(flag[u^1]==true) return false;
    flag[u]=true;
    int tmp=head[u];
    while(tmp)
    {
        if(!dfs(tov[tmp]))
        {
            flag[u]=false;
            return false;
        }
        tmp=nxt[tmp];
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&p[i].s,&p[i].l);
        if(p[i].s>p[i].l) swap(p[i].s,p[i].l);
    }
    int num=0;
    for(int i=1;i<=m-1;i++)
        for(int j=i+1;j<=m;j++)
        {
            if((p[i].s<p[j].s && p[j].s<p[i].l && p[i].l<p[j].l)||(p[j].s<p[i].s && p[i].s<p[j].l && p[j].l<p[i].l))
            {
                int inc=(i<<1);
                int ouc=inc|1;
                int ind=(j<<1);
                int oud=ind|1;
                nxt[++num]=head[inc];
                head[inc]=num;
                tov[num]=oud;
                nxt[++num]=head[ouc];
                head[ouc]=num;
                tov[num]=ind;
                nxt[++num]=head[ind];
                head[ind]=num;
                tov[num]=ouc;
                nxt[++num]=head[oud];
                head[oud]=num;
                tov[num]=inc;
            }
        }
    for(int i=1;i<=m;i++)
    {
        int inc=(i<<1);
        int ouc=inc|1;
        if(flag[inc]||flag[ouc]) continue;
        if(dfs(inc))
        {
            continue;
        }
        if(dfs(ouc))
        {
            continue;
        }
        printf("the evil panda is lying again\n");
        return 0;
    }
    printf("panda is telling the truth...\n");
    return 0;
}
