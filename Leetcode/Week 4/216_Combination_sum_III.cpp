class Solution {
public:
    vector<vector<int>> answer;
    void func(vector<int> &combo, int n, int k, int idx){
        if(combo.size() == k && !n){
            answer.push_back(combo);
            return;
        }
        if(n < 0)
            return;

        for(int i = idx; i < 10; i++){
            combo.push_back(i);
            func(combo, n - i, k, i+1);
            combo.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if( n < (k * (k+1) / 2)) 
            return {};
        vector<int> combo;
        func(combo, n, k, 1);
        return answer;
    }
};