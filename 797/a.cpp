#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int div=n/3;
        int rim=n-3*div;
        if(rim==0)
        {
            cout<<div<<" "<<div+1<<" "<<div-1<<endl;
        }
        else if(rim==1)
        {
            cout<<div<<" "<<div+2<<" "<<div-1<<endl;
        }
        else 
        {
            cout<<div+1<<" "<<div+2<<" "<<div-1<<endl;
        }

    }
    return 0;
}

