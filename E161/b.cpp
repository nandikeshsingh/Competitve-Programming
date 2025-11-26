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
        vector<int>a(n),b(n+1,0);
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[a[i]]++;
            mp[a[i]]++;
        }
        for(int i=1;i<=n;i++)b[i]+=b[i-1];
        int ans=0;
        for(auto& u : mp)
        {
            if(u.second>=3)
            {
                int c=u.second;
                ans+=(c*(c-1)*(c-2))/6;
            }
        }
        for(auto& u : mp)
        {
            if(u.first==0)continue;
                int g=(u.second*(u.second-1))/2;
                ans+=(g*(b[u.first-1]));
        }
        cout<<ans<<endl;
    }
    return 0;
}

