class Solution {
public:

    __int128 factorial(int n)
    {
        __int128 fact = 1;

        for(int i = 1; i <= n; i++)
        {
            fact *= i;
        }

        return fact;
    }

    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;

        for(int i = 1; i <= n; i++){
            vector<int> rows;

            for(int j = 1; j <= i; j++){
                int nr = i - 1;
                int r = j - 1;

                __int128 factorial_n = factorial(nr);
                __int128 factorial_r = factorial(r);
                __int128 factorial_nr = factorial(nr - r);

                __int128 element = factorial_n / (factorial_r * factorial_nr);

                rows.push_back((int)element);
            }

            ans.push_back(rows);
        }

        return ans;
    }
};