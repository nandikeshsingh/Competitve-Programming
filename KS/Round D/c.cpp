#include<bits/stdc++.h>
using namespace std;
// #define int long long;
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n;
        cin>>n;
        vector<int>s;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            if(s.size()==0)s.push_back(x);
            else 
            {
                if(s.back()==x)continue;
                else s.push_back(x);
            }
        }
        n=s.size();
        int m;
        cin>>m;
        vector<int>k(m);
        vector<int>pos[2510];
        for(int i=0;i<m;i++)
        {
            cin>>k[i];
            pos[k[i]].push_back(i);
        }
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e9));
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                for(auto & u : pos[s[i]])
                dp[i][u]=0;
            }
            else 
            {
                for(auto& u : pos[s[i]])
                {
                    // int cur=1e9;
                    auto idx = lower_bound(pos[s[i-1]].begin(),pos[s[i-1]].end(),u)-pos[s[i-1]].begin();
                    if(idx==0)
                    {
                        dp[i][u]=min(dp[i][u],abs(u-pos[s[i-1]][idx])+dp[i-1][pos[s[i-1]][idx]]);
                    }
                    else if(idx==pos[s[i-1]].size())
                    {
                        dp[i][u]=min(dp[i][u],abs(u-pos[s[i-1]][idx-1])+dp[i-1][pos[s[i-1]][idx-1]]);
                    }
                    else 
                    {
                        dp[i][u]=min(dp[i][u],abs(u-pos[s[i-1]][idx])+dp[i-1][pos[s[i-1]][idx]]);
                         dp[i][u]=min(dp[i][u],abs(u-pos[s[i-1]][idx-1])+dp[i-1][pos[s[i-1]][idx-1]]);
                    }
                    // for(auto& v : pos[s[i-1]])
                    // {
                    //     cur=min(cur,abs(u-v)+dp[i-1][v]);
                    // }
                    
                    // dp[i][u]=cur;
                }
            }
        }
        // cout<<"Printing dp"<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=1e9;
        for(auto& u : pos[s[n-1]])
        ans=min(ans,dp[n-1][u]);
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
    return 0;
}