#ifndef COMMAND_H
#define COMMAND_H

#include <QCoreApplication>
#include <QString>
#include <QSet>
#include <QTextStream>
#include <QMap>
#include <QChar>
#include <QVector>
#include <iostream>

QTextStream out(stdout);
QTextStream in(stdin);

class Command{
private:
    QVector<int> vec_;
public:
    void fill(QVector<int>& vec){
        vec_ = vec;
    }
    virtual void execute(int num) = 0;

    void Task(int number){
        switch(number){
        case 174:
            Task174();
            break;
        case 186:
            Task186();
            break;
        case 198:
            Task198();
            break;
        default:
            out << "Command not found\n";
        }
    }

    void Task174(){
        std::cout << "Input 3 words\n";
        int count = 3;
        QMap<QChar, int> map;
        while(count){
            QString str;
            in >> str;
            str = str.toLower();
            QSet<QChar> letters(str.begin(), str.end());
            foreach(const QChar c, letters){
                ++map[c];

            }
            --count;
        }


        for (auto i = map.cbegin(), end = map.cend(); i != end; ++i)
            if(i.value()==3){
                out << i.key() ;
            }
        out << Qt::endl;
    }


    void Task186(){
        std::cout << "Input a sentence in one line\n";
        QString str;
        str = in.readLine();
        qsizetype size = str.size();
        QVector<QString> vec;

        QString tmp;
        int i = 0;
        while(i!=size){

            if(str[i]==' '){
                ++i;
                continue;
            }
            int counter = 0;
            int beginI = i;
            while(str[i] != ' ' and i!=size){
                ++i;
                ++counter;
            }
            tmp = str.mid(beginI, counter);
            vec.push_back(tmp);


        }

        std::sort(vec.begin(), vec.end(), [](const QString& lhs, const QString& rhs){return lhs.size() < rhs.size();});
        for(const QString& c : vec){
            out << c << ' ';
        }
        out << Qt::endl;
    }


    void Task198(){
        std::cout << "Input a sentence\n";
        QString str_ = in.readLine();
        std::cout << "Input length of future sentence\n";
        int l;
        in >> l;
        if(l == str_.size()){
            out << str_ << Qt::endl;
            return;
        }
        int amountOfBs = 0;
        int amountOfWords = 0;
        int i = 0;
        while (i != str_.size()) {
            while (str_[i] == ' ' and i != str_.size()) {
                ++amountOfBs;
                ++i;
            }
            if (i == 0 or str_[i - 1] == ' ') {
                ++amountOfWords;
            }
            ++i;
        }
        if(amountOfWords==1){
            while(l){
                str_ +=' ';
                --l;
            }
            out << str_ << Qt::endl;
            return;
        }
        amountOfBs += (l - str_.size());
        int mod = amountOfBs % (amountOfWords - 1);
        int regular = amountOfBs / (amountOfWords - 1);

        QString result = {};
        QVector<QString> vec;

        int j = 0;
        while (j != str_.size()) {
            if (str_[j] == ' ') {
                ++j;
                continue;
            }
            int counter = 0;
            int beginJ = j;
            while (str_[j] != ' ' and j != str_.size()) {
                ++j;
                ++counter;
            }

            QString tmp;
            tmp = str_.mid(beginJ, counter);
            vec.push_back(tmp);

        }

        int ind = 0;
        while (mod) {
            result += vec[ind];
            int tmpBs = regular + 1;
            while (tmpBs) {
                result += ' ';
                --tmpBs;
            }
            --mod;
            ++ind;
        }

        while (ind != vec.size()) {
            if (ind == vec.size() - 1) {
                result += vec[ind];
                break;
            }
            int tmpBs = regular;
            result += vec[ind];
            while (tmpBs) {
                result += ' ';
                --tmpBs;
            }
            ++ind;
        }

        str_ = std::move(result);
        out <<  Qt::endl <<  Qt::endl << str_ << Qt::endl;

    }

};

#endif // COMMAND_H
