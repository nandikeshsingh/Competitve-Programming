#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
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
        string a,b;cin>>a>>b;
        int k=0;
        int cur=0;
        for( k=0;k<n;)
        {
            if(a[k]==b[cur])
            {
                cur++;
                k++;
            }
            else cur++;
            if(cur>=m)break;
        }
        cout<<k<<endl;
    }
    return 0;
}


