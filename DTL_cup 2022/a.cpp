#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,kk;
        cin>>n>>kk;
        string s;cin>>s;
        vector<int>cnt(26);
        for(int i=0;i<n;i++)cnt[s[i]-'a']++;
        vector<multiset<char>>vec;
        int k=n/kk;
        for(int i=0;i<sz(s);)
        {
            int cur=k;
            multiset<char>temp;
            bool ok=0;
            while(1)
            {
                for(int j=0;j<26;j++)
                {
                    if(cnt[j]==0)
                    {
                        ok=1;
                        continue;
                    }
                    if(!ok)
                    {
                        temp.insert(j+'a');
                        cnt[j]--;
                        cur--;
                        i++;
                        if(cur==0)break;
                    }
                    else 
                    {
                        while(cur && cnt[j])
                        {
                            temp.insert(j+'a');
                            cnt[j]--;
                            cur--;
                            i++;
                        }
                    }
                }
                if(cur==0)break;
            }
            vec.push_back(temp);
        }
        string ans;
        for(auto& u : vec)
        {
            for(int i=0;i<26;i++)
            {
                char c=i+'a';
                if(u.count(c))continue;
                else 
                {
                    ans+=c;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}