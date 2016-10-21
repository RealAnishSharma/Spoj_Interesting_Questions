#include <bits/stdc++.h>
#include <limits>
using namespace std;
int arr[300001];
int marr[300001],mar[300001];

int maxo(int N,int M)
{
    int s,p,maxp=INT_MIN;
    for(int i=0;i<N;i++)
    {
        if(i==0){s=0;p=0;}else {s=mar[i-1]+1;p=marr[i-1]-arr[i-1];}
        while(p<=M&&s<N)
        {
            p+=arr[s];
            s++;
        }
        s--;
        if(p>M){p-=arr[s];s--;}

        if(p>maxp) maxp=p;
        marr[i]=p;
        mar[i]=s;
    }
    return maxp;
}

int main()
{
    int N,M;

    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&arr[i]);
    for(int i=0;i<300001;i++){marr[i]=0;mar[i]=0;}
    printf("%d\n",maxo(N,M));

    return 0;
}
