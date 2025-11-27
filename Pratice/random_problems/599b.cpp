#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int maxn=2e5+5;
int n,m;
set<int>gp[maxn];
set<int>st;
vector<int>ans;
int dfs(int n)
{
    int tot=1;
    for(auto itr=st.begin();itr!=st.end();)
    {
        if(gp[n].count(*itr)==0)
        {
            int cur=*itr;
            st.erase(itr);
            tot+=dfs(cur);
            itr=st.upper_bound(cur);
        }
        else itr++;
    }
    return tot;
}
signed main()
{
    speed;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        gp[u].insert(v);
        gp[v].insert(u);
    }
    for(int i=1;i<=n;i++)st.insert(i);
    while(sz(st))
    {
        int node=*st.begin();
        st.erase(node);
        ans.push_back(dfs(node));
    }
    cout<<sz(ans)-1<<endl;
    return 0;
}


