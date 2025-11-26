#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mod=1e9+7;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        int cnt=0;
        int q=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')cnt++;
            else if(s[i]==')')cnt--;
            else q++;
        }
        int open=(q-cnt)/2;
        int close=(q+cnt)/2;
        if(open==0 || close==0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else 
        {
            string str;
            for(int i=1;i<open;i++)str+='(';
            str+=')'; str+='(';
            for(int i=1;i<close;i++)str+=')';
            int pos=0;
            string f;
            for(int i=0;i<n;i++)
            {
                if(s[i]!='?')f+=s[i];
                else f+=str[pos++];
            }
            int cnt=0;
            bool ok=1;
            for(int i=0;i<n;i++)
            {
                if(f[i]=='(')cnt++;
                else cnt--;
                if(cnt<0)ok=0;
            }   
            if(cnt!=0)ok=0;
            if(!ok)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}

