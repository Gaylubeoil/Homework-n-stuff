/*Задача 3:
*Бонус 1 – направете програмата, така че да работи с двойни оператори && и ||, т.е
1 & 1 & 0 = 1 , да не е валиден израз, а само изрази от вида 1 && 1 && 0 = 1 да са.
*/
#include <iostream>
const int maxsize = 256;
void sort1(char* str) {
	char arr[maxsize];
	int index = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '1' || str[i] == '0' || str[i] == '&' || str[i] == '|' || str[i] == '=') {
			arr[index] = str[i];
			index++;
		}
	}
	bool flag = false;
	for (int i = 0; i < index; i++) {
		std::cout << arr[i];
	}
	for (int j = 0, i = 1; j < index, i < index - 3; j += 3, i += 3) {
		if ((arr[j] == '0'||arr[j] == '1')&&((arr[i] == '|'&&arr[i + 1] == '|'))||(arr[i] == '&' && arr[i + 1] == '&')&&(arr[index - 2] == '='))flag = true;
		else flag = false;
	}
	std::cout << std::endl << "Boolean expression is " << (flag ? "valid!" : "not valid!") << std::endl;
	// 1hgf&&gdf0g5=df0n - valid
	// 1hgf&gdf0g5=df0n - not valid
}
int main() {
	char str1[maxsize];
	std::cin.getline(str1, maxsize);
	sort1(str1);
	return 0;
}
