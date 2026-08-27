class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i <= n; i++){
            int found = 0;

            for(int j = 0; j <= n - 1; j++){
                if(nums[j] == i){
                    found = 1;
                    break;  // number found
                }
            }
            if(found == 0){
                return i; // number not found
            }
        }
        return -1;
    }
};