#include <bits/stdc++.h>
using namespace std;
void cal(){
    int n,m;
    cin>>n>>m;
    vector<string>grid(n);
    for(int i=0;i<n;i++)cin>>grid[i];
    vector<string>parent(n,string(m,'.'));
    vector<int>coda={-1,-1};
    vector<int>codb={-1,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                coda[0]=i;
                coda[1]=j;
            }
            if(grid[i][j]=='B'){
                codb[0]=i;
                codb[1]=j;
            }
        }
    }
    queue<array<int,2>>q;
    vector<vector<bool>>vist(n,vector<bool>(m,false));
    q.push({coda[0],coda[1]});
    vist[coda[0]][coda[1]]=true;
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    vector<char>move(4);
    move[0]='D';
    move[1]='R';
    move[2]='U';
    move[3]='L';
    while(!q.empty()){
        int s=q.size();
        while(s--){
            int i=q.front()[0];
            int j=q.front()[1];
            q.pop();
            for(int k=0;k<4;k++){
                int x=i+dir[k][0];
                int y=j+dir[k][1];
                if(x<n&&y<m&&x>-1&&y>-1&&vist[x][y]==false&&grid[x][y]!='#'){
                    vist[x][y]=true;
                    q.push({x,y});
                    parent[x][y]=move[k];
                }
            }
        }
    }
    // for(int i=0;i<n;i++)cout<<parent[i]<<endl;
    if(parent[codb[0]][codb[1]]=='.'){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        string ans;
        map<char,int>m1;
        m1['L']=1;
        m1['D']=2;
        m1['R']=3;
        m1['U']=0;
        int i=codb[0];
        int j=codb[1];
        while(parent[i][j]!='.'){
            char p=parent[i][j];
            ans.push_back(p);
            i+=dir[m1[p]][0];
            j+=dir[m1[p]][1];
        }
        cout<<ans.size()<<endl;
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
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