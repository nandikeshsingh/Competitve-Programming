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
    string f,b;
    while (s.back()!='|')
    {
        b+=s.back();
        s.pop_back();
    }
    reverse(all(b));
    reverse(all(s));
        while (s.back()!='|')
    {
        f+=s.back();
        s.pop_back();
    }
    cout<<f+b<<endl;
    return 0;
}


