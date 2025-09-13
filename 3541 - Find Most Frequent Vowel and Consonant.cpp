#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        unordered_set<char> vowels = {'a','e','i','o','u'};
        int maxVowel = 0, maxCons = 0;

        for (auto &p : freq) {
            if (vowels.count(p.first)) {
                maxVowel = max(maxVowel, p.second);
            } else {
                maxCons = max(maxCons, p.second);
            }
        }

        return maxVowel + maxCons;
    }
};
