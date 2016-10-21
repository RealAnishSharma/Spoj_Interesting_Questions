#include <bits/stdc++.h>

using namespace std;
unsigned long long int marr[70][11];
/*
int maxo(int N,int z)
{
    if(N==1) return 10-z;
    int p=0;
    for(int i=z;i<10;i++)
    {
        p+=maxo(N-1,i);
    }
    return p;
}
*/
void maxo(int N,int z)
{
    if(N==1) {marr[N][z]=10-z;return;}
    unsigned long long int p=0;
    for(int i=z;i<10;i++)
    {
        if(marr[N-1][i]==0) maxo(N-1,i);
        p+=marr[N-1][i];
    }
    marr[N][z]=p;
}


int main()
{
    int P,N;
    scanf("%d",&P);
    while(P--)
    {
        int k;
        scanf("%d %d",&k,&N);

        for(int i=0;i<70;i++)for(int j=0;j<11;j++)marr[i][j]=0;

        maxo(N,0);
      //  printf("%d %d\n",k,maxo(N,0));
        printf("%d ",k);cout<<marr[N][0]<<"\n";
    }
    return 0;
}
