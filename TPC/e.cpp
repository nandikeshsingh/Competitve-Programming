#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,m,k;
vector<int>vec;
vector<pair<int,pair<int,int>>>edges;
vector<int>parent;//initialize this after taking the input
vector<int>sz;//initialize this after taking the input
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void merge(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
void init(int n)
{
    parent.clear();
    sz.clear();
    parent.resize(n+1);
    sz.resize(n+1);
    for(int i=1;i<=n;i++)make_set(i);
}
signed main()
{
    speed;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,{v,w}});
    }
    vec.resize(m,0);
    for(int i=0;i<n-1;i++)vec[i]=1;
    int ans=1e18;
    do
    {
        init(n);
        int cur=0;
        bool ok=1;
        for(int i=0;i<m;i++)
        {
            if(vec[i])
            {
                if(find_set(edges[i].first)==find_set(edges[i].second.first))
                {
                    ok=0;
                    break;
                }
                merge(edges[i].first,edges[i].second.first);
                cur=(cur+edges[i].second.second)%k;
            }
        }
        
        if(ok)
        {
            set<int>st;
            for(int i=1;i<=n;i++)st.insert(find_set(i));
            if(sz(st)==1)
            ans=min(ans,cur);
        }
    } while (prev_permutation(all(vec)));
    cout<<ans<<endl;
    return 0;
}


