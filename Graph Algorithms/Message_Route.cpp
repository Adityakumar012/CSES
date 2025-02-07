#include <bits/stdc++.h>
using namespace std;
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
    vector<int>parent(n,-1);
    queue<int>q;
    q.push(0);
    vector<bool>vist(n,0);
    vist[0]=true;
    while(!q.empty()){
        int a=q.size();
        while(a--){
            int node=q.front();
            q.pop();
            vist[node]=true;
            for(auto it:adj[node]){
                if(!vist[it]){
                    vist[it]=true;
                    q.push(it);
                    parent[it]=node;
                }
            }
        }
    }
    if(parent[n-1]==-1){
        cout<<"IMPOSSIBLE";
    }
    else{
        vector<int>s;
        int curr=n-1;
        while(curr!=0){
            s.push_back(curr);
            curr=parent[curr];
        }
        s.push_back(0);
        reverse(s.begin(),s.end());
        cout<<s.size()<<endl;
        for(int i=0;i<(int)s.size();i++){
            cout<<s[i]+1<<' ';
        }
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