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
        if(n==1)cout<<0<<endl;
        else 
        {
            reverse(all(s));
            while(s.back()=='0')s.pop_back();
            if((int)s.length()==0)cout<<0<<endl;
            else 
            {
                 reverse(all(s));
                int ans=0;
                for(int i=1;i<(int)s.length();i++)
                {
                    if(s[i]!=s[i-1])ans++;
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}


