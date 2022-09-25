#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ret;
        string tmp = "";
        bool inComment = false;
        for(const string& s: source) {
            for (int i = 0; i < s.length(); i++) {
                string sub = s.substr(i, 2);
                if (!inComment) {
                    if (sub == "//") {
                        if (tmp.length()) ret.emplace_back(tmp);
                        tmp = "";
                        break;
                    }
                    if (sub == "/*") {
                        inComment = true;
                        i++;
                        continue;
                    }
                    tmp += s[i];
                    continue;
                }
                if (sub == "*/") {
                    inComment = false;
                    i++;
                }
            }
            if (!inComment) {
                if (tmp.length()) ret.emplace_back(tmp);
                tmp = "";
            }
        }
        return ret;
    }
};

int main() {
    ifstream input;
    input.open("input.txt");

    vector<string> ret;
    string tmp;
    while (getline(input, tmp)) {
        ret.emplace_back(tmp);
    }

    ret = Solution().removeComments(ret);
    for(const string& s: ret) {
        cout << s << "\n";
    }

    return 0;
}
