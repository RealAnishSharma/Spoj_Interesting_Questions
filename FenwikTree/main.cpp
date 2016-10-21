//Here is the implementation of fenwick tree
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


//Function to getSum

int getSum(int BIT[],int index)
{
   // index+=1;
    int sum=0;
    while(index>0)
    {
        sum+=BIT[index];
        index-=index&(-index);
    }
return sum;
}

int ansSum(int BIT[],int a,int b)
{
    if(b>a)
    return getSum(BIT,b)-getSum(BIT,a-1);
    else
    return getSum(BIT,a)-getSum(BIT,b-1);
}

void updateBit(int BIT[],int n,int index,int val)
{
 //   index+=1;
    while(index<=n&&index>0)
    {
        BIT[index]+=val;
        index+=index&(-index);
    }
}


int *constructBIT(int arr[],int n)
{
    int *BIT=new int[n+1];
    for(int i=1;i<=n;i++)
        BIT[i]=0;
    for(int i=0;i<n;i++)
        updateBit(BIT,n,i,arr[i]);

    return BIT;
}

int main()
{
    int N,Q,A,B,k=0,ans[100099];
    char str[5];
    cin>>N>>Q;
    int BIT[N+1];
    for(int i=0;i<=N;i++) BIT[i]=0;
    while(Q--)
    {
        cin>>str>>A>>B;
        if(strlen(str)==4)
            ans[k++]=ansSum(BIT,A,B);
        else
            updateBit(BIT,N,A,B);
    }

    for(int i=0;i<k;i++)
    cout<<ans[i]<<endl;

    return 0;
}
