class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        // bitset bits;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            bitset<32> bits(i);
            if(bits.count() == k)
                res += nums[i];
        }
        return res;
    }
};