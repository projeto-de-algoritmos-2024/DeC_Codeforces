n, goal = map(int, input().split())
vs = list(map(int, input().split()))
prefix_sum = [0] * (n + 1)
MAX = 10**18

def binary_search(starting_index, left = 0, right = MAX):
    while right >= left:
        mid = (right + left) // 2

        current_index, current_sum, missing = starting_index, 0, mid

        if starting_index + mid >= n:
            current_index = 0
            current_sum += prefix_sum[n] - prefix_sum[starting_index]
            missing -= n - starting_index

        times = missing // n
        current_sum += times * prefix_sum[n]
        missing -= times * n

        if current_index != 0:
            current_sum += prefix_sum[current_index + missing] - prefix_sum[current_index]
        else:
            current_sum += prefix_sum[missing]

        if current_sum == goal:
            return True

        if current_sum > goal:
            right = mid - 1
        else:
            left = mid + 1

def solve():
    for starting_index in range(1, n + 1):
        prefix_sum[starting_index] = prefix_sum[starting_index - 1] + vs[starting_index - 1]

    for starting_index in range(n):
        res = binary_search(starting_index)

        if res or vs[starting_index] == goal:
            return True

    return False

print("Yes" if solve() else "No")
