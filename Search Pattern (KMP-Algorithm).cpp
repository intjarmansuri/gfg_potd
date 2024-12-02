


class Solution {
  public:
    vector<int> computeLPS(string &pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    vector<int> search(string& pat, string& txt) {
        int n = txt.size();
        int m = pat.size();
        vector<int> lps = computeLPS(pat);
        vector<int> result;

        int i = 0; // Index for txt
        int j = 0; // Index for pat

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m) {
                // Pattern found, store the starting index
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};