#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,t;
    cin>>n>>t;
    vector<int>a(n+1,0);
    map<int,int>mp;
    for(int i=1;i<=n;i++)mp[0]++;
    for(int i=1;i<=t;i++)
    {
        int p,b;cin>>p>>b;
        mp[a[p]]--;
        if(mp[a[p]]==0)mp.erase(a[p]);
        a[p]+=b;
        mp[a[p]]++;
        cout<<sz(mp)<<endl;
    }
    return 0;
}


