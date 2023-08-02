#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class Book
{
public:
	std::string name;
	std::string authors;

	void print()
	{
		std::cout << this->name << std::endl;
		std::cout << "\t(by " << this->authors << ")" << std::endl;
	}
};


std::vector<Book> readBooksFromTextFile(const std::string& file_name)
{
	std::vector<Book> results;
	std::ifstream file(file_name);
	if (file.is_open())
	{
		std::string line;
		int line_number = 0;
		Book myBook;
		while (std::getline(file, line))
		{
			line_number++;
			if (line_number % 2 == 1)
			{
				myBook.name = line;
			}
			else
			{
				myBook.authors = line;
				results.emplace_back(myBook);
			}

		}
		file.close();
	}
	else
	{
		std::cout << "The file cannot be opened." << std::endl;
	}

	return results;
}

int main()
{
	std::string input_data("../../data/ermahgerd_berks.txt");
	std::cout << "Reading the data from " << input_data << std::endl;
	std::vector<Book> books_from_file = readBooksFromTextFile(input_data);

	std::cout << "Here are all the books found in the data file..." << std::endl;
	for (auto book : books_from_file)
	{
		book.print();
	}

	return 0;
}