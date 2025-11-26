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
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(all(a));
        int ans=1e18;
        for(int i=2;i<n;i++)
        {
            ans=min(ans,abs(a[i-1]-a[i-2])+abs(a[i]-a[i-1]));
        }
        cout<<ans<<endl;
    }
    return 0;
}


