#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <algorithm>
using namespace std;

class Vector {
	public:
	vector<string> book_vector;
	vector<string> name_vector;
};		


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
	
	Vector obj;
	
do{
	cout << endl << "Enter the number: ";
	int a;
	cin >> a;
	
	
switch (a)
	{
	case 1: {
	if(obj.book_vector.size() == 0) {
		ifstream book_stream;
		book_stream.open("Books.txt");
		string b;
		while(getline(book_stream, b)){ 
			obj.book_vector.push_back(b);
		} 
		book_stream.close();
		sort(obj.book_vector.begin(),obj.book_vector.end());
		for (auto i:obj.book_vector){
			cout << i << endl;}}
	else {
		sort(obj.book_vector.begin(),obj.book_vector.end());
		for (auto i:obj.book_vector){
			cout << i << endl;}}
		break;
	}
	
	case 2: {
		if(obj.name_vector.size() == 0) {
		ifstream name_stream;
		name_stream.open("Names.txt");
		string n;
		while(getline(name_stream, n)){ 
			obj.name_vector.push_back(n);
		}
		name_stream.close();
		sort(obj.name_vector.begin(),obj.name_vector.end());
		for (auto i:obj.name_vector){
			cout << i << endl;}}
	else {
		sort(obj.name_vector.begin(),obj.name_vector.end());
		for (auto i:obj.name_vector){
			cout << i << endl;}}
	break;
	}
	
	case 3: {
		if(obj.book_vector.size() == 0) {
		ifstream book_stream;
		book_stream.open("Books.txt");
		string b;
		while(getline(book_stream, b)){ 
			obj.book_vector.push_back(b);
		} 
		book_stream.close();
		sort(obj.book_vector.begin(),obj.book_vector.end());}
		string asd;
		cout << "Enter the name of the book and its author: ";
		getline(cin >> ws, asd);
		obj.book_vector.push_back(asd);
		cout << "Done" << endl;
		break;
	}
	
	case 4: {
		if(obj.name_vector.size() == 0) {
		ifstream name_stream;
		name_stream.open("Names.txt");
		string n;
		while(getline(name_stream, n)){ 
			obj.name_vector.push_back(n);
		}
		name_stream.close();
		sort(obj.name_vector.begin(),obj.name_vector.end());}
		string asd;
		cout << "Enter the name of the reader: ";
		getline(cin >> ws, asd);
		obj.name_vector.push_back(asd);
		cout << "Done" << endl;
		break;
	}
	
	case 5: {
		if(obj.book_vector.size() == 0) {
		ifstream book_stream;
		book_stream.open("Books.txt");
		string b;
		while(getline(book_stream, b)){ 
			obj.book_vector.push_back(b);
		} 
		book_stream.close();
		sort(obj.book_vector.begin(),obj.book_vector.end());}
		string name;
		cout << "Enter the name of the book you are looking for: ";
		getline(cin >> ws, name);
		auto it = find(obj.book_vector.begin(),obj.book_vector.end(),name);
		if (it == obj.book_vector.end()) {
			cout << "No such book" << endl;}
			else cout << "Such a book exists" << endl;		
		break;	
	}
	
	case 6: {
		if(obj.name_vector.size() == 0) {
		ifstream name_stream;
		name_stream.open("Names.txt");
		string n;
		while(getline(name_stream, n)){ 
			obj.name_vector.push_back(n);
		}
		name_stream.close();
		sort(obj.name_vector.begin(),obj.name_vector.end());}
		string name;
		cout << "Enter the name of the reader you are looking for: ";
		getline(cin >> ws, name);
		auto it = find(obj.name_vector.begin(),obj.name_vector.end(),name);
		if (it == obj.name_vector.end()) {
			cout << "No such reader" << endl;}
			else cout << "Such a reader exists" << endl;		
		break;	
	}
	
	case 7: cout << "Sn" << endl; break;
	case 8: cout << "Df" << endl; break;
	case 9: return(0);
	default: cout << "Incorrect number" << endl; break;
	}
	
}
while (true);
return 0; 
}





