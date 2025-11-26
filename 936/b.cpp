#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=1e9+7;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        vector<int>a(n);
        int tot=0;
        for(int i=0;i<n;i++)cin>>a[i],tot+=a[i];
        int cur=0;
        int mn=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cur+=a[i];
            ans=max(ans,cur-mn);
            mn=min(mn,cur);
        }
        ans%=mod;
        ans=(ans+mod)%mod;
        tot%=mod;
        tot=(tot+mod)%mod;
        for(int i=1;i<=k;i++)
        {
            tot=(tot+ans)%mod;
            ans=(ans*2)%mod;
        }
        cout<<tot<<endl;
    }
    return 0;
}


