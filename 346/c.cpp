#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,k;
    cin>>n>>k;
    int tot=(k*(k+1))/2;
    set<int>st;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        st.insert(x);
    }
    for(auto& u : st)
    {
        if(u<=k)tot-=u;
    }
    cout<<tot<<endl;
    return 0;
}


