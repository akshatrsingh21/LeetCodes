class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> mp;
        for (int &num : nums) {
            mp[num]++;
            if (mp[num] == 2) {
                result.push_back(num);
            }
        }
        return result;
    }
};
