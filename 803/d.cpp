#include<bits/stdc++.h>
#define int long long
// #define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int get(int n)
{
    int cur=1;
    while(cur*2<n)
    {
        cur*=2;
    }
    return cur;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int idx=get(n);
        int last=n;//last index
        int lo=1;//first index
        while(last>lo)
        {
            idx=get(last-lo+1);
            // cout<<"idx="<<idx<<endl;
            cout<<"? "<<lo<<" "<<lo+idx-1;
            cout<<endl;
            vector<int>vec(idx);
            int cnt=0;
            for(int i=0;i<(int)vec.size();i++)
            {
                cin>>vec[i];
                if(vec[i]>=lo && vec[i]<=(lo+idx-1))cnt++;
            }
            int rim=cnt;
            
            // cout<<"rim = "<<rim<<endl;
            if(rim%2)
            {
                last=lo+idx-1;
            }
            else lo=lo+idx;
        }
        cout<<"! "<<lo<<endl;
    }
    return 0;
}

