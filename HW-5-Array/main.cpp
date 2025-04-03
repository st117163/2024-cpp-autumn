#include "array.h"

int main(int argc, char **argv)
{
    int int_arr[7] = {4, 3, 7, 11, 9, 2, 69};
	double double_arr[3] = {11.1, -7.3, 100.69};
	char char_arr[6] = {'H', 'e', 'l', 'l', 'o', '!'};
	std::string str_arr[4] = {"earth", "water", "fire", "air"};

	Array<int, 7> iArr(int_arr);
	Array<double, 3> dArr(double_arr);
	Array<char, 6> cArr(char_arr);
	Array<std::string, 4> sArr(str_arr);

	iArr.show();
	dArr.show();
	cArr.show();
	sArr.show();

	std::cout << "Minimal value in iArr is " << iArr.minimum(iArr) << std::endl;
	std::cout << "Minimal value in dArr is " << dArr.minimum(dArr) << std::endl;
	std::cout << "Minimal value in cArr is " << cArr.minimum(cArr) << std::endl;
	std::cout << "Minimal value in sArr is " << sArr.minimum(sArr) << std::endl;
	return EXIT_SUCCESS;
}