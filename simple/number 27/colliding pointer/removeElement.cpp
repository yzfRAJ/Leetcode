//对撞指针，左指针从左遍历，右指针从右遍历，直到Left超过right
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size=nums.size();
        int right=size-1,left=0;
        while(left<=right){
            if(nums[left]!=val&&nums[right]==val){
                left++;
                right--;
            }else if(nums[left]==val&&nums[right]!=val){
                nums[left++]=nums[right--];
            }else if(nums[right]!=val){
                left++;
            }else right--;
        }
        return right+1;
    }
};