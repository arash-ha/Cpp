/*
Word Ladder

Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Return 0 if there is no such transformation sequence.

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 

Constraints:

1 <= beginWord.length <= 100
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the strings in wordList are unique.
*/

class Solution {
    void findNextWord(string word, unordered_set<string>& wordDict, queue<string>& toVisit){
        wordDict.erase(word);
        for(int i = 0; i < word.length(); i++){
            char letter = word[i];
            for(int j = 0; j < 26; j++){
                word[i] = 'a' + j;
                if(wordDict.find(word) != wordDict.end()){
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[i] = letter;
        }
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        queue<string> toVisit;
        findNextWord(beginWord, wordDict, toVisit);
        int res = 2;
        while(!toVisit.empty()){
            int n = toVisit.size();
            for(int i = 0; i < n; i++){
                string word = toVisit.front();
                toVisit.pop();
                if(word == endWord)
                    return res;
                findNextWord(word, wordDict, toVisit);
            }
            res++;
        }
        return 0;
    }
};
