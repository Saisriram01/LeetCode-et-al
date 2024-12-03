// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         sort(arr.begin(),arr.end(),[x](int a, int b){
//             if(abs(a-x) != abs(b-x))
//                 return abs(a-x) < abs(b-x);
//             else
//                 return a < b;
//         });
//         vector<int> out(arr.begin(), arr.begin()+k);
//         sort(out.begin(), out.end());
//         return out;
        
//     }
// };
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;
        
        // Binary search to find the starting point of the closest elements
        while(r - l >= k) {
            // Compare the distances of arr[l] and arr[r] from x
            if(abs(arr[l] - x) > abs(arr[r] - x)) {
                l++;
            } else {
                r--;
            }
        }
        
        // Extract the k closest elements
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};
