#include <iostream>
#include <string>
#include <vector>
#include <set>


struct Book {
	std::string book_name;
	std::string author;
	std::string publisher;
	std::string genre;
	int year;

	void print_book() {
		std::cout << "Name: " << book_name << std::endl;
		std::cout << "Author: " << author << std::endl;
		std::cout << "Publisher: " << publisher << std::endl;
		std::cout << "Genre: " << genre << std::endl;
		std::cout << "Year: " << year << std::endl;
	}
};


struct Library {
	std::vector <Book> book;
};


int getAction();
void printBooks(std::vector<Book>& b);
void findAuthor(std::vector<Book>& b);
void findBookName(std::vector<Book>& b);
void findOldBook(std::vector<Book>& b);
void changeBook(std::vector<Book>& b);
void addBook(std::vector<Book>& b);
void deleteBook(std::vector<Book>& b);
void sortBooks(std::vector<Book>& b);


int main() {

	std::vector <Book> book;

	book.push_back({ "The_Pop-Up_Dear_Zoo", "Rod_Campbell",
		"Macmillan Children's Books", "Children's play books", 2018 });
	book.push_back({ "Hide_and_Seek", "Taro_Gomi",
		"Chronicle Books; Brdbk edition", "Children's play books", 2013 });
	book.push_back({ "Mommy!_Mommy!", "Taro_Gomi",
		"Chronicle Books; Translation edition", "Children's play books", 2013 });
	book.push_back({ "Hug", "Jez_Alborough",
		"Walker Books", "Children's story books", 2016 });
	book.push_back({ "Haathi_Bhai", "Tulika_Publishers",
		"Tulika Publishers, Paridhi Didwania", "Children's story books", 2017 });
	book.push_back({ "Akkad_Bakkad", "Shreya_Sen",
		"Tulika Publishers", "Children's story books", 2017 });
	book.push_back({ "I_Know_Numbers!", "Taro_Gomi",
		"Chronicle Books", "Children's books: Learning Maths", 2017 });
	book.push_back({ "Why_I_Love_My_Mummy", "Daniel_Howarth",
		"HarperCollins Children's Books", "Children's books: Learning Science", 2014 });
	book.push_back({ "Alphablock", "Christopher_Franceschelli",
		"Harry N. Abrams, Brdbk edition", "Children's books: Reading & Writing", 2013 });

	while (true) {

		int action = getAction();

		if (action == 1) {
			printBooks(book);
		}
		else if (action == 2) {
			findAuthor(book);
		}
		else if (action == 3) {
			findBookName(book);
		}
		else if (action == 4) {
			findOldBook(book);
		}
		else if (action == 5) {
			changeBook(book);
		}
		else if (action == 6) {
			addBook(book);
		}
		else if (action == 7) {
			deleteBook(book);
		}
		else if (action == 8) {
			sortBooks(book);
		}
		else if (action == 0) {
			std::cout << "Thank you! Good bye!" << std::endl;
			break;
		}
	}

	system("pause");
	return 0;
}


int getAction() {

	std::cout << std::endl;
	std::cout << "Please, choose action:" << std::endl;
	std::cout << "enter 1 - to print all books;" << std::endl;
	std::cout << "enter 2 - to search author;" << std::endl;
	std::cout << "enter 3 - to search book_name;" << std::endl;
	std::cout << "enter 4 - to search old book;" << std::endl;
	std::cout << "enter 5 - to change book information;" << std::endl;
	std::cout << "enter 6 - to add book;" << std::endl;
	std::cout << "enter 7 - to delete book;" << std::endl;
	std::cout << "enter 8 - to sort book_name;" << std::endl;
	std::cout << "enter 0 - to EXIT" << std::endl;
	int act = 0;
	std::cin >> act;
	return act;
}


void printBooks(std::vector<Book>& b) {
	for (int i = 0; i < b.size(); ++i) {
		std::cout << i << std::endl;
		b[i].print_book();
	}
}


