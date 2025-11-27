#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    multiset<int>ms;
    vector<int>t(m);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ms.insert(x);
    }
    for(int i=0;i<m;i++)cin>>t[i];
    for(auto& u : t)
    {
        auto itr=ms.upper_bound(u);
        if(itr==ms.begin())cout<<-1<<endl;
        else
        {
            cout<<*prev(itr)<<endl;
            ms.erase(prev(itr));
        }
    }
    return 0;
}


