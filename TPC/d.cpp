#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    string s;
    cin>>s;
    stack<char>st;
    int cnt=0;
    int n=(int)s.length();
    for(int i=0;i<n;i++)
    {
        st.push(s[i]);
        if(s[i]=='C' && (int)st.size()>=3)
        {
            int c=st.top();st.pop();
            int b=st.top();st.pop();
            int a=st.top();st.pop();
            if(a=='A' && b=='B' && c=='C')continue;
            else 
            {
                st.push(a);st.push(b);st.push(c);
            }
        }
    }
    string ans;
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(all(ans));
    cout<<ans<<endl;
    return 0;
}


