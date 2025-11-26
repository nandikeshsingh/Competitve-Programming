#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
bool cmp(pair<string,int>& p1,pair<string,int>& p2)
{
    return p1.first.length()>=p2.first.length();
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int len=s.length();
        int n;
        cin>>n;
        vector<string>str(n);
        for(int i=0;i<n;i++)cin>>str[i];
        vector<bool>temp(len,0);
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(s.substr(j,str[i].length())==str[i])
                {
                    for(int k=j;k<j+str[i].length();k++)
                    temp[k]=1;
                    ans.push_back({i+1,j+1});
                }
            }
        }
        bool ok=1;
        for(int i=0;i<len;i++)
        {
            if(temp[i]==0)ok=0;
        }
        // cout<<"Printing ans"<<endl;
        if(!ok)cout<<-1<<endl;
        else 
        {
            for(int i=0;i<len;i++)temp[i]=0;
            ans.clear();
            vector<pair<string,int>>sstr;
            for(int i=0;i<n;i++)sstr.push_back({str[i],i});
            sort(all(sstr),cmp);
            int tot=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<len;j++)
                {
                    if(s.substr(j,(int)sstr[i].first.length())==sstr[i].first)
                    {
                        int cnt=0;
                        for(int k=j;k<j+(int)sstr[i].first.length();k++)
                        {
                            if(temp[k]==0)cnt++;
                        }
                        if(cnt==(int)sstr[i].first.length())
                        {
                            for(int k=j;k<j+(int)sstr[i].first.length();k++)
                            temp[k]=1;
                            tot+=cnt;
                            ans.push_back({sstr[i].second+1,j+1});
                        }
                    }                   
                }
            }
            // cout<<"tot="<<tot<<endl;
            // cout<<"ans size="<<ans.size()<<endl;
            if(tot==len)
            {
                // cout<<"PRINTING"<<endl;
                cout<<ans.size()<<endl;
                for(auto& u : ans)cout<<u.first<<" "<<u.second<<endl;
            }
            else 
            {
                // cout<<"ELSE"<<endl;
                vector<string>left;
                string xx;
                for(int i=0;i<len;i++)
                {
                    if(temp[i]==0)xx+=s[i];
                    else 
                    {
                        if(xx.size()>0)
                        left.push_back(xx);
                        xx.clear();
                    }
                }
                if(xx.size()>0)left.push_back(xx),xx.clear();
                // cout<<"Printing left"<<endl;
                // for(auto& u : left)cout<<u<<endl;
                // cout<<"ans size="<<ans.size()<<endl;
                // cout<<"Printing temp"<<endl;
                // for(int i=0;i<len;i++)cout<<temp[i]<<" ";
                // cout<<endl;
                // cout<<"Printing sstr"<<endl;
                // for(auto& u : sstr)cout<<u.first<<" "<<u.second<<endl;
                int cur=0;
                for(int kk=0;kk<left.size();kk++)
                {
                    cur++;
                    for(int i=0;i<n;i++)
                    {
                        // cout<<"i="<<i<<endl;
                        bool found=0;
                        for(int j=0;j<len;j++)
                        {
                            if(s.substr(j,(int)sstr[i].first.length())==sstr[i].first)
                            {
                                int cnt=0;
                                for(int k=j;k<j+(int)sstr[i].first.length();k++)
                                {
                                    if(temp[k]==0)cnt++;
                                }
                                // cout<<"cnt="<<cnt<<endl;
                                if(cnt==(int)left[kk].length())
                                {
                                    for(int k=j;k<j+(int)sstr[i].first.length();k++)
                                    temp[k]=1;
                                    // cout<<"u="<<left[kk]<<endl;
                                    // cout<<"cur="<<cur<<endl;
                                    // cout<<"checking "<<endl;
                                    ans.push_back({sstr[i].second+1,j+1});
                                    found=1;
                                    break;

                                }
                            }
                        }
                        if(found)break;
                    }
                }
                // cout<<"PRINTING"<<endl;
                cout<<ans.size()<<endl;
                for(auto& u : ans)cout<<u.first<<" "<<u.second<<endl;
            }
        }
    }
    return 0;
}