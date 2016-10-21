#include <bits/stdc++.h>

using namespace std;
int n,arr[10001];

void update(int idx,int val)
{
    idx++;
    while(idx<=n)
    {
        arr[idx]+=val;
        idx+=(idx&(-idx));
    }
}


void update2(int a,int b,int val)
{
    update(a,val);
    update(b+1,-val);
}

int sum(int idx)
{
    idx++;
    int s=0;
    while(idx>0)
    {
        s+=arr[idx];
        idx=idx-(idx&(-idx));
    }
    return s;
}


int ind(int idx)
{
    idx++;
    int s=arr[idx];
    if(idx>0){
        int z=idx-(idx&(-idx));
        idx--;
        while(idx!=z)
        {
            s-=arr[idx];idx-=(idx&(-idx));
        }
    }
    return s;
}

int main()
{
    int t,u,l,r,val;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&u);

        memset(arr,0,sizeof(arr));
        for(int i=0;i<u;i++)
        {
            scanf("%d %d %d",&l,&r,&val);

            update2(l,r,val);
           // for(int j=l;j<=r;j++) update(j,val);
        }
        int q,a;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d",&a);printf("%d\n",sum(a));
        }
    }
    return 0;
}
