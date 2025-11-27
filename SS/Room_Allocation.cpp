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
    vector<pair<int,pair<int,int>>>vec;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        vec.push_back({b,{a,i}});
    }
    sort(all(vec));
    vector<int>ans(n);
    set<pair<int,int>>st;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        auto itr=st.lower_bound({vec[i].second.first,-1});
        if(itr==st.begin())
        {
            cnt++;
            ans[vec[i].second.second]=cnt;
            st.insert({vec[i].first,cnt});
        }
        else 
        {
            itr=prev(itr);        
            int val=itr->second;
            ans[vec[i].second.second]=val;
            st.erase(itr);
            st.insert({vec[i].first,val});
        }
    }
    cout<<cnt<<endl;
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}
