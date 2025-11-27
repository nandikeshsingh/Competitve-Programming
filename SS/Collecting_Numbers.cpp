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
    vector<pair<int,int>>x;
    for(int i=0;i<n;i++)
    {
        int v;
        cin>>v;
        x.push_back({v,i});
    }
    int ans=0;
    sort(all(x));
    // cout<<"Printing x"<<endl;
    // for(auto& u : x)cout<<u.first<<" "<<u.second<<endl;
    for(int i=1;i<n;i++)
    {
        if(x[i].second<x[i-1].second)ans++;
    }
    cout<<ans+1<<endl;
    
    return 0;
}


