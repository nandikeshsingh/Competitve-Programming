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
    vector<int>p(n+1,0);
    vector<int>pos(n+1,0);
    for(int i=1;i<=n;i++)cin>>p[i],pos[p[i]]=i;
    int q;cin>>q;
    while(q--)
    {
        int a,b;cin>>a>>b;
        if(pos[a]<pos[b])cout<<a<<endl;
        else cout<<b<<endl;
    }
    return 0;
}


