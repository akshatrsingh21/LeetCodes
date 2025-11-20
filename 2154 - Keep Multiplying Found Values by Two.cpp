class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> set;

        for (int n : nums) {
            set.insert(n);
        }

        while (set.find(original) != set.end()) {
            original = original * 2;
        }

        return original;
    }
};
