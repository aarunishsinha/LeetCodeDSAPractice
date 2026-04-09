class Solution {
public:
    bool isPalindrome(string& s) {
        if (s.size() == 0) return false;
        if (s.size() == 1) return true;
        int left = 0, right = s.size()-1;
        while (left <= right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void create(vector<vector<string>>& res, string& s, vector<string>& pal, int start) {
        if (start == s.size()) {
            res.push_back(pal);
            return;
        }
        for (int i = start+1; i<=s.size(); i++) {
            string st = s.substr(start, i-start);
            if (isPalindrome(st)) {
                pal.push_back(st);
                create(res, s, pal, i);
                pal.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if (s.size() == 1) return {{s}};
        vector<vector<string>> res;
        vector<string> cand;
        create(res, s, cand, 0);
        return res;
    }
};