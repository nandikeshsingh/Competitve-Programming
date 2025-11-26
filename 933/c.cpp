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
        string s;cin>>s;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='p')
            {
                string l,r;
                if(i>=2)
                {
                    l+=s[i-2];
                    l+=s[i-1];
                    l+=s[i];
                }
                if(i+2<n)
                {
                    r+=s[i];
                    r+=s[i+1];
                    r+=s[i+2];
                }
                if(l=="map"||r=="pie")ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


