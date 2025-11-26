#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
//answer will never be more than n.
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        map<int,int>mp;
        mp[0]=0;
        vector<int>dp(n+1,0);
        int cur=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1]+1;
            cur^=a[i];
            if(mp.count(cur))
            {
                int last=mp[cur];
                dp[i]=min(dp[i],dp[last]+i-last-1);
            }
            mp[cur]=i;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}

