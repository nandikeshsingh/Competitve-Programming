#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
map<string,int>mp;
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
signed main()
{
    speed;
    string s;
    cin>>s;
    vector<int>pi=prefix_function(s);
    int q;
    cin>>q;
    while(q--)
    {
        string t;
        cin>>t;
        int pos=s.length();
        s+=t;
        for(int i=0;i<t.length();i++)
        {
            pi.push_back(0);
        }
        string cur;
        for(int i=pos;i<pi.size();i++)
        {
            cur+=s[i];
            if(mp.count(cur))
            {
                pi[i]=mp[cur];
                continue;
            }
            int j=pi[i-1];
            while(j>0 && s[i]!=s[j])
            j=pi[j-1];
            if(s[i]==s[j])
            j++;
            pi[i]=j;
            mp[cur]=j;
        }
        for(int i=pos;i<pi.size();i++)
        cout<<pi[i]<<" ";
        cout<<endl;
        int cnt=t.length();
        while(cnt--)s.pop_back(),pi.pop_back();
    }
    return 0;
}



