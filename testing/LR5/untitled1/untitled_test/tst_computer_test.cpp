#include <QtTest>
#include "../untitled/computer.h"

// add necessary includes here

class computer_test : public QObject
{
    Q_OBJECT

public:
    computer_test();
    ~computer_test();

private slots:
    void testFreeMemory();
    void testFreeMemoryCool();
    void testFormula();
};

computer_test::computer_test() {}

computer_test::~computer_test() {}

void computer_test::testFreeMemory() {
    Computer pk1(1, 100, 10);
    Computer pk2(2, 90, 20);
    Computer pk3(0, 200, 40);

    QCOMPARE(pk1.FreememoryProcent(), 90);
    QCOMPARE(pk2.FreememoryProcent(), 77.77);
    QCOMPARE(pk3.FreememoryProcent(), 80);
}

void computer_test::testFreeMemoryCool() {
    Computer pk1(1, 100, 10);
    Computer pk2(2, 90, 20);
    Computer pk3(0, 200, 40);

    QVERIFY(pk1.FreeMemoryIsCool(80));
    QVERIFY(pk1.FreeMemoryIsCool(70));
    QVERIFY(pk1.FreeMemoryIsCool(80));
}

void computer_test::testFormula() {
    Computer pk1(1, 100, 10);
    Computer pk2(2, 90, 20);
    Computer pk3(0, 200, 40);

    QCOMPARE(pk1.Formula(1,2), 4);
    QCOMPARE(pk2.Formula(1,2), 3);
    QCOMPARE(pk3.Formula(1,2), 0);
    QCOMPARE(pk1.Formula(2,1), 5);
    QCOMPARE(pk2.Formula(2,1), 3);
    QCOMPARE(pk3.Formula(2,1), 0);
}

QTEST_APPLESS_MAIN(computer_test)

//#include "tst_computer_test.moc"

