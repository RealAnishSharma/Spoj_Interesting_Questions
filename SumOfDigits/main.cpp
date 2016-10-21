
#include <bits/stdc++.h>
using namespace std;

int sumo(int n,int d)
{
    if(n<10) return n*(n+1)/2;
    if(d==1) return 45;

    int p=0,q,q=n/10^(d-1),r=n%10^(d-1);

    p=q*r;r--;
    while(r>0)
    {p+=(10^(d-1))*r;r--;}

    p+=sumo(r,d-1);
    return p;
}


int main()
{
    int a,b;
    while(1){
    scanf("%d %d",&a,&b);
    if(a==-1&&b==-1) break;

    int m=a,n=b,ad=0,bd=0;

    while(m>0){ad++;m=m/10;}
    while(n>0){bd++;n=n/10;}

    printf("%d\n",sumo(b,bd)-sumo(a,ad));
    }
    return 0;
}




























/*

unsigned long long int marr[1000000001];
 while(1)
    {
        unsigned long long int i,a,b;
        cin>>a>>b;

        if(a==-1&&b==-1) return 0;


        for(i=0;i<1000000001;i++)
        {
            unsigned long long int a,sum=0,j=i;
            while(j%10!=j)
            {
            a=j%10;
            i=j/10;
            sum+=a;
            }
            sum+=j;
            marr[i]=sum;

        }

        cout<<marr[b]-marr[a]<<"\n";
    }
*/
