class Solution {
public:
    // void norepsub(string &s, int &l, int &r, map<char,int>& chmap){
    //     while(l<=r){
    //         chmap[s[l++]]--;
    //         auto it = chmap.begin();
    //         while(it != chmap.end()){
    //             if(it->second > 1)
    //                 break;
    //             it++;
    //         }
    //         if(it == chmap.end())
    //             return;
    //     }
    // }
    int lengthOfLongestSubstring(string s) {
        map<char, int> chmap;
        int l = 0, r = 0,  max_len = 0;
        for(; r < s.size(); r++){
            chmap[s[r]]++;
            while(chmap[s[r]] > 1){
                chmap[s[l]]--;
                l++;
            }
            max_len = max(max_len, r-l+1);
            
        }
        return max_len;
    }
};