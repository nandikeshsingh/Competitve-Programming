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
        string s;
        cin>>s;
        if(s.back()=='e')s+='s';
        else if(s.back()=='Y')
        {
            s+="es";
        }
        reverse(all(s));
        if(s.back()=='s')s+="eY";
        else if(s.back()=='e')s+='Y';
        reverse(all(s));
        bool ok=1;
        for(int i=0;i<(int)s.length();i+=3)
        {
            if(s[i]=='Y' && s[i+1]=='e' && s[i+2]=='s')continue;
            else 
            {
                ok=0;
                break;
            }
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


