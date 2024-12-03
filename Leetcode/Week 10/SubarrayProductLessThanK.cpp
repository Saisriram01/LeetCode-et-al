class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;  

        int left = 0;
        int mul = 1;
        int ans = 0;

        for (int right = 0; right < nums.size(); ++right) {
            mul *= nums[right];  
            while (mul >= k && left <= right) {
                mul /= nums[left];
                left++;
            }
            ans += (right - left + 1);
        }

        return ans;
    }
};


/*class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0 || k==1) return 0;
        int left=0,right=0;
        int mul = 1;
        int ans =0;
        while(right < n){
            mul *= nums[right];
            while(mul>=k && left < n){
                ans += right - left ;
                mul /= nums[left];
                left++;
            }
            right++;
        }

        return ans + (right - left) *(right - left + 1)/2 ;

    }
};*/