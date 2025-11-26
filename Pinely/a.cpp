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
        int n,a,b;
        cin>>n>>a>>b;
        if(a==b && a==n)cout<<"Yes"<<endl;
        else if(a+b>=n-1)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
