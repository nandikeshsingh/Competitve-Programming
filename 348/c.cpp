#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n),c(n);
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        if(mp.find(c[i])==mp.end())
        {
            mp[c[i]]=a[i];
        }
        else 
        {
            mp[c[i]]=min(mp[c[i]],a[i]);
        }
    }
    int ans=0;
    for(auto& u : mp)
    {
        ans=max(ans,u.second);
    }
    cout<<ans<<endl;
    return 0;
}


