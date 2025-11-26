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
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool ok;
        if(s[0]=='1')
         ok=0;
        else ok=1; 
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')cout<<"+";
            else 
            {
                if(ok)cout<<"+";
                else cout<<"-";
                ok=1-ok;
            }
        }
        cout<<endl;
    }
    return 0;
}


