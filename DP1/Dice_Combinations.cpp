#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mod=1e9+7;
int n;
int dp[1000100];
int get(int val)
{
    if(val<0)return 0;
    if(val==0)return 1;
    if(dp[val]!=-1)return dp[val];
    return dp[val]=(get(val-1)+get(val-2)+get(val-3)+get(val-4)+get(val-5)+get(val-6))%mod;
}
signed main()
{
    speed;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<get(n)<<endl;
    return 0;
}


