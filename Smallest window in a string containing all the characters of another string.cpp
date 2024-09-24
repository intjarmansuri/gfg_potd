class Solution {
public:
    string smallestWindow(string s, string p) {
        vector<int>freqP(256, 0);
        vector<int>windowFreq(256, 0);

        for (char c : p) {
            freqP[c]++;
        }

        int required = p.length();
        int formed = 0;
        int minLen = INT_MAX;
        int start = 0;

        int left = 0, right = 0;

        while (right < s.length()) {
            char c = s[right];
            windowFreq[c]++;

            if (freqP[c] != 0 && windowFreq[c] <= freqP[c]) {
                formed++;
            }

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                windowFreq[leftChar]--;

                if (freqP[leftChar] != 0 && windowFreq[leftChar] < freqP[leftChar]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "-1" : s.substr(start, minLen);
    }
};