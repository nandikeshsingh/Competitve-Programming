#include<bits/stdc++.h>
using namespace std;
// #define int long long
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        set<int>st,all;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            --u,--v;
            st.insert(v);
        }
        for(int i=0;i<n;i++)all.insert(i);
        for(int i=0;i<n;i++)
        {
            if(st.find(i)==st.end())all.erase(i);
        }
        cout<<"Case #"<<c<<": "<<all.size()<<endl;
    }
    return 0;
}