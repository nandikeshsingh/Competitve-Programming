// #include<iostream>
// #include<vector>

// #define int long long
// using namespace std;
 
// vector<vector<int>>gp;
// vector<int>inf;
// vector<int>del;
// vector<int>sub;
// void dfs1(int node,int par)
// {
//     sub[node]=1;
//     for(auto& u : gp[node])
//     {
//         if(u!=par)
//         {
//             dfs1(u,node);
//             sub[node]+=sub[u];
//         }
//     }
// }
// void dfs(int node,int par)
// {
//     vector<pair<int,int>>v;
//     for(auto& u : gp[node])
//     {
//         if(u!=par)
//         {
//             dfs(u,node);
//             v.push_back({inf[u],del[u]});
//         }
//     }
 
//     if(v.size()==2)
//     inf[node]=max(v[0].first+v[1].second,v[0].second+v[1].first);
//     else if(v.size()==1)
//     inf[node]=v[0].second;
 
//     del[node]=sub[node]-1;
// }
// signed main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         inf.clear();
//         del.clear();
//         sub.clear();
//         gp.clear();
//         inf.resize(n+1,0);
//         del.resize(n+1,0);
//         sub.resize(n+1,0);
//         gp.resize(n+1,vector<int>(0));
//         for(int i=1;i<n;i++)
//         {
//             int u,v;
//             cin>>u>>v;
//             gp[u].push_back(v);
//             gp[v].push_back(u);
//         } 
//         dfs1(1,-1);//node parent
//         dfs(1,-1);
//         cout<<inf[1]<<endl;
//     }
//     return 0;
// }
 
// //  C:\MinGW\bin



namespace std {
    float cin; 
}
#include <iostream> 