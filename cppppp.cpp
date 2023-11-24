#ifdef _WIN32
	#define CLEAR "cls"
	#define PAUSE_COMMAND "pause"
#else 
	#define CLEAR "clear"
	#define PAUSE_COMMAND "read -p 'Press Enter to continue...' -n 1 -r"
#endif

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


fstream file;
//Add func
void Dict::sadd() {
	cout << "****** ADD NEW WORDS ******\n" <<
		"Enter new words EN/AZ\n";
	cout << "EN: "; cin >> word.en;
	cout << "AZ: "; cin >> word.az;


	file.open("file.txt", ios::app);
	file << word.en << endl << word.az << endl;
	file.close();
	system(PAUSE_COMMAND);
	system(CLEAR);

}

//List func
void Dict::slist(){
	cout << "****** LIST OF WORDS ******\n";
		file.open("file.txt", ios::in);
		while (file >> word.en >> word.az)
		{
			cout << "EN: " << word.en << endl
			<< "AZ: " << word.az << endl
			<< "==========================" << endl;
		}
		file.close();
		system(PAUSE_COMMAND);
		system(CLEAR);
		
		
}

//Sort func
void Dict::ssort(){
	cout << "****** SORTED LIST ******\n";
	file.open("file.txt", ios::in);
	string array[100];
	int i = 0;
	while (file >> word.en >> word.az)
	{
		array[i] = word.en;
		i++;
	}
	file.close();
	int n = i;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) {
			if (array[i] > array[j]) {
				string temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		file.open("file.txt", ios::in);
		while (file >> word.en >> word.az)
		{
			if (array[i] == word.en)
			{
				cout << "EN: " << word.en << endl
					<< "AZ: " << word.az << endl
					<< "==========================" << endl;
			}
		}
		file.close();
	}
	system(PAUSE_COMMAND);
	system(CLEAR);

}

//Delete func
void Dict::sdel(){
	cout << "****** DELETE WORD ******\n" <<
		"Enter word EN\n";
	string s;
	cout << "EN: "; cin >> s;

	file.open("file.txt", ios::in);
	int k = 0;
	while (file >> word.en >> word.az)
	{
		if (s.compare(word.en) == 0)
		{
			k = 1;
			break;
		}
	}
	file.close();
	if (k == 0) cout << "Not Found\n";
	else {
		file.open("file.txt", ios::in);
		ofstream temp;
		temp.open("temp.txt", ios::out);
		while (file >> word.en >> word.az)
		{
			if (s.compare(word.en) != 0)
			{
				temp << word.en << endl << word.az << endl;
			}
		}
		file.close();
		temp.close();
		remove("file.txt");
		rename("temp.txt", "file.txt");
		cout << "Deleted\n";
	}
	system(PAUSE_COMMAND);
	system(CLEAR);
	
}

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

	system(PAUSE_COMMAND);
	system(CLEAR);


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
			system(CLEAR);
			sadd();
			break;
		case 2:
			system(CLEAR);
			sfind();
			break;
		case 3:
			system(CLEAR);
			slist();
			break;
		case 4:
			system(CLEAR);
			ssort();
			break;
		case 5:
			system(CLEAR);
			sdel();
			break;
		case 6:
			squit();
			break;
		default:

			cout << " Invalid character\n";
			system(CLEAR);
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