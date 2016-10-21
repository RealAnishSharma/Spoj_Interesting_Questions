#include <iostream>
#include <cmath>
#include<cstdio>
using namespace std;

struct N{int sum,minsum;} st[65536];
char arr[35536];

void updateUtil(int ss,int se,int i,int si)
{

    if(ss==se){
        st[si].sum=st[si].minsum=-st[si].sum;
        return;
        }
    int m=(ss+se)/2;
    if(i<=m) updateUtil(ss,m,i,2*si+1);
    else updateUtil(m+1,se,i,2*si+2);

    st[si].sum=st[2*si+1].sum+st[2*si+2].sum;
    st[si].minsum=min(st[2*si+1].minsum,st[2*si+1].sum+st[2*si+2].minsum);
}


struct N constructUtil(int ss,int se,int si)
{
    if(ss==se)
    {
        if(arr[ss]==')')
        {st[si].sum=st[si].minsum=-1;}
        else
        {st[si].sum=st[si].minsum=1;}
        return st[si];
    }
    int m=(ss+se)/2;
   constructUtil(ss,m,2*si+1);
   constructUtil(m+1,se,2*si+2);

   st[si].sum=st[si*2+1].sum+st[si*2+2].sum;
   st[si].minsum=min(st[si*2+1].minsum,st[si*2+1].sum+st[si*2+2].minsum);
    return st[si];
}

int main()
{
    int i=0,j,m,n,p;
    while(i<10)
    {
        scanf("%d",&n);
        scanf(" %s",arr);
        constructUtil(0,n-1,0);
        scanf("%d",&m);

        printf("Test %d:\n",++i);
        for(int u=0;u<m;u++)
        {
            scanf("%d",&p);
            if(p==0)
                if(!st[0].sum&&!st[0].minsum) printf("YES\n");
                else printf("NO\n");
            else
                updateUtil(0,n-1,p-1,0);
        }
    }
    return 0;
}
