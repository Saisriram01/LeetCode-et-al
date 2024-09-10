class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0]; 
        int fast = nums[0];

        do {
            slow = nums[slow];        
            fast = nums[nums[fast]];  
        } while (slow != fast); 

        fast = nums[0]; 
        while (slow != fast) {
            slow = nums[slow]; 
            fast = nums[fast]; 
        }

        return slow; 
    }
};

/*
class Solution {
    public int findDuplicate(int[] nums) {
        int low = 1, high = nums.length - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            
            // numbers less than or equal to mid
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            
            // if count more than mid, duplicate is in the lower half
            if (count > mid) {
                high = mid;
            } else {
                // else in the upper half
                low = mid + 1;
            }
        }
        
        // duplicate found at low
        return low;
    }
}
*/