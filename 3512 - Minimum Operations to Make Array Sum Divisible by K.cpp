#include <vector>
using namespace std;

class Solution {
public:
    // Function expected by your driver/tests
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) sum += x;
        return static_cast<int>(sum % k);
    }

    // Backwards-compatible alias (optional)
    int minimumOperations(vector<int>& nums, int k) {
        return minOperations(nums, k);
    }
};
