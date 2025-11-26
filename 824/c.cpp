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
        int n;
        cin>>n;
        string t;
        cin>>t;
        map<char,char>mp,rmp;
        vector<bool>ok(26);
        string s;
        for(int i=0;i<sz(t);i++)
        {
            if(mp.count(t[i]))
            {
                s+=mp[t[i]];
            }
            else if(ok[t[i]-'a'])
            {
                char x=t[i];
                while(rmp.count(x))x=rmp[x];
                int val=-1;
                for(int j=0;j<26;j++)
                {
                    if(!ok[j] && x!=(j+'a') && (j+'a')!=t[i])
                    {
                        ok[j]=1;
                        val=j;
                        break;
                    }
                }
                if(val!=-1)
                {
                char c=val+'a';
                s+=c;
                mp[t[i]]=c;
                rmp[c]=t[i];
                }
                else 
                {
                    char find=t[i];
                    while(rmp.count(find))find=rmp[find];
                    ok[find]=1;
                    s+=find;
                    mp[t[i]]=find;
                    rmp[find]=t[i];
                }
            }
            else 
            {
                // ok[t[i]-'a']=1;
                int val=-1;
                for(int j=0;j<26;j++)
                {
                    if(!ok[j] && (j+'a')!=t[i])
                    {
                        ok[j]=1;
                        val=j;
                        break;
                    }
                }
                    char c=val+'a';
                    s+=c;
                    mp[t[i]]=c;   
                    rmp[c]=t[i];  
            }
        }
        cout<<s<<endl;
    }
    return 0;
}


