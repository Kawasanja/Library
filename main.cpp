#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
using namespace std;

class Book {
	private:
	vector<string> book_vector;
		
	public:
	void set_book_vector (const string & asd){
		book_vector.push_back (asd);
		}
		
	void get_book_vector (){
		for (unsigned int i = 0; i<book_vector.size(); i++){
			cout << book_vector[i] << endl;}
		}
		
};
/*
class Name {
	private:
	vector<string> name_vector;
	
	public:
	void set_name_vector (vector<string> & asd){
		name_vector = asd;
		}
		
	void get_name_vector (){
		for (unsigned int i = 0; i<name_vector.size(); i++){
			cout << name_vector[i] << endl;}
		}
		
};*/

int main()
{	
	cout << "Libary" << endl << endl;
	cout << "1 - show all books" << endl;
	cout << "2 - show all readers" << endl;
	cout << "3 - add book" << endl;
	cout << "4 - add reader" << endl;
	cout << "5 - find the book" << endl;
	cout << "6 - find the reader" << endl;
	cout << "7 - give the book to the reader" << endl;
	cout << "8 - return the book from the reader" << endl;
	cout << "9 - exit" << endl << endl;
	

	
do{
	cout << endl << "Enter the number: ";
	int a;
	cin >> a;
	switch (a)
	{
	case 1: {
		ifstream book_stream;
		book_stream.open("Books.txt");
		string b;
		Book obj;
		while(getline(book_stream, b)){ 
			obj.set_book_vector(b);
		} 
		book_stream.close();
		obj.get_book_vector();
		break;
	}
	/*
	case 2: {
		ifstream name_stream;
		name_stream.open("Names.txt");
		string n;
		Name obj;
		while(getline(name_stream, n)){ 
			obj.name_vector.push_back(n);
		}
		name_stream.close();
		obj.get_name_vector();
	break;
	}*/
	case 3: {
		string asd;
		cout << "Enter the name of the book and its author: ";
		getline(cin >> ws, asd);
		Book obj;
		obj.set_book_vector(asd);
		cout << "Done" << endl;
		break;
	}
	case 4: cout << "Th" << endl; break;
	case 5: cout << "Fr" << endl; break;
	case 6: cout << "St" << endl; break;
	case 7: cout << "Sn" << endl; break;
	case 8: cout << "Df" << endl; break;
	case 9: return(0);
	default: cout << "Incorrect number" << endl; break;
	}
}
while (true);
	
	

	

    return 0; 
}





