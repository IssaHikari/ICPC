#include<bits/stdc++.h>

class Solution {
    private:
        std::vector<std::unordered_map<int , int>> memo;

        int backtrack(int i , int total , const std::vector<int>& nums , int target){
            if( i == nums.size()){
                return (total == target) ? 1  : 0;
            }

            if(memo[i].count(total)){
                return memo[i][total];
            }

            int add = backtrack(i+1 ,total + nums[i] , nums , target);

            int subtract = backtrack(i+1 , total-nums[i] , nums , target);

            memo[i][total] = add + subtract;

            return memo[i][total];
        }
        
    public:
        int findTargetSumWays(std::vector<int>& nums , int target){
            memo.resize(nums.size());

            return backtrack(0 , 0 , nums , target);
        }
};

