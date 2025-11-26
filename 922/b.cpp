#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++)vec.push_back({a[i],b[i]});
        sort(all(vec));
        for(int i=0;i<n;i++)cout<<vec[i].first<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)cout<<vec[i].second<<" ";
        cout<<endl; 
    }
    return 0;
}


