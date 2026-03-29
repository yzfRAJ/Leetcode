//调用sort函数时间复杂度为O(nlongn)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> num;
        for(auto x:nums){
            num.push_back(pow(x,2));
        }
        sort(num.begin(),num.end());
        return num;
    }
};