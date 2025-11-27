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
    multiset<int>ms;
    for(int i=1;i<=n;i++)ms.insert(i);
    vector<int>ans;
    auto itr=ms.begin();
    while((int)ms.size()>0)
    {
        auto nxt=next(itr);
        if(nxt==ms.end())nxt=ms.begin();
        ans.push_back(*nxt);
        ms.erase(nxt);
        itr=next(itr);
        if(itr==ms.end())itr=ms.begin();
    }
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}


