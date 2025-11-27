#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    string s;cin>>s;
    set<string>st;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        
        for(int j=i;j<len;j++)
        {
            string ss;
            for(int k=i;k<=j;k++)
            {
                ss+=s[k];
            }
            st.insert(ss);
        }
    }
    cout<<sz(st)<<endl;
    return 0;
}


