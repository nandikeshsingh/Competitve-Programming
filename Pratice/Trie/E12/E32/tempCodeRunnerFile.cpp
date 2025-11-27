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
const int M=(2e5+1)*30;
const int A=2;
typedef struct Trie
{
	typedef struct node
	{
		node* nxt[2];
		int cnt = 0;
 
		node()
		{
			nxt[0] = nxt[1] = NULL;
			cnt = 0;
		}
 
	}Node;
 
	Node* head;
 
	Trie() { head = new Node(); }
 
	void add(int x)
	{
		Node* cur = head;
		for(int i = 30; i >= 0; i--)
		{
			int b = (x >> i) & 1;
			if(!cur -> nxt[b])
				cur -> nxt[b] = new Node();
			cur = cur -> nxt[b];
			cur -> cnt++;
		}
	}
 
	void remove(int x)
	{
		Node* cur = head;
		for(int i = 30; i >= 0; i--)
		{
			int b = (x >> i) & 1;
			cur = cur -> nxt[b];
			cur -> cnt--;
		}
	}
 
	int getmin_xor(int x)
	{
		Node* cur = head;
		int ans = 0;
		for(int i = 30; i >= 0; i--)
		{
			int b = (x >> i) & 1;
			if(cur -> nxt[b] && cur -> nxt[b] -> cnt > 0)
			{
				cur = cur -> nxt[b];
			}
			else
            {
                ans += (1LL << i);
                cur = cur -> nxt[!b];
            }
				
		}
		return ans;
	}
};
DSU D;
Trie T;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n+1);
    D.init(n);
    map<int,set<int>>rmp;
    for(int i=1;i<=n;i++)cin>>a[i],T.add(a[i]),rmp[a[i]].insert(i);
    // cout<<T.getmin_xor(6)<<endl;
    int ans=0;
    while(D.connected>1)
    {
        vector<pair<int,int>>mp(n+1);
        vector<vector<int>>comp(n+1,vector<int>(0));
        for(int i=1;i<=n;i++)comp[D.getPar(i)].push_back(i),mp[i]={1e18,-1};
        for(int i=1;i<=n;i++)
        {
            for(auto& v : comp[i])
            T.remove(a[v]),rmp[a[v]].erase(v);
            for(auto& v : comp[i])
            {
                int mn=T.getmin_xor(a[v]);
                int a_node=a[v]^mn;
                int p1=i;
                int p2=D.getPar(*rmp[a_node].begin());
                assert(p1!=p2);
                if(p1!=p2)
                {
                    {
                        if(mp[p1].first>mn)mp[p1]={mn,p2};
                    }
                }
            }
            for(auto& v : comp[i])T.add(a[v]),rmp[a[v]].insert(v);
        }
        for(int i=1;i<=n;i++)
        {
            int p1=i;
            int p2=mp[i].second;
			if(p2==-1)continue;
            if(p1!=p2)
            {
                D.unite(p1,p2);
                ans+=mp[i].first;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}