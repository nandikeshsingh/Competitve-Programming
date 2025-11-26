#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>h(n+1);
        for(int i=1;i<=n;i++)cin>>h[i];
        vector<int>mn(n+1,0);
        for(int i=2;i<n;i++)
        {
            if(h[i]>max(h[i-1],h[i+1]))
            mn[i]=0;
            else mn[i]=(max(h[i-1],h[i+1])-h[i])+1;
        }
        int cur=0;
        int dp[n+1]={0};
        // dp[1]=1e18;
        for(int i=2;i<n;i++)
        {
            if(i==2)dp[i]=mn[i];
            else if(i==3)dp[i]=min(dp[i-1],mn[i]+dp[i-2]);
            else 
            {   
                if(i%2==0)dp[i]=mn[i]+dp[i-2];
                else 
                dp[i]=min({dp[i-1],mn[i]+dp[i-2],mn[i]+dp[i-3]});
            }
        }
        cout<<dp[n-1]<<endl;
        // for(int i=2;i<n;i++)
        // {
        //     if(h[i]>max(h[i-1],h[i+1]))cur++;
        // }
        // int x=0,y=0;
        // for(int i=2;i<n;i++)
        // {
        //     if(i%2)
        //     {
        //         int mx=max(h[i-1],h[i+1]);
        //         if(h[i]<=mx)
        //         y+=((mx-h[i])+1);
        //     }
        //     else 
        //     {
        //         int mx=max(h[i-1],h[i+1]);
        //         if(h[i]<=mx)
        //         x+=((mx-h[i])+1);
        //     }
        // }
        // if(cur>=(n-1)/2)cout<<0<<endl;
        // else 
        // {
        //     if(n%2)cout<<x<<endl;
        //     else cout<<min(x,y)<<endl;
        // }
    }
    return 0;
}