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
        vector<int>a(n+1,0),b(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int j=1;j<=n;j++)cin>>b[j];
        int ans=1e18;
        int cur=0;
        for(int i=n;i>=1;i--)
        {
            if(i<=m)
            {
                ans=min(ans,a[i]+cur);
            }
            cur+=min(a[i],b[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}


