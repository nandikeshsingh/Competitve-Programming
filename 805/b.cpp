#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
        int ans=0;
        set<char>st;
        for(int i=0;i<s.length();)
        {
            if(st.size()==3 && st.find(s[i])==st.end())
            {
                st.clear();
                ans++;
            }
            else st.insert(s[i++]);
        }
        if(st.size()>0)ans++;
        cout<<ans<<endl;
    }
    return 0;
}

