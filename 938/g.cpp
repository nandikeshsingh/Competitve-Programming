#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>a(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        cin>>a[i][j];
        int g=__gcd(a[1][1],a[n][m]);
        vector<int>div;
        for(int i=1;i*i<=g;i++)
        {
            if(g%i==0)
            {
                div.push_back(i);
                if(i*i!=g)
                div.push_back(g/i);
            }
        }
        sort(all(div));
        reverse(all(div));
        vector<vector<int>>vec(n+1,vector<int>(m+1,0));
        // vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        auto get=[&](int g)->bool
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(a[i][j]%g)
                    vec[i][j]=0;
                    else vec[i][j]=1;
                }
            }
            // for(auto& u : dp)u.assign(m+1,0);
            // for(int i=0;i<=n;i++){
            //     for(int j=0;j<=m;j++)
            //     dp[i][j]=0;
            // }
            vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
            dp[1][1]=1;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(i==1)
                    {
                        if(vec[i][j])
                        {
                            if(dp[i][j-1])dp[i][j]=1;
                        }
                    }
                    else if(j==1)
                    {
                        if(vec[i][j])
                        {
                            if(dp[i-1][j])dp[i][j]=1;
                        }
                    }
                    else 
                    {
                        if(vec[i][j])
                        {
                            if(dp[i][j-1]||dp[i-1][j])dp[i][j]=1;
                        }
                    }
                }
            }
            return dp[n][m];
        };
        int ans=1;
        for(auto& u : div)
        {
            if(get(u))
            {
                ans=u;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}