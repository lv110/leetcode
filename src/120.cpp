#include<iostream>
#include<vector>
#define MINIMUM 1000000
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int len =triangle.size(),layer;
        vector<vector<int>> mini;
        
        mini.push_back(vector<int>(1,triangle[0][0]));
        if(len==1) return mini[0][0];

        for(int i=1;i<len;i++)
            mini.push_back(vector<int>(triangle[i].size(),MINIMUM));
        
        for(int i =0;i<len-1;i++){
            layer=triangle[i].size();
            for(int j = 0;j<layer;j++){

                if(mini[i+1][j]>triangle[i+1][j]+mini[i][j])
                    mini[i+1][j]=triangle[i+1][j]+mini[i][j];
                
                if(mini[i+1][j+1]>triangle[i+1][j+1]+mini[i][j])
                    mini[i+1][j+1]=triangle[i+1][j+1]+mini[i][j];
                
            }
        }

        int result=MINIMUM;
        for(auto& num : mini[len-1]){
            if(result>num){
                result=num;
            }
        }
        return result;
    }
};
int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<Solution().minimumTotal(triangle);
    
    return 0;
}
