#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    for(int cc=1;cc<=t;cc++)
    {
        int n,m,q;
        cin>>n>>m>>q;
        vector<multiset<pair<int,int>>>gp(n+1);
        // set<pair<int,int>>gp[n+1];
        // cout<<"before"<<endl;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            gp[a].insert({b,c});
            gp[b].insert({a,c});
        }
        // cout<<"after"<<endl;
        vector<int>ans;
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            if((int)gp[x].size()>(int)gp[y].size())swap(x,y);
            int cur=0;
            for(auto& u : gp[x])
            {
                if(u.first==y)cur+=(2*(u.second));
                else 
                {
                    //    auto it = std::find_if(gp[u.first].begin(), gp[u.first].end(), [&](const pair<int,int>& p ){ return p.first == y; });
                        
                        pair<int,int>p={y,0LL};
                        auto it=gp[u.first].lower_bound(p);
                       if(it!=gp[u.first].end())
                       {
                            if((it->first)==y)
                            cur+=min(u.second,it->second);
                       }
                }
            }
            ans.push_back(cur);
        }
        // cout<<"Printing size of the answer"<<ans.size()<<endl;
        cout<<"Case #"<<cc<<": ";
        for(auto& u : ans)cout<<u<<" ";
        cout<<endl;
        // cout<<"done"<<endl;
        
        gp.clear();
        ans.clear();
    }
    return 0;
}


