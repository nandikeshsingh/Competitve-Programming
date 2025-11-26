#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    string s;
    cin>>s;
    reverse(all(s));
    while(s.back()=='0')s.pop_back();
    if((int)s.length()==0)
    {
        cout<<0<<endl;
    }
    else 
    {
        reverse(all(s));
        string x;
        int pos=0;
        while(s[pos]=='1')pos++;
        if(pos==(int)s.length())
        {
            cout<<s<<endl;
        }
        else 
        {
            for(int i=pos;i<(int)s.length();i++)
            {
                x+=s[i];
            }
            for(auto& u : x)
            {
                if(u=='0')u='1';
                else u='0';
            }
            int bst_pos=-1;
            string ans;
            string god;
            int szx=(int)x.length();
            int szs=(int)s.length();
            for(int i=0;i<szx;i++)ans+='0';
            for(int i=0;i+szx<szs;i++)
            {
                string str=s.substr(i,szx);
                string final;
                for(int j=0;j<szx;j++)
                {
                    if(str[j]=='1' && x[j]=='1')
                    final+='1';
                    else final+='0';
                }
                for(int j=0;j<szx;j++)
                {
                    if(final[j]=='1' && ans[j]=='0')
                    {
                        ans=final;
                        god=str;
                        bst_pos=i;
                        break;
                    }
                    else if(final[j]=='0' && ans[j]=='1')
                    {
                        break;
                    }
                }
            }
            int cnt=(int)god.length();
            int j=cnt-1;
            int i=(int)s.length()-1;
            while(cnt--)
            {
                if(s[i]=='0' && god[j]=='1')
                s[i]='1';
                i--;j--;
            }
            cout<<s<<endl;
        }
    }
    return 0;
}


