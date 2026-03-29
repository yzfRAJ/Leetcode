//二分查找算法，时间复杂度为O(logn)，空间复杂度为O(1)，有两种写法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size() - 1;
        int left = 0, right = length;
        int mid=0;
        while (left <= right) {
            mid=left+(right-left)/2;
            if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else return mid;
        }
        return left;
    }
};