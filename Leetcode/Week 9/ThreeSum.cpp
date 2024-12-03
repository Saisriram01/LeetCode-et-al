class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        // set<vector<int>> s;
        int i,j,k;
        for(i = 0; i < nums.size(); i++){ 
            if(i>0 && nums[i] == nums[i-1])
                continue;      
            j = i + 1;
            k = nums.size() - 1;
            while(j < k){
                if(!(nums[i] + nums[j] + nums[k])){
                    // s.insert({nums[i], nums[j], nums[k]});
                    out.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else
                    j++;
            }

        }
        // for(auto i:s)
            // out.push_back(i);
        return out;
    }
};

/*
Sort the given array in non-decreasing order.
Loop through the array from index 0 to n-1.
For each iteration, set the target as -nums[i].
Set two pointers, j=i+1 and k=n-1.
While j<k, check if nums[j]+nums[k]==target.
If yes, add the triplet {nums[i], nums[j], nums[k]} to the result and move j to the right and k to the left.
If no, move either j or k based on the comparison of nums[j]+nums[k] with target.
To avoid duplicate triplets, skip the iterations where nums[i]==nums[i-1] and also skip the iterations where nums[j]==nums[j-1] or nums[k]==nums[k+1].

*/