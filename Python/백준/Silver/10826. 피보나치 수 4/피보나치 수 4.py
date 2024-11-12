n = int(input())  # 0 <= n <= 10,000

# 피보나치 수열을 저장할 리스트
dp = [0, 1]

for i in range(2, n + 1):
    dp.append(dp[i - 1] + dp[i - 2])

print(dp[n])
