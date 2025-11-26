#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
pair<int,int>get(int i,int v,int n)
{
    if(v==0)return {i+1,n};
    else 
    {
        int x=i/(v+1);
            return {x+1,i/v};
    }
}
bool cmp(pair<pair<int,int>,int>&p1 ,pair<pair<int,int>,int>&p2)
{
    if(p1.first!=p2.first)return p1.first<p2.first;
    else return p1.second<p2.second;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>b(n+1),a(n+1);
        // vector<pair<pair<int,int>,int>>range;
        vector<int>arr[n+1];
        vector<int>L(n+1),R(n+1);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            // range.push_back({get(i,b[i],n),i});
            pair<int,int>p=get(i,b[i],n);
            arr[p.first].push_back(i);
            L[i]=p.first;
            R[i]=p.second;
        }
        // cout<<"Printing l and r"<<endl;
        // for(int i=1;i<=n;i++)
        // cout<<L[i]<<" "<<R[i]<<endl;
        // cout<<"Printing arr"<<endl;
        // for(int i=1;i<=n;i++)
        // {
        //     for(auto& u : arr[i])
        //     cout<<u<<" ";
        //     cout<<endl;
        // }
        // sort(range.begin(),range.end(),cmp);
        vector<int>ans(n+1);
        set<pair<int,int>>st;
        for(int i=1;i<=n;i++)
        {
            for(auto& u : arr[i])
                st.insert({R[u],u});
            ans[st.begin()->second]=i;
            st.erase(st.begin());
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
