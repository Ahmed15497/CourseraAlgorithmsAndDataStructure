#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}


int gcd_fast(int a, int b) {
  int temp = 0;
	if (a < b){
    temp = a;
    a = b;
    b = temp;
  }
  if (b == 0){
    return a;
  }else{
    temp = a % b;
    a = b;
    b = temp;

  }

	return gcd_fast(a,b);
}


long long lcm_fast(int a, int b) {

  int gcd = gcd_fast(a, b);
  int b_new = b / gcd;
  long long lcm = (long long) a * b_new;
  return lcm;
}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

