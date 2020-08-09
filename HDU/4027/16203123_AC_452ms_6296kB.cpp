#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#ifdef WIN32
#define AUTO "%I64d"
#else
#define AUTO "%lld"
#endif
#define Maxn 100005
#define L(u) (u<<1)
#define R(u) ((u<<1)|1)
typedef long long ll;
struct tree {
    int l,r;
}tr[Maxn*4];
ll e[Maxn],sum[Maxn*4];
int n,m;
void build(int le, int ri, int u)
{
    tr[u].l=le;
    tr[u].r=ri;
    if(le==ri)
    {
        sum[u]=e[le];
        return;
    }
    int mid=(le+ri)>>1;
    build(le,mid,L(u));
    build(mid+1,ri,R(u));
    sum[u]=sum[L(u)]+sum[R(u)];
    return;
}
ll Query(int le,int ri,int u)
{
    if(tr[u].l==le&&tr[u].r==ri) return sum[u];
    int mid=(tr[u].l+tr[u].r)>>1;
    if(ri<=mid) return Query(le,ri,L(u));
    else if(le>mid) return Query(le,ri,R(u));
    return Query(le,mid,L(u))+Query(mid+1,ri,R(u));
}
void Update(int le,int ri,int u)
{
    if(sum[u]==tr[u].r-tr[u].l+1ll)
        return;
    if(tr[u].l==tr[u].r)
    {
        sum[u]=(ll)sqrt(sum[u]);
        return;
    }
    int mid=(tr[u].l+tr[u].r)>>1;
    if(ri<=mid) Update(le,ri,L(u));
    else if(le>mid) Update(le,ri,R(u));
    else {
        Update(le,mid,L(u));
        Update(mid+1,ri,R(u));
    }
    sum[u]=sum[L(u)]+sum[R(u)];
    return;
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        scanf(AUTO,&e[i]);
    }
    build(1,n,1);
    scanf("%d",&m);
}

int main()
{
    int Ti=0;
    while(~scanf("%d",&n))
    {
        printf("Case #%d:\n",++Ti);
        init();
        for(int i=1;i<=m;i++)
        {
            int T,X,Y;
            scanf("%d%d%d",&T,&X,&Y);
            if(X>Y) swap(X,Y);
            if(T)
            {
                printf(AUTO,Query(X,Y,1));
                printf("\n");
            }
            else
            {
                Update(X,Y,1);
            }
        }
        printf("\n");
    }
}
