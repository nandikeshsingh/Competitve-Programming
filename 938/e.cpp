#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int get(vector<int> A, int k) {
        int n = A.size(), flipped = 0, res = 0;
        vector<int>isFlipped(n,0);
        for (int i = 0; i < A.size(); ++i) {
            if (i >= k)
                flipped ^= isFlipped[i - k];
            if (flipped == A[i]) {
                if (i + k > A.size())
                    return -1;
                isFlipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }
        return res;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s;
        cin>>s;
        int ans=1;
        vector<int>a;
        for(auto& u : s)
        {
            if(u=='1')a.push_back(1);
            else a.push_back(0);
        }
        for(int i=n;i>=1;i--)
        {
            if(get(a,i)!=-1)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


