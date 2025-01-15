#include <string>
#include <vector>
class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
int wordCount = words.size();
        if (wordCount == 0) return {};
        
        int wordLen = words[0].size();
        int totalLen = wordCount * wordLen;
        int n = s.size();
        std::vector<int> result;

        if (n < totalLen) return result;


        std::unordered_map<std::string, int> wordFreq;
        for (std::string& word : words) {
            wordFreq[word]++;
        }


        for (int i = 0; i < wordLen; i++) {
            std::unordered_map<std::string, int> umap;
            int matched = 0;
            int start = i;
            int end = i;

            while (end + wordLen <= n) {
                std::string word = s.substr(end, wordLen);
                if (wordFreq.count(word)) {
                    umap[word]++;
                    matched++;
                    while (umap[word] > wordFreq[word]) {
                        std::string leftWord = s.substr(start, wordLen);
                        umap[leftWord]--;
                        matched--;
                        start += wordLen;
                    }
                    if (matched == wordCount) {
                        result.push_back(start);
                        
                        
                    }
                    end += wordLen;

                } else {
                    umap.clear();
                    matched = 0;
                    start = end + wordLen;
                    end += wordLen;
                }
            }
        }

        return result;
    }
};