#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mxN=50010;
int parent[mxN]; //map<ll,ll> parent;
int siz[mxN];    //map<ll,ll> siz;
void make_set(int v) {
    parent[v]=v; siz[v]=1;
}
int find_set(int v) {
    return (v==parent[v])?v:parent[v]=find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if(siz[a]<siz[b]) swap(a,b);
    parent[b] = a;
    siz[a]+=siz[b]; 
    siz[b]=0; //siz.erase(b);
}
int get_size(int v){
    return siz[find_set(v)];
}
signed main()
{
    speed;
    int n,m,k;
    cin>>n>>m>>k;
    set<pair<int,int>>edges;
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        edges.insert({u,v});
    }
    vector<pair<string,pair<int,int>>>query;
    for(int i=0;i<k;i++)
    {
        string s;
        int u,v;
        cin>>s>>u>>v;
        query.push_back({s,{u,v}});
    }
    reverse(query.begin(),query.end());
    for(int i=1;i<=n;i++)make_set(i);
    vector<string>ans;
    for(auto& u : query)
    {
        if(u.first=="ask")
        {
            if(find_set(u.second.first)==find_set(u.second.second))
            ans.push_back("YES");
            else ans.push_back("NO");
        }
        else 
        {
            if((edges.find({u.second.first,u.second.second})!=edges.end()) || (edges.find({u.second.second,u.second.first})!=edges.end()) )
            union_sets(u.second.first,u.second.second);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto& u  : ans)cout<<u<<endl;
    return 0;
}
