/*
Encode and Decode TinyURL

Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

class Solution {
    unordered_map<string, string> encodeump;
    unordered_map<string, string> decodeump;
public:
    
    Solution(){
        decodeump[""] = "";
    }
    
    string getAlphabet(){
        string ans;
        int num = (rand() % (122 - 97 + 1)) + 97;
        ans = char(num);
        return ans;
    }
    
    string getCode(){
        string code = "";
        code += to_string(rand() % 10) + getAlphabet() + to_string(rand() % 10) + getAlphabet() + to_string(rand() % 10) + getAlphabet();
        return code;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encodeump.find(longUrl) != encodeump.end())
            return encodeump[longUrl];
        string code = "";
        while(decodeump.find(code) != decodeump.end())
            code = getCode();
        string encodString = "http://tinyurl.com/" + code;
        encodeump[longUrl] = encodString;
        decodeump[encodString] = longUrl;
        return encodString;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeump[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
