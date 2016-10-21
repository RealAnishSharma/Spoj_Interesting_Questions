#include <bits/stdc++.h>

using namespace std;
int A[33900],B[33900];

int main()
{
    int a,j,x,k=0;

    memset(A,0,sizeof(A));

    for(int i=2;i<33900;i++)
    {
        if(A[i]==0)
        {
            B[k++]=i;
            x=i+1;j=0;
            while(x<33900)
            {
               if(A[x++]==0) j++;
               if(j==i){j=0;A[x-1]=1;}
            }
        }
    }


    while(1)
    {
        scanf("%d",&a);
        if(a==0) break;
        printf("%d\n",B[a-1]);
    }
    return 0;
}
