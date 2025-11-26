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
        string s;cin>>s;
        int cnt=0;
        int pos=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                pos=i;
                break;
            }
        }
        int ans=0;
        for(int i=pos;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                cnt++;
            }
            else 
            {
                ans+=(cnt+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


