class Solution {
public:
    int singleNumber(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            int count = 0;

            // Check frequency of current element
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            // Return the element that appears only once
            if (count == 1) {
                return nums[i];
            }
        }

        return -1; // Just in case no unique element exists
    }
};