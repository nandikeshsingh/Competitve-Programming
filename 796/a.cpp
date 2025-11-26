#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        if(x==1)cout<<3<<endl;
        else if(x%2)cout<<1<<endl;
        else 
        {
            if(__builtin_popcount(x)==1)
            cout<<(x&(-x)) + 1<<endl; 
            else cout<<(x&(-x)) <<endl;
        }

    }
    return 0;
}


