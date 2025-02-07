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
    vector<int>team(n,-1);
    bool check=true;
    for(int i=0;i<n;i++){
        if(team[i]==-1){
            int curr=0;
            queue<int>q;
            q.push(i);
            team[i]=curr;
            while(!q.empty()){
                int a=q.size();
                while(a--){
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(team[it]==1-curr)continue;
                        if(team[it]==curr)check=false;
                        else{
                            team[it]=1-curr;
                            q.push(it);
                        }
                        if(!check)break;
                    }
                    if(!check)break;
                }
                curr=1-curr;
                if(!check)break;
            }
        }
    }
    if(!check){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int i=0;i<n;i++){
            cout<<team[i]+1<<' ';
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