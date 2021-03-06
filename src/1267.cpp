#include<iostream>
#include<vector>
#include<unordered_map>
#include<deque>
using namespace std;

typedef struct Node{
    int i;
    int j;
}NODE,*PNODE;
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        deque<Node> q;
        int len_row = grid.size();
        int len_col=grid[0].size();
        for(int i=0;i<len_row;i++){
            for(int j=0;j<len_col;j++){
                if(grid[i][j]==1){   
                    row[i]+=1;
                    col[j]+=1;
                    q.push_back(Node{i,j});
                }
            }
        }
        int count = 0;
        for(auto& node:q){
            if(row[node.i]>=2||col[node.j]>=2){              
                count++;
            }
        }
        
        return count;
    }
};
int main(){
    vector<vector<int>> m = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    cout<<Solution().countServers(m);
    return 0;
}