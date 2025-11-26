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
        int n;
        cin>>n;
        vector<int>x(n+1);
        int sum=0;
        rep(i,2,n)
        {
            cin>>x[i];
            sum+=x[i];
        }
        vector<int>ans(n+1);
        int cur=1e9;
        int j=n;
        per(i,n,2)
        {
            ans[j]=cur;
            j--;
            cur-=x[i];
        }
        ans[j]=cur;
        rep(i,1,n)cout<<ans[i]<<" ";
        cout<<endl;
        bool ok=1;
        rep(i,2,n)
        {
            if(x[i]!=ans[i]%ans[i-1])ok=0;
        }
        assert(ok==1);

    }
    return 0;
}


