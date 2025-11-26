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
        int n,k;
        cin>>n>>k;
        string s;cin>>s;
        int ans=0;
        vector<int>lo(26),hi(26);
        for(auto& u : s)
        {
            if(u>='a' && u<='z')lo[u-'a']++;
            else hi[u-'A']++;
        }
        int can=0;
        for(int i=0;i<26;i++)
        {
            ans+=min(lo[i],hi[i]);
            can+=(max(hi[i],lo[i])-min(hi[i],lo[i]))/2;
        }
        if(can<=k)ans+=can;
        else ans+=k;
        cout<<ans<<endl;
    }
    return 0;
}


