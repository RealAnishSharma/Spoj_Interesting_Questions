#include <bits/stdc++.h>
using namespace std;

int marr[1001][1001];

int maxo(int arr[],int b,int e)
{
    int t1=0,t2=0;
   //  if(b>e) return 0;
   // return max(arr[b]+maxo(arr,b+1,e),arr[e]+maxo(arr,b,e-1));
    if(b==e) marr[b][e]=0;
    else
    {
    if(arr[e]>arr[b]){e--;t1=1;}else {b++;t2=-1;}
    if(marr[b+1][e]==-1) maxo(arr,b+1,e);
    if(marr[b][e-1]==-1) maxo(arr,b,e-1);

    marr[b+t2][e+t1]=max(arr[b]+marr[b+1][e],arr[e]+marr[b][e-1]);
    }
    return marr[b+t2][e+t1];
}



int main()
{
    int n,kk=1;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        else
        {
            int arr[n],u,v,sum=0;
            for (int i=0;i<n;i++) {scanf("%d",&arr[i]);sum+=arr[i];}

            for(int i=0;i<1001;i++)
            for(int j=0;j<1001;j++)
            marr[i][j]=-1;

            u=arr[0]+maxo(arr,1,n-1);
            v=arr[n-1]+maxo(arr,0,n-2);

            if(u>v)printf("In game %d, the greedy strategy might lose by as many as %d points.\n",kk++,u-abs(u-sum));
            else printf("In game %d, the greedy strategy might lose by as many as %d points.\n",kk++,v-abs(v-sum));
        }
    }
    return 0;
}
