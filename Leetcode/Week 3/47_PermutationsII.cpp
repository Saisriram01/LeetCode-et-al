class Solution {
public:
    vector<vector<int>> ans;
    void algo(vector < int> a, int idx){
        if(idx == a.size()){
            ans.push_back(a);
            return;
        }
        unordered_set<int> dup_find;
        for(int i = idx; i < a.size(); i++){
            if(dup_find.find(a[i]) != dup_find.end())
                continue;
            dup_find.insert(a[i]);
            swap(a[i],a[idx]);
            algo(a, idx + 1);
            swap(a[i],a[idx]);
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        algo(nums, 0);

        return ans;
    }
};