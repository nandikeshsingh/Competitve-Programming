#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int ca,cb;
bool check(int a,int b)
{
    a+=(b/2);
    b-=(b/2);
    int fa=min(a,b),fb=max(a,b);
    if(ca==fa && cb==fb)return 0;
    else return 1;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a%2 && b%2)cout<<"No"<<endl;
        else 
        {
            ca=min(a,b),cb=max(a,b);
            if(a%2)
            {
                if(check(a,b))cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
            else if(b%2)
            {
               if(check(b,a))cout<<"Yes"<<endl;
               else cout<<"No"<<endl;
            }
            else 
            {
                if(check(a,b) || check(b,a))cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }

    }
    return 0;
}


