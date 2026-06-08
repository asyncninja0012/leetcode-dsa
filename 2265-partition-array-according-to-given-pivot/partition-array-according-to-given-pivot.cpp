class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small;
        vector<int> large;
        vector<int> equal;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>pivot){
                large.push_back(nums[i]);
            }

            else if(nums[i]<pivot){
                small.push_back(nums[i]);
            }
            else{
                equal.push_back(nums[i]);
            }
        }

        int i=0;
        for(int x: small) nums[i++]=x;
        for(int x:equal) nums[i++]=x;
        for(int x:large) nums[i++]=x;

        return nums;
    }
};