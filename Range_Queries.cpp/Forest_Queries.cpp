#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,q;
    cin>>n>>q;
    vector<vector<int>>f(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char c;
            cin>>c;
            if(c=='*')f[i][j]=1;
            f[i][j]+=f[i][j-1];
        }
    }
    for(int j=1;j<=n;j++)
    for(int i=1;i<=n;i++)
    f[i][j]+=f[i-1][j];
    while(q--)
    {
        int y1,x1,y2,x2;
        cin>>x1>>y1>>x2>>y2;
        cout<<f[x2][y2]-f[x2][y1-1]-f[x1-1][y2]+f[x1-1][y1-1]<<endl;
    }
    return 0;
}


