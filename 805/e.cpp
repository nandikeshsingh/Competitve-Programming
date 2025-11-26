#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<vector<int>>gp;
vector<int>col;
int n;
bool is_bipartite()
{
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 1; st <= n; ++st) {
        if (col[st] == -1) {
            q.push(st);
            col[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : gp[v]) {
                    if (col[u] == -1) {
                        col[u] = col[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= col[u] != col[v];
                    }
                }
            }
        }
    }
    return is_bipartite; return 
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        gp.clear();
        col.clear();
        gp.resize(n+1,vector<int>(0));
        col.resize(n+1,-1);
        vector<int>cnt(n+1,0);
        for(int i=0;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            cnt[u]++;
            cnt[v]++;
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]!=2)ok=0;
        }
        cout<<((is_bipartite()&ok)?"YES":"NO")<<endl;
    }
    return 0;
}