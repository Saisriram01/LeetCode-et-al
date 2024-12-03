class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c[3] = {0,0,0};
        for(int i: nums){
            switch(i){
                case 0:{ c[0]++;
                        break;}
                case 1:{ c[1]++;
                        break;}

                case 2:{ c[2]++;
                        break;}

            }
        }

        for(int i = 0, it = 0, j = 0; i < 3; i++, j = 0){
            while(j < c[i]){
                nums[it] = i;
                j++;
                it++;
            }
        }
    }
};