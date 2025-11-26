#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>p(n+1);
        for(int i=1;i<=n;i++)cin>>p[i];
        int ans=0;
        for(int i=1;i<=k;i++)
        {
            if(p[i]>k)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}


