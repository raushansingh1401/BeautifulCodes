class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndReach = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0 && maxIndReach == i) return false;
            maxIndReach = max(maxIndReach, i+nums[i]);
        }
        
        return true;
    }
};