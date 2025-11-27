#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++)
    {
        int c;cin>>c;
        a.push_back({c,i+1});
    }
    sort(all(a));
    int l=0,r=n-1;
    while(l<r)
    {
        if(a[l].first+a[r].first<x)l++;
        else if(a[l].first+a[r].first>x)r--;
        else 
        {
            cout<<a[l].second<<" "<<a[r].second<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;

    return 0;
}


