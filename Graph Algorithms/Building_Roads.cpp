#include <bits/stdc++.h>
using namespace std;
vector<int>parent;
int num;
int find(int node){
    if(node==parent[node])return node;
    return parent[node]=find(parent[node]);
}
void uni(int a,int b){
    int p1=find(a);
    int p2=find(b);
    if(p1==p2)return;
    num--;
    parent[p1]=p2;
}
void cal(){
    int n,m;
    cin>>n>>m;
    num=n;
    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        int a=find(u);
        int b=find(v);
        uni(a,b);
    }
    cout<<num-1<<endl;
    set<int>s;
    s.insert(find(0));
    for(int i=0;i<n;i++){
        if(s.find(find(i))==s.end()){
            s.insert(find(i));
            cout<<find(0)+1<<' '<<find(i)+1<<endl;
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


