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
        int n;cin>>n;
        vector<int>a(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(all(a));
        int md=a[(n+1)/2];
        int ans=0;
        for(int i=(n+1)/2;i<=n;i++)
        {
            ans+=(a[i]==md);
        }
        cout<<ans<<endl;
    }
    return 0;
}


