#include <QCoreApplication>
#include <QDebug>
#include <QDomDocument>
#include <iostream>
#include <QXmlStreamWriter>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qDebug() << "Example 1: Find using QDomDocument, QDomNodeList and QDomElement";
    QString xmlString = "<library><book><title>Harry Potter</title></book><book><title>To Kill a Mockingbird</title></book></library>";
    QDomDocument doc;
    doc.setContent(xmlString);

    QDomNodeList titleNodes = doc.elementsByTagName("title");
    for(int i = 0; i < titleNodes.count(); ++i) {
        QDomElement titleElement = titleNodes.at(i).toElement();
        if(titleElement.text() == "Harry Potter") {
            qDebug() << "Found Harry Potter!";
        }
    }

    qDebug() << "\nExample 2: Find using QXmlStreamReader";
    QString xmlString2 = "<library><book id='1'><title>Harry Potter</title></book><book id='2'><title>To Kill a Mockingbird</title></book></library>";
    QXmlStreamReader xml2(xmlString2);

    while (!xml2.atEnd()) {
        xml2.readNext();
        if (xml2.isStartElement()) {
            if (xml2.name() == QString("title") && xml2.readElementText() == "Harry Potter") {
                qDebug() << "Found Harry Potter!";
            }
        }
    }
    return QCoreApplication::exec();
}
