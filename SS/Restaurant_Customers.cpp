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
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        vec.push_back({a,1});
        vec.push_back({b,-1});
    }
    sort(all(vec));
    int ans=0;
    int cur=0;
    for(auto& u : vec)
    {
        if(u.second==1)cur++;
        else cur--;
        ans=max(cur,ans);
    }
    cout<<ans<<endl;
    
    return 0;
}


