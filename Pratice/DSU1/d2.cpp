#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int parent[1010];
int sz[1010];
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
signed main()
{
    speed;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)make_set(i);
    set<pair<int,int>>st;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        if(find_set(u)==find_set(v))
        {
            st.insert({u,v});
        }
        else union_sets(u,v);
    }
    set<int>cm;
    for(int i=1;i<=n;i++)cm.insert(find_set(i));
    vector<int>ccm;
    for(auto& u : cm)ccm.push_back(u);
    cout<<ccm.size()-1<<endl;
    if(ccm.size()>1)
    {
        for(int i=0;i<ccm.size()-1;i++)
        {
            pair<int,int>p=*st.begin();
            st.erase(st.begin());
            cout<<p.first<<" "<<p.second<<" "<<ccm[i]<<" "<<ccm[i+1]<<endl;
        }
    }
    return 0;
}