#include <iostream>

void swap_nums(int &x, int &y) {
	int z = x;
	x = y;
	y = z;
}

int main() {
	int first_num = 10;
	int second_num = 30;
	std::cout << "before change:\n" << first_num << "\n" << second_num;
	swap_nums(first_num, second_num);
	std::cout << "\n\nafter change:\n" << first_num << "\n" << second_num;
	return 0;
}
