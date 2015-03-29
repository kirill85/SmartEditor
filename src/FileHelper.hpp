#ifndef FILEHELPER_HPP
#define FILEHELPER_HPP

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QStringList>

class FileHelper : public QObject
{
    Q_OBJECT
private:
    QString content;
public:
    explicit FileHelper(QObject *parent = 0);
    virtual ~FileHelper();
    void setContent(QString content);
    QStringList filter;
signals:
    void fileContent(QString content);

public slots:
    void fileOpen(QString fileName);
    void fileSave(QString fileName);

};

#endif // FILEHELPER_HPP
