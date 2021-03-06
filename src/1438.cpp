#include<iostream>
#include<vector>
#include<math.h>
#include<set>
#include<deque>
using namespace std;

int __ABS(int i,int j,vector<int>& nums){
    int min = nums[i];
    int max = nums[i];
    for(int k=i+1;k<j;k++){
        if(min>nums[k])
            min=nums[k];
        if(max<nums[k])
            max=nums[k];
    }
    return max-min;
}

class Solution {
public:
    // int longestSubarray(vector<int>& nums, int limit) {
    //     // cout<<__ABS(0,nums.size(),nums)<<endl;  
    //     int i=0,j=1,len=nums.size(),max_len=1;
    //     while(j<=len){
    //         if(__ABS(i,j,nums)<=limit){
    //             if(j-i>max_len)
    //                 max_len=j-i;
    //                // cout<<"i: "<<i<<" k:"<<j<<" max_len:"<<max_len<<endl;
    //             j++;
    //         }else
    //             i++;   
    //     }
    //     return max_len;    
    // }

    //有序集合
    // int longestSubarray(vector<int>& nums, int limit) {
    //     // cout<<__ABS(0,nums.size(),nums)<<endl;  
    //     multiset<int> s;
    //     int i=0,j=0,len=nums.size(),max_len=1;
    //     s.insert(nums[i]);
    //     while(j<len){
    //         if(*s.rbegin()-*s.begin()<=limit){
    //             if(j-i+1>max_len)
    //                 max_len=j-i+1;      
    //             j++;
    //             if(j!=len)
    //                 s.insert(nums[j]);
    //         }else{
    //             s.erase(s.find(nums[i]));
    //             i++;
    //         }
    //     }
    //     return max_len;    
    // }

    //单调队列
    int longestSubarray(vector<int>& nums, int limit) {
        
        deque<int> max;
        deque<int> min;
        int i=0,j=0,len=nums.size(),max_len=1;
        //max.push_back(nums[i]);
        //min.push_back(nums[i]);
        while(j<len){
            cout<<i<<" "<<j<<endl;
            while(!max.empty()&&max.back()<nums[j]){
                max.pop_back();        
            }
            while(!min.empty()&&min.back()>nums[j]){
                min.pop_back();        
            }
            max.push_back(nums[j]);
            min.push_back(nums[j]);

            if(max.front()-min.front()<=limit){
                cout<<"lim "<<max.front()-min.front()<<endl;
                if(j-i+1<=max_len)
                    max_len=j-i+1;
                j++;
            }else{
                if(!max.empty()&&nums[i]==max.front()){
                    max.pop_front();
                }
                if(!min.empty()&&nums[i]==min.front()){
                    min.pop_front();
                }
                i++;
            }
        }
        return max_len;    
    }
};

using namespace std;
int main(){
    // cout<<"ad"<<endl;
    vector<int> v = {4,2,2,2,4,4,2,2};
    cout<<Solution().longestSubarray(v,0);
    return 0;
}