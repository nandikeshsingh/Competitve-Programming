#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define for(i,n)   for(int i=0;i<(n);++i)
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
        string s;
        cin>>s;
        int cnt=0;
        for(i,n)cnt+=(s[i]=='U');
        if(n&1)
        {
            if(cnt&1)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else
        {
            if(cnt%2==0)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}


