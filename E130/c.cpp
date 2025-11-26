#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
        string s,t;
        cin>>s>>t;
        vector<int>s_b,s_c,s_a;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='b')s_b.push_back(i);
            if(s[i]=='c')s_c.push_back(i);
            if(s[i]=='a')s_a.push_back(i);
        }
        reverse(s_b.begin(),s_b.end());
        reverse(s_c.begin(),s_c.end());
        reverse(s_a.begin(),s_a.end());
        // cout<<"Printing s_b"<<endl;
        // for(auto& u : s_b)cout<<u<<" ";
        // cout<<endl;
        //         cout<<"Printing s_c"<<endl;
        // for(auto& u : s_c)cout<<u<<" ";
        // cout<<endl;
        //         cout<<"Printing s_a"<<endl;
        // for(auto& u : s_a)cout<<u<<" ";
        // cout<<endl;
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i])
            {
                if(s[i]=='a')s_a.pop_back();
                if(s[i]=='b')s_b.pop_back();
                if(s[i]=='c')s_c.pop_back();
            }
            else if(s[i]=='a' && t[i]=='b')
            {
                if(s_b.size()==0)
                {
                    ok=0;
                    break;
                }
                else if((s_c.size()>0) && (s_b.back()>s_c.back()))
                {
                    ok=0;
                    break;
                }
                else 
                {
                    s[i]='b';
                    // cout<<"s_b back = "<<s_b.back()<<endl;
                    s[s_b.back()]='a';
                    s_a.pop_back();
                    s_a.push_back(s_b.back());
                    s_b.pop_back();
                   
                }
            }
            else if(s[i]=='b' && t[i]=='c')
            {
                if(s_c.size()==0)
                {
                    ok=0;
                    break;
                }
                else if((s_a.size()>0) && (s_c.back()>s_a.back()))
                {
                    ok=0;
                    break;
                }
                else
                {
                    s[i]='c';
                    s[s_c.back()]='b';
                    s_b.pop_back();
                    s_b.push_back(s_c.back());
                    s_c.pop_back();
                }
            }
            else 
            {
                ok=0;
                break;
            }
            // cout<<"Printing s"<<endl;
            // cout<<s<<endl;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

