// 매개변수의 선언으로 함수 포인터 변수가 올 수 있다.
// 전달되는 인자에 따라서 달리 동작하는 함수의 정의도 가능하다.

#include <stdio.h>

int WhoIsFirst(int age1, int age2, int (*cmp)(int n1, int n2)) {
	return cmp(age1, age2);
}

int OlderFirst(int age1, int age2) {
	if (age1 > age2) {
		return age1;
	}
	else if (age1 < age2) {
		return age2;
	}
	else {
		return 0;
	}
}

int YoungerFirst(int age1, int age2) {
	if (age1 < age2) {
		return age1;
	}
	else if (age1 > age2) {
		return age2;
	}
	else {
		return 0;
	}
}

int main(void) {
	int age1 = 20;
	int age2 = 30;
	int first;

	printf("입장순서 1 \n");
	first = WhoIsFirst(age1, age2, OlderFirst);
	printf("%d세와 %d세 중 %d세가 먼저 입장! \n\n", age1, age2, first);

	printf("입장순서 2 \n");
	first = WhoIsFirst(age1, age2, YoungerFirst);
	printf("%d세와 %d세 중 %d세가 먼저 입장! \n\n", age1, age2, first);
	return 0;
}