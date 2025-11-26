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
        int n;
        cin>>n;
        if(n==1)cout<<2<<endl;
        else if(n==2)cout<<1<<endl;
        else if(n==3)cout<<1<<endl;
        else if(n==4)cout<<2<<endl;
        else 
        {
            if(n%3==0)cout<<n/3<<endl;
            else 
            {
                cout<<n/3+1<<endl;
            }
        }

    }
    return 0;
}