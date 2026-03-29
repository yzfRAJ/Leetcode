//set容器自动去重并排序
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> num;
        for(int i=0;i<nums.size();i++){
            num.insert(nums[i]);
        }
        int j=0;
        for(auto x:num){
            nums[j]=x;
            j++;
        }
        return num.size();
    }
};