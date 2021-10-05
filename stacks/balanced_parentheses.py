class Solution:
    # @param A : string
    # @return an integer
    def solve(self, A):
        stack = []
        for p in A:
            if p == ")":
                if len(stack) > 0:
                    stack.pop()
                else:
                    return 0
            else:
                stack.append(p)
        return 1 if len(stack) == 0 else 0
