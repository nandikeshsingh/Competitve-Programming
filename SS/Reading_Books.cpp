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
    vector<int>t(n);
    int tot=0;
    for(int i=0;i<n;i++)cin>>t[i],tot+=t[i];
    sort(all(t));
    if(t[n-1]>tot-t[n-1])cout<<2*t[n-1]<<endl;
    else cout<<tot<<endl;
    // cout<<max(tot,2*t[n-1])<<endl;
    return 0;
}


