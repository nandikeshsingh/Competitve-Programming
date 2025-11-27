#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    vector<int>ans;
    while(1)
    {
        int a;cin>>a;
        ans.push_back(a);
        if(a==0)break;
    }
    reverse(all(ans));
    for(auto& u : ans)cout<<u<<endl;
    return 0;
}


