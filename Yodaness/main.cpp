#include <bits/stdc++.h>

using namespace std;
int arr[30001],ans[30001],n,cnt;
char rt[30001][21],wg[30001][21];
map<string,int> mp;

void Merge(int b,int mid,int e)
{
    int l1,l2,i;

    for(l1=b,l2=mid+1,i=b;l1<=mid&&l2<=e;i++)
    {
        if(arr[l1]<=arr[l2]) {ans[i]=arr[l1++];}
        else {ans[i]=arr[l2++];cnt+=(mid-l1+1);}
    }

    int u=0;
    while(l1<=mid){ans[i++]=arr[l1++];}//if(u==1)cnt+=(e-mid);u=1;}
    while(l2<=e){ans[i++]=arr[l2++];}

    for(int i=b;i<=e;i++) arr[i]=ans[i];
}

void msort(int b,int e)
{
    int mid;
    if(b<e)
    {
        mid=(b+e)/2;
        msort(b,mid);msort(mid+1,e);Merge(b,mid,e);
    }
    else
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        cnt=0;

        scanf("%d",&n);

        for(int i=0;i<n;i++)
        scanf(" %s",wg[i]);

        for(int i=0;i<n;i++)
        {
            scanf(" %s",rt[i]);mp[rt[i]]=i;
        }

        for(int i=0;i<n;i++) arr[i]=mp[wg[i]];

        msort(0,n-1);
        printf("%d\n",cnt);
    }

    return 0;
}











