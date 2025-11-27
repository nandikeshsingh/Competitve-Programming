#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
char vec[50][50];
int n;
int k,m,cnt; 
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low;
int timer;
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                cnt++;
            ++children;
        }
    }
    if(p == -1 && children > 1)
        cnt++;
}
void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
int get_id(int i,int j)
{
    return i*m+j;
}
bool is_valid(int i,int j)
{
    if(i>=0 && i<k && j>=0 && j<m)return 1;
    else return 0;
}
signed main()
{
    speed;
    cin>>k>>m;
    int tot=0;
    for(int i=0;i<k;i++)for(int j=0;j<m;j++)cin>>vec[i][j];
    adj.resize(k*m);
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vec[i][j]=='#')
            {
                tot++;
                for(auto& u : dir)
                {
                    int ni=i+u.first;
                    int nj=j+u.second;
                    if(is_valid(ni,nj) && vec[ni][nj]=='#')
                    {
                        adj[get_id(i,j)].push_back(get_id(ni,nj));
                    }
                }
            }
        }
    }
    n=k*m;
    find_cutpoints();
    if(tot<=2)cout<<-1<<endl;
    else if(cnt>=1)cout<<1<<endl;
    else cout<<2<<endl;
    return 0;
}


