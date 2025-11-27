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
    
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    else if(n==2 || n==3 )
    {
        cout<<"NO SOLUTION"<<endl;
        return 0 ; 
    }
    else if(n==4)
    {   
        cout<<"2 4 1 3"<<endl;
        return 0;
    }
    else 
    {
        for(int i=1;i<=n;i+=2)cout<<i<<" ";
        for(int i=2;i<=n;i+=2)cout<<i<<" ";
        return 0;
    }

    return 0;
}

