#include <string>
#include <iostream>

using namespace std;

void fatalError(std::string errorString) {
	cout << errorString << endl;
	cout << "Presione cualquier tecla para continuar" << endl;
	int tmp;
	cin >> tmp;
	exit(-1);
}


