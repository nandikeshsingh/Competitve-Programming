#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<vector<int>>dp,gp;
string s;
void dfs(int n,int p)
{
    for(auto& u : gp[n])
    {
        if(u==p)continue;
        dfs(u,n);
        dp[n][1]+=min(dp[u][0]+1,dp[u][1]);
        dp[n][0]+=min(dp[u][0],dp[u][1]+1);
    }
    if(s[n-1]=='P')dp[n][1]=1e18;
    if(s[n-1]=='S')dp[n][0]=1e18;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int>a(n+1);
        for(int i=2;i<=n;i++)cin>>a[i];
        cin>>s;
        gp.clear();
        gp.resize(n+1,vector<int>(0));
        for(int i=2;i<=n;i++)
        {
            gp[i].push_back(a[i]);
            gp[a[i]].push_back(i);
        }
        dp.clear();
        dp.resize(n+1,vector<int>(2,0));
        dfs(1,-1);
        cout<<min(dp[1][0],dp[1][1])<<endl;
    }
    return 0;
}