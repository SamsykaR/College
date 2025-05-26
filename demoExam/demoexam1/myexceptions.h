#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <QString>

class myExceptions
{
public:
    myExceptions();

    class dbOpenException
    {
    public:
        dbOpenException(const QString&);
        QString getMessage() const;
    private:
        QString message;
    };

    class queryReadException
    {
    public:
        queryReadException(const QString&, const QString& = "");
        QString getMessage() const;
    private:
        QString message;
        QString addMessage;
    };
};

#endif // MYEXCEPTIONS_H
