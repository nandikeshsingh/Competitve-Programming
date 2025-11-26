#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
bool cmp(string s1,string s2)
{
    return (int)s1.length()<(int)s2.length();
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string>s;
        for(int i=0;i<2*n-2;i++)
        {
            string ss;
            cin>>ss;
            s.push_back(ss);
        }
        sort(all(s),cmp);
        bool ok=1;
        for(int i=1;i<sz(s);i+=2)
        {
            if(s[i][0]!=s[i-1].back() || s[i-1][0]!=s[i].back())
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


