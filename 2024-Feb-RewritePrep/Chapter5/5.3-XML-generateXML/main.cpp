#include <QCoreApplication>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>
#include <iostream>
#include <QXmlStreamWriter>

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    cout << "Example 1: Create XML using QDomDocument" << endl;
    QDomDocument doc;
    QDomElement root = doc.createElement("person");
    doc.appendChild(root);

    QDomElement name = doc.createElement("name");
    name.appendChild(doc.createTextNode("John"));
    root.appendChild(name);

    QDomElement age = doc.createElement("age");
    age.appendChild(doc.createTextNode("30"));
    root.appendChild(age);

    QString xmlString = doc.toString();
    cout << "Generated XML:" << endl;
    cout << xmlString.toStdString() << endl;
    cout << "---Example 1 end---" << endl;

    cout << "\n----------------------------------------------------------" << endl;
    cout << "Example 2: Create XML using QXmlStreamWriter" << endl;
    QString xmlString2;
    QXmlStreamWriter xml(&xmlString2);

    xml.setAutoFormatting(true);
    xml.writeStartDocument();
        xml.writeStartElement("library");
            xml.writeStartElement("book");
                xml.writeAttribute("id", "1");
                xml.writeTextElement("title", "Harry Potter and the Sorcerer's Stone");
                xml.writeTextElement("author", "J.K. Rowling");
            xml.writeEndElement();  // book

            xml.writeStartElement("book");
                xml.writeAttribute("id", "2");
                xml.writeTextElement("title", "To Kill a Mockingbird");
                xml.writeTextElement("author", "Harper Lee");
             xml.writeEndElement();  // book

        xml.writeEndElement();  // library
    xml.writeEndDocument();

    cout << "Generated Advanced XML:" << endl;
    cout << xmlString2.toStdString() << endl;
    cout << "---Example 2 end---" << endl;
    return QCoreApplication::exec();
}
