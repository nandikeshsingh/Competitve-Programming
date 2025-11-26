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
        int n;cin>>n;
        vector<int>a(n+1,0);
        vector<vector<int>>pos(30,vector<int>(n+1,0));
        vector<int>pre_xor(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pre_xor[i]=pre_xor[i-1]^a[i];
        }
        for(int bit=0;bit<30;bit++)
        {
            for(int i=1;i<=n;i++)
            {
                pos[bit][i]=pos[bit][i-1]+(pre_xor[i]>>bit&1);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int mb=31-__builtin_clz(a[i]);
            int left=pos[mb][i-1];
            int right=pos[mb][n]-pos[mb][i-1];
            ans+=left*right;
            ans+=(i-left)*(n-i+1-right);
        }       
        cout<<ans<<endl;
    }
    return 0;
}


