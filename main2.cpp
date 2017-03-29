#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <algorithm>
#include <map>
#include <cctype>

using namespace std;


int main()
{	
	vector<string> book_vector;
	vector<string> name_vector;
	map<string,string> bn;
	
	if(book_vector.empty()) {
		ifstream stream;
		stream.open("Books.txt");
		if (!stream) {cout << "Book's file is not loaded" << endl;}
			else {cout << "Book's file is loaded" << endl;}
		string str;
		while(getline(stream, str)){book_vector.push_back(str);} 
		stream.close();	
		
	} 
	
	if(name_vector.empty()) {
		ifstream stream;
		stream.open("Names.txt");
		if (!stream) {cout << "Reader's file is not loaded" << endl;}
			else {cout << "Reader's file is loaded" << endl;}
		string str;
		while(getline(stream, str)){name_vector.push_back(str);}
		stream.close();
	}
	
	if(bn.empty()) {
		ifstream streamB;
		ifstream streamN;
		streamB.open("Given_books.txt");
		streamN.open("Given_names.txt");
		if (!streamB || !streamN) {cout << "Given's list file is not loaded" << endl;}
			else {cout << "Given's list file is loaded" << endl;}
		string list1;
		string list2;
		while(getline(streamB, list1) && getline(streamN, list2)){ 
			bn.insert(make_pair(list1, list2));;
		}
		streamB.close();
		streamN.close();
	}
		
		
		
do{
	cout << endl << "Libary" << endl;
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
	
	cout << endl << endl << "Enter the number: ";
	int a;
	cin >> a;
	cin.clear();
	cin.sync();
	
	
switch (a)
	{
	case 1: {
		if (book_vector.empty()) {cout << "No books" << endl; break;}
		sort(book_vector.begin(),book_vector.end());
		for (auto i:book_vector){ cout << i << endl;}
		break;
	}
	
	case 2: {
		if (name_vector.empty()) {cout << "No readers" << endl; break;}
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
		
		ofstream stream;
		stream.open("Books.txt", ios::trunc);
		for (auto i:book_vector){stream << i << endl;}
		stream.close();
		break;
	}
	
	case 4: {
		string asd;
		cout << "Enter the name of the reader: ";
		getline(cin >> ws, asd);
		name_vector.push_back(asd);
		cout << "Done" << endl;
			
		ofstream stream;
		stream.open("Names.txt", ios::trunc);
		for (auto i:name_vector){stream << i << endl;}
		stream.close();
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
		unsigned int b;
		bool flag;
		
		while (true) {
			flag = true;
			cout << endl << "Enter the book's code: ";
			cin >> b; 		
			if (!cin) {cout << "Incorrect enter" << endl; cin.clear(); cin.sync(); continue;}
			if (b<0 || b>=book_vector.size()) {cout << "Wrong code" << endl; continue;}
			for (auto i:bn)
			{if (book_vector[b] == i.first) {cout << "The book is already given" << endl; flag = false; break;}}
			if (flag == false) continue;
			break;
				
		}
				
		cout << endl << "Choose the reader: " << endl;
		sort(name_vector.begin(),name_vector.end());
		for (unsigned int j = 0; j < name_vector.size(); j++){ cout << j << ' ' << '-' << ' ' << name_vector[j] << endl;}
		unsigned int n;
		
		while (true) {
			cout << endl << "Enter the reader's code: ";
			cin >> n;
			if (!cin) {cout << "Incorrect enter" << endl; cin.clear(); cin.sync(); continue;}
			if (n<0 || n>=name_vector.size()) {cout << "Wrong code" << endl; continue;}
			break;
		}
				
		bn.insert (make_pair(book_vector[b], name_vector[n]));
		cout << endl << "The book " << book_vector[b] << " is given to " << name_vector[n] << endl;
		
		ofstream streamB, streamN;
		streamB.open("Given_books.txt", ios::trunc);
		streamN.open("Given_names.txt", ios::trunc);
		for (auto i = bn.begin(); i != bn.end(); i++){streamB << i->first << endl; streamN << i->second << endl;}
		streamB.close();
		streamN.close();		
		break;
	}
	
	case 8: {
		if (bn.empty()) {cout << "Nothing to return" << endl; break;}
		unsigned int j = 0;
		for (auto i:bn) {
			cout << j << ' ' << '-' << ' ' << "The book " << i.first << " is given to " << i.second << endl;
			j++;}
		unsigned int b;
		while (true) {	
			cout << endl << "Choose the code to delete: ";
			cin >> b; 		
			if (!cin) {cout << "Incorrect enter" << endl; cin.clear(); cin.sync(); continue;}
			if (b<0 || b>=bn.size()) {cout << "Wrong code" << endl; continue;}
			break;}
			j = 0;
			for (auto i = bn.begin(); i != bn.end(); i++,j++){
				if(j == b){bn.erase(i->first);break;}
			}
			cout << "Delete complete" << endl ;
			
		ofstream streamB, streamN;
		streamB.open("Given_books.txt", ios::trunc);
		streamN.open("Given_names.txt", ios::trunc);
		for (auto i = bn.begin(); i != bn.end(); i++){streamB << i->first << endl; streamN << i->second << endl;}
		streamB.close();
		streamN.close();		
		break;
	}
	
	case 9: {
		if (bn.empty()) {cout << "No given books" << endl; break;}
		else
		for (auto i:bn) {cout << "The book " << i.first << " is given to " << i.second << endl;}
		break;
	}
	
	case 10: return(0);
	
	default: {cout << "Incorrect enter" << endl; break;}
	}
	
}
while (true);
return 0; 
}
