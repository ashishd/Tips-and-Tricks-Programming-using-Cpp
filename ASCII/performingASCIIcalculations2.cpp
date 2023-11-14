#include<iostream>
#include<string>

// Class to validate user input
class InputValidator {
public:
	std::string input_str; // Store the input string for debugging
	InputValidator(std::string s) : input_str(s) {} // Constructor to initialize input string
	bool validate() {
		if (input_str.empty())
			return false;
		int input_num = 0;
		for (char c : input_str) {
			if (c < '0' || c > '9')
				return false;
			input_num = input_num * 10 + (c - '0');
		}
		return input_num >= 1 && input_num < 3999; // Validate that input is between 1 and 3998
	}
};

// Class to add two character strings
class CharAdder {
public:
	CharAdder(const std::string& c1, const std::string&c2) : char1(c1), char2(c2) {}
	int add() {
		int num1 = 0, num2 = 0;
		for (char c : char1)
			num1 = num1 * 10 + (c - '0');
		for (char c : char2)
			num2 = num2 * 10 + (c - '0');
		return num1 + num2;
	}
private:
	std::string char1, char2;
};

// Class to get user input
class UserInput {
public:
	std::string getInput(std::string message) {
		std::string input;
		std::cout << message;
		std::cin >> input;
		return input;
	}
};

// Main function to run the program
int main() {
	UserInput userInput;
	InputValidator inputValidator1(userInput.getInput("Enter first input between 0 to 3999, both excluded: "));
	if (inputValidator1.validate() != true) {
		std::cout << "Invalid input: " << inputValidator1.input_str << std::endl;
		system("pause");
		return -1;
	}

	InputValidator inputValidator2(userInput.getInput("Enter second input between 0 to 3999, both excluded: "));
	if (inputValidator2.validate() != true) {
		std::cout << "Invalid input: " << inputValidator2.input_str << std::endl;
		system("pause");
		return -1;
	}

	CharAdder adder(inputValidator1.input_str, inputValidator2.input_str);
	int sum = adder.add();
	std::cout << "The sum of " << inputValidator1.input_str << " and " << inputValidator2.input_str << " is " << sum << std::endl;
	system("pause");
	return 0;
}