#include <bits/stdc++.h>

using namespace std;

int prime[10000],value[10000],vis[10000];


void foo(int p,int q)
{
    int c,e,b,d,w1,w2,w3,w4;
    queue<int> Q;

    vis[p]=0;
    Q.push(p);

    while(!Q.empty())
    {
        c=Q.front();Q.pop();
        e=c;

        w1=e%10;e/=10;
        w2=e%10;e/=10;
        w3=e%10;e/=10;
        w4=e%10;

        for(int i=1;i<10;i++)
        {
            if(i==w4) continue;
            d=i*1000+w3*100+w2*10+w1;
            if(prime[d]==1&&vis[d]==-1)
            {
                if(value[c]+1<value[d])
                value[d]=value[c]+1;
                vis[d]=0;
                Q.push(d);
            }
        }

        for(int i=0;i<10;i++)
        {
            if(i==w3) continue;
            d=w4*1000+i*100+w2*10+w1;
            if(prime[d]==1&&vis[d]==-1)
            {
                if(value[c]+1<value[d])
                value[d]=value[c]+1;
                vis[d]=0;
                Q.push(d);
            }
        }


        for(int i=0;i<10;i++)
        {
            if(i==w2) continue;
            d=w4*1000+w3*100+i*10+w1;
            if(prime[d]==1&&vis[d]==-1)
            {
                if(value[c]+1<value[d])
                value[d]=value[c]+1;
                vis[d]=0;
                Q.push(d);
            }
        }


        for(int i=1;i<10;i++)
        {
            if(i==w1) continue;
            d=w4*1000+w3*100+w2*10+i;
            if(prime[d]==1&&vis[d]==-1)
            {
                if(value[c]+1<value[d])
                value[d]=value[c]+1;
                vis[d]=0;
                Q.push(d);
            }
        }

    }

    if(value[q]==10000) printf("Impossible\n");
    else printf("%d\n",value[q]);
}







int main()
{
    int t;
    scanf("%d",&t);
    memset(prime,-1,sizeof(prime));

    //set of prime numbers
    for(int i=2;i<10000;i++)
    {
        if(prime[i]==-1) prime[i]=1;
        for(int k=2;k<5000;k++)
        {
            if(k*i>=10000) break;
            else prime[k*i]=0;
        }
    }

    while(t--)
    {
        int p,q;
        memset(value,10000,sizeof(value));
        memset(vis,-1,sizeof(vis));
        scanf("%d %d",&p,&q);
        value[p]=0;
        foo(p,q);
    }

    return 0;
}
