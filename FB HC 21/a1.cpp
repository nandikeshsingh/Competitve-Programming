#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        char last='#';
        for(int i=0;i<n;i++)
        {
            if(last=='#')
            {
                if(s[i]=='X' || s[i]=='O')
                last=s[i];
            }
            else 
            {
                if(s[i]=='X' && last=='O')
                {
                    last=s[i];
                    cnt++;
                }
                else if(s[i]=='O' && last=='X')
                {
                    last=s[i];
                    cnt++;
                }

            }
        }


        cout<<"Case #"<<c<<": "<<cnt<<endl;
    }
    return 0;
}


