//滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0;//窗口左右指针
        int length=nums.size()-1;//数组最后一个元素索引
        int sum=nums[left];//窗口内元素和
        int mini_length=length+2;//最小长度
        while(right<=length){
            if(sum>=target){ 
                if(right-left+1<mini_length&&sum>=target) mini_length=right-left+1;//更新最小长度
                sum-=nums[left];
                left++;//窗口左边界右移
            }if(sum<target&&right<length){
                right++;//窗口右边界右移
                sum+=nums[right]; 
            }else if(mini_length==length+2) return 0;//如果没有找到满足条件的子数组，返回0
            //如果窗口右边界已经到达数组末尾，且当前窗口内元素和小于目标值，且之前已经找到满足条件的子数组，则右边界右移结束循环
            if(sum<target&&right==length&&mini_length!=length+2) right++;
        }
        return mini_length;
    }
};