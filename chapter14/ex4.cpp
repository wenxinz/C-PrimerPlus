#include <iostream>
#include <string>
#include <cstring>
#include "baddude.h"

const int SIZE = 4;

int main(){
	using std::cout;
	using std::cin;
	using std::endl;
	using std::strchr;

	Person * pp[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the person category:\n"
				<< "p: person  g: gunslinger  "
            << "k: poker player  b: bad dude \n"
				<< "q: quit\n";
		cin >> choice;
		while (strchr("pgkbq", choice) == NULL)
		{
			cout << "Please enter a p, g, k, b, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch(choice)
		{
			case 'p':   pp[ct] = new Person;
							break;
			case 'g':   pp[ct] = new Gunslinger;
							break;
			case 'k':   pp[ct] = new Pokerplayer;
							break;
			case 'b': 	pp[ct] = new BadDude;
							break;
		}
		cin.get();
		pp[ct]->Set();
	}
	
	cout << "Your selection:" << endl << endl;
	int i;
	for (i = 0; i < ct; i++){
		cout << endl;
		pp[i]->Show();
	}
	for(i=0; i<ct; i++){
		delete pp[i];
	}
	cout << "Bye.\n";
	return 0;
}