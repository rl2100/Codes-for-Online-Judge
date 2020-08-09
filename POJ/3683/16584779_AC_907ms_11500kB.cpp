#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define Maxn 1005
#define Maxin 1000005
struct Wed {
    string prest;
    string preend;
    string postst;
    string postend;
}tim[Maxn];
struct Nub {
    int ps,pe,ls,le;
}nub[Maxn];
int tov[2*Maxin],head[2*Maxin],nxt[2*Maxin],num,N;
bool flag[2*Maxin];
string timPlus(string a, int c)
{
    a[3]+=c/10;
    a[4]+=c%10;
    if(a[4]>'9')
    {
        a[4]-=10;
        a[3]+=1;
    }
    if(a[3]>='6')
    {
        a[1]+=(a[3]-'0')/6;
        a[3]='0'+(a[3]-'0')%6;
    }
    if(a[1]>'9')
    {
        a[0]+=(a[1]-'0')/10;
        a[1]='0'+(a[1]-'0')%10;
    }
    return a;
}
string timSub(string a, int c)
{
    a[3]-=c/10;
    a[4]-=c%10;
    if(a[4]<'0')
    {
        a[4]+=10;
        a[3]-=1;
    }
    if(a[3]<'0')
    {
        a[1]-=('0'-a[3])/6;
        if(('0'-a[3])%6) a[1]--;
        a[3]='0'+(600-'0'+a[3])%6;
    }
    if(a[1]<'0')
    {
        a[0]-=('0'-a[1])/10;
        if(('0'-a[1])%10)a[0]--;
        a[1]='0'+(30-'0'+a[1])%10;
    }
    return a;
}
bool intersec(int st1,int end1,int st2, int end2)
{
    if(st1>st2)
    {
        swap(st1,st2);
        swap(end1,end2);
    }
    if(st2>=end1) return false;
    return true;
}
void build(int fr,int to)
{
    nxt[++num]=head[fr];
    head[fr]=num;
    tov[num]=to;
}
bool dfs(int u)
{
    if(flag[u]) return true;
    if(flag[u^1]) return false;
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
int timTostring(string fi)
{
    return fi[0]*1000+fi[1]*100+fi[3]*10+fi[4];
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        string a;
        string b;
        int c;
        cin>>a>>b;
        scanf("%d",&c);
        tim[i].prest=a;
        tim[i].postend=b;
        tim[i].preend=timPlus(a,c);
        tim[i].postst=timSub(b,c);
        nub[i].ps=timTostring(tim[i].prest);
        nub[i].ls=timTostring(tim[i].postst);
        nub[i].pe=timTostring(tim[i].preend);
        nub[i].le=timTostring(tim[i].postend);
    }
    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            int a1=(i<<1);
            int a2=(a1|1);
            int b1=(j<<1);
            int b2=(b1|1);
            if(intersec(nub[i].ps,nub[i].pe,nub[j].ps,nub[j].pe))
            {
                build(a1,b2);
                build(b1,a2);
            }
            if(intersec(nub[i].ps,nub[i].pe,nub[j].ls,nub[j].le))
            {
                build(a1,b1);
                build(b2,a2);
            }
            if(intersec(nub[i].ls,nub[i].le,nub[j].ps,nub[j].pe))
            {
                build(a2,b2);
                build(b1,a1);
            }
            if(intersec(nub[i].ls,nub[i].le,nub[j].ls,nub[j].le))
            {
                build(a2,b1);
                build(b2,a1);
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        int a1=(i<<1);
        int a2=(a1|1);
        if(flag[a1]||flag[a2]) continue;
        if(dfs(a1)) continue;
        if(dfs(a2)) continue;
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(int i=1;i<=N;i++)
    {
        int a1=(i<<1);
        if(flag[a1]) 
        {
            string fi=tim[i].prest;
            string se=tim[i].preend;
            printf("%c%c%c%c%c %c%c%c%c%c\n",fi[0],fi[1],fi[2],fi[3],fi[4],se[0],se[1],se[2],se[3],se[4]);
        }
        else 
        {
            string fi=tim[i].postst;
            string se=tim[i].postend;
            printf("%c%c%c%c%c %c%c%c%c%c\n",fi[0],fi[1],fi[2],fi[3],fi[4],se[0],se[1],se[2],se[3],se[4]);
        }
    }
    return 0;
}
