
#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false);std::cin.tie(false)
#define endl "\n"
typedef long long ll;
const ll MAX = 200002;
using namespace std;
ll bit[MAX], arr[MAX], temp[MAX], n;

//----------------------------BIT CODE******************************************************
void update(int ind, int val){
 while (ind <= n){
 bit[ind] += val;
 ind += ind & (-ind);
 }
}
ll get(int ind){
 ll sum = 0;
 while (ind >= 1){
 sum += bit[ind];
 ind -= ind & (-ind);
 }
 return sum;
}
void construct(){
 for (int i = 1; i < n; i++)
 update(n, i);
}
//*****************************************************BIT CODE-----------------------
ll b_search(ll val){
 int start = 1, end = n;
 while (start <= end){
 int mid = (start + end) >> 1;
 if (temp[mid] == val)return mid;
 else if (temp[mid] > val)end = mid - 1;
 else start = mid + 1;
 }
}
int main(int argv, char** args)
{
 ll t;
 cin >> t;
 while (t--){
 ll sum = 0;
 cin >> n;
 for (int i = 1; i <= n; i++)bit[i] = 0;
 for (int i = 1; i <= n; i++){
 cin >> arr[i];
 temp[i] = arr[i];
 }
 sort(temp + 1, temp + n + 1);//Helps in getting index of each element of arr in its sorted form
 for (ll i = 1; i <= n; i++){
 ll pos = b_search(arr[i]); //To get index of arr[i] in its sorted form
 sum += get(n) - get(pos);
 update(pos, 1);
 }
 cout << sum << endl;
 }
 return 0;
}
