#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>>res;
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low=i+1 ,high=nums.size()-1,sum=-nums[i];
                while(low<high){
                    if (nums[low]+nums[high]==sum){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);

                        res.push_back(temp);

                        while(low<high && nums[low]==nums[low+1])  low++;
                        while(low<high && nums[high]==nums[high-1]) high--;

                        low++;
                        high--;

                    }
                    else if (nums[low]+nums[high]<sum)
                    low++;

                    else
                    high--;
                }
            }
            }
            return res;
        
    }
};

int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
    Solution obj;
    vector<vector<int>> res=obj.threeSum(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
        cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}