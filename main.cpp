#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

namespace Utils {
    template<typename T>
    void input(T &value, const string &error_message) {
        /*
         * Функция для безопасного ввода с автоматическим выводом ошибки с просьбой написать снова
         * T &value ссылка на переменную в которую записывается ввод
         * const string &error_message сообщение выводимое пользователю при ошибке (ожидается текст вроде "Введите число")
         * Использование:
         * cout << "Введите номер: ";
         * Utils::input<int>(var, "text");
         */
        while (true) {
            cin >> value;
            if (cin.good()) {
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: " << error_message << ": ";
        }
    }
}

namespace Circle {
    float radius;

    float len() {}
    float area() {}
    float sector_area(float angle) {}

    void menu() {
        char exit = 0;
        while (exit == 0) {
            char choice;
            cout << "Что вы хотите вычислить?" << endl;
            cout << "1 — Длина окружности" << endl;
            cout << "2 — Площадь окружности" << endl;
            cout << "3 — Площадь сектора" << endl;
            cout << "0 — Выход" << endl;
            cout << "> ";
            Utils::input<char>(choice, "введите число");
            switch(choice) {
                case '1':
                    cout << "l = " << len() << endl;
                    break;
                case '2':
                    cout << "S_окружности = " << area(360.0f) << endl;
                    break;
                case '3':
                    float angle;
                    cout << "Введите угол сектора: ";
                    while (true) {
                        Utils::input<float>(angle, "введите число");
                        if ((angle <= 0.0f) || (angle >= 360.0f)) {
                            cout << "укажите значение от 0 до 360" << endl;
                        }
                    }
                    cout << "S_сектора = " << area(angle) << endl;
                    break;
                case '0':
                    exit = 1;
                    break;
                default:
                    cout << "Пожалуйста введите число от 1 до 3 или используйте 0 для выхода" << endl;
                    break;
            }
        }
    }


    void start() {
        cout << "Вы выбрали круг" << endl;
        cout << "Введите начальные параметры для круга:" << endl;
        cout << "Введите радиус: " << endl;
        Utils::input<float>(radius, "введите число с плавающей точкой");
        menu();

    }
}

namespace Triangle {
    float side_a;
    float side_b;
    float side_c;

    float perimeter() {
        return (side_a + side_b + side_c);
    }

    float area() {
        float halfmeter = perimeter() / 2.0f;
        return (sqrt(halfmeter*(halfmeter-side_a)*(halfmeter-side_b)*(halfmeter-side_c)));
    }

    bool is_isoscels() {
        if ((side_a == side_b) || (side_a == side_c) || (side_b == side_c)) {
            return 1;
        }   return 0;
    }

    bool is_real_triangle() {
        if ((side_a < side_b + side_c) &&
            (side_b < side_c + side_a) &&
            (side_c < side_a + side_b)) {
            return 1;
        }
        return 0;
    }

    void set_sides() {
        while (true) {
            cout << "Введите длину стороны a: ";
            Utils::input<float>(side_a, "введите число");
            cout << "Введите длину стороны b: ";
            Utils::input<float>(side_b, "введите число");
            cout << "Введите длину стороны c: ";
            Utils::input<float>(side_c, "введите число");

            if (!is_real_triangle()) {
                cout << "Таковой треугольник не возможен, введите значения заново" << endl;
            } else {
                break;
            }
        }
    }

    void select() {
        char exit = 0;
        while (exit == 0) {
            char choice;
            cout << "Что вы хотите вычислить?" << endl;
            cout << "1 — Перметр" << endl;
            cout << "2 — Площадь" << endl;
            cout << "3 — Проверить равнобедренность" << endl;
            cout << "0 — Выход" << endl;
            cout << "> ";
            Utils::input<char>(choice, "введите число");
            switch(choice) {
                case '1':
                    cout << "P = " << perimeter() << endl;
                    break;
                case '2':
                    cout << "S = " << area() << endl;
                    break;
                case '3':
                    if (is_isoscels()) {
                        cout << "Треугольник равнобедренный" << endl;
                    } else {
                        cout << "Треугольник не равнобедренный" << endl;
                    }
                    break;
                case '0':
                    exit = 1;
                    break;
                default:
                    cout << "iПожалуйста введите число от 1 до 3 или используйте 0 для выхода" << endl;
                    break;
            }
        }
    }

    void start() {
        cout << "Вы выбрали треугольник" << endl;
        cout << "Введите исходные значения для сторон треугольника" << endl;
        set_sides();
        select();
    }
}

int main(void) {
    char choice;
    char exit = 0;
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
                Triangle::start();
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
