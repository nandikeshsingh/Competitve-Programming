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
        int v;cin>>v;
        vec.push_back({v,i+1});
    }
    sort(all(vec));
    for(int i=0;i<n;i++)
    {
        int rim=x-vec[i].first;
        int l=i+1,r=n-1;
        while(l<r)
        {
            if(vec[l].first+vec[r].first==rim)
            {
                cout<<vec[i].second<<" "<<vec[l].second<<" "<<vec[r].second<<endl;
                return 0;
            }
            else if(vec[l].first+vec[r].first>rim)r--;
            else l++;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
//try with a different idea