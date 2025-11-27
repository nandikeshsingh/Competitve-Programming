#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int n,m;
vector<int>parent;
vector<int>sz;
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
        {
            swap(a, b);
        }

        parent[b] = a;
        sz[a] += sz[b];
    }
}
signed main()
{
    speed;
    cin>>n>>m;
    parent.resize(n+1,0);
    sz.resize(n+1,0);
    for(int i=0;i<=n;i++)make_set(i);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        merge(u,v);
    }
    set<int>st;
    for(int i=1;i<=n;i++)
    {
        st.insert(find_set(i));
    }
    cout<<st.size()-1<<endl;
    vector<int>ans;
    for(auto& u : st)ans.push_back(u);
    for(int i=1;i<(int)ans.size();i++)
    cout<<ans[i]<<" "<<ans[i-1]<<endl;
    return 0;
}


