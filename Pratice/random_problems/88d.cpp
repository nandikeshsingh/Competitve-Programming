#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    int cur=0,mx=-1e18;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(cur+a[i]>=0)
        {
            cur+=a[i];
            mx=max(mx,a[i]);
            ans=max(ans,cur-mx);
        }
        else 
        {
            cur=0;
            mx=-1e18;
        } 
    }
    cout<<ans<<endl;
    return 0;
}


