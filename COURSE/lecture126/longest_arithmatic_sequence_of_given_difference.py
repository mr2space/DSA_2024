
def longestSubsequence(self, arr: list[int], difference: int) -> int:
    i = 0
    dp = {}
    longest_sequence = 1
    if arr == []:
        return 0
    for i in range(len(arr)):
        if dp.get(arr[i]-difference, False):
            dp[arr[i]] = dp[arr[i]-difference] + 1
        else:
            dp[arr[i]] = 1
    return max(dp.values())