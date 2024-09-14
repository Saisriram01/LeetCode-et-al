class Solution {
public:
    vector<string> answer;
    void func(string &combo, int &n, int op, int cl){
        if(op < cl)
            return;
        if(op == n){
            string temp = combo;
            while(cl != n){
                temp += ')';
                cl++;
            }
            answer.push_back(temp);
            return;
        }

        for(; op < n; op++){
            combo.push_back('(');
            func(combo, n, op+1, cl);
            combo.pop_back();
            combo.push_back(')');         
            func(combo, n, op, cl+1);
            combo.pop_back();

        }
    }
    vector<string> generateParenthesis(int n) {
        string combo;
        int op=0, cl=0;
        func(combo,n, op, cl);
        return answer;
    }
};