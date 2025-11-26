#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const int N = 300000;
 
// int n; // array size
 
// Max size of tree
// int tree_min[2 * N];
// int tree_max[2 * N];
vector<int>tree_min,tree_max;
 
// function to build the tree
void build_min( int arr[],int n)
{
    // insert leaf nodes in tree
    for (int i=0; i<n; i++)   
        tree_min[n+i] = arr[i];
     
    // build the tree by calculating parents
    for (int i = n - 1; i > 0; --i)    
        tree_min[i] = min(tree_min[i<<1] , tree_min[i<<1 | 1]);   
}
void build_max( int arr[],int n)
{
    // insert leaf nodes in tree
    for (int i=0; i<n; i++)   
        tree_max[n+i] = arr[i];
     
    // build the tree by calculating parents
    for (int i = n - 1; i > 0; --i)    
        tree_max[i] = max(tree_max[i<<1] , tree_max[i<<1 | 1]);   
}
 
 
// // function to update a tree node
// void updateTreeNode(int p, int value)
// {
//     // set value at position p
//     tree[p+n] = value;
//     p = p+n;
     
//     // move upward and update parents
//     for (int i=p; i > 1; i >>= 1)
//         tree[i>>1] = tree[i] + tree[i^1];
// }
 
// function to get sum on interval [l, r)
int query_min(int l, int r,int n)
{
    int res = 1e18;
     
    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            res =min(res,tree_min[l++]);
     
        if (r&1)
            res = min(res,tree_min[--r]);
    }
     
    return res;
}
int query_max(int l, int r,int n)
{
    int res = 0;
     
    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            res = max(res,tree_max[l++]);
     
        if (r&1)
            res = max(res,tree_max[--r]);
    }
     
    return res;
}

 
vector<int> printNSE(int arr[], int n)//next smaller
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
            ans[s.top().second] = next;
            s.pop();
        }
 
        // push next to stack so that we can find NSE for it
 
        s.push({ next, i });
    }
 
    // After iterating over the loop, the remaining elements
    // in stack do not have any NSE, so set -1 for them
 
    while (!s.empty()) {
        ans[s.top().second] = -1;
        s.pop();
    }

    return ans;
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ---> " << ans[i] << endl;
    // }
}
vector<int> printNGE(int arr[], int n)//next greater
{
    stack<int> s;
    vector<int>res(n);
    for (int i = n - 1; i >= 0; i--) {
        /* if stack is not empty, then
        pop an element from stack.
        If the popped element is smaller
        than next, then
        a) print the pair
        b) keep popping while elements are
        smaller and stack is not empty */
        if (!s.empty()) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return res;
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " --> " << res[i] << endl;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        tree_max.resize(2*n+10);
        tree_min.resize(2*n+10);
        int a[n],pos[n];
        for(int i=0;i<n;i++)cin>>a[i],--a[i],pos[a[i]]=i;
        build_max(a,n);
        build_min(a,n);
        
        vector<int>nxt_sml=printNSE(a,n);
        vector<int>nxt_grt=printNGE(a,n);
        for(int i=0;i<n;i++)
        {
            if(nxt_grt[i]==-1)nxt_grt[i]=a[i];
            if(nxt_sml[i]==-1)nxt_sml[i]=a[i];
        }
        // cout<<"Printing next smaller"<<endl;
        // for(int i=0;i<n;i++)
        // cout<<nxt_sml[i]<<" ";
        // cout<<endl;
        // cout<<"Printing next greater"<<endl;
        // for(int i=0;i<n;i++)
        // cout<<nxt_grt[i]<<" ";
        // cout<<endl;
        vector<int>gp[n+1];
        for(int i=1;i<n;i++)
        {
            gp[i].push_back(i-1);
            gp[i-1].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            // if(nxt_sml[i]!=a[i])
            {
                int idx=pos[nxt_sml[i]];
                int v=0;
                if(nxt_sml[i]!=a[i])
                 v=query_max(i,idx,n);
                else v=query_max(i,n,n);
                // cout<<"idx = "<<idx<<" v="<<pos[v]<<endl;
                // if(i==pos[v])continue;
                gp[i].push_back(pos[v]);
                gp[pos[v]].push_back(i);
            }
        }
        // cout<<"break"<<endl;
        for(int i=0;i<n;i++)
        {
            // if(nxt_grt[i]!=a[i])
            {
                int idx=pos[nxt_grt[i]];
                int v=0;
                if(nxt_grt[i]!=a[i])
                v=query_min(i,idx,n);
                else v=query_min(i,n,n);
                // cout<<"idx = "<<idx<<" v="<<pos[v]<<endl;
                // if(i==pos[v])continue;
                gp[i].push_back(pos[v]);
                gp[pos[v]].push_back(i);
            }
        }
        // cout<<"Printing gp"<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<" ->";
        //     for(auto& u : gp[i])
        //     cout<<u<<" ";
        //     cout<<endl;
        // }
        int dis[n],vis[n];
        for(int i=0;i<n;i++)dis[i]=0,vis[i]=0;
        queue<int>q;
        vis[0]=1;
        q.push(0);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto& u : gp[node])
            {
                if(vis[u]==0)
                {
                    dis[u]=dis[node]+1;
                    vis[u]=1;
                    q.push(u);
                }
            }
        }
        cout<<dis[n-1]<<endl;
    }
    return 0;
}