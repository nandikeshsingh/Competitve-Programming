#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    set<pair<int,int>>st;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        st.insert({u,v});
    }
    cout<<"Printing set"<<endl;
    for(auto& u : st)cout<<u.first<<" "<<u.second<<endl;
    return 0;
}
