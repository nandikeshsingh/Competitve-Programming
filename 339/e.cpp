#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int maxn=1e6+10;
int n, t[4*maxn];
int d;
vector<int>a;
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = 0;
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = max(t[v*2] ,t[v*2+1]);
    }
}
int query(int v, int tl, int tr, int l, int r) {
    if(l>tr || r<tl)return 0;
    if (l<= tl && r >= tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    int p1=query(v*2, tl, tm, l, r);
    int p2=query(v*2+1, tm+1, tr, l, r);
    return max(p1,p2);
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2] , t[v*2+1]);
    }
}
signed main()
{
    speed;
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.push_back(x);
    }
    build(1,0,maxn-1);
    vector<int>best(n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int lo=max(a[i]-d,0LL);
        int hi=a[i]+d;
        best[i]=1+query(1,0,maxn-1,lo,hi);
        update(1,0,maxn-1,a[i],best[i]);
        ans=max(ans,best[i]);
    }
    cout<<ans<<endl;
    return 0;
}


