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
        int tot=0;
        for(int i=0;i<n;i++)cin>>a[i],tot+=a[i];
        int ans=0;
        int cur=0;
        for(int i=0;i<n-1;i++)
        {
            cur+=a[i];
            ans=max(ans,__gcd(cur,tot-cur));
        }
        cout<<ans<<endl;
    }   
    return 0;
}


