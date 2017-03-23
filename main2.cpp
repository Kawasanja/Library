#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <algorithm>
#include <map>
using namespace std;


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
	cout << "9 - watch the book's given list" << endl;
	cout << "10 - exit" << endl;
	
	
	vector<string> book_vector;
	vector<string> name_vector;
	map<string,string> bn;
	
	if(book_vector.size() == 0) {
		ifstream book_stream;
		book_stream.open("Books.txt");
		string b;
		while(getline(book_stream, b)){ 
			book_vector.push_back(b);
		} 
		book_stream.close();
		sort(book_vector.begin(),book_vector.end());
	}
	
	if(name_vector.size() == 0) {
		ifstream name_stream;
		name_stream.open("Names.txt");
		string n;
		while(getline(name_stream, n)){ 
			name_vector.push_back(n);
		}
		name_stream.close();
		sort(name_vector.begin(),name_vector.end());
	}
	
	

do{
	cout << endl << endl << "Enter the number: ";
	int a;
	cin >> a;
	cin.clear();
	cin.sync();
	
	
switch (a)
	{
	case 1: {
		sort(book_vector.begin(),book_vector.end());
		for (auto i:book_vector){ cout << i << endl;}
		break;
	}
	
	case 2: {
		sort(name_vector.begin(),name_vector.end());
		for (auto i:name_vector){ cout << i << endl;}
	break;
	}
	
	case 3: {
		string asd;
		cout << "Enter the name of the book and its author: ";
		getline(cin >> ws, asd);
		book_vector.push_back(asd);
		cout << "Done" << endl;
		break;
	}
	
	case 4: {
		string asd;
		cout << "Enter the name of the reader: ";
		getline(cin >> ws, asd);
		name_vector.push_back(asd);
		cout << "Done" << endl;
		break;
	}
	
	case 5: {
		string name;
		cout << "Enter the name of the book you are looking for: ";
		getline(cin >> ws, name);
		auto it = find(book_vector.begin(),book_vector.end(),name);
		if (it == book_vector.end()) {
			cout << "No such book" << endl;}
			else cout << "Such a book exists" << endl;		
		break;	
	}
	
	case 6: {
		string name;
		cout << "Enter the name of the reader you are looking for: ";
		getline(cin >> ws, name);
		auto it = find(name_vector.begin(),name_vector.end(),name);
		if (it == name_vector.end()) {
			cout << "No such reader" << endl;}
			else cout << "Such a reader exists" << endl;		
		break;	
	}
	
	case 7: {
		cout << endl << "Choose the book: " << endl;
		sort(book_vector.begin(),book_vector.end());
		for (unsigned int i = 0; i < book_vector.size(); i++){ cout << i << ' ' << '-' << ' ' << book_vector[i] << endl;}
	b1:	cout << endl << "Enter the book's code: ";
		unsigned int b;
		cin >> b;
		if (b<0 || b>=book_vector.size()) {cout << "Wrong code" << endl; goto b1;}
		
		for (auto i:bn){
		if (book_vector[b] == i.first) {cout << "The book is already given"; goto b1;}}
				
		cout << endl << "Choose the reader: " << endl;
		sort(name_vector.begin(),name_vector.end());
		for (unsigned int j = 0; j < name_vector.size(); j++){ cout << j << ' ' << '-' << ' ' << name_vector[j] << endl;}
	n1:	cout << endl << "Enter the reader's code: ";
		unsigned int n;
		cin >> n;
		if (n<0 || n>=name_vector.size()) {cout << "Wrong code" << endl; goto n1;}
				
		bn.insert (make_pair(book_vector[b], name_vector[n]));
		cout << endl << "The book " << book_vector[b] << " is given to " << name_vector[n];
		break;
	}
	
	case 8: {
		int j = 0;
		for (auto i:bn) {
			cout << endl << j << ' ' << '-' << ' ' << "The book " << i.first << " is given to " << i.second;
			j++;}
			cout << endl << endl << "Choose the code to delete: ";
			unsigned int b;
			cin >> b;
			
			for (auto i = bn.begin(); i != bn.end(); i++){
			bn.erase(book_vector[b]);}
			cout << "Delete complete";
			
		break;
	}
	
	case 9: {
		for (auto i:bn) {cout << endl << "The book " << i.first << " is given to " << i.second;}
		break;
	}
	
	case 10: return(0);
	
	default: {cout << "Incorrect enter" << endl; break;}
	}
	
}
while (true);
return 0; 
}
