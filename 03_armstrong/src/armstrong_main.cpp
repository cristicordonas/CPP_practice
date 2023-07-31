#include <iostream>

bool isArmstrongNumber(int number)
{
	int originalNum, digit, result;
	originalNum = number;
	result = 0;
	while (number != 0) 
	{
		digit = number % 10;
		result += digit * digit * digit;
		number /= 10;
	}
	if (result == originalNum)
	{
		return true;
	}
	return false;
}

void printIsArmstrong(int number)
{
	if (isArmstrongNumber(number))
	{
		std::cout << "Armstrong" << std::endl;
	}
	else
	{
		std::cout << "NOT Armstrong" << std::endl;
	}
}

int main(int argc, char *argv[])
{

	if (argc <= 1)
	{
		std::cout << "No program arguments found." << std::endl;
		return 1;
	}

	int readNumber = 0;
	std::string argumentAsString = argv[1];
	
	readNumber = std::atoi (argumentAsString.c_str());
	if (readNumber == 0 && argumentAsString != "0")
	{
		printf("NAN\n");
		return 1;
	}

	printIsArmstrong(readNumber);
	return 0;
}
