/********************************************
作者:Alfeim
题目:TinyUrl的加密与揭秘
时间消耗:4ms
解题思路:哈希表
********************************************/
class Solution {
public:
    unordered_set<string> S;
    unordered_map<string,string> M;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        S.insert(longUrl);
        int number = S.bucket(longUrl);
        string ShortUrl = "https://tinyurl.com/" + to_string(number);
        M[ShortUrl] = longUrl ;
        return ShortUrl;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return M[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
