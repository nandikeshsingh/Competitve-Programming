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
        int n,m;
        cin>>n>>m;
        set<int>row,col;
        for(int i=0;i<m;i++)
        {
            int r,c;
            cin>>r>>c;
            row.insert(r);
            col.insert(c);
        }
        bool ok=0;
        for(int i=1;i<=n;i++)
        {
            if(row.count(i)==0)
            {
                ok=1;
                break;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(col.count(i)==0)
            {
                ok=1;
                break;
            }
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


