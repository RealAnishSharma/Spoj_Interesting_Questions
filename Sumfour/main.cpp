#include <bits/stdc++.h>

using namespace std;

vector<long long int> A,B,C,D,X,Y;
map<long long int,long long int> mymap;

int main()
{
    long long int n,a,b,c,d,cnt=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }


    for(int i=0;i<A.size();i++)
    for(int j=0;j<B.size();j++)
    {
        mymap[A[i]+B[j]]=mymap[A[i]+B[j]]+1;
    }

    for(int i=0;i<C.size();i++)
    for(int j=0;j<D.size();j++)
    {
        if(mymap[-(C[i]+D[j])]>0)
        {
            cnt++;
            mymap[-(C[i]+D[j])]=mymap[-(C[i]+D[j])]-1;
        }
    }

    printf("%lld\n",cnt);
    return 0;
}
