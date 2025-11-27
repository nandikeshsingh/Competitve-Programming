#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    string s;
    cin>>s;
    sort(all(s));
    vector<string>ans;
    do
    {
        ans.push_back(s);
    }while(next_permutation(all(s)));
    cout<<ans.size()<<endl;
    for(auto& u : ans)cout<<u<<endl;
    return 0;
}


