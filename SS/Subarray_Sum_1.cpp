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
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,int>mp;
    mp[0]++;
    int cur=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cur+=a[i];
        ans+=mp[cur-x];
        mp[cur]++;
    }
    cout<<ans<<endl;
    return 0;
}


