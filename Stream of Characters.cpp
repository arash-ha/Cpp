/*
Stream of Characters
Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
 

Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.
*/

class Trie{
    Trie *children[26];
    bool endOfWord;
public:
    Trie():endOfWord(false){
        for(int i = 0; i < 26; ++i) children[i] = nullptr;
    }
    
    void insert(string s){
        Trie *t = this;
        for(char c: s){
            if(t -> children[c-'a'] == nullptr)
                t -> children[c-'a'] = new Trie();
            t = t -> children[c-'a'];
        }
        t->endOfWord = true;
    }
    
    bool search(deque<char>& s){
        Trie *t = this;
        for(char c: s){
            if(t -> children[c-'a'] == nullptr) return false;
            t = t -> children[c-'a'];
            if(t -> endOfWord) return true;
        }
        return false;
    }
};

class StreamChecker {
    Trie t;
    deque<char> dq;
public:
    StreamChecker(vector<string>& words) {
        for(string& w: words){
            reverse(w.begin(), w.end());
            t.insert(w);
        }
    }
    
    bool query(char letter) {
        dq.push_front(letter);
        return t.search(dq);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
