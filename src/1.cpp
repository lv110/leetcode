#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vi;
        bool isfind=false;
        int num_i=-1,num_j=-1;
        for(int i = 0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(target ==nums[i]+nums[j]&&i!=j){
                    num_i=i;
                    num_j=j;
                    isfind = true;
                    break;
                }
            }
            if(isfind){
                break;
            }
        }
        vi.push_back(num_i);
        vi.push_back(num_j);
        return vi;
    }
};

int main(){
    cout<<"test algorithm"<<endl;
    vector<int> input = {2,7,11,15};
    vector<int> result = Solution().twoSum(input,9);

    for(auto & elem : result){
        cout<<elem<<" ";
    }
    return 0;
}