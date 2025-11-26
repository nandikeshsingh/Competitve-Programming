#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s;
        cin>>s;
        string ans;
        for(int i=n-1;i>=0;)
        {
            if(s[i]=='0')
            {
                char x=s[i-2];
                char y=s[i-1];
                string str;
                str+=x;str+=y;
                int val=stoi(str);
                ans+=('a'+val-1);
                i-=3;
            }
            else 
            {
                string str;
                str+=s[i];
                 int val=stoi(str);
                ans+=('a'+val-1);
                i--;
            }
        }
        reverse(all(ans));
        cout<<ans<<endl;
    }
    return 0;
}


