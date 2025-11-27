#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int get(char c1,char c2)
{
    string s;
    s+=c1;
    s+=c2;
    if(s=="BA")return 0;
    else if(s=="AB")return 1;
    else if(s=="BB")return 2;
    else if(s=="AA")return 3;
}
signed main()
{
    speed;
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    set<int>st[4];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)st[get(s[i],t[i])].insert(i);
        else 
        {
            if(s[i]=='A'&&t[i]=='B')
            {
                if(st[0].size()>0)
                {   
                    ans++;
                    int idx=*st[0].begin();
                    s[idx]=t[idx];
                    st[0].erase(st[0].begin());
                    st[3].insert(idx);
                    s[i]=t[i];
                }
                else if(st[3].size()>0)
                {
                    ans++;
                    s[i]=t[i];
                }
               
            }
             st[get(s[i],t[i])].insert(i);
        }
    }
    for(int i=0;i<4;i++)st[i].clear();
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
        {
            st[get(s[i],t[i])].insert(i);
        }
        else 
        {
            if(s[i]=='B' && t[i]=='A')
            {
                if(st[2].size()>0)
                {
                    ans++;
                    s[i]=t[i];
                }
            }
            st[get(s[i],t[i])].insert(i);
        }
    }
    bool ok=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])ok=0;
    }
    if(!ok)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}


