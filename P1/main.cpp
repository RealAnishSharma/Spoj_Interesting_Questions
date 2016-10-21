#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int arr[20000];

int main()
{
    int k,N,j,i;
    while(scanf(" %d",&N)!=0)
    {
        for(int i=0;i<N;i++)
            scanf(" %d",&arr[i]);

        sort(arr,arr+N);
        int sol=0;
        for(i=N-1;i>1;i--)
        {
            k=0;j=i-1;
            while(k<j)
            {
                if(arr[i]>(arr[k]+arr[j])){sol+=j-k;k++;}
                else j--;
            }
        }

        printf("%d\n",sol);
    }
    return 0;
}
