#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

class Word {
public:
	string en, az;
};

class Dict {
	Word word;
	void sadd();
	void slist();
	void ssort();
	void sdel();
	void squit();
	void sfind();
	void menu();
public:
	void start();


};


//Add func
void Dict::sadd() {
	cout << "****** ADD NEW WORDS ******\n" <<
		"Enter new words EN/AZ\n";
	cout << "EN: "; cin >> word.en;
	cout << "AZ: "; cin >> word.az;

	fstream file;

	file.open("file.txt", ios::app);
	file << word.en << endl << word.az << endl;
	file.close();
	system("pause");
	system("CLS");

}

//List func
void Dict::slist(){}

//Sort func
void Dict::ssort(){}

//Delete func
void Dict::sdel(){}

//Quit func
void Dict::squit(){
	exit(1);
}

//Find quit
void Dict::sfind(){
	cout << "****** ENTER WORD IN EN ******\n" <<
		"Enter word EN\n";
	string s;
	cout << "EN: "; cin >> s;

	fstream file;

	file.open("file.txt", ios::in);
	int k = 0;
	while (file >> word.en >> word.az)
	{
		if (s.compare(word.en) ==0)
		{
			cout << "AZ: " << word.az << endl;
			k = 1;
			break;
		}
	}
	file.close();
	if (k == 0) cout << "Not Found\n";

	system("pause");
	system("CLS");


}

//Menu func
void Dict::menu(){
	do
	{
		cout << "***** EN-AZ DICTIONARY *****" << endl <<
			"1. ADD\n" <<
			"2. FIND\n" <<
			"3. LIST\n" <<
			"4. SORT\n" <<
			"5. DEL\n" <<
			"6. QUIT\n";
		int n;
		cin >> n;

		switch (n)
		{
		case 1:
			system("CLS");
			sadd();
			break;
		case 2:
			system("CLS");
			sfind();
			break;
		case 3:
			system("CLS");
			slist();
			break;
		case 4:
			system("CLS");
			ssort();
			break;
		case 5:
			system("CLS");
			sdel();
			break;
		case 6:
			squit();
			break;
		default:
			cout << " Invalid character\n";
			system("CLS");
			break;
		}

	} while (true);
}


//Start invoker
void Dict::start(){

	menu();
}


int main() {
	Dict t;
	t.start();
	
	



	return 0;
}