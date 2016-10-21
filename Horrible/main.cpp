#include <bits/stdc++.h>

using namespace std;

long long A[100001],B[100001];
int n;

void update(long long* arr,int idx,long long val)
{
    while(idx<=n)
    {
        arr[idx]+=val;
        idx+=(idx&(-idx));
    }
}

void update2(int b,int e,long long val)
{
    update(A,b,val);
    update(A,e+1,-val);
    update(B,b,val*(b-1));
    update(B,e+1,-val*e);
}

long long sum(long long* arr,int idx)
{
    long long sum=0;
    for(;idx;idx-=(idx&(-idx)))
        sum+=arr[idx];

    return sum;
}


long long Query(int idx)
{
    return sum(A,idx)*idx-sum(B,idx);
}

long long query(int b,int e)
{
    return Query(e)-Query(b-1);
}

int main()
{
    int T,C,h,p,q;
    long long v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&C);
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        for(int i=0;i<C;i++)
        {
            scanf("%d",&h);
            if(h==0)
            {
                scanf("%d %d %lld",&p,&q,&v);
                update2(p,q,v);
            }
            else
            {
                scanf("%d %d",&p,&q);
                printf("%lld\n",query(p,q));
            }
        }
    }
    return 0;
}
