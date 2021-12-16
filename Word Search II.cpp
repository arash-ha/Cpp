/*
Word Search II

Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example 1:

Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:

Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 
Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 10^4
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
*/


class Solution {
private:
class Trie
{
public:    
    Trie * children[26];
    bool isLeaf;
    int  wordIdx;
    int prefixCount;
    
    Trie()
    {
        isLeaf = false;
        wordIdx = 0;
        prefixCount = 0;
        fill_n(children, 26, nullptr);
    }
    
    ~Trie()
    {
        for(auto i=0; i<26; ++i) delete children[i];
    }
};
    void insertWord(Trie *root,  const vector<string>& words, int idx){
        int i, childID, len = words[idx].size();
        for(i=0, root->prefixCount++ ; i<len; ++i){
            childID = words[idx][i]-'a';
            if(!root->children[childID]) root->children[childID] = new Trie();
            root = root->children[childID];
            ++root->prefixCount;
        }
        root->isLeaf = true; 
        root->wordIdx = idx;
    }
    
    Trie *buildTrie(const vector<string> &words){
        Trie *root = new Trie();
        for(int i=0; i < words.size(); ++i) insertWord(root, words, i);
        return root;
    }
    
    int dfs_Trie(vector<string> &res, Trie *root, vector<vector<char>>& board, vector<string>& words, int row, int col){
        int detected = 0;

        if(root->isLeaf){
            ++detected;
            root->isLeaf = false;
            res.push_back(words[root->wordIdx]);
        }
        
        if( row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]=='*' || !root->children[ board[row][col]-'a'] || root->children[ board[row][col]-'a']->prefixCount <= 0 ) return detected;
        int curC = board[row][col] - 'a';
        board[row][col] = '*';
        detected += dfs_Trie(res, root->children[curC], board, words, row-1, col) + 
               dfs_Trie(res, root->children[curC], board, words, row + 1, col) +    
               dfs_Trie(res, root->children[curC], board, words, row, col - 1) +    
               dfs_Trie(res, root->children[curC], board, words, row, col + 1) ;
        root->prefixCount -=detected;
        board[row][col] = curC + 'a';
        return detected;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int M, N, wordNum = words.size();
        vector<string> res;
        if( !(M = board.size()) || !(N = board[0].size()) || !wordNum) return res;
        Trie *root = buildTrie(words);
        for(auto i=0; i<M && root->prefixCount; ++i)
            for(auto j=0; j<N; ++j)
                dfs_Trie(res, root, board, words, i, j);
        delete root;
        return res;
    }
};
