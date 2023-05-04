#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
#include <sstream>

using namespace std;
using namespace ariel;

TEST_CASE("1.Test + "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(4, 1);

    Fraction ans1 = num1 + num2;
    Fraction ans2 = num1 + 4;
    Fraction ans3 = 4 + num1;

    CHECK(ans1 == ans2);
    CHECK(ans2 == ans3);
    CHECK(ans1 == Fraction(9, 2));
}

TEST_CASE("2.Test - "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(4, 1);

    Fraction ans1 = num1 - num2;
    Fraction ans2 = num1 - 4;
    Fraction ans3 = 4 - num1;

    CHECK(ans1 == ans2);
    CHECK(ans1 == Fraction(-7, 2));
    CHECK(ans3 == Fraction(7, 2));
}

TEST_CASE("3.Test * "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(3, 1);

    Fraction ans1 = num1 * num2;
    Fraction ans2 = num1 * 3;
    Fraction ans3 = 0.5 * num2;

    CHECK(ans1 == ans2);
    CHECK(ans2 == ans3);
    CHECK(ans1 == Fraction(3, 2));
}

TEST_CASE("4.Test / "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(3, 1);

    Fraction ans1 = num1 / num2;
    Fraction ans2 = num1 / 3;
    Fraction ans3 = 0.5 / num2;

    CHECK(ans1 == ans2);
    CHECK(ans2 == ans3);
    CHECK(ans1 == Fraction(1, 6));
}

TEST_CASE("5.Test == "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(2, 4);

    Fraction num3 = Fraction(7, 2);
    Fraction num4 = Fraction(21, 6);

    Fraction num5 = Fraction(100, 2);
    Fraction num6 = Fraction(200, 4);

    CHECK(num1 == num2);
    CHECK(num3 == num4);
    CHECK(num5 == num6);
}

TEST_CASE("6.Test > "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(2, 4);

    Fraction num3 = Fraction(1, 2);
    Fraction num4 = Fraction(0, 4);

    CHECK_FALSE(num1 > num2);
    CHECK(num3 > num4);
}

TEST_CASE("7.Test < "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(2, 4);

    Fraction num3 = Fraction(1, 2);
    Fraction num4 = Fraction(0, 4);

    CHECK_FALSE(num1 < num2);
    CHECK(num4 < num3);
}

TEST_CASE("8.Test >= "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(2, 4);

    Fraction num3 = Fraction(1, 2);
    Fraction num4 = Fraction(0, 4);

    CHECK(num1 >= num2);
    CHECK(num3 >= num4);
}

TEST_CASE("9.Test <= "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(2, 4);

    Fraction num3 = Fraction(1, 2);
    Fraction num4 = Fraction(0, 4);

    CHECK(num1 <= num2);
    CHECK_FALSE(num3 <= num4);
}

TEST_CASE("10.Test PRE ++ "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(5, 3);

    CHECK(++num1 == Fraction(3, 2));
    CHECK(++num2 == Fraction(8, 3));
}

TEST_CASE("11.Test PRE -- "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(5, 3);

    CHECK(--num1 == Fraction(-1, 2));
    CHECK(--num2 == Fraction(2, 3));
}

TEST_CASE("12.test Fraction creation"){
    Fraction num1 = Fraction(2.3);
    Fraction num2 = Fraction(2.299);
    Fraction num3 = Fraction(100, 4);

    CHECK(num1 == Fraction(23, 10));
    CHECK(num2 == Fraction(2299, 1000));
    CHECK(num3 == 25);
}

TEST_CASE("13.Test simplify"){
    Fraction num1 = Fraction(100, 4);
    Fraction num2 = Fraction(23, 4);
    Fraction num3 = Fraction(1000, 100);

    CHECK(num1 == 25);
    CHECK(num2 == 23.0 / 4);
    CHECK(num3 == 10);
}

TEST_CASE("14.Order of operations"){
    Fraction num1 = Fraction(100, 4);
    Fraction num2 = Fraction(23, 4);
    Fraction num3 = Fraction(1000, 100);

    Fraction ans = num1 + num2 * num3;

    CHECK(ans == 25 + 230.0 / 4);
}

TEST_CASE("15.Division by zero"){
    Fraction num1 = Fraction(10, 1);
    Fraction num2 = Fraction(0, 1);

    CHECK_THROWS(num1 / 0);
    CHECK_THROWS(num1 / num2);
    CHECK_THROWS(Fraction(10, 0));
}

TEST_CASE("16.Test POST ++ "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(5, 3);

    CHECK(num1++ == Fraction(1, 2));
    CHECK(num2++ == Fraction(5, 3));
    CHECK(num1 == Fraction(3, 2));
    CHECK(num2 == Fraction(8, 3));
}

TEST_CASE("17.Test POST -- "){
    Fraction num1 = Fraction(1, 2);
    Fraction num2 = Fraction(5, 3);

    CHECK(num1-- == Fraction(1, 2));
    CHECK(num2-- == Fraction(5, 3));
    CHECK(num1 == Fraction(-1, 2));
    CHECK(num2 == Fraction(2, 3));
}

TEST_CASE("18.Test << "){
    Fraction num = Fraction(0,1);
    ostringstream out;
    out << num;
    CHECK(out.str() == "0/1");
}

TEST_CASE("19.Test >> "){
    Fraction num;
    istringstream in("20 10");
    in >> num;
    CHECK(num == 2);
}

TEST_CASE("20. Demo remake + addition"){
    ostringstream out;
    istringstream in("23 4");

    const char expedted_out[]  = "a: 5/3, b: 2/3\n\
a+b : 7/3\n\
a-b : 1/1\n\
a/b : 5/2\n\
a*b : 10/9\n\
2.3*b : 23/15\n\
a+2.421 : 12263/3000\n\
d==\n\
4/3\n\
4/3\n\
c >=b ? : 1\n\
 a is bigger than 1.1\n\
";

    Fraction a(5,3), b(14,21), d;
    out << "a: " << a << ", b: " << b << endl;
    out << "a+b : " << a+b << endl; 
    out << "a-b : " << a-b << endl; 
    out << "a/b : " << a/b << endl; 
    out << "a*b : " << a*b << endl; 
    out << "2.3*b : " << 2.3*b << endl; 
    out << "a+2.421 : " << a+2.421 << endl; 
    in >> d;
    if(d == 23.0/4) out << "d==" << endl;

    Fraction c = a+b-1;
    out << c++ << endl;
    out << --c << endl;
    out << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1) out << " a is bigger than 1.1" << endl;
    else out << " a is smaller than 1.1" << endl;

    CHECK(expedted_out == out.str());
}