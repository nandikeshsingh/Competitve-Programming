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
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

        }
        set<int>st;
        int cnt=0;
        int idx=-1;
        for(int i=n-1;i>=0;i--)
        {
            st.insert(a[i]);
            cnt++;
            if(st.size()!=cnt)
            {
                idx=i;
                break;
            }
        }
        // cout<<"Printing"<<endl;
        cout<<idx+1<<endl;
    }
    return 0;
}