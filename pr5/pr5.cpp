//VARIANT 4

#define _CRT_SECURE_NO_WARNINGS
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0') 

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    //1110001DRRRRAAAA
    unsigned short D; // 0..1
    unsigned short R; // 0b1111 0..15
    unsigned short A; // 0b0000000000001111 0..15
    unsigned short UnitStateWord = 0;
    // Ввод данных
    printf("Введите направление передачи - в регистр(0)/в память(1): ");
    scanf_s("%hu", &D);
    printf("Введите 1-й операнд - регистр (0-15): ");
    scanf_s("%hu", &R);
    printf("Введите регистр адреса 2-го операнда (0-15): ");
    scanf_s("%hu", &A);

    printf("D = %d\n", D);
    printf("R = %d\n", R);
    printf("A = %d\n", A);
    // Запаковка
    UnitStateWord = (0b1110001) << 9;
    UnitStateWord |= (D & 1) << 8;
    UnitStateWord |= (R & 0b1111) << 4;
    UnitStateWord |= A & 0b0000000000001111;
    printf("\nСлово состояния устройства (16-ричное число от 0 до 0xFFFF): %04x\n", UnitStateWord);
    printf("\nСлово состояния устройства (DEC): %d\n", UnitStateWord);
    printf("\nДвоичный код: %c%c%c%c%c%c%c%c:%c%c%c%c%c%c%c%c \n", \
        BYTE_TO_BINARY(UnitStateWord >> 8), BYTE_TO_BINARY(UnitStateWord));
    // Распаковка
    printf("\nРаспаковка:");
    D = (UnitStateWord >> 8) & 1;
    R = (UnitStateWord >> 4) & 0b1111;
    A = UnitStateWord & 0b0000000000001111;
    printf("\nD = %d\n", D);
    printf("R = %d\n", R);
    printf("A = %d\n", A);
    return 0;
}