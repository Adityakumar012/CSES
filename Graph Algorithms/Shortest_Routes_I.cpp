#include <bits/stdc++.h>
using namespace std;
void cal(){
    int n,m;
    cin>>n>>m;
    vector<vector<array<int,2>>>adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back({v,w});
    }
    vector<long long>dist(n,LLONG_MAX);
    priority_queue<array<long long,2>,vector<array<long long,2>>,greater<array<long long,2>>>pq;
    dist[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        auto node=pq.top();
        pq.pop();
        if(node[0]>dist[node[1]])continue;
        for(auto &it:adj[node[1]]){
            // cout<<it[0];
            long long nd=node[0]+it[1];
            if(nd<dist[it[0]]){
                dist[it[0]]=nd;
                pq.push({nd,it[0]});
            }
        }
    }
    for(auto it:dist)cout<<it<<' ';
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