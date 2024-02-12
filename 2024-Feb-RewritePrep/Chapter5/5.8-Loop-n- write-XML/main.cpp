#include <QCoreApplication>
#include <QDebug>
#include <QDomDocument>
#include <iostream>
#include <QXmlStreamWriter>

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    cout << "Example 1: loop and write with QDomDocument " << endl;
    QStringList bookTitles = {"Harry Potter", "To Kill a Mockingbird"};
    QDomDocument doc;
    QDomElement root = doc.createElement("library");
    doc.appendChild(root);

    int bookId = 1;
    double price = 123.99;
    for (const QString &title : bookTitles) {

        QDomElement bookElement = doc.createElement("book");
        bookElement.setAttribute("id", QString::number(bookId++));

        QDomElement titleElement = doc.createElement("title");
        titleElement.setAttribute("price", QString::number(price++));

            titleElement.appendChild(doc.createTextNode(title));

        bookElement.appendChild(titleElement);
        root.appendChild(bookElement);
    }

    QString xmlString = doc.toString();
    cout << xmlString.toStdString();
/* output:
<library>
 <book id="1">
  <title price="123.99">Harry Potter</title>
 </book>
 <book id="2">
  <title price="124.99">To Kill a Mockingbird</title>
 </book>
</library>
 */

    cout << "\nExample 2: loop and write with QXmlStreamWriter " << endl;
    QString xmlString2;
    QXmlStreamWriter xml2(&xmlString2);
    QStringList bookTitles2 = {"Harry Potter", "To Kill a Mockingbird"};

    xml2.setAutoFormatting(true);
    xml2.writeStartDocument();
    xml2.writeStartElement("library");

    int bookId2 = 1;
    double price2 = 123.99;

    for (const QString &title : bookTitles) {

        xml2.writeStartElement("book");
        xml2.writeAttribute("id", QString::number(bookId2++));

            xml2.writeStartElement("title");
            xml2.writeAttribute("price", QString::number(price2++));
            xml2.writeCharacters(title);

            xml2.writeEndElement();  // title

        xml2.writeEndElement();  // book
    }

    xml2.writeEndElement();  // library
    xml2.writeEndDocument();

    cout << xmlString2.toStdString();

    /*
<?xml version="1.0"?>
<library>
    <book id="1">
        <title price="123.99">Harry Potter</title>
    </book>
    <book id="2">
        <title price="124.99">To Kill a Mockingbird</title>
    </book>
</library>
     */
    return QCoreApplication::exec();
}
