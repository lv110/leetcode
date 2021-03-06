//有序数组平方和
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> new_nums;
        int len = nums.size();
        int mid=len;
        for(int i=0;i<len;i++){
            if(nums[i]>0){ 
                mid = i;
                break;
            }
        }

        int i=mid-1,j=mid;        
        
        if(mid==len){
            mid--;
            while(mid>=0){
               cout<<nums[mid]<<" ";
               new_nums.push_back((nums[mid])*(nums[mid])); 
               mid--; 
            }
            return new_nums;
        }
        
        
        while(i>=0&&j<len){
            int i_num=nums[i]*nums[i]
            ,j_num=nums[j]*nums[j];        
            if(i_num<j_num){
                new_nums.push_back(i_num);
                i--;
                if(i!=-1)
                    i_num=nums[i]*nums[i];
            }else{
                new_nums.push_back(j_num);
                j++;
                if(j!=len)
                    j_num=nums[j]*nums[j];
            }
        }
        while (i>=0){
            new_nums.push_back(nums[i]*nums[i]);
            i--;
        }       
        while(j<len){
            new_nums.push_back(nums[j]*nums[j]);
            j++;
        }
        return new_nums;
    }
};

int main(){
    vector<int> nums={-5,-3,-2,-1};
    vector<int> result=Solution().sortedSquares(nums);
    for(int num:result){
        cout<<num<<" ";
    }
    return 0;
}