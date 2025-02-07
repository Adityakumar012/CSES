#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
class trie{
public:
    bool check;
    trie* child[26];
    trie(){
        check=false;
        memset(child,0,sizeof(child));
    }
};
trie* root ;
void insert(string &s){
    trie* curr=root;
    for(auto it:s){
        int index=it-'a';
        if(curr->child[index]==NULL){
            curr->child[index]=new trie();
        }
        curr=curr->child[index];
    }
    curr->check=true;
}
int dp[5001];
int solve(int index,string&s){
    int n=s.size();
    if(index==n)return 1;
    if(dp[index]!=-1)return dp[index];
    trie* curr=root;
    int ans=0;
    for(int i=index;i<n;i++){
        int ind=s[i]-'a';
        if(curr->child[ind]==NULL)break;
        curr=curr->child[ind];
        if(curr->check)ans=(ans+solve(i+1,s))%mod;
    }
    return dp[index]= ans;
}
void cal(){
    root=new trie();
    string s;
    cin>>s;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        string t;
        cin>>t;
        insert(t);
    }
    memset(dp,-1,sizeof(dp));
    int ans=solve(0,s);
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        cal();
    }
    return 0;
}
//checklist--->
//1) comment test case line
//2) memset?
//3) long long dp[]?
//4) using same variable ?
//5) might be &
//6) moded-something ?