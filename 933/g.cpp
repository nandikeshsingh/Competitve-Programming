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
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,int>>>gp(n+1,vector<pair<int,int>>(0));
        for(int i=0;i<m;i++)
        {
            int u,v,c;cin>>u>>v>>c;
            gp[u].push_back({v,c});
            gp[v].push_back({u,c});
        }
        int b,e;cin>>b>>e;
        vector<int>dis(n+1,1e18);
        vector<set<int>>ecol(n+1);
        dis[b]=0;
        ecol[b].insert(0);
        auto work=[&](int b)->void
        {
            multiset<pair<int,int>>mst;
            mst.insert({0,b});
            while(!mst.empty())
            {
                pair<int,int>p=*mst.begin();
                mst.erase(mst.begin());
                int cur_dis=p.first;
                int cur_node=p.second;
                for(auto& u : gp[cur_node])
                {
                    int nxt_node=u.first;
                    int nxt_col=u.second;
                    if(ecol[cur_node].find(nxt_col)==ecol[cur_node].end())
                    {
                        if(dis[nxt_node]>dis[cur_node]+1)
                        {
                            if(mst.find({dis[nxt_node],nxt_node})!=mst.end())//remove the previous values from multiset as they cannot produce optimal result so no point running the algorithm with these values,it's an optimization;
                            mst.erase(mst.find({dis[nxt_node],nxt_node}));
                            dis[nxt_node]=dis[cur_node]+1;
                            mst.insert({dis[nxt_node],nxt_node});
                            ecol[nxt_node].clear();
                            ecol[nxt_node].insert(nxt_col);
                        }
                        else if(dis[nxt_node]==dis[cur_node]+1)
                        {
                            if(ecol[nxt_node].find(nxt_col)==ecol[nxt_node].end())
                            {
                                ecol[nxt_node].insert(nxt_col);
                                if(mst.find({dis[nxt_node],nxt_node})==mst.end())
                                mst.insert({dis[nxt_node],nxt_node});
                            }
                        }
                    }
                    else 
                    {
                        if(dis[nxt_node]>dis[cur_node])
                        {
                            if(mst.find({dis[nxt_node],nxt_node})!=mst.end())
                            mst.erase(mst.find({dis[nxt_node],nxt_node}));
                            dis[nxt_node]=dis[cur_node];
                            mst.insert({dis[nxt_node],nxt_node});
                            ecol[nxt_node].clear();
                            ecol[nxt_node].insert(nxt_col);
                        }
                        else if(dis[nxt_node]==dis[cur_node])
                        {
                            if(ecol[nxt_node].find(nxt_col)==ecol[nxt_node].end())
                            {
                                ecol[nxt_node].insert(nxt_col);
                                if(mst.find({dis[nxt_node],nxt_node})==mst.end())
                                mst.insert({dis[nxt_node],nxt_node});
                            }
                        }
                    }
                }
            }
        };  
        work(b);
        cout<<dis[e]<<endl;
    }
    return 0;
}


