class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;        
        vector<int> count;
        count.push_back(0);
        count.push_back(1);
        count.push_back(2);
        for(int i = 3; i<=n ; i++){
            count.push_back(count[i-1] + count[i-2]);
            // cout<<count[i]<<"\n";
        }
        return count[n];
    }
};