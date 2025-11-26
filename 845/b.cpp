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
        int n;
        cin>>n;
        int ans=1;
        for(int i=2;i<=n;i++)
        {
            ans*=i;
            ans%=mod;
        }
        ans*=n;
        ans%=mod;
        ans*=(n-1);
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}


