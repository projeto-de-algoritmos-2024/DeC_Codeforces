def solve():
        n = int(input())
        s = input()

        def good_string(sub, char):
                if len(sub) == 1: return 1 if sub[0] != char else 0

                mid = len(sub) // 2
                left_half = sub[:mid]
                right_half = sub[mid:]
                count1 = len(left_half) - sum(1 for c in left_half if c == char)
                count1 += good_string(right_half, chr(ord(char) + 1))                
                count2 = len(right_half) - sum(1 for c in right_half if c == char)
                count2 += good_string(left_half, chr(ord(char) + 1))

                return min(count1, count2)

        print(good_string(s, 'a'))

t = int(input())
for _ in range(t):
        solve()
