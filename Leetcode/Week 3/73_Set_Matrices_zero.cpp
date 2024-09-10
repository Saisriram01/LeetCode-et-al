class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        set<int> row, col;
        for (size_t i = 0; i < mat.size(); ++i) {   
            for (size_t j = 0; j < mat[i].size(); ++j) {
                if(!mat[i][j]){
                    row.insert(i);
                    col.insert(j);
                }
            }
            auto it = row.find(i);
            if(it != row.end())
                std::memset(mat[i].data(),0,mat[i].size() * sizeof(int));
        }

        for(auto j: col){
            for(size_t i = 0; i < mat.size(); i++)
                mat[i][j] = 0;
        }

    }
};