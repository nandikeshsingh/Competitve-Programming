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
        int n,x;cin>>n>>x;
        vector<int>p(n+1,0);
        int idx=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            if(p[i]==x)idx=i;
        }
        vector<pair<int,int>>ans;
        if(idx>1)ans.push_back({1,idx}),swap(p[1],p[idx]);
        int l=1,r=n+1;
        while(r-l>1)
        {
            int m=(l+r)>>1;
            if(p[m]<=x)l=m;
            else r=m;
        }
        if(l!=1)
        {
            ans.push_back({1,l});
        }
        cout<<sz(ans)<<endl;
        for(auto& u : ans)cout<<u.first<<" "<<u.second<<endl;
    }
    return 0;
}


