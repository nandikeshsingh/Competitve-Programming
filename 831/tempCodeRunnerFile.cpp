#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int INF = 1e18;
template<class T> bool amin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
}
template<class T> bool amax(T& a, const T& b) { 
    return a < b ? a = b, 1 : 0;
} 
vector<set<int>>gp;
vector<int>depth,val;
int cur=1;
bool cmp(int a,int b)
{
    return depth[a]<depth[b];
}
void dfs(int node,int par,int d)
{
    depth[node]=d;
    for(auto& u : gp[node])
    {
        // if(u==par)continue;
        dfs(u,node,d+1);
    }
}
void dfs1(int node,int par)
{
    for(auto& u : gp[node])
    {
        // if(u==par)continue;
        dfs1(u,node);
        val[node]=min(val[node],val[u]);
    }
    // if(gp[node].size()==1 && val[node]==1e18)val[node]=cur++;
}
// int lis(vector<int> const& a) {
//     vector<int>vec;
//     for(int i=0;i<sz(a);i++)
//     {
//         auto itr=upper_bound(all(vec),a[i]);
//         if(itr==vec.end())vec.push_back(a[i]);
//         else if(*prev(itr)==a[i])
//     }
// }
signed main()
{
    speed;
    int n;
    cin>>n;
    depth.resize(n+1);
    val.resize(n+1);
    for(int i=0;i<=n;i++)val[i]=1e18;
    vector<int>p(n+1);
    gp.resize(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
        gp[p[i]].insert(i);
        // gp[i].push_back(p[i]);
    }
    dfs(1,-1,1);
    vector<int>child;
    for(int i=1;i<=n;i++)
    {
        if(gp[i].size()==0)child.push_back(i);
    }
    sort(all(child),cmp);
    int cur=1;
    for(auto& u : child)val[u]=cur++;
    vector<int>ans;
    multiset<pair<int,int>>ms;
    for(auto & u : child)ms.insert({val[u],u});
    while (sz(ms))
    {
        // cout<<"size="<<sz(ms)<<endl;
        ans.push_back(ms.begin()->first);
        int par=p[ms.begin()->second];
        int now=ms.begin()->first;
        if(val[par]>now)val[par]=now;
        gp[par].erase(ms.begin()->second);
        ms.erase(ms.begin());
        if(gp[par].size()==0 && par!=0)ms.insert({val[par],par});
    }
    
    // dfs1(1,-1);
    // map<int,vector<int>>mp;
    // for(int i=1;i<=n;i++)
    // {
    //     mp[depth[i]].push_back(val[i]);
    // }
    // vector<int>ans;
    // for(auto itr=mp.rbegin();itr!=mp.rend();++itr)
    // {
    //     vector<int>temp=itr->second;
    //     sort(all(temp));
    //     for(auto& u : temp)
    //     ans.push_back(u);
    // }
    vector<int> lis(n + 1,INF);
    lis[0] = -INF;
    int anss = 0;
    for(int i = 0; i < n; i++){
        int ind = upper_bound(all(lis),ans[i]) - lis.begin();
        if(lis[ind - 1] <= ans[i]){
            amin(lis[ind],ans[i]);
        }
        amax(anss,ind);
    }
    cout<<anss<<endl;
    return 0;
}
