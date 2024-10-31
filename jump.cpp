//https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> minJumpVec(size,INT_MAX);
        minJumpVec[0] = 0;

        for(int i=0;i<size;i++){
            for(int j=i+1;j<=i+nums[i]&&j<size;j++){
                minJumpVec[j] = min(minJumpVec[j], 1+minJumpVec[i]);
            }
        }

        return minJumpVec[size-1];

        

        
    }
};