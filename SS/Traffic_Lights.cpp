#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int x,n;
    cin>>x>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    multiset<int>ms,ans;
    ms.insert(0);
    ms.insert(x);
    ans.insert(x);
    for(int i=0;i<n;i++)
    {
        auto itr=ms.upper_bound(p[i]);
        int cur=*itr-*prev(itr);
        ans.erase(ans.find(cur));
        ans.insert(*itr-p[i]);
        ans.insert(p[i]-*prev(itr));
        ms.insert(p[i]);
        cout<<*prev(ans.end())<<" ";
    }
    
    return 0;
}


