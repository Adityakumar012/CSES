#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
void solve(int i,int j,vector<string>&grid){
    int n=grid.size();
    int m=grid[0].size();
    grid[i][j]='#';
    for(int k=0;k<4;k++){
        int x=i+dir[k][0];
        int y=j+dir[k][1];
        if(x<n&&y<m&&x>-1&&y>-1&&grid[x][y]=='.'){
            solve(x,y,grid);
        }
    }
}
void cal(){
    int n,m;
    cin>>n>>m;
    vector<string>grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                ans++;
                solve(i,j,grid);
            }
        }
    }
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