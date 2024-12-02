class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        sort(i.begin(), i.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0]; 
        });
        int j = 1, count = 0, k = 0;

        while(j < i.size()){
            if(i[k][1] > i[j][0]){
                count++;
                if(i[j][1] <= i[k][1])
                    k = j;
            }
            else 
                k = j;
            j++;
        }
        return count;
    }
};