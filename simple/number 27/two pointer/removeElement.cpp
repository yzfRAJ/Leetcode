class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0,fast=0;
        int size=nums.size();
        for(fast;fast<size;fast++){
            if(nums[fast]!=val){
                nums[slow++]=nums[fast];
            }
        }
        return slow;
    }
};