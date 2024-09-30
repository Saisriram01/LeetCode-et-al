class Solution {
public:
    int hammingWeight(int n) {
        // int count = 0;
        if(!n)
            return 0;
        if(n%2 == 0)
            return hammingWeight(n>>1);
        else
            return hammingWeight(n>>1) + 1;

    }
};