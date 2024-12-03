class Solution {
public:
    bool searchforelem(vector<int> &values, int target ){
        // cout<<"Values size, and target: "<<values.size()<<" "<<target<<"\n";
        for(int i:values){
            cout<<i<<" ";
            if(i == target)
                return true;     
        }
        
        return false;
    }
    
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return false;

        map<int, vector<int>> mp;
        auto insert_val = [](map<int, vector<int>>& m, int key, int value){
            m[key].push_back(value);
        };
        for(int i: nums){
            auto it = mp.find(i%10000); 
            if(it != mp.end())
                {   
                    bool found = searchforelem(it->second, i);
                    cout<<found<<" ";
                    if (found)
                        return true;
                    else
                        insert_val(mp, i%10000, i);

                }
            else {
                // cout<<"Inserting "<<target<<" at "<<nums
                insert_val(mp, i%10000, i);
            }
        }
        return false;
    }
};