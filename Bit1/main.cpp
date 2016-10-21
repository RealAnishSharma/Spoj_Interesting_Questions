#include <bits/stdc++.h>

using namespace std;
int arr[200000];
int res[200000];


void change(int i,int n)
{
    int t=res[i-n];
    for(int j=i-n;j<i;j++)
        res[j]=res[j+1];
    res[i]=t;
}

int main()
{
    int t,n;
    scanf(" %d",&t);
    while(t--)
    {
        scanf(" %d",&n);
        for(int i=0;i<n;i++)
        {
            scanf(" %d",&arr[i]);
            res[i]=i+1;
        }

        for(int i=n-1;i>0;i--)
        {
            if(arr[i]==0)
                continue;
            else
            {
                change(i,arr[i]);
            }
        }

        for(int i=0;i<n;i++)
            printf("%d ",res[i]);
        printf("\n");

    }
    return 0;
}
