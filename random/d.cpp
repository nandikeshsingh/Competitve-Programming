#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const int maxn=5e5+5;
vector<int>gp[maxn];
vector<pair<int,int> >depth[maxn];
vector<int> in(maxn),out(maxn);
vector<int>has(27);
string s;
int t;
inline int get(int node)
{
    return (1<<(s[node-1]-'a'));
}
void dfs(int node,int par,int h)
{
    in[node] = ++t;
    depth[h].push_back({t,depth[h].back().second^has[s[node-1]-'a']});
    for(auto& u : gp[node])
    {
        if(u==par)continue;
        else 
        {
            dfs(u,node,h+1);
        }
    }
    out[node] = ++t;
    // depth[h].push_back({t,depth[h].back().second});
}
// int findLowerBound(vector<pair<int, int> >& arr,
//                     pair<int, int>& p)
// {
//     // Given iterator points to the
//     // lower_bound() of given pair
//     int low = lower_bound(arr.begin(), arr.end(), p)-arr.begin();
//     return low;
 
//     // cout << "lower_bound() for {2, 5}"
//     //      << " is at index: " << low - arr.begin() << endl;
// }
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    vector<int>p(n-1,0);
    for(int i=1;i<=n-1;i++)
    {
        cin>>p[i];
        gp[p[i]].push_back(i+1);
        gp[i+1].push_back(p[i]);
    }
    cin>>s;
    for(int i=0;i<=n;i++)depth[i].push_back({0,0});
    for(int i=0;i<27;i++)has[i]= (1 << i);
    // cout<<"printing for checking"<<endl;
    dfs(1,-1,1);//node par depth
    // cout<<"Printing depth"<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     for(auto& u : depth[i])
    //     cout<<u.first<<" "<<u.second<<"---";
    //     cout<<endl;
    // }
    while(m--)
    {
        int v,h;
        cin>>v>>h;
        // // make_pair(in[v],-1)
        pair<int,int>p1={in[v],-1};
        pair<int,int>p2={out[v],-1};
        // int l=findLowerBound(depth[h],p1);
        // int r=findLowerBound(depth[h],p2);
        int l=lower_bound(depth[h].begin(),depth[h].end(),p1)-depth[h].begin();
        int r=lower_bound(depth[h].begin(),depth[h].end(),p2)-depth[h].begin();
        int val=depth[h][r-1].second^depth[h][l-1].second;
        // cout<<"val before="<<val<<endl;
        // val-=setBitNumber(val);
        val-=(val&(-val));
        // cout<<"val="<<val<<endl;
        if(val)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
} 

