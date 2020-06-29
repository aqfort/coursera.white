Лидирующие нули: printf("%02d:%02d\n", hours, minutes);

//these gcd-programs may give negative numbers

НОД:
int gcd(int a, int b) {
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int gcd(int a, int b) {
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int gcd(int a, int b) {
	while(true) {
		a = a % b;
		if(a == 0)
			return b;
		b = b % a;
		if(b == 0)
			return a;
	}
}

НОД * НОК = a * b;

unsigned int fact(unsigned int n) {
	int fuck = 1;
	if(n > 1)
		fuck = n * fact(n - 1);
	return fuck;
}

#define false 1
#define true 0

Пока A > 0 и B > 0:
 Если A > B:
 A = A % B
 иначе:
 B = B % A
Вывести A + B
