#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if (nums.empty())  return res;

        int n=nums.size();
        sort(nums.begin(),nums.end());

        for (int i=0;i<n;i++){
            long int target_3=target-nums[i];
            for(int j=i+1;j<n;j++){
                long int target_2=target_3-nums[j];

                int front=j+1;
                int back=n-1;

                while (front<back){
                    int two_sum=nums[front]+nums[back];

                    if (two_sum<target_2)     front++;
                    else if (two_sum>target_2)    back--;
                    else{
                        vector<int>quadrupled(4,0);
                        quadrupled[0]=nums[i];
                        quadrupled[1]=nums[j];
                        quadrupled[2]=nums[front];
                        quadrupled[3]=nums[back];
                        res.push_back(quadrupled);


                       
                        while(front<back  &&  nums[front]==quadrupled[2])  ++front;

                        while(front <back &&  nums[back]==quadrupled[3])   --back ;
                        }
                }
                  while(j+1<n  &&  nums[j+1]==nums[j]) ++j;

            }
              while(i+1<n  &&  nums[i+1]==nums[i]) ++i;
        }
        return res;
    }
};


int main(){
    vector<int> nums={1,0,-1,0,-2,2};
    int target=0;
    Solution obj;
    vector<vector<int>> res=obj.fourSum(nums,target);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}