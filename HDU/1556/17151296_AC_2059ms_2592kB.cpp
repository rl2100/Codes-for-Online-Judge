#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[100000],tot[100000],d,n,x,y;
int lowbit(int i)
{
    return i&(-i);
}
int getsum(int i)
{
    int sum=0;
    while(i<=n)
    {
        sum+=s[i];
        i=i+lowbit(i);
    }
    return sum;
}
void update(int i,int j )
{
    while(i>0)
    {
        s[i]+=j;
        i=i-lowbit(i);
    }
}


int main()
{
    while(scanf("%d",&n)&&n)
    {
        memset(s,0,sizeof(s));
        memset(tot,0,sizeof(tot));
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        update(y,1);
        update(x-1,-1);
    }
    for(int i=1;i<n;i++)
    printf("%d ",getsum(i));
    cout<< getsum(n)<<endl;
    }
    return 0;

}