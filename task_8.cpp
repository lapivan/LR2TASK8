#include <iostream>

double mysqrt(double x) {
   int terms = 20;
    if (x < 0) {
        std::cerr << "Ошибка: нельзя вычислить квадратный корень отрицательного числа." << std::endl;
        return -1;
    }

    // Начальное приближение
    double guess = x / 2.0; // Начинаем с половины числа
    double previous_guess;

    for (int i = 0; i < terms; ++i) {
        previous_guess = guess;
        guess = (guess + x / guess) / 2.0; // Метод Ньютона
        // Проверяем, достигли ли мы достаточной точности
        if (guess == previous_guess)
            break;
    }

    return guess;
}
double myacos(double x) {
 const double pi = 3.1415926535;
 double res = (pi / 2) - (x + ((x * x * x) / 6) + ((3 * x * x * x * x * x) / 40) + ((15 * x * x * x * x * x * x * x) / 336) + ((105 * x * x * x * x * x * x * x * x * x) / 3456) );
 return res;
}

int main() {
    double x1, y1, x2, y2, x3, y3, l1, l2, l3;
    std::cout << "Enter x1: " << std::endl;
    std::cin >> x1;
    std::cout << "Enter y1: " << std::endl;
    std::cin >> y1;
    std::cout << "Enter x2: " << std::endl;
    std::cin >> x2;
    std::cout << "Enter y2: " << std::endl;
    std::cin >> y2;
    std::cout << "Enter x3: " << std::endl;
    std::cin >> x3;
    std::cout << "Enter y3: " << std::endl;
    std::cin >> y3;
    //расчет сторон треугольника
    l1 = mysqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) ; 
    l2 = mysqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2)) ; 
    l3 = mysqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1)) ; ;
    std::cout << "Длины сторон: " << l1 << ' ' << l2 << ' '<< l3 << std::endl;
    double h1, h2, h3, p;
    p = (l1+l2+l3) / 2; // полупериметр
    //высоты треугольника
    h1 = 2 / l1 * mysqrt(p * (p - l1) * (p - l2) * (p - l3));
    h2 = 2 / l2 * mysqrt(p * (p - l1) * (p - l2) * (p - l3));
    h3 = 2 / l3 * mysqrt(p * (p - l1) * (p - l2) * (p - l3));
    std::cout << "Длины высот: " << h1 << ' ' << h2 << ' '<< h3 << std::endl;
    //медианы
    double m1, m2, m3;
    m1 = 0.5 * mysqrt(2 * l3 * l3 + 2 * l2 * l2 - l1 * l1);
    m2 = 0.5 * mysqrt(2 * l3 * l3 + 2 * l1 * l1 - l2 * l2);
    m3 = 0.5 * mysqrt(2 * l1 * l1 + 2 * l2 * l2 - l3 * l3);
    std::cout << "Длины медиан: " << m1 << ' ' << m2 << ' '<< m3 << std::endl;
    //биссектрисы
    double b1, b2, b3;
    b3 = (2 * (mysqrt(l1 * l2 * p * (p - l3))/ (l1 + l2)));
    b2 = (2 * mysqrt(l1 * l3 * p * (p - l2))/ (l1 + l3));
    b1 = (2 * mysqrt(l3 * l2 * p * (p - l1))/ (l2 + l3));
    std::cout << "Длины биссектрис: " << b1 << ' ' << b2 << ' '<< b3 << std::endl;
    //значения углов 
    double cos1, cos2, cos3;
    const double pi = 3.14159265;
    cos1 = (((l2 * l2) + (l3 * l3) - (l1 * l1)) / (2 * l2 *l3));
    cos2 = (((l3 * l3) + (l1 * l1) - (l2 * l2)) / (2 * l1 *l3));
    cos3 = (((l2 * l2) + (l1 * l1) - (l3 * l3)) / (2 * l2 *l1));
    std::cout << "Углы треугольника(в радианах): " << myacos(cos1) << ' ' << myacos(cos2) << ' '<< myacos(cos3) << std::endl;
    std::cout << "Углы треугольника(в градусах): " << (myacos(cos1)) * 180 / pi << ' ' << (myacos(cos2)) * 180 / pi << ' ' << (myacos(cos3)) * 180 / pi << std::endl;
    double s1, s2, s3, r1, r2;
    //радиусы вписанной и описанной окружноси
    s1 = mysqrt(p * (p-l1) * (p-l2) * (p-l3)); // первая формула для площади
    r1 = s1 / p;
    r2 = (l1 * l2 * l3) / (4 * s1);
    std::cout << "Радиус вписанной окружности: " << r1 << std::endl;
    std::cout << "Радиус описанной окружности: " << r2 << std::endl;
    //длины и площади вписанной и описанной окружностей
    double sc1, sc2, lc1, lc2;
    lc1 = 2 * pi * r1;
    sc1 = pi * r1 * r1;
    lc2 = 2 * pi * r2;
    sc2 = pi * r2 * 2;
    std::cout << "Длина вписанной окружности: " << lc1 << std::endl;
    std::cout << "Длина описанной окружности: " << lc2 << std::endl;
    std::cout << "Площадь вписанной окружности: " << sc1 << std::endl;
    std::cout << "Площадь описанной окружности: " << sc2 << std::endl; 
    //периметр
    double per = p * 2;
    //оставшиеся две формулы для площади
    s2 = 0.5 * l1 * h1;
    s3 = (l1 / (2 * r2)) * 0.5 * l2 * l3;
    std::cout << "Площадь треугольника(3 способа): " << s1 << ' ' << s2 << ' ' << s3 << std::endl;
    std::cout << "Периметр треугольника:  " << per << std::endl;
    return 0;
}