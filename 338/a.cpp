#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    string s;cin>>s;
    bool ok=1;
    for(int i=0;i<s.length();i++)
    {
        if(i==0)
        {
            if(s[i]>='A' && s[i]<='Z')continue;
            else ok=0;
        }
        else 
        {
            if(s[i]>='a' && s[i]<='z')continue;
            else ok=0;
        }
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


