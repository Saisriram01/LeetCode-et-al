class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Need to sort the intervals before thinking to merge them, it would be easier. We shall use the standard sort function, with a lambda defined to help sort them based on first element of the interval.
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};