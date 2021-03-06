//三数排序
#include<iostream>
#include<vector>
#include<algorithm>
#define MIN_NUM -2147483648
#define MAX_NUM 2147483647
using namespace std;
class Solution {
public:
    //排序
    // int maximumProduct(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     int len = nums.size();
    //     return max(nums[len-1]*nums[len-2]*nums[len-3],
    //     nums[0]*nums[1]*nums[len-1]);
    // }
    //找出最大的三个和最小的两个，线性扫描
    int maximumProduct(vector<int>& nums) {
        int max_1=MIN_NUM,max_2=MIN_NUM,max_3=MIN_NUM;
        int min_1=nums[0],min_2=nums[0];
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(max_1<nums[i]){
                max_1=nums[i];
            }else{
                if(max_2<nums[i]){
                    max_2=nums[i];
                }else{
                    if(max_3<nums[i]){
                    }
                }
            }
        }
        return 0;
    }
};
int main(){
    vector<int> v = {-1,-2,-3,1};
    cout<<Solution().maximumProduct(v);
    return 0;
}