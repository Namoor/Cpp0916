#include <iostream>
using namespace std;


#include "DoSomething.h"



void main2()
{
	printf("Ich bin eine funktion!\n");
	//printf("asd2\n");

	cout << "Gib bitte eine Zahl ein: ";
	int i;
	cin >> i;

	if (i > 5)
		cout << "Deine Zahl ist groesser als 5\n";
	else
		cout << "Deine Zahl ist kleiner oder gleich 5\n";

	int x;

	Test test;
	test.i = 0;

	DoSomething(test);

	cout << "I ist: " << test.i << "\n";

	for (int x = 0; x <= 10; x++)
	{

		cout << "Iteration: " << x << "\n";
	}

	//while (true)
	//{
	//	// Gameloop
	//	cout << "Running Game\n";
	//	cout << "Your input: ";
	//
	//	cin >> i;
	//
	//	if (i == 5)
	//		break;
	//}
	char Character;
	cout << "Gib ein beliebiges Zeichen ein: ";
	cin >> Character;


	switch (Character)
	{
	case 'L':
		cout << "Capital letter";
	case 'l':
		cout << "letter: l";
		break;
	default:
		cout << "letter not l";
		break;
	}
}

