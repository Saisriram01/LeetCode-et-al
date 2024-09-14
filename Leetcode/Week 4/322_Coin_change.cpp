class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dparr(amount + 1, amount+2);
        dparr[0] = 0;
        sort(coins.begin(), coins.end());
        int coin_count_temp = 0;
        for(int i = 1; i <= amount; i ++){
            for(int j = 0; j < coins.size(); j++){
                if(coins [j] > i)
                    break;
                else if(coins[j] == i){
                    dparr[i] = 1;
                    continue;
                }
                
                    coin_count_temp = dparr[i - coins[j]] + dparr[coins[j]];
                    dparr[i] = min(dparr[i], coin_count_temp) ;
                
            }
        }
        return dparr[amount] > amount ? -1 : dparr[amount]; 
    }
};
/*
GREEDY DOESN'T WORK

int coin_count = 0;
        sort(coins.begin(), coins.end());
        for(int i = coins.size() - 1; i >= 0; i--){
            while(amount >= coins[i]){
                amount -= coins[i];
                coin_count++;
            }
            if(amount  == 0 ){
                return coin_count;
            }
        }
        return -1;

*/