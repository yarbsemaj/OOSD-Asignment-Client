#include <iostream>
#include "Aircraft.h"
#include <random>

using namespace std;

int main(void)
{
	cout << "Enter a 6 digit registration number:"<<endl;
	char reg[7] ;
	cin >> reg;
	reg[6] = '\0';
	Aircraft aircraft = Aircraft(reg,1,rand()%10000 - 5000, rand() % 10000 - 5000,500,0);

	while (1) {
		aircraft.update();
		Sleep(1000);
	}



	return 0;
}