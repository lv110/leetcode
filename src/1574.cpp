#include<vector>
#include<iostream>
#include<deque>
#include<algorithm>
#define MIN_LEN 1000000
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int len=arr.size(),start=0,end=len-1;
        if (len==1) return 0;
        
        for(int i=1;i<len;i++){
            if(arr[i]>=arr[i-1])
                start = i;
            else
                break;
        }
        
        for(int j=len-2;j>=0;j--){
            if(arr[j]<=arr[j+1]){
                end=j;
            }else
                break;
        }

        if(start+1==len) return 0;

        if(arr[start]<=arr[end]) return end-start-1;

        int mini = min(len-start-1,end);
        //cout<<mini<<endl;
        for(int i=0;i<=start;i++){
            for(int j=end;j<len;j++){
                if(arr[i]<=arr[j]){
                    mini = min(mini,j-i-1);
                    break;
                }
            }
        }
        return mini;
    }
};
int main(){
    vector<int> arr = {1,2,3,10,4,2,3,5};
    vector<int> arr2 = {2,2,2,1,1,1};
    cout<<Solution().findLengthOfShortestSubarray(arr2);
    return 0;
}