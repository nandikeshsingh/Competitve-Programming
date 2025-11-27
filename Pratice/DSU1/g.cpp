#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>freq;
bool cmp(int a,int b)
{
    return freq[a]>freq[b];
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        if(n*a!=m*b)
        {
            cout<<"NO"<<endl;
            continue;
        }
        freq.resize(m);
        for(int i=0;i<m;i++)freq[i]=b;
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            vector<int>idx(m);
            for(int i=0;i<m;i++)idx[i]=i;
            sort(all(idx),cmp);
            for(int j=0;j<a;j++)
            {
                ans[i][idx[j]]=1;
                freq[idx[j]]--;
            }
            for(int j=a;j<m;j++)
            ans[i][idx[j]]=0;
        }
        cout<<"YES"<<endl;
        for(auto& u : ans)
        {
            for(auto& v : u)
            cout<<v;
            cout<<endl;
        }

    }
    return 0;
}






In a tree of zeros and ones, an island is defined as a group of ones that are surrounded by zeros or are at the boundary of the tree.

Example:

       0(a)
      /   \
     1(b)  1(c)
    /     /
   0(e)  1(d)
  /   \
 1(f)  1(g)
  \     \
   1(h)  1(i)
Find the number of islands in the tree.

In the above example, there are 4 islands.
         
       int answer=0;
       bool ok=0;
         
       void dfs(treenode* node)
       {
         if(node==nullptr)return;
         if(node->val==0)ok=1;
         if(node->left!=nullptr && node->val==0 &&node->left->val==1)answer++;
         if(node->right!=nullptr && node->val==0 &&node->right->val==1)answer++;
         dfs(node->left);
         dfs(node->right);
       }

       int cound(treenode* node)
       {
         dfs(node);
         if(!ok)answer=1;
         return answer;
       } 
         
       map<treenode*,treenode*>par;
       set<treenode*>visited;
       void dfs(treenode* cur,treenode* parent)
       {
         if(cur==nullptr)return;
         par[cur]=parent;
         dfs(cur->left,cur);
         dfs(cur->right,cur);
       }
       void find_island(treenode* node)
       {
         if(node==nullptr)return;
         if(node->val==0)return;
         if(visited.find(node)!=visited.end())
         {
           return;
         } 
         visited.insert(node);
         find_island(node->left);
         find_island(node->right);
         find_island(par[node]);
       } 
       int count(treenode* root)
       {
         dfs(root,nullptr);
         int answer=0;
         for(auto& [node,parent]:par)
         {
            if(visited.find(node)==visited.end() && node->val==1)
            {
                find_island(node);
                answer++;
            } 
         }
         return answer;
       }
      

       class TrieNode
{
public:
    TrieNode* child[26];
    bool end;
    TrieNode()
    {
        for(int i=0;i<26;i++)child[i]=nullptr;
        end=0;
    }
};
class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
         root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur=root;
        for(auto& c : word)
        {
            int i=c-'a';
            if(cur->child[i]==nullptr)
            cur->child[i]=new TrieNode();
            cur=cur->child[i];
        }
        cur->end=1;
    }
    
    bool search(string word) {
        TrieNode* cur=root;
        for(auto& c: word)
        {
            int i=c-'a';
            if(cur->child[i]==nullptr)
            return 0;
            cur=cur->child[i];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(auto&c:prefix)
        {
            int i=c-'a';
            if(cur->child[i]==nullptr)return 0;
            cur=cur->child[i]; 
        }
        return 1;
    }
};




