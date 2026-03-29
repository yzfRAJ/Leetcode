class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num;//可不用，直接返回列表初始化即可
        int size=nums.size();
        for(int i=0;i<size-1;i++){
            for(int j=i+1;j<size;j++){
                if(nums[j]+nums[i]==target){
                    num.push_back(i);
                    num.push_back(j);
                    return num;//return {i,j}; 直接返回列表初始化即可
                }
            }
        } 
        return num;
    }
};