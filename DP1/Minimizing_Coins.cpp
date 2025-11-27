#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>c;
int n,x;
int dp[1000010];
int get(int val)
{
    if(val<0)return 2e18;
    if(val==0)return 0;
    if(dp[val]!=-1)return dp[val];
    int ans=1e18;
    for(auto& u : c)
    {
        ans=min(ans,get(val-u)+1);
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
    // vector<int>dp(1e6+2);
    // for(auto& u : dp)u=1e18;
    // dp[0]=0;
    // for(int i=0;i<1e6+2;i++)
    // {
    //     for(auto& u : c)
    //     {
    //         if(u+i>1e6)continue;
    //         dp[u+i]=min(dp[u+i],dp[i]+1);
    //     }
    // }
    // int ans=dp[x];
    // if(ans==1e18)ans=-1;
    // cout<<ans<<endl;
    int ans=get(x);
    if(ans==1e18)ans=-1;
    cout<<ans<<endl;
    return 0;
}


