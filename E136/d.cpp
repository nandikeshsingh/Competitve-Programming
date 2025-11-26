#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int INF=1e18;
int n,k;
vector<vector<int>>gp;
vector<int>dep,p,lazy,t,euler_tour;
void dfs(int v, int par, int h) {
    euler_tour.push_back(v);
    dep[v] = h;
    for (int u : gp[v]) {
        if (u == par)
            continue;
        dfs(u, v, h + 1);
    }
    euler_tour.push_back(v);
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        dep[t[v]] = dep[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        if(dep[t[2*v]]>dep[t[2*v+1]])
        t[v]=t[2*v];
        else t[v]=t[2*v+1];
    }
}
void push(int v) {
    dep[t[v*2]] += dep[lazy[v]];
    dep[lazy[v*2]] += dep[lazy[v]];
    dep[t[v*2+1]] += dep[lazy[v]];
    dep[lazy[v*2+1]] += dep[lazy[v]];
    dep[lazy[v]] = 0;
}
void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        dep[t[v]] += addend;
        dep[lazy[v]] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        if(dep[t[2*v]]>dep[t[2*v+1]])
        t[v]=t[2*v];
        else t[v]=t[2*v+1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    int p1=query(v*2, tl, tm, l, min(r, tm));
    int p2=query(v*2+1, tm+1, tr, max(l, tm+1), r);
    if(dep[p1]>dep[p2])
    return p1;
    else return p2;
}

signed main()
{
    speed;
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>n>>k;
        dep.resize(n+1);
        gp.resize(n+1,vector<int>(0));
        p.resize(n+1);
        lazy.resize(n+1);
        t.resize(4*n+4);
        for(int i=2;i<=n;i++)
        {
            cin>>p[i];
            p[i]--;
            gp[i-1].push_back(p[i]);
            gp[p[i]].push_back(i-1);
        }
        p[0]=-1;
        cout<<"1"<<endl;
        dfs(1,-1,0);
        cout<<"2"<<endl;
        build(1,0,n-1);
        cout<<"3"<<endl;
        map<int,vector<int>>mp;
        for(int i=0;i<2*n-1;i++)
        {
            mp[euler_tour[i]].push_back(i);
        }
        vector<vector<int>>anc(19,vector<int>(n+1));
        for(int i=0;i<=18;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==0)anc[i][j]=p[j];
                else 
                {
                    if(anc[i-1][j]>=1)
                    anc[i][j]=anc[i-1][anc[i-1][j]];
                    else anc[i][j]=-1;
                }
            }
        }
        cout<<"4"<<endl;
        while(k--)
        {
            cout<<"k="<<k<<endl;
            int pos=query(1,0,n-1,0,n-1);
            cout<<"pos="<<pos<<endl;
            int jump=dep[pos]/2;
            while(jump)
            {
                int last=(jump&(-jump));
                jump-=last;
                pos=anc[log2(last)][pos];
                if(pos==-1)break;
            }
            cout<<"out"<<endl;
            update(pos,0,n-1,mp[euler_tour[pos]][0],mp[euler_tour[pos]][1],-dep[pos]);
            cout<<"done"<<endl;
        }
        cout<<dep[query(1,0,n-1,0,n-1)]<<endl;
    }
    return 0;
}


