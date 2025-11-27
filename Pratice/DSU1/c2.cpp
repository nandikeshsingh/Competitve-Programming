#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    string s;
    cin>>s;
    stack<int>st;
    vector<int>cnt(1e6+10,0);
    for(int i=0;i<s.length();i++)
    {
        if(st.empty())
        {
            st.push(i);
        }
        else 
        {
            if(s[i]=='(')st.push(i);
            else 
            {
                if(s[st.top()]=='(')
                {
                    
                    st.pop();
                    if(!st.empty())
                    cnt[i-st.top()]++;
                    else cnt[i+1]++;
                }
                else st.push(i);
            }
        }
    }
    int mx=-1;
    int val=-1;
    for(int i=0;i<=s.length();i++)
    {
        if(cnt[i]>0)
        {
            mx=cnt[i];
            val=i;
        }
    }
    if(val==-1)val=0,mx=1;
    cout<<val<<" "<<mx<<endl;
    return 0;
}