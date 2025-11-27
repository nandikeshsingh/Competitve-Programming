#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    // int pre=0;
    // int mn=0;
    int ans=-1e18;
    // for(int i=0;i<n;i++)
    // {
    //     pre+=a[i];
    //     ans=max(ans,pre-mn);
    //     mn=min(mn,pre);
    // }
    int cur=0;
    for(int i=0;i<n;i++)
    {
        cur+=a[i];
        
        ans=max(ans,cur);
        if(cur<0)cur=0;
    }
    cout<<ans<<endl;
    return 0;
}


