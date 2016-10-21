#include <bits/stdc++.h>

using namespace std;

int min(int a,int b,int c)
{
    return min(a,min(b,c));
}

int editD(string str1,string str2,int m,int n)
{
    /*
    //if first string is empty,insert all n characters of second string
    if(m==0) return n;
    //if second string is empty,delete all m characters of first string
    if(n==0) return m;

    if(str1[m-1]==str2[n-1])
    {
        return editD(str1,str2,m-1,n-1);
    }
    return 1+min(editD(str1,str2,m,n-1),editD(str1,str2,m-1,n),editD(str1,str2,m-1,n-1));
    */

    int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j==0) dp[i][j]=i;
            else if(i==0) dp[i][j]=j;

            else if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);

        }
    }



    return dp[m][n];




}




int main()
{
    string str1="sunday";
    string str2="saturday";

    cout<<editD(str1,str2,str1.length(),str2.length());
    return 0;
}
