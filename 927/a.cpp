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
        int ans=0;
        for(int i=1;i<n;)
        {
            if(s[i]!='*')
            {
                if(s[i]=='@')ans++;
                i++;
            }
            else 
            {
                if(i+1<n && s[i+1]=='*')break;
                else i++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


