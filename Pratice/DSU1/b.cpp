#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int> getNSE(vector<int>arr, int n)
{
    stack<pair<int, int> > s;
    vector<int> ans(n);
 
    // iterate for rest of the elements
    for (int i = 0; i < n; i++) {
        int next = arr[i];
 
        // if stack is empty then this element can't be NSE
        // for any other element, so just push it to stack
        // so that we can find NSE for it, and continue
        if (s.empty()) {
            s.push({ next, i });
            continue;
        }
 
        // while stack is not empty and the top element is
        // greater than next
        //  a) NSE for top is next, use top's index to
        //    maintain original order
        //  b) pop the top element from stack
 
        while (!s.empty() && s.top().first > next) {
            ans[s.top().second] = i;
            s.pop();
        }
 
        // push next to stack so that we can find NSE for it
 
        s.push({ next, i });
    }
 
    // After iterating over the loop, the remaining elements
    // in stack do not have any NSE, so set -1 for them
 
    while (!s.empty()) {
        ans[s.top().second] = n;
        s.pop();
    }
    return ans;

}
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>right=getNSE(a,n);
    reverse(all(a));
    vector<int>left=getNSE(a,n);
    reverse(all(a));
    reverse(all(left));
    for(auto& u : left)u=n-1-u;
    vector<int>ans(n+1,0);
    for(int i=0;i<n;i++)
    {
        int len=right[i]-left[i]-1;
        ans[len]=max(ans[len],a[i]);
    }
    for(int i=n-1;i>=0;i--)
    ans[i]=max(ans[i+1],ans[i]);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}

