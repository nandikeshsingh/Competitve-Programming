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
    vector<pair<int,int>>vec;
    int tot=0;
    for(int i=0;i<n;i++)
    {
        int a,d;cin>>a>>d;
        vec.push_back({a,d});
        tot+=d;
    }
    sort(all(vec));
    int ans=0;
    int cur=0;
    for(int i=0;i<n;i++)
    {
        cur+=vec[i].first;
        ans+=vec[i].second-cur;
    }
    cout<<ans<<endl;
    // int cur=n;
    // for(int i=0;i<n;i++)
    // {
    //     tot-=(cur*vec[i].first);
    //     cur--;
    // }
    // cout<<tot<<endl;
    return 0;
}


