class Solution:
    # @param A : integer
    # @return an integer]
    def recursion(self, A):
        if A <= 1:
            return 0
        answer = 0
        cur = 1
        mod = 10 ** 9 + 7
        total = 1
        while total + cur <= A:
            answer = (2 * answer + cur) % mod
            total += cur
            cur <<= 1
        A -= total
        answer = (answer + self.recursion(A) + A) % mod
        return answer

    def solve(self, A):

        #   0001 -> 1
        #   0010 -> 2
        #   0011 -> 3
        #   0100 -> 4
        #   0101 -> 5
        #   0110 -> 6
        #   0111 -> 7
        #   1000 -> 8
        #   1001 -> 9

        return self.recursion(A + 1)
