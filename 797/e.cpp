#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        vector<vector<int> >rim(k,vector<int>());
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
           
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
             rim[a[i]%k].push_back(a[i]);
        }
        int ans=0;
        for(int j=((int)rim[0].size())-2;j>=0LL;j-=2)
        {
            ans+=(rim[0][j]+rim[0][j+1])/k;
            rim[0].pop_back();
            rim[0].pop_back();
        }
        int s=1,e=k-1;
        while(s<e)
        {
            while(1)
            {
                if((int)rim[s].size()>0LL && (int)rim[e].size()>0LL)
                {
                    ans+=(rim[s][(int)rim[s].size()-1]+rim[e][(int)rim[e].size()-1])/k;
                    rim[s].pop_back();
                    rim[e].pop_back();
                }
                else 
                {
                    s++;e--;
                    break;
                }
            }
        }
        vector<int>last;
        for(int i=0;i<k;i++)
        {
           for(auto & u : rim[i])
           {
               ans+=u/k;
               last.push_back(u%k);
           }
        }
        sort(last.begin(),last.end());
        int i=0,j=(int)last.size()-1;
        while(j>i)
        {
            if(last[i]+last[j]>=k)
            {
                ans++;
                // last[i]=-100;
                i++;
                j--;
            }
            else i++;
        }  
        cout<<ans<<endl;
        // }
        // // sort(last.begin(),last.end());
        // // cout<<"up"<<endl;
        // cout<<"ans="<<ans<<endl;
        // cout<<"Printing last"<<endl;
        // for(auto & u : last)cout<<u<<" ";
        // cout<<endl;
        // while(last.size()>0)
        // {
        //     // cout<<"in"<<endl;
        //     int lst=*last.rbegin();
        //     // cout<<"in2"<<endl;
        //     last.erase(last.rbegin());
        //     // auto itr=last.rbegin();
        //     // last.erase(itr,last.end());
        //     // cout<<"in3"<<endl;
        //     cout<<"k-lst = "<<k-lst<<endl;
        //     cout<<"Printing inside"<<endl;
        //     for(auto& u :last)cout<<u<<" ";
        //     cout<<endl;
        //     auto cur=last.lower_bound(k-lst);
            
        //     if(cur!=last.end())
        //     {
        //         cout<<"last="<<lst<<"cur="<<*cur<<endl;
        //         ans+=(lst+*cur)/k;
        //         cout<<"ans = "<<ans<<endl;
        //         last.erase(*cur);
        //     }
        //     else 
        //     {
        //         cout<<"last="<<lst<<"cur="<<*cur<<endl;
        //         ans+=(*last.begin()+lst)/k;
        //         cout<<"ans="<<ans<<endl;
        //         last.erase(*last.begin());

        //     }
        //     // cout<<"in4"<<endl;
            
        //     // cout<<"out"<<endl;
        // }
        // cout<<"down"<<endl;
        // cout<<"final = "<<ans<<endl;
        // reverse(last.begin(),last.end());
        // for(int i=0;i<last.size();i++)
        // {
        //     int mn_rim=10000;
        //     int cur_val=-1;
        //     int cur_idx=-1;
        //     if(last[i]==-1)continue;
        //     else 
        //     {
        //         for(int j=i+1;j<(int)last.size();j++)
        //         {
        //             if(last[j]==-1)continue;
        //                 int cur_rim=(last[i]+last[j])%k;
        //                 if(cur_rim<mn_rim)
        //                 {
        //                     mn_rim=cur_rim;
        //                     cur_val=last[j];
        //                     cur_idx=j;
        //                 }
        //         }
        //         ans+=(last[i]+cur_val)/k;
        //         last[cur_idx]=-1;
        //         last[i]=-1;
        //     }
        // }
        // cout<<ans<<endl;

    }
    return 0;
}



