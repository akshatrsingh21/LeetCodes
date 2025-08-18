class Solution {
public:
    // tolerance value
    const double EPS = 1e-6; 
    // recursive fn that checks whether given lost can form 24 or not.
    bool solve(vector<double> & nums){

        // BASE CASE: - if only one number is left
        if(nums.size() == 1){
               // checking if the digit is closer to 24 or not
            return fabs(nums[0] - 24) < EPS;
        }

        //  Try every pair (i,j) of numbers
        //  i= 0 -> n-1
        for(int i = 0;i<nums.size();i++){
            // j = 0 -> n-1
            for(int j = 0;j<nums.size();j++){
                
                // if i==j then continue(skip)
                if(i == j){
                    continue;
                }

                // build the nextstate
                vector<double> next;
                for(int k = 0;k<nums.size();k++){
                    if(k != i && k != j){
                        next.push_back(nums[k]);
                    }
                }

                // try all possibilities of nums[i] and nums[j]
                for(double val: compute(nums[i],nums[j])){
                    // Add this result into llist
                    next.push_back(val);

                    // Recursively check if 24 can be formed or not
                    if(solve(next)) return true;

                    // backTrack (remove the last added value)
                    next.pop_back();
                }
            }
        }
        // if no combination works
        return false;
    }

    // compute all possible results using mathematical operations
    vector<double> compute(double a, double b){
        vector<double> res;

        res.push_back(a+b);
        res.push_back(a-b);
        res.push_back(b-a);
        res.push_back(a*b);
        if(fabs(b) > EPS) res.push_back(a/b);
        if(fabs(a) > EPS) res.push_back(b/a);
        return res;
    }

    bool judgePoint24(vector<int>& cards) {
        // convert all integers into doubles (to handle division properly)
        vector<double> nums(cards.begin(),cards.end());
        // fn which tells about the possibility
        return solve(nums);
    }
};
