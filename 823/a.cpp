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
        int n,c;
        cin>>n>>c;
        map<int,int>mp;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
        int ans=0;
        for(auto& u : mp)
        {
            ans+=min(u.second,c);
        }
        cout<<ans<<endl;
    }
    return 0;
}


