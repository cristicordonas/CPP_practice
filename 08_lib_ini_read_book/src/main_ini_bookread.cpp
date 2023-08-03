// Includes

// C++ system headers
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <SimpleIni.h>

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

std::vector<Book> readBooksFromIniFile(const std::string& file_name)
{
	std::vector<Book> results;
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(file_name.c_str());
	if (rc < 0) 
	{
		std::cout << "The file can not be accessed" << std::endl;
		return results;
	}

	Book myBook;
	std::string section_name;
	std::string section_authors;
	const char* count;
	count = ini.GetValue("books", "count");
	std::stringstream ss;
	for (int i = 0; i < std::atoi(count); i++)
	{
		ss.str("");
		ss << "book." << (i + 1);
		section_name = ini.GetValue(ss.str().c_str(), "name");
		section_authors = ini.GetValue(ss.str().c_str(), "author");
		myBook.name = section_name;
		myBook.authors = section_authors;
		results.emplace_back(myBook);
	}
	return results;
}

int main()
{
	std::string input_data("../../data/ermahgerd_berks.ini");
	std::cout << "Reading the data from " << input_data << std::endl;
	std::vector<Book> books_from_file = readBooksFromIniFile(input_data);

	std::cout << "Here are all the books found in the data file..." << std::endl;
	for (auto book : books_from_file)
	{
		book.print();
	}

	return 0;
}