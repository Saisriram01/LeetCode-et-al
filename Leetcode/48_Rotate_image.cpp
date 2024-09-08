class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        // taking transpose of matrix
        int n = m[0].size(), temp;
        for (int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                {
                    temp = m[i][j];
                    m[i][j] = m[j][i];
                    m[j][i] = temp;
                }
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n/2;j++)
                {
                    temp = m[i][j];
                    m[i][j] = m[i][n - j - 1];
                    m[i][n - j - 1] = temp;
                }
    }
};