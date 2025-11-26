#include<bits/stdc++.h>
// #define int long long
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
        string s;
        cin>>s;
        int n=(int)s.length();
        map<char,vector<int>>mp;
        map<char,int>al;
        for(int i=0;i<26;i++)al[i+'a']=i+1;
        for(int i=0;i<n;i++)mp[s[i]].push_back(i);
 
        multiset<char>st;
        for(auto& u : s)st.insert(u);
 
 
        vector<int>ans;
        int tot=0;
        char last=s[0];
        if(s[0]<s[n-1])
        {
            for(char i=s[0];i<=s[n-1];i++)
            {
                for(auto& u : mp[i])
                {

                    ans.push_back(u);
                }
                    tot+=(abs(al[i]-al[last]));
                    last=i;   
            }
        }
        else 
        {
            for(char i=s[0];i>=s[n-1];i--)
            {
                for(auto& u : mp[i])
                {
 
                    ans.push_back(u);
                }
                    tot+=(abs(al[i]-al[last]));
                    last=i;  
            }          
        }
        cout<<tot<<" "<<ans.size()<<endl;
        for(auto& u : ans)cout<<u+1<<" ";
        cout<<endl;
    }
    return 0;
}
