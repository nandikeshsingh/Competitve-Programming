#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+5;
int n;
vector<int>white,black;
vector<int>gp[maxn];
void dfs(int node,int par)
{
    white[node]=1;
    black[node]=1;
    for(auto& c : gp[node])
    {
        if(c!=par)
        {
            dfs(c,node);
            white[node]*=((white[c]+black[c])%mod);
            white[node]%=mod;
            black[node]*=white[c];
            black[node]%=mod;
        }
    }
}
signed main()
{
    speed;
    cin>>n;
    white.resize(n+1);
    black.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    if(n==1)
    {
        cout<<2<<endl;
        return 0;
    }
    dfs(1,-1);
    cout<<(white[1]+black[1])%mod<<endl;
}