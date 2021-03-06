#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len=nums.size();
        unordered_map<int,int> hash;
        bool exsist=true;
        for(int i=0;i<len;i++){
            // hash[nums[i]]=i+1;
            if(hash[nums[i]]!=0){
                if(i+1-hash[nums[i]]<=k){
                    // cout<<i<<" ";
                    return true;
                }
                else{
                    hash[nums[i]]=i+1;
                }   
            }else{
                hash[nums[i]]=i+1;
            }
        }
        return false;
    }
};
int main(){
    vector<int> vm = {1,2,3,1};
    cout<<Solution().containsNearbyDuplicate(vm,3);
    return 0;
}