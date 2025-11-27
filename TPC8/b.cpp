#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    string s,t;
    cin>>s>>t;
    if(s[0]>s[1])swap(s[0],s[1]);
    if(t[0]>t[1])swap(t[0],t[1]);
    int x=s[1]-s[0];
    x=min(x,5-x);
    int y=t[1]-t[0];
    y=min(y,5-y);
    if(x==y)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


