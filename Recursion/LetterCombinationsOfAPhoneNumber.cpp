class Solution {
private:
    unordered_map<int, vector<char>> map = {{2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}}, {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}}, {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}}, {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}}};
public:
    void create(vector<string>& res, string& digits, int idx, string& made) {
        if (made.size() == digits.size()) {
            res.push_back(made);
            return;
        }
        vector<char> letters = map[digits[idx]-'0'];
        for (char ch : letters) {
            made.push_back(ch);
            create(res, digits, idx+1, made);
            made.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string made;
        create(res, digits, 0, made);
        return res;
    }
};