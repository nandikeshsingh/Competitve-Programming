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
        for(int i=1;i<n;)
        {
            if(vec[i]<vec[i-1])
            {
                cnt++;
                i+=2;
            }
            else i++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
