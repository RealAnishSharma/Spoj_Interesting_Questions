#include <bits/stdc++.h>
#include <limits>
using namespace std;

int arr[100000];
int marr[100000],mar[100000],ma[100000];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        for(int i=0;i<a;i++) scanf("%d",&arr[i]);

        int p,s,minp=0,maxs=0;
        for(int i=0;i<a;i++)
        {
            if(i==0) {p=0;s=0;}
            else     {p=marr[i-1]-arr[i-1];s=ma[i-1]+1;}

            while(p<=b&&s<a)
            p+=arr[s++];
            s--;

            if(p>b){p=p-arr[s];s--;}

            marr[i]=p;mar[i]=s-i+1;ma[i]=s;


            if(minp>marr[i]&&maxs==mar[i]) minp=marr[i];
            if(maxs<mar[i]) {minp=marr[i];maxs=mar[i];}

        }
        printf("%d %d\n",minp,maxs);
    }
    return 0;
}











        /*
        int s,p,ns,np=0,maxs=INT_MIN;
        for(int i=0;i<a;i++)
        {
        s=i;p=0;
        while(p<=b&&s<a)
        {
            p+=arr[s++];
        }s--;

        if(p>b) {p=p-arr[s];s--;}
        ns=s-i;
        if(ns==maxs&&p<np){np=p;}
        if(maxs<ns) {maxs=ns;np=p;}
        }


        printf("%d %d\n",np,maxs+1);*/
