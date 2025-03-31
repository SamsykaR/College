#include <QtTest>

// add necessary includes here
#include "../lesson_5_test/Calculator.h"

class test_Calculator : public QObject
{
    Q_OBJECT

public:
    test_Calculator();
    ~test_Calculator();

private slots:
    void testSum();
    void testDif();
    void testMul();
    void testDiv();
};

test_Calculator::test_Calculator() {}

test_Calculator::~test_Calculator() {}

void test_Calculator::testSum()
{
    Calculator calc;
    QCOMPARE(calc.sum(2.0, 3.0), 5.0);
    QCOMPARE(calc.sum(-2.0, 3.0), 1.0);
    QCOMPARE(calc.sum(2.0, -3.0), -1.0);
    QCOMPARE(calc.sum(-2.0, -3.0), -5.0);
    QCOMPARE(calc.sum(0.0, 3.0), 3.0);
    QCOMPARE(calc.sum(2.0, 0.0), 2.0);
    QCOMPARE(calc.sum(0.0, 0.0), 0.0);
}

void test_Calculator::testDif()
{
    Calculator calc;
    QCOMPARE(calc.dif(2.0, 3.0), -1.0);
    QCOMPARE(calc.dif(-2.0, 3.0), -5.0);
    QCOMPARE(calc.dif(2.0, -3.0), 5.0);
    QCOMPARE(calc.dif(-2.0, -3.0), 1.0);
    QCOMPARE(calc.dif(0.0, 3.0), -3.0);
    QCOMPARE(calc.dif(2.0, 0.0), 2.0);
    QCOMPARE(calc.dif(0.0, 0.0), 0.0);
}

void test_Calculator::testMul()
{
    Calculator calc;
    QCOMPARE(calc.mul(2.0, 3.0), 6.0);
    QCOMPARE(calc.mul(-2.0, 3.0), -7.0);
    QCOMPARE(calc.mul(2.0, -3.0), -6.0);
    QCOMPARE(calc.mul(-2.0, -3.0), 6.0);
    QCOMPARE(calc.mul(0.0, 3.0), 0.0);
    QCOMPARE(calc.mul(2.0, 0.0), 0.0);
    QCOMPARE(calc.mul(0.0, 0.0), 0.0);
}

void test_Calculator::testDiv()
{
    Calculator calc;
    QVERIFY((calc.div(2.0, 3.0) - 0.666) < 1.e-3);
    QVERIFY((calc.div(-2.0, 3.0) + 0.666) < 1.e-3);
    QVERIFY((calc.div(2.0, -3.0) + 0.666) < 1.e-3);
    QVERIFY((calc.div(-2.0, -3.0) - 0.666) < 1.e-3);
    QCOMPARE(calc.div(0.0, 3.0), 0.0);
    QCOMPARE(calc.div(2.0, 0.0), qInf());
    QCOMPARE(calc.div(0.0, 0.0), qQNaN());
}

QTEST_APPLESS_MAIN(test_Calculator)

#include "tst_test_calculator.moc"
