class Solution:
    # @param A : list of integers
    # @return an integer
    def largestRectangleArea(self, A):
        stack = []
        ans = 0
        n = len(A)
        for i in range(n):
            while len(stack) > 0 and A[stack[-1]] > A[i]:
                top = stack[-1]
                stack.pop()
                ans = max(ans, A[top] * ((i - stack[-1] - 1) if stack else i))
            stack.append(i)
        while len(stack) > 0:
            top = stack[-1]
            stack.pop()
            ans = max(ans, A[top] * ((n - stack[-1] - 1) if stack else n))
        return ans
