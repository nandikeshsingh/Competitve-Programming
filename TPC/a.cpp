#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,x;
    cin>>n>>x;
    vector<int>vec(n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
        if(vec[i]<=x)ans+=vec[i];
    }
    cout<<ans<<endl;
    return 0;
}


