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
        int a,b;
        cin>>a>>b;
        if((a+b)%3)cout<<"NO"<<endl;
        else 
        {
            if((2*a-b)<0 || (2*a-b)%3)cout<<"NO"<<endl;
            else if((2*b-a)<0 || (2*b-a)%3)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}