void findAuthor(std::vector<Book>& b) {
	std::cout << "Enter author" << std::endl;
	std::cout << "(Please, when you enter author's name and " << std::endl;
	std::cout << "surname, use '_', not use ' ')" << std::endl;
	std::string auth;
	std::cin >> auth;

	int sum = 0;
	for (int i = 0; i < b.size(); ++i) {
		if (auth == b[i].author) {
			std::cout << i << std::endl;
			b[i].print_book();
		}
		else {
			++sum;
		}
	}

	if (sum == 9) {
		std::cout << "This author's book is not found in library" << std::endl;
	}
}


void findBookName(std::vector<Book>& b) {
	std::cout << "Enter book_name" << std::endl;
	std::cout << "(Please, when you enter book_name " << std::endl;
	std::cout << "use '_', not use ' ')" << std::endl;
	std::string b_name;
	std::cin >> b_name;

	int count = 0;
	for (int i = 0; i < b.size(); ++i) {
		if (b_name == b[i].book_name) {
			std::cout << i << std::endl;
			b[i].print_book();
		}
		else {
			++count;
		}
	}
	if (count == 9) {
		std::cout << "This book is not found in library" << std::endl;
	}
}


void findOldBook(std::vector<Book>& b) {
	int old = 0;
	for (int i = 0; i < b.size(); ++i) {
		if (b[i].year <= b[old].year) {
			old = i;
		}
	}
	for (int i = 0; i < b.size(); ++i) {
		if (b[i].year == b[old].year) {
			std::cout << i << std::endl;
			b[i].print_book();
		}
	}
}


void changeBook(std::vector<Book>& b) {
	std::cout << "Enter number of book what do you want ";
	std::cout << "to change (0 - " << b.size() - 1 << ")" << std::endl;
	int number = 0;
	std::cin >> number;
	std::cout << "Choose part what do you want to change:" << std::endl;
	std::cout << "enter \'n\' - if you want to change book name" << std::endl;
	std::cout << "enter \'a\' - if you want to change author" << std::endl;
	std::cout << "enter \'p\' - if you want to change publisher" << std::endl;
	std::cout << "enter \'g\' - if you want to change genre" << std::endl;
	std::cout << "enter \'y\' - if you want to change year" << std::endl;
	char choose;
	std::cin >> choose;
	std::cout << "Enter changes" << std::endl;
	std::string changes;
	int changes_year;
	if (choose != 'y') {
		std::cin >> changes;
	}
	else {
		std::cin >> changes_year;
	}

	for (int i = 0; i < b.size(); ++i) {
		if (i == number) {
			if (choose == 'n') {
				b[i].book_name = changes;
			}
			else if (choose == 'a') {
				b[i].author = changes;
			}
			else if (choose == 'p') {
				b[i].publisher = changes;
			}
			else if (choose == 'g') {
				b[i].genre = changes;
			}
			else if (choose == 'y') {
				b[i].year = changes_year;
			}
			else {
				std::cout << "Error choose" << std::endl;
			}
		}
	}
}


void addBook(std::vector<Book>& b) {
	std::cout << "Enter book_name: " << std::endl;
	std::string new_name;
	std::cin >> new_name;
	std::cout << "Enter author: " << std::endl;
	std::string new_author;
	std::cin >> new_author;
	std::cout << "Enter publisher: " << std::endl;
	std::string new_publisher;
	std::cin >> new_publisher;
	std::cout << "Enter genre: " << std::endl;
	std::string new_genre;
	std::cin >> new_genre;
	std::cout << "Enter year: " << std::endl;
	int new_year = 0;
	std::cin >> new_year;

	b.push_back({ new_name, new_author,
		new_publisher, new_genre, new_year });
}


void deleteBook(std::vector<Book>& b) {
	std::cout << "Enter number of book what do you want to delete" << std::endl;
	int number_delete = 0;
	std::cin >> number_delete;

	b.erase(b.begin() + number_delete);
}


void sortBooks(std::vector<Book>& b) {
	std::set<std::string> mySet;
	for (int i = 0; i < b.size(); ++i) {
		mySet.insert(b[i].book_name);
	}

	for (auto it = mySet.begin(); it != mySet.end(); ++it) {
		for (int i = 0; i < b.size(); ++i) {
			if (b[i].book_name == *it) {
				b[i].print_book();
			}
		}
	}
}


