//vector全部初始化为0，从后往前插入大元素即可
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1,i=nums.size() - 1;
        vector<int> num(right+1,0);//全部初始化
        while(left<=right){
            if(pow(nums[left],2)>=pow(nums[right],2)){
                num[i]=pow(nums[left],2);
                left++;

            }else{
                num[i]=pow(nums[right],2);
                right--;
            }
            i--; 
        }
        return num;
    }
};