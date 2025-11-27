#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    string s;cin>>s;
    vector<int>cnt(26,0);
    int tot=0;
    int ans=0;
    bool f=0;
    for(auto& u : s)
    {
        ans+=(tot-cnt[u-'a']);
        if(cnt[u-'a']>0)f=1;
        cnt[u-'a']++;
        tot+=1;
    }
    if(f)ans++;
    cout<<ans<<endl;
    return 0;
}


