#include <iostream>
const int maxsize = 100;
void sort1(char* str) {
	char arr[maxsize];
	int index = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == '&' || str[i] == '|' || str[i] == '=') {
			arr[index] = str[i];
			arr[index + 1] = ' ';
			index +=2;
		}
	}
	
	bool flag = false;
	for (int i = 0; i < index; i++)
		std::cout << arr[i];

	for (int j = 0, i = 1; j < index, i < index - 2; j += 2, i += 2) {
		if ((arr[j] == '0' || arr[j] == '1') && (arr[i] == '|' || arr[i] == '&') && (arr[index - 2] == '=')) flag = true;
		else flag = false;
	}
	std::cout << std::endl << "Boolean expression is " << (flag ? "valid!" : "not valid!") << std::endl;
}
int main() {
	char str1[maxsize];
	std::cin.getline(str1, maxsize);
	sort1(str1);
	return 0;
}
