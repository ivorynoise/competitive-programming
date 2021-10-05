class Solution:
    def numMatchingSubseq(self, s: str, words) -> int:
        positions = []
        current = {}
        N = len(s)
        for i in range(N - 1, -1, -1):
            positions.append(current.copy())
            current[s[i]] = i
        answer = 0
        positions = positions[::-1]
        for word in words:
            i = 0
            j = 0
            while i < len(word) and j < len(s):
                if word[i] == s[j]:
                    i += 1
                if i < len(word) and word[i] in positions[j]:
                    j = positions[j][word[i]]
                else:
                    break
            if i == len(word):
                answer += 1
        return answer


Solution().numMatchingSubseq("abcde", ["a", "bb", "acd", "ace"])
