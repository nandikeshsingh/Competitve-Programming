#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
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

	void unite(int u, int v)
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
DSU D;
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    D.init(n);
    vector<pair<int,int>>a;
    vector<int>val(n+1);
    for(int i=1;i<=n;i++)
    {
        int v;cin>>v;
        val[i]=v;
        a.push_back({v,i});
    }
    multiset<pair<int,pair<int,int>>>mst;
    for(int i=0;i<m;i++)
    {
        int u,v,c;cin>>u>>v>>c;
        if(c<val[u]+val[v])
        mst.insert({c,{u,v}});
    }
    sort(all(a));
    int ans=0,i=1;
    while(D.connected>1)
    {
        if(sz(mst)==0 || a[i].first+a[0].first<mst.begin()->first)
        {
            if(D.getPar(a[i].second)!=D.getPar(a[0].second))
            {
                ans+=a[i].first+a[0].first;
                D.unite(a[i].second,a[0].second);
            }
            i++;
        }
        else 
        {
            if(D.getPar(mst.begin()->second.first)!=D.getPar(mst.begin()->second.second))
            {
                ans+=mst.begin()->first;
                D.unite(mst.begin()->second.first,mst.begin()->second.second);
            }
              mst.erase(mst.begin());
        }
    }
    cout<<ans<<endl;
    return 0;
}


