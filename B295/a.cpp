#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    bool ok=0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(s=="and" || s=="not" || s=="that" || s=="the" || s=="you")
        ok=1;
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


