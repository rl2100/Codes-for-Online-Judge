#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5+2;
typedef long long ll;
struct Seg
{
    ll pre,suf,sub,sum;
    int l,r,pr,sl;
}tr[maxn<<2];
#define lid (id<<1)
#define rid (id<<1|1)
int n,m,a[maxn];
int ql,qr;

void updata(Seg&u,Seg&v1,Seg&v2)
{
    if(v1.pre >= v1.sum+v2.pre){//y
        u.pr = v1.pr; u.pre = v1.pre;
    }else {
        u.pr = v2.pr; u.pre = v1.sum+v2.pre;
    }

    if(v2.suf <= v2.sum+v1.suf){//x
        u.sl = v1.sl; u.suf = v2.sum+v1.suf;
    }else {
        u.sl = v2.sl; u.suf = v2.suf;
    }

    if(v1.sub >= v2.sub){
        u.l = v1.l; u.r = v1.r; u.sub = v1.sub;
    }else {
        u.l = v2.l; u.r = v2.r; u.sub = v2.sub;
    }
    if(u.sub < v1.suf+v2.pre || (u.sub == v1.suf+v2.pre && (u.l>v1.sl ||(u.l == v1.sl && u.r > v2.pr) ) ) ){
        u.sub = v1.suf+v2.pre; u.l = v1.sl; u.r = v2.pr;
    }

    u.sum = v1.sum + v2.sum;
}

void build(int l = 1,int r = n,int id = 1)
{
	if(l==r) 
 {
		Seg &u = tr[id];
        u.pre = u.suf = u.sub = u.sum = a[l];
        u.l = u.r = u.pr = u.sl = l;
        return;
    }
    int mid = (l+r)>>1, lc = lid, rc = rid;
    build(l,mid,lc);
    build(mid+1,r,rc);
    updata(tr[id],tr[lc],tr[rc]);

}

Seg query(int l = 1,int r = n, int id = 1)
{
    if(ql<=l&&r<=qr) { return tr[id]; }
    int mid = (l+r)>>1, lc = lid, rc = rid;
    Seg ret;
    if(ql<=mid && mid<qr){
        Seg L = query(l,mid,lc), R = query(mid+1,r,rc);
        updata(ret,L,R);
        return ret;
    }
    if(qr <= mid) {
        return query(l,mid,lc);
    }
    return query(mid+1,r,rc);
}

int main()
{

    int kas = 0;
    while(~scanf("%d%d",&n,&m)){
        for(int i = 1; i <= n; i++) scanf("%d",a+i);
        build();
        printf("Case %d:\n",++kas);
        while(m--){
            int x,y; scanf("%d%d",&x,&y);
            ql = x,qr = y;
            Seg ans = query();
            printf("%d %d\n",ans.l,ans.r);
        }
    }
    return 0;
}
