class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n+1, 0);
         int prev = nums[0];
         int prev2 = 0;
         int curi;
       

        for(int i=1; i<nums.size(); i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int notTake = prev;
            curi = max(take, notTake);
            prev2=prev;
            prev=curi;

        }

        return prev;
        
    }
};