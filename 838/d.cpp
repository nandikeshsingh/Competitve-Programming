#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    // speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x=1,y=2;
        for(int i=3;i<=n;i++)
        {
            int u,v;
            cout<<"? "<<x<<" "<<i<<endl;
            cin>>u;
            cout<<"? "<<y<<" "<<i<<endl;
            cin>>v;
            if(u>v)y=i;
            else if(v>u)x=i;
        }
        cout<<"! "<<x<<" "<<y<<endl;
        int ret;cin>>ret;
        if(ret==-1)break;
    }
    return 0;
}


