#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
int isSubArray(vector<int>&A, vector<int>&B, int n, int m)
{
    int i = 0, j = 0;
     while (i < n && j < m) {
        if (A[i] == B[j]) {
            i++;
            j++;
            if (j == m)
                return i-m;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    return -1;
}
bool check(vector<int>&a,vector<int>&b,int x,int y)
{
    bool ok=1;
    int cnt=(int)a.size();
    int n=cnt;
    while(cnt--)
    {
        if(a[x]!=b[y])ok=0;
        else 
        {
            x++;y++;
            if(x>=n)x-=n;
            if(y>=n)y-=n;
        }
    }
    return ok;
}
signed main()
{
    speed;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n,k;
        cin>>n>>k;
        vector<int>a(n),b(n);
        int pos_a=-1;
        int pos_b=-1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        vector<int>ca;
        ca=a;
        for(int i=0;i<n;i++)ca.push_back(ca[i]);
        // cout<<"Printing copy"<<endl;
        // for(auto& u : ca)cout<<u<<" ";
        // cout<<endl;
        pos_a=isSubArray(ca,b,n+n,n);
        pos_b=0;
        // cout<<"pos_a="<<pos_a<<" pos_b="<<pos_b<<endl;
        if(pos_a==-1)
        {
            cout<<"Case #"<<c<<": NO"<<endl;
        }
        else 
        {
            // int rot=pos_a-pos_b;
            // if(rot<0)rot+=n;
            if(pos_a==pos_b)
            {
                if(n!=2)
                {
                    if(k!=1)cout<<"Case #"<<c<<": YES"<<endl;
                    else cout<<"Case #"<<c<<": NO"<<endl;
                }
                else 
                {
                    if(k%2)cout<<"Case #"<<c<<": NO"<<endl;
                    else cout<<"Case #"<<c<<": YES"<<endl;
                }
            }
            else 
            {
                if(n!=2)
                {
                    if(k) cout<<"Case #"<<c<<": YES"<<endl;
                    else cout<<"Case #"<<c<<": NO"<<endl;
                }
                else 
                {
                    if(k%2)cout<<"Case #"<<c<<": YES"<<endl;
                    else cout<<"Case #"<<c<<": NO"<<endl;                   
                }
            }
        }
    }
    return 0;
}
