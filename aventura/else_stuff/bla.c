#include <stdio.h>
#include <stdlib.h>

typedef void (*soma)(int, int);
void somar(int x, int y) {
	printf("%d\n", (x+y));
}

int main() {
	void** func = malloc(sizeof(soma));
	soma g = somar;
	func[0] = g;
	((soma)func[0])(1, 2);

	return 0;
}
