#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
map<int,int>dp;
int get(int n)
{
    if(n<2)return 0;
    if(dp.find(n)!=dp.end())return dp[n];
    else return dp[n]=n+get(n/2)+get((n+1)/2);
}
signed main()
{
    speed;
    int n;
    cin>>n;
    cout<<get(n)<<endl;
    return 0;
}


