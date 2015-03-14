#include "FileHelper.hpp"
#include "IOException.hpp"

FileHelper::FileHelper(QObject *parent) :
    QObject(parent)
{
    content = "";
    filter = new QStringList(std::initializer_list<QString>({QString("C source files (*.c)"),
                                                            QString("Objective-C source files (*.m)"),
                                                            QString("Header files (*.h)")}));
}

FileHelper::~FileHelper()
{
    delete filter;
}

void FileHelper::setContent(QString content)
{
    this->content = content;
}

void FileHelper::fileOpen(QString fileName)
{
    QString list;
    QFile file(fileName);
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream streamReader(&file);
        while(!streamReader.atEnd())
        {
            streamReader >> list;
        }
        emit fileContent(list);
        file.close();
    }
    else throw new IOException(this);
}

void FileHelper::fileSave(QString fileName)
{
    if(!content.isEmpty())
    {
        QFile file(fileName);
        QTextStream streamWriter(&file);
        if(file.open(QIODevice::ReadWrite))
        {

            streamWriter << content;
        }
        streamWriter.flush();
        file.close();
    }
    else throw new IOException(this);
}
