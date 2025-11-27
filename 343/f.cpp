#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
vector<int>a;
struct segtree
{
  struct data
  {
	//Use required attributes
	int mn;
    int mx;
	//Default Values
	data() : mn(1e9),mx(0) {};
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
        if(l.mx>r.mx)
        {
            cur.mx=l.mx;
            cur.mn=max(l.mn,r.mx);
        }
        else if(l.mx<r.mx)
        {
            cur.mx=r.mx;
            cur.mn=max(l.mx,r.mn);
        }
        else 
        {
            cur.mx=l.mx;
            cur.mn=max(r.mn,l.mn);
        }
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
		st[node].mx = lazy[node];//then change the current node
        st[node].mn=0;
		cLazy[node] = 0;
    		lazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mx = a[L];//change the value as per the question.
            st[node].mn=0;
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
signed main()
{
    speed;
    int n,q;
    cin>>n>>q;
    a.resize(n,0);
    segtree ss;
    ss.init(n);
    map<int,ordered_set>mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]].insert(i);
    }
    ss.build(1,0,n-1);
    while(q--)
    {
        int t;cin>>t;
        if(t==1)
        {
            int p,x;cin>>p>>x;
            p--;
            ss.update(p,x);
            mp[a[p]].erase(p);
            a[p]=x;
            mp[a[p]].insert(p);
        }
        else if(t==2)
        {
            int l,r;cin>>l>>r;
            l--;r--;
            int v=ss.query(l,r).mn;
            cout<<mp[v].order_of_key(r+1)-mp[v].order_of_key(l)<<endl;
        }
    }
    return 0;
}


