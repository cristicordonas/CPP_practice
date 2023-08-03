#include <iostream>

int main(int argc, char* argv[])
{
	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		printf("No program arguments found.\n");
		return 1;
	}

	//Print the arguments, one on each line.
	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}

	return 0;
}
