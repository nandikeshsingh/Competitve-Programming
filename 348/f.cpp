#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    bitset<2001>arr[m][1000];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        bitset<2001> cur=0;
        for(int j=0;j<m;j++)
        {
            int a;cin>>a;
            cur^=arr[j][a];
            arr[j][a][i]=1;
        }
        ans+=cur.count();
    }
    cout<<ans<<endl;
    return 0;
}


