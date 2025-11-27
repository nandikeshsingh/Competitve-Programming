#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n+1),pos(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    vector<pair<int,int>>ans;
    for(int i=1;i<=n;i++)
    {
        if(i==a[i])continue;
        ans.push_back({i,pos[i]});
        int l=a[i],r=a[pos[i]];
        swap(a[i],a[pos[i]]);
        pos[l]=pos[i];

    }
    assert(sz(ans)<=n-1);
    cout<<sz(ans)<<endl;
    for(auto& u : ans)cout<<u.first<<" "<<u.second<<endl;
    return 0;
}


