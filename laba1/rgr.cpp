#include <iostream>
#include <cmath>
#include <iomanip>
 
using namespace std;
// ������� ������� ��������� ������ �����
long double Fact( long n );
// ������� ������� ����������� cos^2( x ) ��� ������ ���� �������
// - �������� x
// - �������� ����������
// - ����, ������� ���������� ���������� �� ������� ������� ��� ������� ��� ������� x
long double Calc( long double x, const long double e, bool flagNew = true);
 
int main() {
 
     double xBegin, xEnd; // ��������� � �������� �������� x
     unsigned count; // ���������� ����������� �������� �� ������� �� ���������� �� ��������� �������� x [ xBegin, xEnd ]
     double epsilon; // �������� ����������
 
     // ����������� � ������������ �������� ������
     cout << "������� ��������� � �������� �������� x ( � �������� )" << endl;
     cin >> xBegin >> xEnd;
 
     cout << "������� ���������� ����������� ��������" << endl;
     cin >> count;
 
     cout << "������� �������� ����������" << endl;
     cin >> epsilon;
 
     const double xDelta = ( xEnd - xBegin ) / ( count - 1 ); // ������� ��� ��� ����������
     cout << "��� ��� ���������� " << xDelta << "( ������ )" << endl;
 
     // � ����� �������� ������� ��� �������� ���������� �������� ������� � xBegin � ���������� xEnd - xDelta ���������
     for ( unsigned i = 0; i < count - 1; ++i )
     cout << "X" << i + 1 << " = " << setprecision( 3 ) << Calc( xBegin + xDelta * i, epsilon ) << endl;
 
     // �������� ������� Calc( xEnd ) � ����� ��������� ��������, ��� ��� ������� � ��������� ������
     // � ��� ������������ � ����� ����� ���� ���������� ��� ���������� ���������� �������� xEnd.
     cout << "X" << count << " = " << setprecision( 3 ) << fixed << Calc( xEnd, epsilon ) << endl;
 
 
    return 0;
}
 
long double Calc( long double x, const long double e, bool flagNew ) {
    static long double p; // �������
    static int koef; // ��� ����� + ��� -
    // ���� ������� ������� � ������ ��� - �.�. ������������
    if ( flagNew ){ // �� ������������� ��������� �������� ������� � ������������
        koef = 1;
        p = 2.0;
    }
    // ��� ���� ����� � ��������� ��������� � ����������� � ������ ������� �� ����� "="
    // �������� ���� ��������� ������� ���� �� ����������������� �����, ������� ��� � ���������� ����������
    koef *= -1;
 
    // ��������� ��������� ������� ����
    long double res = ( pow( x, p ) * pow( 2.0L, p - 1 ) / Fact( p ) ) * koef;
 
    // �������� �� ��������� ��������
    if ( fabs( res ) <= e ) // ���� ��������� ������� ���� �� ������ ����� ��� ����� epsilon
        return 1 + res; // �� ���������� �������� � ��������� ��������
    else { // � ���� ��
        p += 2.0; // �� ����������� �������
        // ���������� � ���������� �������� ���� ��������� ������� ����, ������� ����� �������� ����������
        return res + Calc( x, e, false );
    }
 
}
 
long double Fact( long n ) {
    return n > 0 ? n * Fact( n - 1 ) : 1;
}