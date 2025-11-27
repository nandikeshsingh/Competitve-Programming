#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a<=l)cout<<l<<endl;
        else if(r>=a)cout<<r<<endl;
        else cout<<a<<endl;
    }
    return 0;
}


