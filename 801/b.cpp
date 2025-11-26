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
        vector<int>vec(n);
        int idx=-1;
        int val=1e18;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            if(val>vec[i])
            {
                val=vec[i];
                idx=i;
            }
        }
        if(n%2)cout<<"Mike"<<endl;
        else 
        {
            if(idx%2)
            {
                    cout<<"Mike"<<endl;
            }
            else cout<<"Joe"<<endl;
        }
    }
    return 0;
}

