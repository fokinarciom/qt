#ifndef INVOKER_H
#define INVOKER_H
#include "Command.h"
class Invoker : public Command{

public:
    Invoker(QVector<int>& vector){
        fill(vector);
    };
    void executeTask(){
        int number;
        std::cin >> number;
        execute(number);
    }
    void execute(int number) override{
        Task(number);
    }
};

#endif // INVOKER_H
