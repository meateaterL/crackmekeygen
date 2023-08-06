#include <iostream>
#include <vector>

using std::vector;

int main()
{
    std::cout << "Keygen for crackme8 by fant0m\nWritten by Minelast\n\n\nInput your name: ";

    std::string name;
    std::cin >> name;

    std::cout << '\n';

    int name_len = name.length();

    vector<int> sc;

    name_len += 1;
    int symb;
    int sel_char;
    bool zf = 0;

    for (int i = 0; i < name.length(); i++) {
        symb = 66 + name_len;
        sel_char = name[i];
        sel_char = sel_char xor symb; // xor eax, ebx
        sel_char *= 32;       // rol eax, 5
        sel_char /= 4;       // shr eax, 2

        int ost = sel_char % 16; // div bx
        sel_char -= ost;
        ost *= 256;
        sel_char /= 16;
        sel_char += ost;
        zf = 0;
        UPPERCASE:

        sel_char += 12288;    // add ah, 30h

        if ((sel_char / 256) > 64) {
            sel_char += 1792;
        }

        sc.push_back(sel_char / 256);

        if ((sel_char % 256) < 16 && zf == 0) {
            ost = 0;
            ost = sel_char % 16;
            ost = ost * 256;
            ost += 17;
            zf = 1;
            sel_char = ost;
            goto UPPERCASE;
        }
        name_len -= 1;
    }

    std::cout << "Your serial code: ";
    name_len = name.length();

    for (int i = 0; i < sc.size(); i++) {
        std::cout << char(sc[i]);
    }

    std::cout << '8' << std::endl; // При любом NAME в конец строки добавляется 8, т.к. цикл зашифровки отрабатывает лишний раз

    system("pause");

    return 0;
}
