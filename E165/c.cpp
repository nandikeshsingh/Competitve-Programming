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
        int n,k;
        cin>>n>>k;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        vector<vector<int>>dp(k+1,vector<int>(n+1,1e18));
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            int mn=a[i];
            for(int len=1;len<=k+1;len++)
            {
                if(i-len>=0)
                {
                    mn=min(mn,a[i-len+1]);
                    for(int rim=0;rim<=len-1;rim++)
                    {
                        dp[len-1][i]=min(dp[len-1][i],dp[len-1-rim][i-len]+len*mn);
                    }
                }
            }
        }   
        int ans=1e18;
        for(int j=0;j<=k;j++)ans=min(ans,dp[j][n]);
        cout<<ans<<endl;     
    }
    return 0;
}


