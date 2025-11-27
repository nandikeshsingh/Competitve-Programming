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
    vector<int>cnt(26);
    int tot=0;
    for(int i=0;i<(int)s.length();i++)
    {
        cnt[s[i]-'A']++;
        if(cnt[s[i]-'A']%2)tot++;
        else tot--;
    }
    if(tot>1)cout<<"NO SOLUTION"<<endl;
    else 
    {
        string ans;
        for(int i=0;i<26;i++)
        {
            int cur=cnt[i]/2;
            while(cur--)
            {
                ans+=(i+'A');
            }
        }
        string op=ans;
        reverse(all(op));
        for(int i=0;i<26;i++)
        {
            if(cnt[i]%2)
            {
                ans+=(i+'A');
                break;
            }
        }
        cout<<ans+op<<endl;
    }
    return 0;
}

