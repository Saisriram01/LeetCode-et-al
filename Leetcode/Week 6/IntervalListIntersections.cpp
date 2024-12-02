class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while(i < fl.size() && j < sl.size()){
            if(fl[i][0] <= sl[j][1] && fl[i][1] >= sl[j][0])
                ans.push_back({max(fl[i][0], sl[j][0]), min(fl[i][1], sl[j][1])});
            else if(fl[i][0] >= sl[j][1] && fl[i][1] <= sl[j][0])
                ans.push_back({max(fl[i][0], sl[j][0]), min(fl[i][1], sl[j][1])});
          
            if(fl[i][1] <= sl[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};