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
    vector<int>mp(1e6+1);
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        mp[x]++;
    }
    int ans=1;
    for(int g=1;g<=1e6;g++)
    {
        int tot=0;
        for(int j=g;j<=1e6;j+=g)
        {
            if(mp[j])tot+=mp[j];
        }
        if(tot>=2)
        {
            ans=max(ans,g);
        }
    }
    cout<<ans<<endl;
    return 0;
}


