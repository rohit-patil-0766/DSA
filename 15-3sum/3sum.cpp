class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1; // last element of array

            while(j < k){// k should not cross k
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0){
                    j++ ;
                   }
                   else if (sum > 0) {
                    k--;
                   }
                   else{ // triplet found 
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                // now checking is the number equivalent to previous element, if yes move until not
                // and also check that k does not crosses j (j < k)
                   while(j < k && nums[j] == nums[j - 1]) j++;
                   while(j < k && nums[k] == nums[k + 1]) k--;
                   }
                }
            }
            return ans;
        }
    
};