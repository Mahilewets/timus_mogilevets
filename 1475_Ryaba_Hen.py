def solve(H, l, h):
	rhs = (H*H + l*l)//H
	low = 0
	high = 10**101
	while low < high:
		mid = (low + high) >> 1
		val = 4*h*mid*(mid+1)
		if val > rhs:
			high = mid
		else:
			low = mid + 1
	return low
N = int(input())
for i in range(N):
	H, l, h = map(int, input().split())
	res = solve(H, l, h)
	print(int(res))
