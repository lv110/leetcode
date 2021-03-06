//所有奇数长度子数组的和
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // int sumOddLengthSubarrays(vector<int>& arr) {
    //     int sum=0;
    //     int len = arr.size();     
    //     for(int i=1;i<=len;i=i+2){
    //         int sum2=0;
    //         for(int j=0;j<=len-i;j=j+1){
    //             for(int k=j;k<j+i;k++){
    //                 sum+=arr[k];
    //                 sum2+=arr[k];
    //             }
    //         }
    //     }
    //     return sum;
    // }

    //前缀和法Prefix sum
    // int sumOddLengthSubarrays(vector<int>& arr) {
    //     int sum=0;
    //     vector<int> pre_sum={0};
    //     int len = arr.size();
    //     for(int i=0;i<len;i++)
    //         pre_sum.push_back(arr[i]+pre_sum.back());
            
    //     for(int i=1;i<=len;i+=2){
    //         // cout<<i<<endl;
    //         for(int j=0;j<=len-i;j++){
    //             // cout<<"     "<<j<<endl;
    //             sum+=pre_sum[j+i]-pre_sum[j];
    //         }
    //     }

    //     return sum;
    // }

    //计算数字出现在奇数子序列中的次数
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int len =arr.size();
        int left,right,
        odds_left,odds_right,
        even_left,even_right;
        int times;
        for(int i=0;i<len;i++){
            left=i-0;
            right=len-i-1;
            even_left=left/2;
            odds_left=left-even_left;

            even_right=right/2;
            odds_right=right-even_right;
            // cout<<i<<":  "<<odds_left<<" "<<even_left<<endl;
            // cout<<i<<":  "<<odds_right<<" "<<even_right<<endl;
            times = odds_right*odds_left
            +even_right*even_left;
            
            times += even_left;
            times += even_right;
            times +=1;
            sum+=times*arr[i];
        }

        return sum;
    }
};
int main(){
    vector<int> arr= {1,4,2,5,3};
    cout<<Solution().sumOddLengthSubarrays(arr);
    
    return 0;
}