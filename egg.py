
# using namespace std;
# int main() {
# 	int x;
# 	x = 63;
# 	while (x < 100000)
# 	{
# 		if (x % 63 == 0 && x % 8 == 1 && x % 6 == 3 && x % 5 == 4)
# 		{
# 			printf("%d", x);
# 		}
# 		x++;
# 	}
# 	if (x >= 100000)
# 		printf("no solution.");
# 	return 0;
# }

x = 0
while True:
#    if (x % 63 == 0 and x % 8 == 1 and x % 6 == 3 and x % 5 == 4):
    if (x % 2 == 1 and x % 3 == 0 and x % 4 == 1 and x % 5 == 4 and x % 6 == 3 and x % 7 == 0 and x % 8 == 1 and x % 9 == 0):
        print(x)
    if (x > 10000):
        break
    x = x + 1
