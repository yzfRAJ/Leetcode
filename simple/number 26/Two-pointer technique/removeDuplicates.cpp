//一个指针指向当前不重复的最后一个元素，另一个指针扫描数组，如果遇到不重复的元素，
//就把它放到第一个指针的下一个位置，并更新第一个指针的位置。最后返回第一个指针的位置加一，即为新的数组长度。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int *p=&nums[0],*s=&nums[0];
        for(int i=1;i<nums.size();i++){
            if(*p==nums[i]){
                s=&nums[i];
            }else if(*s!=nums[i]&&*p!=nums[i]){
                p=p+1;
                *p=nums[i];
            }
        }
        return p-&nums[0]+1;
    }
};