class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        // reverse temp array(5,6,7)
        reverse(nums.begin() + (n - k), nums.end());

        // reverse remaining array(1,2,3,4)
        reverse(nums.begin(), nums.begin() + (n - k));

        // reverse whole array (temp + remaining)
        reverse(nums.begin(), nums.end());
    }
};