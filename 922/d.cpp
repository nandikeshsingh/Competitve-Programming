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
        int n;
        cin>>n;
        vector<int>a(n+1,0);
        int tot=0;
        for(int i=1;i<=n;i++)cin>>a[i],tot+=a[i];
        int lo=0,hi=tot;
        while(hi>lo)
        {
            int mid=(hi+lo)/2;
            // cout<<"lo="<<lo<<" hi="<<hi<<" mid="<<mid<<endl;
            bool ok=1;
            int cur=0;
            multiset<pair<int,int>>mst;
            int last=0;
            vector<int>dp(n+1,0);
            mst.insert({0,0});
            for(int i=1;i<=n;i++)
            {
                dp[i]=mst.begin()->first+a[i];
                cur+=a[i];
                mst.insert({dp[i],i});
                while(cur-a[last]>mid)
                {
                    cur-=a[last];
                    mst.erase(mst.find({dp[last],last}));
                    last++;
                }
            }
            int mn=1e18;
            int seen=0;
            for(int i=n;i>=0;i--)
            {
                if(seen<=mid)
                {
                    mn=min(mn,dp[i]);
                }
                seen+=a[i];
            }
            if(mn<=mid)hi=mid;
            else lo=mid+1;
        }
        cout<<hi<<endl;
    }
    return 0;
}
 