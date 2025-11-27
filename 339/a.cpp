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
    string str;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]!='.')str+=s[i];
        else break;
    }
    reverse(all(str));
    cout<<str<<endl;
    return 0;
}

