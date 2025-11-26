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
        if(n%2)cout<<-1<<endl;
        else
        {
            int a,b,c;
            a=0;
            b=n/2;
            c=n/2;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }
    return 0;
}

