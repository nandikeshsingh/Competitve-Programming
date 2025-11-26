#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
// int get(vector<int>a,vector<int>b,int cur)
// {
//     if(cur==-1)
//     {
//         return 0; 
//     } 
//     int n=(int)a.size();
//     vector<int>ao,az,bo,bz;
//     for(int i=0;i<n;i++)
//     {
//         if((1<<cur)&a[i])
//         {
//             // a[i]^=(1<<cur);
//             ao.push_back(a[i]);
//         }
        
//         else 
//         {
//             az.push_back(a[i]);
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         if((1LL<<cur)&b[i])
        
//         {
//             // b[i]^=(1<<cur);
//             bo.push_back(b[i]);
//         }
//         else bz.push_back(b[i]);
//     }
//     if((int)ao.size()==(int)bz.size())
//     {
//         // cout<<"cur="<<cur<<endl;
//         int x=get(ao,bz,cur-1);
//         int y=get(az,bo,cur-1);
//         // cout<<"x="<<x<<" y="<<y<<endl;
//         return (1<<cur) | (x&y);
//     }
//     else return get(a,b,cur-1);
// }
// bool check(vector<int>& a,vector<int>& b,int bit)
// {
//     int n=a.size();
//     int acnt=0;
//     int bcnt=0;
//     for(int i=0;i<n;i++)
//     {
//         if((1<<bit)&a[i])acnt++;
//         if((1<<bit)&b[i])bcnt++;
//     }
//     return acnt==(n-bcnt);
// }
vector<vector<int>>x,y;
vector<int>a,b;
bool ok(vector<int>a,vector<int>b,int bit)
{
    int n=a.size();
    int acnt=0;
    int bcnt=0;
    for(int i=0;i<n;i++)
    {
        if((1<<bit)&a[i])acnt++;
        if((1<<bit)&b[i])bcnt++;
    }
    return acnt==(n-bcnt);
}
int get(int bit)
{
    if(bit==-1)return 0;
    for(int i=0;i<x.size();i++)
    {
        if(!ok(x[i],y[i],bit))
        {
            return get(bit-1);
        }
    }
    vector<vector<int>>l,m;
    for(int i=0;i<x.size();i++)
    {
        vector<int>az,ao,bz,bo;
        for(int j=0;j<x[i].size();j++)
        {
            if((1<<bit)&x[i][j])ao.push_back(x[i][j]);
            else az.push_back(x[i][j]);
            if((1<<bit)&y[i][j])bo.push_back(y[i][j]);
            else bz.push_back(y[i][j]);
        }
        if(az.size())
        l.push_back(az);
        if(ao.size())
        l.push_back(ao);
        if(bo.size())
        m.push_back(bo);
        if(bz.size())
        m.push_back(bz);
    }
    x.clear();
    y.clear();
    x=l;y=m;
    return (1<<bit)+get(bit-1);
    
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
        a.resize(n);
        b.resize(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        x.push_back(a);
        y.push_back(b);
        cout<<get(30)<<endl;
        x.clear();y.clear();a.clear();b.clear();
    }   
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<vector<int>>vec;
//     vector<int>a,b;
//     cout<<a.size()<<endl;
//     vec.push_back({1,2});
//     vec.push_back(a);
//     vec.push_back({3});
//     vec.push_back({8,9,7,6});
//     vec.push_back(b);
//     cout<<vec.size()<<endl;
//     cout<<"Printing "<<endl;
//     for(auto& u : vec)
//     {
//         for(auto& v : u)
//         cout<<v<<" ";
//         cout<<endl;
//     }
//     cout<<endl;
// }