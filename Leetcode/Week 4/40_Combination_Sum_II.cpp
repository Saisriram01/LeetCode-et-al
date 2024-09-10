class Solution {
public:
    vector<vector<int>> answer;

    void func(vector<int>& candidates,vector<int> &combo, int target, int idx){
        if(!target){
            answer.push_back(combo);
            return;
        }
        if(target<0)
            return;
        int prev = 0;
        for(int i = idx ; i < candidates.size(); i++){
            if(prev == candidates[i])
                continue;
            combo.push_back(candidates[i]);
            func(candidates, combo, target - candidates[i], i+1);
            combo.pop_back();
            prev = candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combo;
        sort(candidates.begin(), candidates.end());
        func(candidates,combo, target, 0);
        return answer;
    }
};


/*

    template <class it, class T>
    bool combo_presence(it begin, it end, T &combo){
        for(; begin != end; begin++){
            if(*begin == combo)
                return true;
        }
        return false;
    }
    ============================================

        map<bool> prev_occ{candidates.size(), false};

        for(int i = 0; i< candidates.size(); i++){
            for(int j = i; j < candidates.size(); j++){
                if(candidates[i] == candidates[j])
                    prev_occ[j] = true;
            }
        }
    ===================================================


*/