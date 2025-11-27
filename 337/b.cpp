#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    string s;
    cin>>s;
    bool ok=1;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]<s[i-1])
        {
            ok=0;
            break;
        }
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


