#include <bits/stdc++.h>
using namespace std;
void solve(int node,int parent,int &no,vector<bool>&vist,vector<vector<int>>&adj){
    if(vist[node]){
        no=node;
        return ;
    }
    vist[node]=true;
    for(auto it:adj[node]){
        if(it!=parent){
            solve(it,node,no,vist,adj);
        }
    }
}
void solve1(int node,int parent,int &final,vector<int>&parent1,vector<bool>&vist,vector<vector<int>>&adj){
    if(node==final&&parent!=-1){
        parent1[node]=parent;
        return ;
    }
    parent1[node]=parent;
    vist[node]=true;
            // cout<<node;
    for(auto it:adj[node]){
        if((it==final&&it!=parent)||!vist[it]){
            solve1(it,node,final,parent1,vist,adj);
        }
    }
}
void cal(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vist(n,0);
    int node=-1;
    for(int i=0;i<n;i++){
        if(vist[i]!=true){
            solve(i,-1,node,vist,adj);
        }
    }
    if(node==-1){
        cout<<"IMPOSSIBLE";
    }
    else{
        vector<int>parent(n,-1);
        vist=vector<bool>(n,0);
        solve1(node,-1,node,parent,vist,adj);
        vector<int>ans;
        int i=node;
        int index=0;
        while(!(index>0&&i==node)){
            ans.push_back(i);
            i=parent[i];
            index=1;
        }
        cout<<ans.size()+1<<endl;
        for(auto it :ans)cout<<it+1<<' ';
        cout<<node+1;
    }
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