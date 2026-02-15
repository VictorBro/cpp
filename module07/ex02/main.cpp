#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
	std::cout << "=== Empty array ===" << std::endl;
	Array<int> empty;
	std::cout << "size: " << empty.size() << std::endl;
	try {
		empty[0];
	} catch (std::exception &e) {
		std::cout << "Access empty[0]: exception caught" << std::endl;
	}

	std::cout << "\n=== Int array (5) ===" << std::endl;
	Array<int> nums(5);
	for (unsigned int i = 0; i < nums.size(); i++)
		std::cout << "nums[" << i << "] = " << nums[i] << std::endl;

	std::cout << "\n=== Modify values ===" << std::endl;
	for (unsigned int i = 0; i < nums.size(); i++)
		nums[i] = (i + 1) * 10;
	for (unsigned int i = 0; i < nums.size(); i++)
		std::cout << "nums[" << i << "] = " << nums[i] << std::endl;

	std::cout << "\n=== Copy constructor ===" << std::endl;
	Array<int> copy(nums);
	nums[0] = 999;
	std::cout << "nums[0] = " << nums[0] << std::endl;
	std::cout << "copy[0] = " << copy[0] << " (unchanged)" << std::endl;

	std::cout << "\n=== Assignment operator ===" << std::endl;
	Array<int> assigned;
	assigned = nums;
	nums[1] = 888;
	std::cout << "nums[1] = " << nums[1] << std::endl;
	std::cout << "assigned[1] = " << assigned[1] << " (unchanged)" << std::endl;

	std::cout << "\n=== Out of bounds ===" << std::endl;
	try {
		nums[42];
	} catch (std::exception &e) {
		std::cout << "Access nums[42]: exception caught" << std::endl;
	}

	std::cout << "\n=== String array ===" << std::endl;
	Array<std::string> strs(3);
	strs[0] = "hello";
	strs[1] = "world";
	strs[2] = "!";
	for (unsigned int i = 0; i < strs.size(); i++)
		std::cout << "strs[" << i << "] = " << strs[i] << std::endl;

	std::cout << "\n=== Const array ===" << std::endl;
	const Array<int> constArr(nums);
	std::cout << "constArr[0] = " << constArr[0] << std::endl;
	std::cout << "constArr.size() = " << constArr.size() << std::endl;

	return 0;
}

// // --- PDF test ---
// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }
