#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,m;
vector<int>tot;
struct segtree
{
  struct data
  {
	//Use required attributes
	int mn;
  
	//Default Values
	data() : mn(-1e18) {};
  };
	int N;
	vector<data> st;
	vector<bool> cLazy;//stores if this values needs to be pushed down or not.
	vector<int> lazy;//stores the value that needs to be pushed down.

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	//also consider what if data l or r has default values then what to return;
	void merge(data &cur, data &l, data &r) 
	{
		cur.mn = max(l.mn,r.mn);
	}
	
	//Handle lazy propagation appriopriately and carefully
	//might need to do cLazy[node*2] = 1-cLazy[node] if updates cancels(like flip operation);
	void propagate(int node, int L, int R)
	{
		if(L != R)//push the changes 
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node];
			lazy[node*2 + 1] = lazy[node]; 
		}
		st[node].mn = max(st[node].mn,lazy[node]);//then change the current node
		cLazy[node] = 0;
    	lazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mn = 0;//change the value as per the question.
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		data left=Query(node*2, L, M, i, j);
		data right=Query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
	}

	data pQuery(int node, int L, int R, int pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
			return st[node];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(node*2, L, M, pos);
		else
			return pQuery(node*2 + 1, M + 1, R, pos);
	}	

	void Update(int node, int L, int R, int i, int j, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	void pUpdate(int node, int L, int R, int pos, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	data query(int pos)
	{
		return pQuery(1, 0, N-1, pos);
	}

	data query(int l, int r)
	{
		return Query(1, 0, N-1, l, r);
	}

	void update(int pos, int val)
	{
		pUpdate(1, 0, N-1, pos, val);
	}

	void update(int l, int r, int val)
	{
		Update(1, 0, N-1, l, r, val);
	}
};
struct ssegtree
{
  struct data
  {
	//Use required attributes
	int mn;
  
	//Default Values
	data() : mn(1e18) {};
  };
	int N;
	vector<data> st;
	vector<bool> cLazy;//stores if this values needs to be pushed down or not.
	vector<int> lazy;//stores the value that needs to be pushed down.

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 1e18);
	}

	//Write reqd merge functions
	//also consider what if data l or r has default values then what to return;
	void merge(data &cur, data &l, data &r) 
	{
		cur.mn = min(l.mn, r.mn);
	}
	
	//Handle lazy propagation appriopriately and carefully
	//might need to do cLazy[node*2] = 1-cLazy[node] if updates cancels(like flip operation);
	void propagate(int node, int L, int R)
	{
		if(L != R)//push the changes 
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = min(lazy[node],lazy[node*2] );
			lazy[node*2 + 1] = min(lazy[node],lazy[node*2 + 1] ); 
		}
		st[node].mn = min(st[node].mn,lazy[node]);//then change the current node
		cLazy[node] = 0;
    	lazy[node] = 1e18;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mn = 1e18;//change the value as per the question.
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		data left=Query(node*2, L, M, i, j);
		data right=Query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
	}

	data pQuery(int node, int L, int R, int pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
			return st[node];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(node*2, L, M, pos);
		else
			return pQuery(node*2 + 1, M + 1, R, pos);
	}	

	void Update(int node, int L, int R, int i, int j, int val)
	{
        // cout<<"node="<<node<<" L="<<L<<" R="<<R<<" i="<<i<<" j="<<j<<" val="<<val<<endl;
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] = min(lazy[node],val);
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	void pUpdate(int node, int L, int R, int pos, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	data query(int pos)
	{
		return pQuery(1, 0, N-1, pos);
	}

	data query(int l, int r)
	{
		return Query(1, 0, N-1, l, r);
	}

	void update(int pos, int val)
	{
		pUpdate(1, 0, N-1, pos, val);
	}

	void update(int l, int r, int val)
	{
        // cout<<"got a call"<<endl;
		Update(1, 0, N-1, l, r, val);
	}
};
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        tot.clear();
        tot.resize(n+2,0);
        ssegtree s;
        s.init(n+1);
        s.build(1,0,n+1);
        // cout<<"s build done"<<endl;
        for(int i=0;i<m;i++)
        {
            int x,y;cin>>x>>y;
            s.update(x,y,x);
            // cout<<"s update done"<<endl;
            tot[x]++;
            tot[y+1]--;
        }
        for(int i=1;i<=n+1;i++)tot[i]+=tot[i-1];
        // cout<<"Printing s"<<endl;
        // for(int i=0;i<=n;i++)cout<<s.query(i).mn<<" ";
        // cout<<endl;
        segtree ss;
        vector<int>dp(n+1,0);
        ss.init(n+1);
        ss.build(1,0,n+1);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int ll=s.query(i).mn;
            if(ll==(1e18))ll=i-1;
            else ll--;
            int best=ss.query(0,ll).mn;
            dp[i]=max(dp[i],best+tot[i]);
            ss.update(i,dp[i]);
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}


