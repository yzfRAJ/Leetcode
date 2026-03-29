class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int i = 0;
        stack<int> num;
        while (left <= right) {
            if (nums[left]<0) {
                num.push(pow(nums[left], 2));
                left++;
            } else {
                if (!num.empty()&&pow(nums[left], 2) < num.top()) {
                    nums[i] = pow(nums[left], 2);
                    left++;
                    i++;
                } else if(!num.empty()){
                    nums[i] = num.top();
                    num.pop();
                    i++;
                }else{
                    nums[i] = pow(nums[left], 2);
                    left++;
                    i++;
                }
            }
        }
        while (!num.empty()) {
            nums[i++] = num.top();
            num.pop();
        }
        return nums;
    }
};