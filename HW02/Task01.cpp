#include <iostream>
bool CheckInput(char *str) {
    while (*str != '/0')
    {
        if (*str != 'I' && *str != 'V' && *str != 'X' && *str != 'L' && *str != 'C' && *str != 'D' && *str != 'M')
            return 0;
        else
            return 1;
        CheckInput(++str);
    }
}
bool CheckIfNumIsCorrect(char* str) {
    for (int i=0; str[i] != '\0'; i++)
    {
        if (str[i] == 'I' && str[i + 1] == 'M') return 0;
        if (str[i] == 'V' && str[i + 1] == 'M') return 0;
        if (str[i] == 'X' && str[i + 1] == 'M') return 0;
        if (str[i] == 'L' && str[i + 1] == 'M') return 0;
        if (str[i] == 'I' && str[i + 1] == 'D') return 0;
        if (str[i] == 'V' && str[i + 1] == 'D') return 0;
        if (str[i] == 'X' && str[i + 1] == 'D') return 0;
        if (str[i] == 'L' && str[i + 1] == 'D') return 0;
        if (str[i] == 'I' && str[i + 1] == 'C') return 0;
        if (str[i] == 'V' && str[i + 1] == 'C') return 0;
        if (str[i] == 'I' && str[i + 1] == 'L') return 0;
        if (str[i] == 'V' && str[i + 1] == 'X') return 0;
        if (str[i] == 'V' && str[i + 1] == 'L') return 0;
        if (str[i] == 'L' && str[i + 1] == 'C') return 0;
        if (str[i] == 'C' && str[i + 1] == 'D') return 0;
        if (str[i] == 'C' && str[i + 1] == 'M') return 0;
        if (str[i] == 'D' && str[i + 1] == 'M') return 0;
        if (str[i] == 'V' && str[i + 1] == 'V') return 0;
    }
    return 1;
}
int value(char str) {
    switch (str)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    }
}
void Convert(char* str, const int size) {
    if (size == 1) {
        if (*str == 'M') std::cout << "Your number in arabic is: 1000";
        if (*str == 'D') std::cout << "Your number in arabic is: 500";
        if (*str == 'C') std::cout << "Your number in arabic is: 100";
        if (*str == 'L') std::cout << "Your number in arabic is: 50";
        if (*str == 'X') std::cout << "Your number in arabic is: 10";
        if (*str == 'V') std::cout << "Your number in arabic is: 5";
        if (*str == 'I') std::cout << "Your number in arabic is: 1";
    }
    else {
        int arabicNum = 0;
        if (str[0] == 'M') std::cout << "That number is off limits! \n";
        for (int i = 0; i < size; i++)
        {
            if (value(str[i]) >= value(str[i + 1])) {
                arabicNum += value(str[i]);
            }
            else {
                arabicNum -= value(str[i]);
            }
        }

        std::cout << "Your number in arabic is: " << arabicNum << std::endl;
    }
}

int main() {
    int size = 0;
    std::cout << "This program converts roman into arabic numbers. \nLimit: I - M ( 1 - 1000 ). \nUse capitals letters only. \n";
    std::cout << "Enter size of the string: ";
    std::cin >> size;
    std::cin.ignore(1, '\n');
    char* str = new char[size+1];
    std::cout << "Input your string: "; // I V X L-50 C-100 D-500 M-1000
    std::cin.getline(str, size+1);
    if (CheckIfNumIsCorrect(str) && CheckInput(str)) {
        Convert(str, size);
    }
    else {
        std::cout << "Invalid number! \n";
    }
    delete[] str;
    return 0;
}
