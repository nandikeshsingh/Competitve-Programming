#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>vec;
        for(int i=1;i<=(1<<n);i++)vec.push_back(i);
        while((int)vec.size()>=4)
        {
            vector<int>temp;
            for(int i=0;i<(int)vec.size();i+=4)
            {
                cout<<"? "<<vec[i]<<" "<<vec[i+2]<<endl;
                int val;cin>>val;
                if(val==1)
                {
                    cout<<"? "<<vec[i]<<" "<<vec[i+3]<<endl;
                    int win;cin>>win;
                    if(win==1)temp.push_back(vec[i]);
                    else temp.push_back(vec[i+3]);
                }
                else if(val==2)
                {
                    cout<<"? "<<vec[i+1]<<" "<<vec[i+2]<<endl;
                    int win;cin>>win;
                    if(win==1)temp.push_back(vec[i+1]);
                    else temp.push_back(vec[i+2]);
                }
                else if(val==0)
                {
                    cout<<"? "<<vec[i+1]<<" "<<vec[i+3]<<endl;
                    int win;cin>>win;
                    if(win==1)temp.push_back(vec[i+1]);
                    else temp.push_back(vec[i+3]);
                }
            }
            vec.clear();
            vec=temp;
        }
        if((int)vec.size()==1)cout<<"! "<<vec[0]<<endl;
        else 
        {
            cout<<"? "<<vec[0]<<" "<<vec[1]<<endl;
            int win;cin>>win;
            if(win==1)cout<<"! "<<vec[0]<<endl;
            else cout<<"! "<<vec[1]<<endl;
        }
    }
    return 0;
}