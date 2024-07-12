class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        def solve(s, x, y):
            if len(s) <= 0:
                return 0
            pos1 = s.find("ab");
            score1 = 0;
            if (pos1 != -1):
                score1 = solve(s.strip("ab"), x, y) + x
            pos2 = s.find("ba")
            score2 = 0;
            if (pos2 != -1):
                score2 = solve(s.strip("ba"), x, y) + y
            return max(score1, score2)
        return solve(s, x, y)