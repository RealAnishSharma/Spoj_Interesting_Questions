#include <bits/stdc++.h>

using namespace std;
int K,L,m;

int darr[1100001];
bool marr[1100001];

void maxo(int nc)
{
    //if(nc<=0) return;
   // printf("%d->",nc);
    if(nc==K||nc==L||nc==1) {darr[nc]=0;marr[nc]=true;return;}

    //if(nc>1)
    //if(darr[nc-1]==-1) maxo(nc-1);

    if(nc-K>0&&nc-L>0)
    {
        if(darr[nc-L]==-1) maxo(nc-L);
        if(darr[nc-K]==-1) maxo(nc-K);
        if(darr[nc-1]==-1) maxo(nc-1);
        darr[nc]=0;
        marr[nc]=!(marr[nc-L]&&marr[nc-K]&&marr[nc-1]);
        return;
    }
    else if(nc-K>0&&nc-L<0)
    {
        if(darr[nc-K]==-1) maxo(nc-K);
        if(darr[nc-1]==-1) maxo(nc-1);
        darr[nc]=0;
        marr[nc]=!(marr[nc-1]&&marr[nc-K]);
        return;
    }
    else if(nc-K<0&&nc-L>0)
    {
        if(darr[nc-L]==-1) maxo(nc-L);
        if(darr[nc-1]==-1) maxo(nc-1);
        darr[nc]=0;
        marr[nc]=!(marr[nc-1]&&marr[nc-L]);
        return;
    }
    else if(nc-1>0)
    {
        if(darr[nc-1]==-1) maxo(nc-1);
        darr[nc]=0;
        marr[nc]=!(marr[nc-1]);
        return;
    }
}

int main()
{
    scanf(" %d %d %d",&K,&L,&m);
    int arr[m];
    for(int i=0;i<m;i++) scanf("%d",&arr[i]);

    for(int i=0;i<1000001;i++) {darr[i]=-1;marr[i]=false;}

    for(int i=0;i<m;i++)
    {
        maxo(arr[i]);
        if(marr[arr[i]]==true) printf("A");
        else printf("B");
    }
    return 0;
}






