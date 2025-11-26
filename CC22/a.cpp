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
          vector<int>vec(n);
          for(int i=0;i<n;i++)cin>>vec[i];
          int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(vec[i]%2)cnt++;
        }
        // cout<<"cnt="<<cnt<<endl;
        cout<<min(cnt,n-cnt)<<endl;
    }
    return 0;
}

