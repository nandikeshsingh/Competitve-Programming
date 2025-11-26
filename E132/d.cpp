#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
// const int N = 100000; 
  
int n,m; // array size
  
// Max size of tree
// int tree[2 * N];
vector<int>tree;
// function to build the tree
void build( vector<int>arr) 
{ 
    // insert leaf nodes in tree
    for (int i=1; i<=m; i++)    
        tree[m+i] = arr[i];
      
    // build the tree by calculating parents
    for (int i = m ; i > 1; --i)     
        tree[i] = max(tree[i<<1] , tree[i<<1 | 1]);    
}
// function to get sum on interval [l, r)
int query(int l, int r) 
{ 
    int res = 0;
      
    // loop to find the sum in the range
    for (l += m, r += m; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) 
            res = max(res,tree[l++]);
      
        if (r&1) 
            res = max(res,tree[--r]);
    }
    return res;
}
signed main()
{
    speed;
    int t;
    // cin>>t;
    // while(t--)
    {
        cin>>n>>m;
        vector<int>vec(m+1);
        for(int i=1;i<=m;i++)cin>>vec[i];
        tree.resize(4*m);
        build(vec);
        // cout<<"out"<<endl;
        int q;cin>>q;
        while(q--)
        {
            int a,b,c,d,k;
            cin>>a>>b>>c>>d>>k;
            // a--,b--,c--,d--;
            if((abs(d-b))%k!=0)cout<<"NO"<<endl;
            else if(d==b)
            {
                if((abs(a-c))%k!=0)cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
            else if(abs(b-d)==1)
            {
                if(b>d)
                {
                    swap(b,d);
                    swap(a,c);
                }
                if((abs(a-c))%k!=0)cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
            else 
            {
                if(b>d)
                {
                    swap(b,d);
                    swap(a,c);
                }
                // int x=n-b+1;
                // int y=n-d+1;
                int mx=query(b+1,d);
                // cout<<"checking"<<query(3,3)<<endl;
                // if(mx>=1)mx--;
                // cout<<"b="<<b<<" d="<<d<<endl;
                // cout<<"mx="<<mx<<endl;
                if(mx==n)
                {
                    cout<<"NO"<<endl;
                }
                else if(a>mx || c>mx)
                {
                    // cout<<"inside"<<endl;
                    if((abs(a-c))%k!=0)cout<<"NO"<<endl;
                    else cout<<"YES"<<endl;
                }
                else 
                {
                    int x=(mx-a)/k;
                    x++;
                    if(x*k+a>n)
                    {
                        cout<<"NO"<<endl;
                        continue;
                    }
                    int val=2*x*k;
                    val+=(a-c);
                    if(val%k!=0)cout<<"NO"<<endl;
                    else cout<<"YES"<<endl;
                }
                // if((x+y)%k!=0)cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
