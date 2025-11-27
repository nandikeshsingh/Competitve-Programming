#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
struct DSU
{
	int connected;
	vector<int> par, sz;
	void init(int n) 
	{
		par = sz = vector<int> (n + 1, 0);
		for(int i = 1; i <= n; i++)
			par[i] = i, sz[i] = 1;
		connected = n;
	}
	int getPar(int u)
	{
		while(u != par[u])
		{
			par[u] = par[par[u]];
			u = par[u];
		}
		return u;
	}
	int getSize(int u)
	{
		return sz[getPar(u)];
	}
	void merge(int u, int v)
	{
		int par1 = getPar(u), par2 = getPar(v);

		if(par1 == par2)
			return;

		connected--;

		if(sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
	}
};
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    multimap<int,vector<int>>mp;
    rep(i,1,m)
    {
        int k,c;
        cin>>k>>c;
        vector<int>vec(k);
        fo(i,k)cin>>vec[i];
        mp.insert({c,vec});
    }
    DSU D;
    D.init(n);
    int ans=0;
    for(auto& u : mp)
    {
        vector<int>vec=u.second;
        int c=u.first;
        int k=sz(vec);
        rep(i,0,k-1)
        {
            if(D.getPar(vec[0])!=D.getPar(vec[i]))
            {
                D.merge(vec[0],vec[i]);
                ans+=c;
            }
        }
    }
    if(D.connected>1)ans=-1;
    cout<<ans<<endl;
    return 0;
}


