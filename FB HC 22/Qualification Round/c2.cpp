#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    vector<string>all;
    for(int num=0;num<(1<<9);num++)
    {
        string cur;
        for(int bit=8;bit>=0;bit--)
        {
            if((1<<bit)&num)cur+='-';
            else cur+='.';
        }
        all.push_back(cur);
    }
    // cout<<"Printing cur"<<endl;
    // for(auto& u : all)cout<<u<<endl;
    // cout<<endl;
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n;cin>>n;
        string s;cin>>s;
        int len=(int)s.length();
        // if((int)s.length()<)
        vector<string>ans;
        for(int i=1;i<n-1;i++)
        {
            string cur=all[i];
            if(s[0]=='.')
            {
                reverse(cur.begin(),cur.end());
                cur+='-';
                reverse(cur.begin(),cur.end());
            }
            else 
            {
                reverse(cur.begin(),cur.end());
                cur+='.';
                reverse(cur.begin(),cur.end());
            }
            // reverse(all(cur));
            ans.push_back(cur);
        }
        // string str;
        // str=s;
        // while((int)str.length()>10)str.pop_back();
        // while((int)str.length()<10)str.push_back('.');
        // // str[4]='.';
        // // str[9]='-';
        // if(str[0]=='.')str[0]='-';
        // else str[0]='.';
        // if(s[(int)s.length()-1]=='.')str[9]='-';
        // else str[9]='.';
        // for(int i=1;i<9;i++)str[i]='.';

        // // int cur=1;
        // for(int i=1;i<n;i++)
        // {   
        //     // str[cur]='-';
        //     ans.push_back(str);
        //     // str[cur]='.';
        //     // if(cur==8)cur=1;
        // }
        cout<<"Case #"<<c<<": "<<endl;
        for(auto& u : ans)cout<<u<<endl;
    }
    return 0;
}


