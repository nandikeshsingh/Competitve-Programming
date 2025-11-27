#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define int long long
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int m,n,p;
        cin>>m>>n>>p;
        vector<vector<int>>vec(m+1,vector<int>(n));
        vector<int>best(n,0);
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>vec[i][j];
                best[j]=max(best[j],vec[i][j]);
            }
        }
        int ans=0;
        for(int j=0;j<n;j++)ans+=abs(best[j]-vec[p][j]);
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
    return 0;
}