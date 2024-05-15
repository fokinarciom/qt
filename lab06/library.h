#ifndef LIBRARY_H
#define LIBRARY_H
#include <QString>
#include <QVector>
class Library
{
private:
    QString category_ = "";
    QString name_ = "";
    QString author_ = "";
    QString year_ = "";
    QString publisher_ = "";
    QString annotation_ = "";
public:
    Library(QString , QString b = "", QString c = "" , QString d = "", QString e= "" , QString f= "");
    Library() = default;
    bool operator ==(const Library& b1);
    bool operator !=(const Library& b1);
    QString getName() const;
    QString getAuthor() const;
    QString getCategory() const;
    QString getYear() const;
    QString getPublisher() const;
    QString getAnnotation() const;
};


#endif // LIBRARY_H
