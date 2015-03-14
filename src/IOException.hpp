#ifndef IOEXCEPTION_HPP
#define IOEXCEPTION_HPP

#include <QObject>

class IOException : public QObject
{
    Q_OBJECT
private:
    QString message = "Input/output error";
public:
    explicit IOException(QObject *parent = 0);
    QString getMessage() {return message;}
signals:

public slots:

};

#endif // IOEXCEPTION_HPP
