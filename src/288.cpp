#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<stdio.h>
#define MAX_LEN 100;
using namespace std;
class Solution{
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> v;
        char buff[100];
        if(len==0) return v; 
        
        int start=0,end=0,lastnnum=nums[0];
        for(int i = 1;i<len;i++){
            if(nums[i]==lastnnum+1){
                end=i;
            }
            else{
                if(end!=start)
                    sprintf(buff,"%d->%d",nums[start],nums[end]);
                else
                    sprintf(buff,"%d",nums[start]);
                //cout<<start<<" "<<end<<endl;
                v.push_back(string(buff));
                start=i;
                end=i;
            }
            lastnnum=nums[i];
        }       
        if(end!=start)
            sprintf(buff,"%d->%d",nums[start],nums[end]);
        else
            sprintf(buff,"%d",nums[start]);
        
        v.push_back(string(buff));
        return v;
    }  
};
int main(){
    vector<int> nums = {0,2,3,4,6,8,9};
    vector<string> result = Solution().summaryRanges(nums);
    for(auto& string:result){
        cout<<string<<endl;
    }
    return 0;
}