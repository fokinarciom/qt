#include "library.h"

Library::Library(QString category,
                 QString name,
                 QString author,
                 QString year,
                 QString publisher,
                 QString annotation):
                 category_(category), name_(name),
                 author_(author), year_(year),
                 publisher_(publisher), annotation_(annotation){}




bool Library::operator ==(const Library& b1){
    return (b1.category_ == category_ and b1.name_ == name_
            and b1.year_ == year_ and b1.author_ == author_
            and b1.publisher_ == publisher_ and b1.annotation_ == annotation_);
}


bool Library::operator !=(const Library& b1){
    return !(*this == b1);
}

QString Library::getName() const{
    return this->name_;
}

QString Library::getAuthor() const{
    return this->author_;
}

QString Library::getCategory() const{
    return this->category_;
}
QString Library::getYear() const{
    return this->year_;
}
QString Library::getPublisher() const{
    return this->publisher_;
}
QString Library::getAnnotation() const{
    return this->annotation_;
}
