#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int maxn=2e5+5;
vector<int>parent(maxn+1,0);
vector<int>sz(maxn+1,0);
vector<pair<int,int>>edges;
vector<int>cycle(3);
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
bool check(vector<int>&vec)
{
    set<int>st;
    for(int i=0;i<3;i++)
    {
        st.insert(edges[cycle[i]].first);
        st.insert(edges[cycle[i]].second);
    }
    if((int)st.size()>=4)return 0;
    else return 1;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++)make_set(i);
        edges.clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            edges.push_back({u,v});
        }
        string ans;
        for(int i=0;i<m;i++)ans+='1';
        if(m==n-1)
        {
            ans[0]='0';
            cout<<ans<<endl;
        }
        else
        {
            for(int i=0;i<m;i++)
            {
                int u=edges[i].first;
                int v=edges[i].second;
                if(find_set(u)==find_set(v))
                {
                    ans[i]='0';
                }
                union_sets(u,v);
            }
            if(m<=n+1)
            cout<<ans<<endl;
            else 
            {
                
                int j=0;
                for(int i=0;i<m;i++)
                {
                    if(ans[i]=='0')
                    cycle[j++]=i;
                }
                if(!check(cycle))
                {
                    cout<<ans<<endl;
                }
                else 
                {
                    ans[cycle[2]]='1';
                    for(int i=0;i<m;i++)
                    {
                        if(ans[i]=='0')continue;
                        cycle[2]=i;
                        if(!check(cycle))
                        {
                            ans[i]='0';
                            break;
                        }
                    }
                    ans[cycle[2]]='0';
                    cout<<ans<<endl;
                }
            }
        }
    }
    return 0;
}