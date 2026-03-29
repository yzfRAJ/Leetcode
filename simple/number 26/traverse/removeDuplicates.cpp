//相邻两个数比较找到不同的数计数，直到找到所有不重复的数，并将不重复的数放在数组前面，最后返回不重复数的个数
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int member=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[member]=nums[i+1];
                member++;
            }
        }
        return member;
    }
};