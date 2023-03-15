
#include"Game.h"
int main() {
	std::ifstream data;
	Game g1;
	string line;
	char choice;
	bool menu = true;
	while (menu) {
		cout << "Welcome To Tetris" << endl;
		cout << "Menu :" << endl;
		cout << "1.Start the game" << endl;
		cout << "2.Game rules" << endl;
		cout << "3.Scores History" << endl;
		cout << "4.Exit game" << endl;
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case '1':
			g1.startGame();
			break;
		case '2':
			try {
				data.open("gameRules.txt");
				if (data.is_open()) {
					while (getline(data, line)) {

						cout << line << endl;
						cout << endl;
					}
					data.close();
				}
				else {
					throw 1;
				}
			}
			catch (int e) {
				cout << "file not found" << endl;
			}
			break;
		case '3':
			cout << "Scores History" << endl;
			try {
				data.open("data.txt");
				if (data.is_open()) {
					while (getline(data, line)) {

						cout << line << endl;
						cout << endl;
					}
					data.close();
				}
				else {
					throw 1;
				}
			}
			catch (int e) {
				cout << "file not found" << endl;
			}
			break;
		case '4':
			menu = false;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	}
	return 0;
	
}