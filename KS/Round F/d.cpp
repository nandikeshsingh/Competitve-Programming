#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define int long long
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n,k,x,d;
        cin>>n>>k>>x>>d;
        int m;cin>>m;
        vector<vector<pair<int,int>>>T(n+1,vector<pair<int,int>>(0));
        for(int i=0;i<m;i++)
        {
            int t,l,r;
            cin>>t>>l>>r;
            T[t].push_back({l,r});
        }
        int ans=1e18;
        int s=0,e=x;
        while(e<=d)
        {
            int cnt=0;
            multiset<int>ms;
            for(int i=1;i<=n;i++)
            {
                auto u=T[i];
                int cur=0;
                for(auto& v : u)
                {
                    int l=v.first;
                    int r=v.second;
                    if(e<=l || s>=r)continue;
                    else 
                    {
                        cur++;
                    }
                }
                ms.insert(cur);
            }
            int kk=k;
            while(kk--)
            {
                cnt+=(*ms.begin());
                ms.erase(ms.begin());
            }
            ans=min(ans,cnt);
            s++;e++;
        }
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
    return 0;
}