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
        string a,b;
        cin>>a>>b;
        if(a.back()>b.back())
        cout<<"<"<<endl;
        else if(a.back()<b.back())
        cout<<">"<<endl;
        else 
        {
            if(a.back()=='S')
            {
                if(sz(a)>sz(b))
                cout<<"<"<<endl;
                else if(sz(a)<sz(b))
                cout<<">"<<endl;
                else cout<<"="<<endl;
            }
            else if(a.back()=='L')
            {
                if(sz(a)>sz(b))
                cout<<">"<<endl;
                else if(sz(a)<sz(b))
                cout<<"<"<<endl;
                else cout<<"="<<endl;               
            }
            else cout<<"="<<endl;
        }
    }
    return 0;
}


