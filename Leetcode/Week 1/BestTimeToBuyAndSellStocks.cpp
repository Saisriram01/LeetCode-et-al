class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p_to_buy = prices[0], prof = 0;
        for(int i: prices){
            if(i < p_to_buy)
                p_to_buy = i;
            if(i - p_to_buy > prof)
                prof = i - p_to_buy;
        }
        return prof;
    }
};