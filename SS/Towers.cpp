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
    vector<int>k(n);
    for(int i=0;i<n;i++)cin>>k[i];
    multiset<int>towers;
    for(int i=0;i<n;i++)
    {
        auto itr=towers.upper_bound(k[i]);
        if(itr!=towers.end())towers.erase(itr);;
        towers.insert(k[i]);
    }
    cout<<towers.size()<<endl;
    return 0;
}

