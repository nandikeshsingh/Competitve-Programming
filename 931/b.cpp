#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    vector<int>dp(31,1e18);
    dp[0]=0;
    vector<int>val={1,3,6,10,15};
    for(int i=1;i<=30;i++)
    {
        for(auto& u : val)
        {
            if(u>i)break;
            dp[i]=min(dp[i-u]+1,dp[i]);
        }
    }
    // cout<<"Printing dp"<<endl;
    // for(int i=1;i<=50;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    // cout<<"done"<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        if(n<=30)cout<<dp[n]<<endl;
        else 
        {
            int d=n/15;
            if(n%15==0)cout<<d<<endl;
            else 
            {
                int rim=n%15;
                rim+=15;
                // cout<<d<<" "<<rim<<endl;
                int ans=d-1+dp[rim];
                cout<<ans<<endl;
            }   
        }
    }
    return 0;
}


