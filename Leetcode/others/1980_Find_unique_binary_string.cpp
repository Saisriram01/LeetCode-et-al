class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());
        int i;
        for(i = 0; i < nums.size(); i++ ){
            if( i == stoi(nums[i], nullptr, 2))
                continue;
            break;
        }
        bitset<32> bits(i);
        return bits.to_string().substr(32 - nums.size(), 32);
    }
};