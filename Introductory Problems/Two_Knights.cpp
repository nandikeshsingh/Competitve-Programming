#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i==1)cout<<0<<endl;
        else if(i==2)cout<<6<<endl;
        else 
        {   
            cout<<((i*i*i*i)-(3*i-4)*(3*i-4))/2<<endl;
        }
    }
    return 0;
}


