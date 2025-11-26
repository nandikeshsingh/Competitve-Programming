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
            
            vec.clear();
            vec.push_back(n);
            int need=n/2;
            int cur=n+1;
            for(int i=1;i<=need;i++)
            {
                vec.push_back(cur);
                cur++;
            }
            cur=n-1;
            reverse(all(vec));
            for(int i=1;i<=need;i++)
            {
                vec.push_back(cur);
                cur--;
            }
            reverse(all(vec));
            for(int i=0;i<n;i++)vec[i]+=2;
            vec[0]--;
            vec[n-1]++;
            vec[n-2]++;

            for(int i=0;i<n;i++)cout<<vec[i]<<" ";
            cout<<endl;

        }
    }   
    return 0;
}


Inputs	Output
CONST_ENUM_ROLL_AWAY_ENABLE	INTERNAL_POWERMODE	INTERNAL_CSS_GSAText	GSAText	DS_RESELECT_GEAR
DISABLED	don’t care	don’t care	don’t care	Not displayed
ENABLED	== 7	IDLE	don’t care	Not displayed
		AVAILABLE	"Gearbox Fault. Stop IMMEDIATELY.Vehicle Recovery required." (10)	Displayed
		MISSING	don’t care	Not displayed
		NEVER_RECEIVED	don’t care	Not displayed
	!= 7	don’t care	don’t care	Not displayed
