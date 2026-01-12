import sys
input = sys.stdin.readline

N, M = map(int, input().split())
nums = list(map(int, input().split()))

nums.sort()              # 1) 정렬
path = [0] * M           # 2) 길이 M짜리 수열 저장용
result = []              # 3) 출력할 문자열들 모아두기

def dfs(depth, start):
    # depth: 지금까지 몇 개 골랐는지 (0 ~ M)
    # start: 이번 칸에서 몇 번 인덱스부터 볼지

    if depth == M:       # 4) M개 다 골랐으면 출력 후보에 추가
        result.append(" ".join(map(str, path)))
        return

    prev = 0             # 5) 이 depth(칸)에서 바로 직전에 쓴 숫자
    for i in range(start, N):
        if i > 0 and prev == nums[i]:
            # 6) 같은 depth에서 이미 쓴 숫자면 스킵
            continue

        prev = nums[i]   # 7) 이번 depth에서 쓴 숫자 기록
        path[depth] = nums[i]     # 8) 현재 칸에 숫자 배치
        dfs(depth + 1, i)         # 9) 다음 칸 채우러 이동 (i부터 가능)

dfs(0, 0)
print("\n".join(result))
