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
    if(s[0]!='<' || s.back()!='>')cout<<"No"<<endl;
    else 
    {
        s.pop_back();
        reverse(all(s));
        s.pop_back();
        bool ok=1;
        for(auto& u : s)
        {
            if(u!='=')ok=0;
        }
        cout<<(ok?"Yes":"No")<<endl;
    }
    return 0;
}


