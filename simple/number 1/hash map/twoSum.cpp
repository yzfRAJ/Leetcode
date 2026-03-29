//hash map查找元素时间复杂度o(1)，空间复杂度o(n)，在这里只需要边插入边查找，时间复杂度o(n)，空间复杂度o(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num;
        int length=nums.size();
        for(int i=0;i<length;i++){
            auto it=num.find(target-nums[i]);//num空的直接返回num.end()
            if(it!=num.end()){
                return {it->second,i};
            }else num.insert({nums[i],i});
        }
        return {};
    }
};