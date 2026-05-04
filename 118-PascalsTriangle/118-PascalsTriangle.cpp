// Last updated: 04/05/2026, 15:44:14
vector<int> generateRow(int row) {
    long long value = 1;
    vector<int> currentRow;

    currentRow.push_back(1);

    for (int col = 1; col < row; col++) {
        value = value * (row - col);
        value = value / col;
        currentRow.push_back((int)value);
    }

    return currentRow;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int row = 1; row <= numRows; row++) {
            result.push_back(generateRow(row));
        }

        return result;
    }
};