#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    
    int k = 0;
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len=flowerbed.size();
        int start,end,state = 0;
        int total;
        for(int i=0;i<len;i++){
            if(flowerbed[i]==1&&state==0){
                start=i;
                state=1;
            }
            if(flowerbed[i]==1&&state==1){
                end=i;
                state=0;
                if((end-start-2)>=3){                    
                
                }
            }
        }
        return true;
    }
};
int main(){       
    vector<int> k = {10};   
    vector <int> a = {1,2,3,4,5};
    Solution().canPlaceFlowers(a,10);
    return 0;
}