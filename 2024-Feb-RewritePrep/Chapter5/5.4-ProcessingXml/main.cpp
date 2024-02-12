#include <QCoreApplication>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNodeList>
#include <QXmlStreamReader>
#include <QString>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    cout << "Simple XML parsing using QDomDocument for simple XML" << endl;
    QString xmlString = "<person><name>John</name><age>30</age></person>";
    QDomDocument doc;
    doc.setContent(xmlString);

    QDomElement root = doc.documentElement();
    QDomElement nameElement = root.firstChildElement("name");
    QDomElement ageElement = root.firstChildElement("age");

    cout << "Name:" << nameElement.text().toStdString() << endl;
    cout << "Age:" << ageElement.text().toStdString() << endl;

    cout << "\n---------------------------------------------------------" << endl;
    cout << "Advanced XML Parsing using QXmlStreamReader for complex XML" << endl;
    QString xmlString2 = "<library><book id='1'><title>Harry Potter</title></book><book id='2'><title>To Kill a Mockingbird</title></book></library>";
    QXmlStreamReader xml(xmlString2);

    while (!xml.atEnd()) {
        xml.readNext();
        if (xml.isStartElement()) {
            if (xml.name() == QString("book")) {
                QString id = xml.attributes().value("id").toString();
                cout << "Book ID:" << id.toStdString() << endl;
            } else if (xml.name() == QString("title")) {
                cout  << "Title:" << xml.readElementText().toStdString() << endl;
            }
        }
    }

    return QCoreApplication::exec();
}
