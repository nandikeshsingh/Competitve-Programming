vector<int>parent;//initialize this after taking the input
vector<int>sz;//initialize this after taking the input
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void merge(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
void init(int n)//n is the size of the input(graph)
{
    parent.clear();
    sz.clear();
    parent.resize(n+1);
    sz.resize(n+1);
    for(int i=1;i<=n;i++)make_set(i);
}

//Struct for DSU
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
