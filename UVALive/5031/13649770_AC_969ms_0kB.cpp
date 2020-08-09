#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
#define MAXN 20005
#define MAXM 60005
#define MAXOP 500005
struct node{
    node* ch[2];
    int v;
    int r;
    int s;
    node(int x)
    {
	ch[0]=ch[1]=NULL;
	r=rand();
	v=x;
	s=1;
    }
    int cmp(int x)
    {
	if(x==v) return -1;
	return x>v;
    }
    void maintain()
    {
	s=1;
	if(ch[0]!=NULL) s+=ch[0]->s;
	if(ch[1]!=NULL) s+=ch[1]->s;
    }
};
node* root[MAXN];
int tim,n,m,w[MAXN],fa[MAXN],fr[MAXM],to[MAXM],op[MAXOP],work[MAXOP],val[MAXOP];
bool del[MAXM];


int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

void rotate(node* &t,int x)
{
    node* k=t->ch[1^x];
    t->ch[1^x]=k->ch[x];
    k->ch[x]=t;
    t->maintain();
    k->maintain();
    t=k;
}
void insert(node* &t,int x)
{
    if(t==NULL) 
    {
	t=new node(x);
	return;
    }
    int d=x > t->v;
    insert(t->ch[d],x);
    if(t->ch[d]->r > t->r) rotate(t,1^d);
    t->maintain();
}
void remove_tree(node* &t)
{
    if(t->ch[0]!=NULL) remove_tree(t->ch[0]);
    if(t->ch[1]!=NULL) remove_tree(t->ch[1]);
    delete t;
    t=NULL;
}
void remove_point(node* &t,int b)
{
    int d=t->cmp(b);
    if(d!=-1) 
    {
	remove_point(t->ch[d],b);
	t->maintain();
	return;
    }
    if(t->ch[0]!=NULL&&t->ch[1]!=NULL)
    {
	int d1=t->ch[0]->r > t->ch[1]->r;
	rotate(t,d1);
	remove_point(t->ch[d1],b);
    }
    else  
    {
	node* tmp=t;
        if(t->ch[0]==NULL) t=t->ch[1];
        else t=t->ch[0];
	delete tmp;
    }
    if(t!=NULL)
        t->maintain();
}

void merge_tree_to(node* &a, node* &b)
{
    if(a->ch[0]!=NULL) merge_tree_to(a->ch[0],b);
    if(a->ch[1]!=NULL) merge_tree_to(a->ch[1],b);
    insert(b,a->v);
    delete a;
    a=NULL;
}

void build_edge(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(root[a]->s > root[b]->s)
    {
	fa[b]=a;
	merge_tree_to(root[b],root[a]);
	return;
    }
    fa[a]=b;
    merge_tree_to(root[a],root[b]);
}
int kth(node* &t,int k)
{
    if(t==NULL||k > t->s || k<=0) return 0;
    int tmp=0;
    if(t->ch[1]!=NULL) tmp=t->ch[1]->s;
    if(k==tmp+1) return t->v;
    if(k<=tmp) return kth(t->ch[1],k);
    return kth(t->ch[0],k-tmp-1);
}
void change_w(int a,int b)
{
    int c=find(a);
    remove_point(root[c],w[a]);
    insert(root[c],b);
    w[a]=b;
}
void init()
{
    memset(del,false,sizeof(del));
}
int main()
{
    while(true)
    {
	tim++;
	scanf("%d%d",&n,&m);
	if(n==0&&m==0) break;
	init();
	for(int i=1;i<=n;i++)
	    scanf("%d",&w[i]);
	for(int i=1;i<=m;i++)
	    scanf("%d%d",&fr[i],&to[i]);
	int cnt=0,q_cnt=0;
	long long tot=(long long)0;
	char tmp;
	while(true)
	{
	    scanf(" %c",&tmp);
	    if(tmp=='E') break;
	    int x;
	    scanf("%d",&x);
	    if(tmp=='D')
	    {
		op[++cnt]=1;
		work[cnt]=x;
		del[x]=true;
		continue;
	    }
	    int k;
	    scanf("%d",&k);
	    work[++cnt]=x;
	    if(tmp=='Q')
	    {
		q_cnt++;
		op[cnt]=2;
		val[cnt]=k;
		continue;
	    }
	    op[cnt]=3;
	    val[cnt]=w[x];
	    w[x]=k;
	}
	for(int i=1;i<=n;i++)
	{
	    fa[i]=i;
	    if(root[i]!=NULL)
		remove_tree(root[i]);
	    root[i]=new node(w[i]);
	}
	for(int i=1;i<=m;i++)
	    if(!del[i]) build_edge(fr[i],to[i]);
	for(int i=cnt;i>=1;i--)
	{
	    if(op[i]==1) build_edge(fr[work[i]],to[work[i]]);
	    if(op[i]==2) tot+=(long long)kth(root[find(work[i])],val[i]);
	    if(op[i]==3) change_w(work[i],val[i]);	    
	}
	if(q_cnt==0) q_cnt=1;
	printf("Case %d: %.6lf\n",tim,tot/(double)q_cnt);
    }
    return 0;
}