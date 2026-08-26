class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        // 1: To add non-zero elements to temp
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {   // Time complexity: O(n)
            if (nums[i] != 0)
            {
                temp.push_back(nums[i]);
            }
        }

        // 2: To add temp elements in front of original array
        int non_zero = temp.size();
        for (int i = 0; i < non_zero; i++)
        {   // Time complexity: O(x), x: no. of non-zero elements
            nums[i] = temp[i];
        }

        // 3: To add zero's in remaining places
        for (int i = non_zero; i < n; i++)
        {   // O(n-x)
            nums[i] = 0;
        }
    }
};