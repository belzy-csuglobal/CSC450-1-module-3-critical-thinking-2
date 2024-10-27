#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	// Create integer variables.
	int firstNumber = 0;
	int secondNumber = 0;
	int thirdNumber = 0;

	// Create integer pointers.
	int* firstPtr = new int;
	int* secondPtr = new int;
	int* thirdPtr = new int;

	// Create vectors for variables for efficiency.
	vector<string> ordinals = { "first", "second", "third" };
	vector<int> numbers = { firstNumber, secondNumber, thirdNumber };
	vector<int*> pointers = { firstPtr, secondPtr, thirdPtr };

	// Iterate over the vectors twice.
	int size = (int)ordinals.size();
	for (int i = 0; i < size * 2; i++) {

		// Get user input to initialize variables.
		if (i < size) {
			string tmp;

			cout << "Enter the " << ordinals[i] << " Number: ";
			cin >> tmp;

			try {
				numbers[i] = stoi(tmp);
				*pointers[i] = numbers[i];
			} catch (const invalid_argument& e) {
				cout << "Invalid input. Number must be an integer. (" << e.what() << ")" << endl << endl;
				i = i - 1;
			}

		// Display the values of the variables.
		} else {
			int j = i - size;

			if (i == size)
				cout << endl << "Values" << endl;

			cout << " " << ordinals[j] << endl;
			cout << " - Value: " << numbers[j] <<endl;
			cout << " - Address: " << pointers[j] <<endl;

			// Delete the pointers to de-allocate memory.
			delete pointers[j];
			pointers[j] = NULL;
		}
	}

	return 0;
}