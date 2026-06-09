class Solution {
public:

    int maxEl(vector<int> &nums){
        int maxi=INT_MIN;
        for(int i:nums){
            maxi=max(i, maxi);
        }
        return maxi;
        

    }

    int minEl(vector<int> &nums){
        int mini = INT_MAX;
        for(int i:nums){
            mini = min(i, mini);
        }

        return mini;
    }
    long long maxTotalValue(vector<int>& nums, int k) {

        long long max = maxEl(nums);
        long long min = minEl(nums);

        return (max-min)*k;


        
    }
};