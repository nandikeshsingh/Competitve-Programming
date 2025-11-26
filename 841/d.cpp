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
        vector<vector<int>>a(n+1,vector<int>(m+1));
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        int lo=1,hi=n;
        while(lo<hi)
        {
            int l=(lo+hi+1)>>1;
            bool ok=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(a[i][j]>=l);
                    if(i<l || j<l)continue;
                    int cnt=dp[i][j]-dp[i-l][j]-dp[i][j-l]+dp[i-l][j-l];
                    if(cnt==l*l)ok=1;
                }
            }
            if(ok)lo=l;
            else hi=l-1;
        }
        cout<<lo<<endl;
    }
    return 0;
}