#include <QCoreApplication>
#include <QDebug>
#include <QDomDocument>
#include <QXmlStreamReader>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qDebug() << "Example 1: Loop through XML using QDomDocument and QDomNodeList";
    QString xmlString = "<library><book><title>Harry Potter</title></book><book><title>To Kill a Mockingbird</title></book></library>";
    QDomDocument doc;
    doc.setContent(xmlString);

    QDomNodeList bookNodes = doc.elementsByTagName("book");
    for (int i = 0; i < bookNodes.count(); ++i) {
        QDomElement bookElement = bookNodes.at(i).toElement();
        QDomElement titleElement = bookElement.firstChildElement("title");
        qDebug() << "Title:" << titleElement.text();
    }

    qDebug() << "\nExample 2: Loop through XML using QXmlStreamReader";
    QString xmlString2 = "<library><book id='1'><title>Harry Potter</title></book><book id='2'><title>To Kill a Mockingbird</title></book></library>";
    QXmlStreamReader xml(xmlString2);
    /* output:
Title: "Harry Potter"
Title: "To Kill a Mockingbird"
     */

    while (!xml.atEnd()) {
        xml.readNext();
        // Check if the current element is a start element named 'book'
        if (xml.isStartElement() && xml.name() == QString("book")) {

            // Retrieve the 'id' attribute of the 'book' element
            QStringView bookId = xml.attributes().value("id");
            qDebug() << "Book ID:" << bookId.toString();

            // Read the next element, which should be the 'title' element based on the structure
            xml.readNext();
            // Assuming the structure is always <book><title>Title</title></book>
            if (xml.isStartElement() && xml.name() == QString("title")) {
                qDebug() << "Title:" << xml.readElementText();
            }
        }

    }


    /* output:
Book ID: "1"
Title: "Harry Potter"
Book ID: "2"
Title: "To Kill a Mockingbird"
 */


    //XML error checking - broken start tag
    qDebug() << "\nXML error checking - must parse to get errors";
    QString xmlStringError = "library><book id='1'><title>Harry Potter</title></book><book id='2'><title>To Kill a Mockingbird</title></book></library>";
    QXmlStreamReader xmlStreamError(xmlStringError);

    // Must parse and errors get collected
    while (!xmlStreamError.atEnd()) {
        xmlStreamError.readNext();
        // Check if the current element is a start element named 'book'
        if (xmlStreamError.isStartElement() && xmlStreamError.name() == QString("book")) {

            // Retrieve the 'id' attribute of the 'book' element
            QStringView bookId = xmlStreamError.attributes().value("id");
            qDebug() << "Book ID:" << bookId.toString();

            // Read the next element, which should be the 'title' element based on the structure
            xmlStreamError.readNext();
            // Assuming the structure is always <book><title>Title</title></book>
            if (xmlStreamError.isStartElement() && xmlStreamError.name() == QString("title")) {
                qDebug() << "Title:" << xmlStreamError.readElementText();
            }
        }
    }
    if (xmlStreamError.hasError()) {

        qDebug() << "XML Error:" << xmlStreamError.errorString();
        // XML Error: "Start tag expected."
    } else {
        qDebug() << "No XML Error:";
    }


    return QCoreApplication::exec();
}
