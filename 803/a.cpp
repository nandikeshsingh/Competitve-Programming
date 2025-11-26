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
        int tot=0;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            tot^=vec[i];
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            int cur=0;
            int x=-1;
            for(int j=0;j<n;j++)
            {
                if(j==i)
                {
                    x=vec[j];
                }
                else 
                {
                    cur^=vec[j];
                }
            }
            if(x^cur==tot)
            {
                ans=x;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

