#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
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
        vector<int>vec(n+1);
        int cur=1;
        for(int i=1;i<=n;i++)
        {
            vec[i]=cur;
            cur+=2;
        }
        if(n%2==0)
        {
            int mid=n/2;
            int val=vec[mid];
            int l=mid-1,r=mid+2;
            while(l>=1)
            {
                vec[l]=val-1;
                val--;
                l--;
            }
            val=vec[mid+1];
            while(r<=n)
            {
                vec[r]=val+1;
                val++;
                r++;
            }

            for(int i=1;i<=n;i++)cout<<vec[i]<<" ";
            cout<<endl;
        }
        else 
        {

            for(int i=1;i<=n;i++)vec[i]+=2;
            vec[1]++;
            vec[n]--;
            vec[2]++;

            for(int i=1;i<=n;i++)cout<<vec[i]<<" ";
            cout<<endl;

        }
    }   
    return 0;
}


