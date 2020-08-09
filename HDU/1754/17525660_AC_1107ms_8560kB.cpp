#include<iostream>
#include<cstdio>
#include<cstring>
#define l(u) u*2
#define r(u) u*2+1
using namespace std;
struct node{
    int l,r;
    int maxl;
}a[800010];
int e,b,c[200005],m,n;
char d;

void build(int u,int le,int ri)
{
    a[u].l=le;
    a[u].r=ri;
    a[u].maxl=0;
    if(le==ri)
    {
        a[u].maxl=c[le];
        return;
    }
    int mid=(le+ri)/2;
    build(l(u),le,mid);
    build(r(u),mid+1,ri);
    a[u].maxl=max(a[l(u)].maxl,a[r(u)].maxl);
    return;
}
int qu(int u,int le,int ri)
{
    if(a[u].l==le&&a[u].r==ri)
    {
        return a[u].maxl;
    }
    int mid=(a[u].l+a[u].r)/2;
    if(ri<=mid)
    return qu(l(u),le,ri);
    else if(le>mid)
    return qu(r(u),le,ri);
    else{
        return max(qu(r(u),mid+1,ri),qu(l(u),le,mid));
    }
}
void update(int u,int ex,int ad)
{
    if(a[u].r==a[u].l)
    {
    a[u].maxl=b;
    return;
    }
    int mid=(a[u].r+a[u].l)/2;
    if(ex<=mid)
    update(l(u),ex,ad);
    else
    update(r(u),ex,ad);
    a[u].maxl=max(a[l(u)].maxl,a[r(u)].maxl);
}
int main()
{
    while(cin>>n>>m)
    {
            for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        cin>>d;
        scanf("%d %d",&e,&b);
        if(d=='Q')
        {
            cout<<qu(1,e,b)<<endl;
        }
        else{
update(1,e,b);
        }
    }
    }

    return 0;
}