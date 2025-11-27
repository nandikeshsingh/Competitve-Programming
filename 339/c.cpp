#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>vec(n+1,0);
    int mn=1e18;
    for(int i=1;i<=n;i++)cin>>vec[i],vec[i]+=vec[i-1],mn=min(mn,vec[i]);
    if(mn<0)mn*=-1;
    else mn=0;
    cout<<mn+vec[n]<<endl;

    return 0;
}


