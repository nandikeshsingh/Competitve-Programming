#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>>range;
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        range.push_back({v,{u,i}});
    }
    sort(all(range),[&](pair<int,pair<int,int>>&p1,pair<int,pair<int,int>>&p2){
        if(p1.first!=p2.first)return p1.first<p2.first;
        else return p1.second.first>p2.second.first;
    });
    vector<int>ans(n,0);
    set<int>st;
    for(int i=0;i<n;i++)
    {
        auto itr=st.lower_bound(range[i].second.first);
        if(itr==st.end())ans[range[i].second.second]=0;
        else ans[range[i].second.second]=1;
        st.insert(range[i].second.first);
    }
    st.clear();
    vector<int>has(n);
    for(int i=n-1;i>=0;i--)
    {
        auto itr=st.upper_bound(range[i].second.first);
        if(itr==st.begin())has[range[i].second.second]=0;
        else has[range[i].second.second]=1;
        st.insert(range[i].second.first);       
    }
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    for(auto& u : has)cout<<u<<" ";
    cout<<endl;
    return 0;
}


