#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<char, char> mmap = {{'a', '0'}, {'b', '1'}, {'c', '2'}, {'d', '3'}, {'e', '4'}, {'f', '5'}, {'g', '6'}, {'h', '7'}, {'i', '8'}, {'j', '9'}};
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        for (int i = 0; i < firstWord.size(); i++)
            firstWord[i] = mmap[firstWord[i]];
        for (int i = 0; i < secondWord.size(); i++)
            secondWord[i] = mmap[secondWord[i]];
        for (int i = 0; i < targetWord.size(); i++)
            targetWord[i] = mmap[targetWord[i]];
        return stoll(firstWord) + stoll(secondWord) == stoll(targetWord);
    }
};
// 通过