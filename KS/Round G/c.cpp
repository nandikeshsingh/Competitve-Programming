#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define int long long
vector<int> findNSE(vector<int>arr, int n)
{
    stack<pair<int, int> > s;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int next = arr[i];
        if (s.empty()) {
            s.push({ next, i });
            continue;
        }
        while (!s.empty() && s.top().first > next) {
            ans[s.top().second] = i;
            s.pop();
        }
        s.push({ next, i });
    }
    while (!s.empty()) { 
        ans[s.top().second] = -1;
        s.pop();
    }
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ---> " << ans[i] << endl;
    // }
    return ans;
}
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n;
        cin>>n;
        vector<int>a(n+1),pre(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
        }
        vector<int>ppre(n+1);
        for(int i=1;i<=n;i++)ppre[i]=ppre[i-1]+pre[i];
        pre.push_back(-1e18);
        int ans=0;
        vector<int>nxt=findNSE(pre,n+2);
        for(int i=0;i<=n;i++)
        {
            int r=nxt[i];
            if(i+1<=r-1)
            {
                int tot=(r-1-i);
                ans+=((ppre[r-1]-ppre[i])-tot*(pre[i]));
            }
        }
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
    return 0;
}


