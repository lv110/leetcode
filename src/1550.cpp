#include<iostream>
#include<vector>
using namespace std;

inline bool if_odds(int num){
    if ((num%2)==0) return false;
    return true;
}
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int len=arr.size();
        int count=0;
        for(int i=0;i<len;i++){
            if(if_odds(arr[i])){
                count++;
            }else{
                count=0;
            }
            if(count==3) return true;
        }
        return false;
    }
};

int main(){
    //cout<<if_odds(1);
    vector<int> vi={1,2,34,3,4,5,7,23,12};
    cout<<Solution().threeConsecutiveOdds(vi);

    return 0;
}