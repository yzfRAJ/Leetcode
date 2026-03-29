class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        stack<int> num;
        int size=nums.size();
        int length=0;
        for(int i=0;i<size;i++){
            if(val!=nums[i]){
                num.push(nums[i]);
                ++length;
            }
        }
        for(int j=length-1;j>=0;j--){
            nums[j]=num.top();
            num.pop();
        }
        return length;
    }
};