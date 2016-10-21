#include <bits/stdc++.h>

using namespace std;

int lps(char x[],int i,int j)
{
    if(i==j) return 1;

    if(x[i]==x[j]&&j-i==1) return 2;
    if(x[i]==x[j]) return 2+lps(x,i+1,j-1);

    return max(lps(x,i+1,j),lps(x,i,j-1));
}




int main()
{
    char str1[]="GEEKSFORGEEKS";
    int n=strlen(str1);
    printf("Tength of LPS is %d",lps(str1,0,n-1));

    return 0;
}
