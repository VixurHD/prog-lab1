.]#include <iostream>
#include <limits>
#include <cmath>

#define PI 3.14159265

using namespace std;
// comment
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

namespace Trapezoid {
    // Основания и боковые стороны трапеции
    float base_a;
    float base_b;
    float side_c;
    float side_d;
    float height;

    // Вычисляем периметр трапеции
    float perimeter() {
        return base_a + base_b + side_c + side_d;
    }

    // Вычисляем площадь трапеции
    float area() {
        return ((base_a + base_b) * height) / 2.0f;
    }

    // Вычисляем среднюю линию трапеции
    float midline() {
        return (base_a + base_b) / 2.0f;
    }

    /*
    * Проверка существует ли трапеция с такими значениями
    * При неверном вводе (отрицательные, нулевые значения или невозможная трапеция) просит повторить
    */
    bool is_real_trapezoid() {
        if (base_a > 0 && base_b > 0 && side_c > 0 && side_d > 0 && height > 0)
        {
            // Проверяем, что высота не больше боковых сторон
            if (height <= side_c && height <= side_d) {
                return 1;
            }
        }
        return 0;
    }

    // Проверка на равнобедренность
    bool is_isosceles() {
        return (side_c == side_d);
    }

    void set_sides() {
        while (true) {
            cout << "Введите длину основания a: ";
            Utils::input<float>(base_a, "введите число");
            cout << "Введите длину основания b: ";
            Utils::input<float>(base_b, "введите число");
            cout << "Введите длину боковой стороны c: ";
            Utils::input<float>(side_c, "введите число");
            cout << "Введите длину боковой стороны d: ";
            Utils::input<float>(side_d, "введите число");
            cout << "Введите высоту h: ";
            Utils::input<float>(height, "введите число");

            if (!is_real_trapezoid()) {
                cout << "Такая трапеция не возможна, введите положительные значения" << endl;
                cout << "(высота не должна быть больше боковых сторон)" << endl;
            }
            else {
                break; // Верные значения - выходим из цикла
            }
        }
    }

    // Меню выбора действий для трапеции
    void select() {
        char exit = 0;
        while (exit == 0) {
            char choice;
            cout << "\nЧто вы хотите вычислить?" << endl;
            cout << "1 — Периметр" << endl;
            cout << "2 — Площадь" << endl;
            cout << "3 — Средняя линия" << endl;
            cout << "4 — Проверка на равнобедренность" << endl;
            cout << "0 — Выход" << endl;
            cout << "> ";
            Utils::input<char>(choice, "введите число");

            switch (choice) {
            case '1':
                cout << "P = " << perimeter() << endl;
                break;
            case '2':
                cout << "S = " << area() << endl;
                break;
            case '3':
                cout << "M = " << midline() << endl;
                break;
            case '4':
                if (is_isosceles()) {
                    cout << "Трапеция является равнобедренной" << endl;
                }
                else {
                    cout << "Трапеция не является равнобедренной" << endl;
                }
                break;
            case '0':
                exit = 1;
                break;
            default:
                cout << "Пожалуйста введите число от 1 до 4 или используйте 0 для выхода" << endl;
                break;
            }
        }
    }

    // Точка входа в модуль трапеции, запрашивает исходные значения для оснований, сторон и высоты трапеции
    void start() {
        cout << "Вы выбрали трапецию" << endl;
        cout << "Введите исходные значения для трапеции" << endl;
        set_sides();
        select();
    }
}

namespace Rectangle {
    // Длины сторон прямоугольника
    float side_a;
    float side_b;
    // Вычисляем периметр прямоугольника
    float perimeter() {
        return 2.0f * (side_a + side_b);
    }
    // Вычисляем площадь прямоугольника
    float area() {
        return side_a * side_b;
    }
    // Вычисляем диагональ прямоугольника 
    float diagonal() {
        return sqrt(side_a * side_a + side_b * side_b);
    }
    /*
    * Проверка существует ли прямоугольник с такими значениями
    * При неверном вводе (отрицательные или нулевые значения) просит повторить
    */ 

    bool is_real_rectangle() {
        if (side_a > 0 && side_b > 0)
        {
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

            if (!is_real_rectangle()) {
                cout << "Такой прямоугольник не возможен, введите положительные значения" << endl;
            }
            else {
                break; // Верные значения - выходим из цикла
            }
        }
  }
    // Меню выбора действии для прямоугольника
    //комментариииии
    void select() {
        char exit = 0;
        while (exit == 0) {
            char choice;
            cout << "Что вы хотите вычислить?" << endl;
            cout << "1 — Периметр" << endl;
            cout << "2 — Площадь" << endl;
            cout << "3 — Диагональ" << endl;
            cout << "0 — Выход" << endl;
            cout << "> ";
            Utils::input<char>(choice, "введите число");
            switch (choice) {
            case '1':
                cout << "P = " << perimeter() << endl;
                break;
            case '2':
                cout << "S = " << area() << endl;
                break;
            case '3':
                cout << "D = " << diagonal() << endl;
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
    // Точка входа в модуль прямоугольника, запрашивает исходные значения для сторон прямоугольника
    void start() {
        cout << "Вы выбрали прямоугольник" << endl;
        cout << "Введите исходные значения для сторон прямоугольника" << endl;
        set_sides();
        select();
    }
}

//test
namespace Circle {
    float radius;

    float len() {
        return (2*PI*radius);
    }
    float area(float angle) {
        return (PI*radius*radius*(angle/angle));
    }

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
                        } else {
                            break;
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
//Z ecnfk
//test123_337
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
    system("chcp 65001");

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
                Rectangle::start();
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
                Circle::start();
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
