#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mod=1e9+7;
vector<int>c;
int n,x;
int dp[1000010];
int get(int val)
{
    if(val<0)return 0;
    if(val==0)return 1;
    if(dp[val]!=-1)return dp[val];
    int ans=0;
    for(auto& u : c)
    {
        ans+=(get(val-u))%mod;
        ans%=mod;
    }
    return dp[val]=ans;
}
signed main()
{
    speed;
    cin>>n>>x;
    c.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>c[i];
    cout<<get(x)<<endl;
    return 0;
}


