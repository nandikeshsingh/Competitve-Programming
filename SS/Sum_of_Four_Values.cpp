#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++)
    {
        int c;cin>>c;
        vec.push_back({c,i+1});
    }
    sort(all(vec));
    // unordered_map<int,pair<int,int>>mp;
    // mp.reserve(1<<20);
    map<int,pair<int,int>>mp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(mp.count(x-vec[i].first-vec[j].first))
            {
                pair<int,int>p=mp[x-vec[i].first-vec[j].first];
                cout<<vec[i].second<<" "<<vec[j].second<<" "<<p.first<<" "<<p.second<<endl;
                return 0;
            }
        }
        for(int j=0;j<i;j++)
        {
            mp[vec[i].first+vec[j].first]={vec[i].second,vec[j].second};
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}


