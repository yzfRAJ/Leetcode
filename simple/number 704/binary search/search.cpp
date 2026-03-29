//二分查找写法一，left+(right-left)/2+1，防止溢出int类型
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        while(left<=right){
            if(target>nums[left+(right-left)/2]) left=left+(right-left)/2+1;
            else if(target<nums[left+(right-left)/2]) right=left+(right-left)/2-1;
            else return left+(right-left)/2;
        }
        return -1;
    }
};