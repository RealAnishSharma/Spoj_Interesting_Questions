#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <set>
#include <assert.h>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <time.h>
#include <climits>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)
#define INT(x) scanf("%d",&x)
#define LLD(x) scanf("%lld",&x)
#define STR(x) scanf("%s",x)
#define CHAR(x) scanf("%c",&x)
#define PINT(x) printf("%d\n",x)
#define PLLD(x) printf("%lld\n",x)
#define CLR(x) memset(x,0,sizeof(x));
#define F first
#define S second
#define PB push_back
#define MOD 1000000007
#define MAX 100005

const int INF = 1e9 ;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef map<int,int> MII;
typedef vector<pair<int,int> > VPII;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VLL> VVL;

char s[5010];
VC s1;
int memo[5010][5010];
bool vis[5010][5010];

void foo(int index,int sum)
{
    vis[index][sum] = true;
	if(index==s1.size()) {if(sum==0)memo[index][sum]=0;else memo[index][sum]=INF;return;}

	int ans = INF;
	int num=0;

	FOR(i,index,s1.size())
	{
		num = num*10 + (s1[i]-'0');
		if(num>sum) break;
		if(!vis[i+1][sum-num]) foo(i+1,sum-num);
		ans = min(ans,1 + memo[i+1][sum-num]);
	}
	memo[index][sum] = ans;
	return;// ans;
}

int main()
{
CLR(s);STR(s);
int len = strlen(s);
s1.clear();

int i=0,c=0;
for(i=0;i<len;++i)
{
	if(s[i]=='=') break;
	if(s[i]!='0'){ s1.PB(s[i]);c=0;}
	else if(s[i]=='0' && c<=3){s1.PB(s[i]);++c;}
}

int sum1=0;
FOR(j,i+1,len)
    sum1 = sum1*10 + (s[j]-'0') ;

CLR(vis);foo(0,sum1);
int ans = memo[0][sum1] - 1;
PINT(ans);
return 0;
}
