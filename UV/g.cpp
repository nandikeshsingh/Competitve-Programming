#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int h,w;
char vec[1000][1000];
int f[1000][1000];
bool vis[1000][1000];
const int mod=998244353;
int binpow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b>>=1;
		a=(a*a)%m;
	}
	return ans;
}
void floodfill(int i,int j,int val)
{
    if(i<0 || j<0 || i>=h || j>=w)return;
    if(vis[i][j])return;
    if(vec[i][j]=='.')return;
    vis[i][j]=1;
    f[i][j]=val;
    floodfill(i+1,j,val);
    floodfill(i-1,j,val);
    floodfill(i,j+1,val);
    floodfill(i,j-1,val);
}
bool isok(int i,int j)
{
    if(i>=0 && i<h && j>=0 && j<w)return 1;
    else return 0;
}
int get_id(int i,int j)
{
    return i*w+j;
}
map<int,int>mp;
int n; 
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
                mp[v]++;
            ++children;
        }
    }
    if(p == -1)
        mp[v]+=(children-1);
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
signed main()
{
    speed;
    cin>>h>>w;
    int tot=0;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>vec[i][j],tot+=(vec[i][j]=='#');
    int cnt=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(vec[i][j]=='.')continue;
            if(!vis[i][j])
            {
                cnt++;
                floodfill(i,j,cnt);
            }
        }   
    }
    adj.resize(h*w);
    vector<pair<int,int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {   
            if(vec[i][j]=='#')
            {
                for(auto u : dir)
                {
                    int ni=i+u.first;
                    int nj=j+u.second;
                    if(isok(ni,nj) && vec[ni][nj]=='#')
                    {
                        adj[get_id(i,j)].push_back(get_id(ni,nj));
                    }
                }
            }
        }
    }
    n=h*w;
    find_cutpoints();
    int sum=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(vec[i][j]=='#')
            {
                sum+=(cnt+mp[get_id(i,j)]);
            }
        }
    }
    int ans=binpow(tot,mod-2,mod);
    ans=(ans*(sum%mod))%mod;
    cout<<ans<<endl;
    return 0;
}


