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
        int n,x,y,a,b;
        cin>>n>>x>>y>>a>>b;
        x=min(x,n-x+1);
        a=min(a,n-a+1);
        y=min(y,n-y+1);
        b=min(b,n-b+1);
        int u=min(x,y);
        int v=min(a,b);
        cout<<abs(u-v)<<endl;
    }
    return 0;
}


