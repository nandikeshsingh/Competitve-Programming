#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string a,b;
        cin>>a>>b;
        if(m>n)cout<<"NO"<<endl;
        else if(m==n)
        {
            if(a==b)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else 
        {
            bool ok=1;
            while(b.size()>1)
            {
                if(a.back()==b.back())
                {
                    a.pop_back();
                    b.pop_back();
                }
                else 
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)cout<<"NO"<<endl;
            else 
            {
                int cnt=0;
                for(auto& u : a)
                {
                    if(u=='1')cnt++;
                }
                if(b[0]=='1')
                {
                    if(cnt>=1)cout<<"YES"<<endl;
                    else cout<<"NO"<<endl;
                }
                else 
                {
                    if(a.length()-cnt>=1)cout<<"YES"<<endl;
                    else cout<<"NO"<<endl;
                }
            }
        }
        
    }
    return 0;
}