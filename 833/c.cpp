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
        vector<int>a(n+1),pre(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
        }
        map<int,int>mp;
        int idx=1;
        while(idx<=n && a[idx]!=0)
        {
            mp[pre[idx]]++;
            idx++;
        }
        int ans=mp[0];
        for(int i=idx;i<=n;)
        {
            mp.clear();
            mp[pre[i]]++;
            int mx=mp[pre[i]];
            int j=i+1;
            while(j<=n && a[j]!=0)
            {
                mp[pre[j]]++;
                mx=max(mx,mp[pre[j]]);
                j++;
            }
            i=j;
            ans+=mx;
        }
        cout<<ans<<endl;
    }
    return 0;
}
