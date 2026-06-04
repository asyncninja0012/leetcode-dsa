class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count=0;
        for(int i=num1; i<=num2; i++){
            int curr=i;
            vector<int> arr;
            while(curr!=0){
                int rem=curr%10;
                arr.push_back(rem);
                curr=curr/10;
            }
            for(int j=1; j<arr.size()-1; j++){
                if((arr[j-1] < arr[j] && arr[j] > arr[j+1]) || (arr[j]<arr[j-1] && arr[j]<arr[j+1])){
                    count++;
                }

            }
        }

        return count;
    }
};