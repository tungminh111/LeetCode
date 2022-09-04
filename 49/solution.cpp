#include "../bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > strByPattern;
        for(const string &s: strs) {
            string sortedStr = "";
            if (s.length() > 0) {
                unordered_map<char, int> cnt;
                for(char c: s) {
                    cnt[c]++; 
                }   

                vector<char> sorted;
                for (char j = 'a'; j <= 'z'; j++) 
                    for(int i = 0; i < cnt[j]; i++) 
                        sorted.emplace_back(j);
                sortedStr = string(sorted.begin(), sorted.end());
            }
            
            if (!strByPattern.count(sortedStr)) {
                strByPattern[sortedStr] = vector<string>();
            }     
            strByPattern[sortedStr].emplace_back(s);
        }
        
        vector<vector<string> > ret;
        for(auto itr = strByPattern.begin(); itr != strByPattern.end(); itr++) {
            vector<string> cur;
            for(auto str: itr->second) {
                cur.emplace_back(str);
            }
            ret.emplace_back(cur);
        }
        return ret;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<string> strs;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs.emplace_back(s);
    }

    auto groups = Solution().groupAnagrams(strs);

    for(int i = 0; i < groups.size(); i++) {
        for(auto s: groups[i]) cout << s << " ";
        cout << endl;
    }
    
    return 0;
}