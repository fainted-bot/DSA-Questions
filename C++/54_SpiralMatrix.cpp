#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0 ,right=matrix[0].size()-1 ,top=0 ,bottom=matrix.size()-1;
        int direction=0;
        vector<int> res;

        while(left<=right  &&   top<=bottom){
            if (direction==0){
                for(int i=left;i<=right;i++)
                    res.push_back(matrix[top][i]);
                    top++;

            }

            else if (direction==1){
                for(int i=top;i<=bottom;i++)
                   res.push_back(matrix[i][right]);
                   right--;
            }

            else if (direction == 2){
                for (int i=right;i>=left;i--)
                    res.push_back(matrix[bottom][i]);
                    bottom--;

            }

            else{
                for(int i=bottom ; i>=top ;i--)
                    res.push_back(matrix[i][left]);
                    left++;
            }

            direction=(direction+1)%4;

        }
        return res;
    }
};

int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    Solution obj;
    vector<int> res=obj.spiralOrder(matrix);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    return 0;
}