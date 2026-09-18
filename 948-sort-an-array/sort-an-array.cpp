class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Function of MERGE CODE
        function<void(int, int, int)> merge = [&](int low, int mid, int high) {
            
            // empty array to store sorted arrays
            vector<int> temp;

            // assigning pointers to array
            int left = low;
            int right = mid + 1;

            while(left <= mid && right <= high) {
                
                if(nums[left] <= nums[right]) {
                    temp.push_back(nums[left]);
                    left++;
                } 
                else {
                    temp.push_back(nums[right]);
                    right++;
                }
            }

            while(left <= mid) {
                temp.push_back(nums[left]);
                left++;
            }

            while(right <= high) {
                temp.push_back(nums[right]);
                right++;
            }

            // now putting all elements stored in temp to original array
            for(int i = low; i <= high; i++) {
                nums[i] = temp[i - low];
            }
        };


        function<void(int, int)> mergeSort = [&](int low, int high) {
            
            // base condition
            if(low >= high) {
                return;
            }

            // finding mid of array
            int mid = (low + high) / 2;

            // dividing array from low to mid
            mergeSort(low, mid);

            // dividing array from mid + 1 to high
            mergeSort(mid + 1, high);

            // merging both the divided arrays
            merge(low, mid, high);
        };


        mergeSort(0, n - 1);

        return nums;
    }
};