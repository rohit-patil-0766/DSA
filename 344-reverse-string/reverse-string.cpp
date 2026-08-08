class Solution {
public:
    void reverseString(vector<char>& s, int i, int j) {
        //  base condition
        if(i >= j){
            return;
        }
        swap(s[i], s[j]);

        // recursive call
        reverseString(s, i+1, j-1);
    }

    // calling recursive function
    void reverseString(vector<char>&s){
        int n = s.size();
        reverseString(s, 0, n-1);
    }
};