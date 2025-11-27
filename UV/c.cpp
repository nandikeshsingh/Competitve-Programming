#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,k;
    cin>>n>>k;
    vector<int>a(k+1);
    for(int i=1;i<=k;i++)cin>>a[i];
    vector<int>pre(k+1,0);
    for(int i=2;i<=k;i+=2)
        pre[i]+=pre[i-2]+a[i]-a[i-1];
    vector<int>suf(k+2,0);
    for(int i=k-1;i>=1;i-=2)
        suf[i]+=suf[i+2]+a[i+1]-a[i];
    int ans=1e18;
    if(k&1)
    {
        for(int i=1;i<=k;i+=2)
            ans=min(ans,pre[i-1]+suf[i+1]);
    }
    else 
    {
        ans=0;
        for(int i=2;i<=k;i+=2)ans+=a[i]-a[i-1];
    }
    cout<<ans<<endl;
    return 0;
}
