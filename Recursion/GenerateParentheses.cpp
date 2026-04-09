class Solution {
public:
    void create(vector<string>& res, int& n , int open, int close, string& paren) {
        if (open == n && close == n) {
            res.push_back(paren);
            return;
        }
        if (open < n) {
            paren.push_back('(');
            create(res, n, open+1, close, paren);
            paren.pop_back();
        }
        if (close < n && close < open) {
            paren.push_back(')');
            create(res, n, open, close+1, paren);
            paren.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string paren;
        create(res, n, 0, 0, paren);
        return res;
    }
};