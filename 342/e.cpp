
#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int inf=2e18;
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    vector<int>l(m),d(m),k(m),c(m),a(m),b(m);
    vector<vector<pair<int,vector<int>>>>gp(n+1);
    vector<int>time(n+1,-1);
    for(int i=0;i<m;i++)
    {
        cin>>l[i]>>d[i]>>k[i]>>c[i]>>a[i]>>b[i];
        vector<int>t;
        t.push_back(l[i]);
        t.push_back(d[i]);
        t.push_back(k[i]);
        t.push_back(c[i]);
        gp[b[i]].push_back({a[i],t});
    }
    auto work=[&](int node)->void
    {
        multiset<pair<int,int>>mst;
        mst.insert({inf,node});
        time[node]=max(time[node],inf);
        while(sz(mst))
        {
            pair<int,int>p=*prev(mst.end());
            mst.erase(prev(mst.end()));
            int node=p.second;
            int allowed=p.first;
            for(auto& u : gp[node])
            {
                int n=u.first;
                int l=u.second[0];
                int d=u.second[1];
                int k=u.second[2];
                int c=u.second[3];
                int x=(allowed-c-l)/d+1;
                if(x>k)x=k;
                // if(x<=k)
                {
                    int val=l+((x-1)*d);
                    if(time[n]<val)
                    {
                        time[n]=val;
                        mst.insert({time[n],n});
                    }
                }
            }
        }
    };
    work(n);
    for(int i=1;i<n;i++)
    {
        if(time[i]==-1)cout<<"Unreachable"<<endl;
        else cout<<time[i]<<endl;
    }
    return 0;
}


