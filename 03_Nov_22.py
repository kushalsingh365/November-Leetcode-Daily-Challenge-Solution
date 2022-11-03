class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        freq = Counter(words)
        pp, p = 0, 0
        for w, f in freq.items():
            if w[0] == w[1]: 
                p = max(p, f % 2)
                pp += f//2 * 2
            else:
                pp += min(f, freq[w[::-1]])
        return (pp + p) * 2
