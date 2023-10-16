#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        
        for(int i=0 ;i<nums.size()-2;i++){
            if (i>0  && nums[i]==nums[i-1])    continue;

            int low=i+1;
            int high=nums.size()-1;

            while(low<high){
                int current_sum=nums[i]+nums[low]+nums[high];

                if (current_sum==target) return current_sum;

                if (abs(target-current_sum)<abs(target-closest)) closest=current_sum;

                if (current_sum>target) high--;
                else low++;
  

            }
                

        
    }
    return closest;
    }
};

int main(){
    vector<int> nums={-1,2,1,-4};
    int target=1;
    Solution obj;
    cout<<obj.threeSumClosest(nums,target);
    return 0;
}