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
        int x;
        cin>>x;
        int a,b,c;
        cin>>a>>b>>c;
        if(x==1)
        {
            if(a==0)cout<<"NO"<<endl;
            else
            {
                if(a==2 && b==0)cout<<"NO"<<endl;
                else if(a==3 && c==0) cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
        }
        else if(x==2)
        {
            if(b==0)cout<<"NO"<<endl;
            else
            {
                if(b==1 && a==0)cout<<"NO"<<endl;
                else if(b==3 && c==0) cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
        }
        else if(x==3)
        {
            if(c==0)cout<<"NO"<<endl;
            else
            {
                if(c==2 && b==0)cout<<"NO"<<endl;
                else if(c==1 && a==0) cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
        }

    }
    return 0;
}