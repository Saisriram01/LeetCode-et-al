class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "", temp1 = "", temp2 = "";
        auto pali = [](string &s, int i, int j){
            string result = "";
            if(i == j)
                result = s[i];
            else if(s[i] == s[j])
                result = s.substr(i,2);
            else
                return result;
            i--; j++;
            while(i>=0 && j < s.size()){
                if(s[i] == s[j])
                    result = s[j] + result + s[i];
                else
                    break;
                i--;
                j++;
            }
            return result;
        };
        for(int i = 0; i < s.size(); i++){
            temp1 = pali(s, i, i);
            if(i + 1 < s.size())
                temp2 = pali(s, i, i+1);
            cout<<temp1<<endl;
            cout<<temp2<<endl;
            if(temp1.size() > temp2.size())
                ans = ans.size() > temp1.size() ? ans : temp1;
            else
                ans = ans.size() > temp2.size() ? ans : temp2;
                
        }   
        return ans;
    }
};