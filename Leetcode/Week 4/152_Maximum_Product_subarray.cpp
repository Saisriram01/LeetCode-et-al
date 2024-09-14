class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref_prod = 1, suff_prod = 1, maxm = INT_MIN;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(pref_prod == 0) pref_prod = 1;
            if(suff_prod == 0) suff_prod = 1;
            pref_prod *= nums[i];
            suff_prod *= nums[size - i -1];
            maxm = max(maxm,max(pref_prod, suff_prod));
        }
        return maxm;
    }
};

/*
int prod, maxm = INT_MIN;
for(int i = 0; i < nums.size(); i++){
    prod = 1;
    for(int j = i; j < nums.size() ; j++){
        prod *= nums[j];
        maxm = max(prod, maxm);
    }
}
    return maxm;
*/