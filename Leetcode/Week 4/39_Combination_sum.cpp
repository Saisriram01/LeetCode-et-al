class Solution {
public:
    vector<vector<int>> answer;
    void func(vector<int> &candidates,vector<int> &combo, int target, int idx){
        if(!target){
            answer.push_back(combo);
            return;
        }
        if(target < 0)
            return;

        for(int i = idx; i < candidates.size(); i++){
            combo.push_back(candidates[i]);
            func(candidates, combo, target - candidates[i], i);
            combo.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>combo;
        func(candidates,combo, target, 0);
        return answer;
    }
};