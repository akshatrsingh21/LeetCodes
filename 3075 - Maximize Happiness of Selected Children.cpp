class Solution {
    using ll = long long;
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ll sum = 0;
        priority_queue<int> maxheap(happiness.begin(),happiness.end());

        int decrease = 0;
        while(k--){
            sum += maxheap.top();
            sum -= min(decrease,maxheap.top());
            maxheap.pop();
            decrease++;
        }
        return sum;
    }
};
