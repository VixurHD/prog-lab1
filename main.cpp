#include <iostream>
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

namespace Trapezoid {
    float base_a;
    float base_b;
    float side_c;
    float side_d;
    float height;

    float perimeter() {
        return base_a + base_b + side_c + side_d;
    }

    float area() {
        return (base_a + base_b) * height / 2.0f;
    }

    float midline() {
        return (base_a + base_b) / 2.0f;
    }

    bool is_isosceles() {
        return fabs(side_c - side_d) < 0.0001f;
    }

    bool is_real_trapezoid() {
        if (base_a <= 0 || base_b <= 0 || side_c <= 0 || side_d <= 0 || height <= 0) {
            return false;
        }

        float m = fabs(base_a - base_b);
        if (m < 0.0001f) {
            return false;
        }

        if (height > side_c || height > side_d) {
            return false;
        }

        float proj_c = sqrt(side_c * side_c - height * height);
        float proj_d = sqrt(side_d * side_d - height * height);
        return fabs((proj_c + proj_d) - m) < 0.001f;
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
                cout << "Такой трапеции не существует, введите значения заново" << endl;
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
            cout << "1 — Периметр" << endl;
            cout << "2 — Площадь" << endl;
            cout << "3 — Средняя линия" << endl;
            cout << "4 — Проверить равнобедренность" << endl;
            cout << "5 — Высота" << endl;
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
                        cout << "Трапеция равнобедренная" << endl;
                    } else {
                        cout << "Трапеция не равнобедренная" << endl;
                    }
                    break;
                case '5':
                    cout << "h = " << height << endl;
                    break;
                case '0':
                    exit = 1;
                    break;
                default:
                    cout << "Пожалуйста введите число от 1 до 5 или используйте 0 для выхода" << endl;
                    break;
            }
        }
    }

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

//test12
namespace Circle {
    float radius;

    float len() {
        return (2*PI*radius);
    }
    float area(float angle) {
        return (PI*radius*radius*(angle/360.0f));   
    }

   
    bool is_real_circle() {
        return radius > 0;
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
     void start() {
        cout << "Вы выбрали круг" << endl;
        cout << "Введите начальные параметры для круга:" << endl;
        while (true) {
            cout << "Введите радиус: ";
            Utils::input<float>(radius, "введите число с плавающей точкой");
            if (!is_real_circle()) {
                cout << "Радиус должен быть положительным, введите значение заново" << endl;
            } else {
                break;
            }
        }
        menu();
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
        cout << "> ";
        cin >> choice;
        cout << endl;

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
                Trapezoid::start();
                break;
            case 'd':
            case '4':
                Circle::start();
                break;
            case 'q':
            case '0':
                exit = 1;
                cout << "Выход..." << endl;
                break;
            default:
                cout << "Пожалуйста введите число от 1 до 4 (или a,b,c,d) или используйте 0 для выхода" << endl;
                break;
        }
    }
    return 0;
}
