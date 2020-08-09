#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    while(true)
    {
    int m,n;
    scanf("%d%d",&n,&m);
    if(n==0&&m==0) break;
    if(m%2&&n%2) printf("What a pity!\n");
    else printf("Wonderful!\n");
    }
    return 0;
}
