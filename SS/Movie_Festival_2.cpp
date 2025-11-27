#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n,k;
    cin>>n>>k;
    multiset<pair<int,int>>time;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        time.insert({b,a});
    }
    int ans=0;
    while(k-- && (int)time.size()>0)
    {
        int last=-1;
        multiset<pair<int,int>>st;
        for(auto& u : time)
        {
            if(u.second>=last)
            {
                ans++;
                last=u.first;
                st.insert(u);
            }
        }
        for(auto& u : st)time.erase(u);
    }
    cout<<ans<<endl;
    return 0;
}
