#include <iostream>

using namespace std;

namespace Utils {
    void input_float(float &value) {
        while (true) {
            cin >> value;
            if (cin.good()) {
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите число: ";
        }
    }
}



namespace Triangle {
    float side_a;
    float side_b;
    float side_c;

    float perimeter() {};
    float area() {};
    float is_isoscels() {};

    void select() {
        cout << "Вы выбрали треугольник" << endl;
        cout << "Введите исходные значения для сторон треугольника" << endl;

        cout >> "Введите длину стороны a: ";
        input_float(side_a);
}

int main(void) {
    char choice;
    char exit;
    while (exit == 0) {
        cout << "Выберите фигуру: "  << endl;
        cout << "1 — Прямоугольник"  << endl;
        cout << "2 — Треугольник"    << endl;
        cout << "3 — Трапеция"       << endl;
        cout << "4 — Круг"           << endl;
        cout << "0 — Выйти"          << endl;
        cout << "\033[6A";cout << "\033[17C"; //Смещение коретки
        cin  >> choice;
        cout << "\033[A";
        switch(choice) {
            case 'a':
            case '1':
                // TODO: вызов функции Айхаана Прямоугольник
                break;
            case 'b':
            case '2':
                // TODO: вызов функции Дениса Треугольник
                break;
            case 'c':
            case '3':
                // TODO: вызов функции Димы Трапеция
                break;
            case 'd':
            case '4':
                // TODO: вызов функции Тимофея Круг
                break;
            case 'q':
            case '0':
                exit = 1;
                cout << "Выход...       " << endl;
                break;
            default:
                cout << "Пожалуйста введите число от 1 до 4 (или a,b,c,d) или используйте 0 для выхода" << endl;
                break;
        }
    }
    return 0;
}
