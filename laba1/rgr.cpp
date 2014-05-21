#include <iostream>
#include <cmath>
#include <iomanip>
 
using namespace std;
// функция считает факториал целого числа
long double Fact( long n );
// функция считает приближенно cos^2( x ) при помощи ряда Тейлора
// - значение x
// - точность вычислений
// - флаг, который определяет рекурсивно ли вызвана функция или впервые для данного x
long double Calc( long double x, const long double e, bool flagNew = true);
 
int main() {
 
     double xBegin, xEnd; // начальное и конечное значения x
     unsigned count; // количество вычисляемых значений на отрезке от начального до конечного значения x [ xBegin, xEnd ]
     double epsilon; // точность вычисления
 
     // запрашиваем у пользователя исходные данные
     cout << "Введите начальное и конечное значения x ( в радианах )" << endl;
     cin >> xBegin >> xEnd;
 
     cout << "Введите количество вычисляемых значений" << endl;
     cin >> count;
 
     cout << "Введите точность вычислений" << endl;
     cin >> epsilon;
 
     const double xDelta = ( xEnd - xBegin ) / ( count - 1 ); // находим шаг для вычислений
     cout << "Шаг для вычислений " << xDelta << "( радиан )" << endl;
 
     // в цикле вызываем функцию для рассчета очередного значения начиная с xBegin и заканчивая xEnd - xDelta элементом
     for ( unsigned i = 0; i < count - 1; ++i )
     cout << "X" << i + 1 << " = " << setprecision( 3 ) << Calc( xBegin + xDelta * i, epsilon ) << endl;
 
     // значение функции Calc( xEnd ) я решил вычислить отдельно, так как работаю с плавающей точкой
     // и при суммировании в цикле может быть неточность при вычислении граничного значения xEnd.
     cout << "X" << count << " = " << setprecision( 3 ) << fixed << Calc( xEnd, epsilon ) << endl;
 
 
    return 0;
}
 
long double Calc( long double x, const long double e, bool flagNew ) {
    static long double p; // степень
    static int koef; // для знака + или -
    // если функцию вызвали в первый раз - т.е. нерекурсивно
    if ( flagNew ){ // то устанавливаем начальные значения степени и коэффициента
        koef = 1;
        p = 2.0;
    }
    // для того чтобы в следующем операторе в вычислениях с правой стороны от знака "="
    // поменять знак очереднго элемент ряда на противоположенный знаку, который был в пердыдущем вычислении
    koef *= -1;
 
    // вычисляем очередной элемент ряда
    long double res = ( pow( x, p ) * pow( 2.0L, p - 1 ) / Fact( p ) ) * koef;
 
    // проверка на окончание рекурсии
    if ( fabs( res ) <= e ) // если очередной элемент ряда по модулю менее или равен epsilon
        return 1 + res; // то возвращаем значение и прерываем рекурсию
    else { // а если не
        p += 2.0; // то увеличиваем степень
        // прибавляем к очередному элементу ряда следующий элемент ряда, который будет вычислен рекурсивно
        return res + Calc( x, e, false );
    }
 
}
 
long double Fact( long n ) {
    return n > 0 ? n * Fact( n - 1 ) : 1;
}