/*
Top K Frequent Words

Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 
Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(auto w : words)
            freq[w]++;
        auto comp = [&](const pair<string, int>& a, const pair<string, int>& b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        typedef priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> my_priority_queue_t;
        my_priority_queue_t pq(comp);
        for(auto w : freq){
            pq.emplace(w.first, w.second);
            if(pq.size() > k)
                pq.pop();
        }
        vector<string> res;
        while(!pq.empty()){
            res.insert(res.begin(), pq.top().first);
            pq.pop();
        }
        return res;
    }
};
