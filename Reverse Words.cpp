class Solution {
  public:
    string reverseWords(string str) {
        vector<string> temp;
        string word = "";
        
        for(int i = 0; i < str.size(); i++) {
            if(str[i] != '.') {
                word += str[i];
            } else {
                temp.push_back(word);
                word = "";
            }
        }
        temp.push_back(word);
        int n = temp.size();
        string result = "";
        
        for(int i = n-1; i >= 0; i--) {
            result += temp[i];
            if(i != 0) result += '.';
        }
        return result;
    }
};