class Solution {
public:
    vector<vector<int>> answer;
    void build_combination(vector<int> &combo,int idx, int k, int n){
        if(combo.size() == k){
            answer.push_back(combo);
            return;
        }
        else if(combo.size() > k)
            return;
        for(int i = idx; i < n; i++){          
        combo.push_back(i + 1);
        build_combination(combo, i + 1, k, n);
        combo.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> combo{};
        build_combination(combo, 0, k, n);
        return answer;
    }
};
