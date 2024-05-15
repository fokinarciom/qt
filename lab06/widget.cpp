#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)


{
    ui->setupUi(this);
    this->setWindowTitle("Database app");



    QFile file("output.json");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonArray jsonArray = jsonDoc.array();


    for (const QJsonValue& value : jsonArray) {
        if (value.isObject()) {

            QJsonObject jsonObject = value.toObject();

            Library newBook(jsonObject["category"].toString(),
                    jsonObject["name"].toString(),
                    jsonObject["author"].toString(),
                    jsonObject["year"].toString(),
                    jsonObject["publisher"].toString(),
                    jsonObject["annotation"].toString());
            data_.append(newBook);


        }
    }

    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &QWidget::close);
    QObject::connect(ui->pushButton_5, &QPushButton::clicked, [&](){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit",
                                     "Do you really want to clear database? After you click OK, you cannot cancel this action.",
                              QMessageBox::Ok | QMessageBox::Cancel);
        if (reply == QMessageBox::Ok){
            QFile file("output.json");
            file.open(QIODevice::ReadWrite | QIODevice::Truncate |  QIODevice::Text);
            file.close();
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_6_clicked() //add-button
{

    QFile file("output.json");
    Library newBook(ui->textEdit->toPlainText().trimmed().simplified(), ui->textEdit_2->toPlainText().trimmed().simplified(),
                    ui->textEdit_3->toPlainText().trimmed().simplified(), ui->textEdit_4->toPlainText().trimmed().simplified(),
                    ui->textEdit_5->toPlainText().trimmed().simplified(), ui->textEdit_6->toPlainText().trimmed().simplified());
    Library empty;
    on_pushButton_9_clicked();
    if(newBook != empty){
    if (std::find(data_.begin(), data_.end(), newBook) == data_.end()){
        data_.push_back(newBook);



    if (file.open(QIODevice::ReadWrite | QIODevice::Text)){
        QByteArray jsonData = file.readAll();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        QJsonObject jsonObject;
        QJsonArray jsonArray = jsonDoc.array();

        jsonObject["category"] =  ui->textEdit->toPlainText().trimmed().simplified();
        jsonObject["name"] =  ui->textEdit_2->toPlainText().trimmed().simplified();
        jsonObject["author"] = ui->textEdit_3->toPlainText().trimmed().simplified();
        jsonObject["year"] =  ui->textEdit_4->toPlainText().trimmed().simplified();
        jsonObject["publisher"] =  ui->textEdit_5->toPlainText().trimmed().simplified();
        jsonObject["annotation"] =  ui->textEdit_6->toPlainText().trimmed().simplified();


        jsonArray.append(jsonObject);


        file.seek(0);
        file.write(QJsonDocument(jsonArray).toJson());
        file.resize(file.pos());
    }
    }
    file.close();
    }
}




void Widget::on_pushButton_8_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_pushButton_2_clicked()
{
    bool flag = true;
    if (ui->plainTextEdit->toPlainText().trimmed().simplified().isEmpty()){
        flag = false;
    }

    QString category = ui->textEdit->toPlainText().trimmed().simplified();


    if (ui->comboBox->currentText() == "по наименованию"){
        QString str = "name";
        if(!flag){
            outJsonEmpty(str, category);
           // QVector<Library> data(data_);
           // qSort(data.begin(), data.end(), [](const Library& f, const Library& s){return f.getName() < s.getName();});
        }else{
            outJson(str, category);
        }

    }else{
        QString str = "author";
        if(!flag){
            outJsonEmpty(str, category);
            //QVector<Library> data(data_);
            //qSort(data.begin(), data.end(), [](const Library& f, const Library& s){return f.getAuthor() < s.getAuthor();});
        }else{
            outJson(str, category);
        }
    }



}


void Widget::outJson(QString& str, QString& category){
    QByteArray jsonData = ui->plainTextEdit->toPlainText().trimmed().toUtf8();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonArray jsonArray = jsonDoc.array();

    QVector<QJsonValue> vec;
    for (const QJsonValue &value : jsonArray) {
        if(category.isEmpty()){
            vec.push_back(value);
        }else{
            QJsonObject obj = value.toObject();
            if(obj["category"].toString() == category){
                vec.push_back(value);
            }
        }

    }


    std::sort(vec.begin(), vec.end(), [str](const QJsonValue &val1, const QJsonValue &val2) {
        QJsonObject obj1 = val1.toObject();
        QJsonObject obj2 = val2.toObject();
        return obj1[str].toString() < obj2[str].toString();
    });

    QJsonArray sortedArray;
    for (const QJsonValue &value : vec) {

        sortedArray.append(value);
    }

    jsonDoc.setArray(sortedArray);

    QString jsonString = jsonDoc.toJson(QJsonDocument::JsonFormat());
    ui->plainTextEdit->setPlainText(jsonString);
}



void Widget::outJsonEmpty(QString& str, QString& category){
    QFile file("output.json");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QByteArray jsonData = file.readAll();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

    QJsonArray jsonArray = jsonDoc.array();

    QVector<QJsonValue> vec;
    for (const QJsonValue &value : jsonArray) {
        if(category.isEmpty()){
            vec.push_back(value);
        }else{
            QJsonObject obj = value.toObject();
            if(obj["category"].toString() == category){
                vec.push_back(value);
            }
        }

    }

    std::sort(vec.begin(), vec.end(), [str](const QJsonValue &val1, const QJsonValue &val2) {
        QJsonObject obj1 = val1.toObject();
        QJsonObject obj2 = val2.toObject();
        return obj1[str].toString() < obj2[str].toString();
    });

    QJsonArray sortedArray;
    for (const QJsonValue &value : vec) {

        sortedArray.append(value);
    }

    jsonDoc.setArray(sortedArray);

    QString jsonString = jsonDoc.toJson(QJsonDocument::JsonFormat());
    ui->plainTextEdit->setPlainText(jsonString);
    file.close();
}




void Widget::on_pushButton_3_clicked()
{
    QString category = ui->textEdit->toPlainText().trimmed().simplified();
    QString name = ui->textEdit_2->toPlainText().trimmed().simplified();
    QString author = ui->textEdit_3->toPlainText().trimmed().simplified();


    QVector<Library> data(data_);
    QVector<Library> outVec;

    auto firstIt = data.begin();
    while (true){
        auto it = std::find_if(firstIt, data.end(), [category, name, author](const Library& book){
            bool res = true;
            if(!category.isEmpty()){
                res = category == book.getCategory();
            }
            if(!name.isEmpty()){
                res = (name == book.getName()) and res;
            }
            if(!author.isEmpty()){
                res = (author == book.getAuthor()) and res;
            }
            return res;
        });
        if(it != data.end()){
            outVec.append(*it);
            firstIt = std::next(it);
        }else{
            break;
        }

    }
    if(outVec.isEmpty()){
        ui->plainTextEdit->setPlainText("Data not found");
        return;
    }
    QJsonArray jsonArray;

    for(const auto& item : outVec){
        QJsonObject jsonObject;

        jsonObject["category"] = item.getCategory();
        jsonObject["name"] =  item.getName();
        jsonObject["author"] = item.getAuthor();
        jsonObject["year"] =  item.getYear();
        jsonObject["publisher"] =   item.getPublisher();
        jsonObject["annotation"] =  item.getAnnotation();


        jsonArray.append(jsonObject);
    }

    QJsonDocument jsonDoc;
    jsonDoc.setArray(jsonArray);
    //jsonArray = QJsonArray();
    QString jsonString = jsonDoc.toJson(QJsonDocument::JsonFormat());
    ui->plainTextEdit->setPlainText(jsonString);

    //on_pushButton_3_clicked();
}



void Widget::on_pushButton_4_clicked()
{
    QString curText = ui->comboBox_3->currentText();
    if(curText == "по году"){
        QString year = ui->textEdit_4->toPlainText();
        QString str = "year";
        if(!year.isEmpty()){
            functionForFilter(year, str);
        }
    }else{
        QString publisher = ui->textEdit_5->toPlainText();
        QString str = "publisher";
        if(!publisher.isEmpty()){
            functionForFilter(publisher, str);
        }

    }
}

void Widget::functionForFilter(const QString& str, const QString& tmp){

    QByteArray jsonData = ui->plainTextEdit->toPlainText().trimmed().toUtf8();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject;
    QJsonArray jsonArray = jsonDoc.array();

    QVector<QJsonValue> vec;
    for (const QJsonValue &value : jsonArray) {
        vec.push_back(value);
    }
    QJsonArray filteredArray;
    auto firstIt = vec.begin();
    while(true){
        auto it = std::find_if(firstIt, vec.end(), [str, tmp](const QJsonValue &val) {
            QJsonObject obj = val.toObject();
            return obj[tmp].toString() == str;
        });
        if(it != vec.end()){
            filteredArray.append(*it);
            firstIt = std::next(it);
        }else{
            break;
        }
    }
    if(filteredArray.empty()){
        ui->plainTextEdit->setPlainText("Data not found");
        return;
    }
    jsonDoc.setArray(filteredArray);

    QString jsonString = jsonDoc.toJson(QJsonDocument::JsonFormat());
    ui->plainTextEdit->setPlainText(jsonString);


}

void Widget::on_pushButton_9_clicked()
{
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->textEdit_3->setText("");
    ui->textEdit_4->setText("");
    ui->textEdit_5->setText("");
    ui->textEdit_6->setText("");
}

