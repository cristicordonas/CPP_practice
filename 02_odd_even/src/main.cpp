#include <stdio.h>
#include <iostream>
#include <string>

void printOddOrEven(int number)
{
	if (number % 2 == 0)
	{
		printf("EVEN\n");
	}
	else
	{
		printf("ODD\n");
	}
}

int main(int argc, char *argv[])
{
	int number = -13;

	if (argc <= 1)
	{
		printf("No program arguments found.\n");
	}

	std::string argumentAsString = argv[1];
	const char* argumentAsCharArray = argumentAsString.c_str();
	number = std::atoi(argumentAsCharArray); 

	if (number == 0 && argumentAsString != "0")
	{
		printf("NAN\n");
		return 1;
	}
	
	printOddOrEven(number);

	return 0;
}
