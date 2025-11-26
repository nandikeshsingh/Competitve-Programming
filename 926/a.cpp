#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    // int k;cin>>k;
    // auto func=[&](int k)->int
    // {
    //     int n=100;
    //     return n-k;
    // };
    // cout<<func(k)<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(all(a));
        int ans=0;
        for(int i=1;i<n;i++)ans+=(a[i]-a[i-1]);
        cout<<ans<<endl;
    }
    return 0;
}
