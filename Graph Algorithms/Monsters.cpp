#include <bits/stdc++.h>
using namespace std;
void cal(){
    int n,m;
    cin>>n>>m;
    vector<string>grid(n);
    for(int i=0;i<n;i++)cin>>grid[i];
    vector<vector<int>>time(n,vector<int>(m,INT_MAX));
    queue<array<int,2>>q;
    array<int,2>start={-1,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='M'){
                q.push({i,j});
                time[i][j]=0;
            }
            if(grid[i][j]=='A'){
                start[0]=i;
                start[1]=j;
            }
        }
    }
    int level=1;
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    while(!q.empty()){
        int a=q.size();
        while(a--){
            auto node=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int x=node[0]+dir[k][0];
                int y=node[1]+dir[k][1];
                if(x<n&&y<m&&x>-1&&y>-1&&grid[x][y]!='#'&&time[x][y]==INT_MAX){
                    time[x][y]=level;
                    q.push({x,y});
                }
            }
        }
        level++;
    }
    vector<string>parent(n,string(m,'.'));
    bool check=false;
    q=queue<array<int,2>>();
    q.push(start);
    level=1;
    map<int ,char>m1;
    m1[0]='D';
    m1[1]='R';
    m1[2]='U';
    m1[3]='L';
    array<int,2>end={-1,-1};
    vector<vector<bool>>vist(n,vector<bool>(m,0));
    vist[start[0]][start[1]]=1;
    while(!q.empty()){
        int a=q.size();
        while(a--){
            auto node=q.front();
            q.pop();
            if(node[0]==0||node[0]==n-1||node[1]==0||node[1]==m-1){
                end[0]=node[0];
                end[1]=node[1];
                check=true;
                break;
            }
            for(int k=0;k<4;k++){
                int x=node[0]+dir[k][0];
                int y=node[1]+dir[k][1];
                if(x<n&&y<m&&x>-1&&y>-1&&grid[x][y]!='#'&&time[x][y]>level&&!vist[x][y]){
                    parent[x][y]=m1[k];
                    vist[x][y]=true;
                    q.push({x,y});
                }
            }
        }
        if(check)break;
        level++;
    }
    map<char,int>m2;
    m2['U']=0;
    m2['L']=1;
    m2['D']=2;
    m2['R']=3;
    if(!check){
        cout<<"NO";
    }
    else{
        cout<<"YES"<<endl;
        string ans;
        while(end!=start){
            char a=parent[end[0]][end[1]];
            ans.push_back(a);
            end[0]+=dir[m2[a]][0];
            end[1]+=dir[m2[a]][1];
        }
        // for(int i=0;i<n;i++)cout<<parent[i]<<endl;
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        cout<<ans;
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