#include "DatabaseManager.h"

#include <QFile>
#include <QDebug>
#include <QXmlStreamReader>


using namespace std;

QString DatabaseManager::xmlPrefixPath = QString("../xml/");

// Singleton instance
DatabaseManager &DatabaseManager::getInstance() {
    static DatabaseManager instance;
    return instance;
}

// Constructor
DatabaseManager::DatabaseManager() = default;

QString DatabaseManager::getXmlpathForObject(SolutionObjectType enumObject) {

    QString enumString = enumToString(enumObject);
    QString fullxmlpath = xmlPrefixPath + enumString + ".xml";

    return fullxmlpath;
}

bool DatabaseManager::createNew(Advisor p_advisor) {

    QString name = p_advisor.getName();
    QString email = p_advisor.getName();
    auto enumObject = p_advisor.getObjectType();
    bool res = createXML(name, email, enumObject, "Advisor");
    return res;
}

bool DatabaseManager::createNew(Student p_student) {
    QString name = p_student.getName();
    QString email = p_student.getName();
    auto enumObject = p_student.getObjectType();
    bool res = createXML(name, email, enumObject, "Student");
    return res;
}

bool DatabaseManager::createXML(QString name, QString email, SolutionObjectType enumObject, QString friendlyName) {
    bool result = false;
    try {

        qDebug() << "-----------------------------";
        qDebug() << name;
        qDebug() << email;
        qDebug() << enumObject;
        qDebug() << friendlyName;
        qDebug() << "-----------------------------";

        int newId = getNextIdForObject(enumObject);
        qDebug() << newId;

        QString fullXmlPath = getXmlpathForObject(enumObject);
        qDebug() << fullXmlPath;

        QFile xmlFileReader(fullXmlPath);
        if (!xmlFileReader.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Couldn't open file.";
            return -1;
        }

        QDomDocument qDoc;
        qDoc.setContent(&xmlFileReader);

        xmlFileReader.close();

        // get the root
        QDomElement root = qDoc.documentElement();

        //Create student elements and set id
        QDomElement newStudentElement = qDoc.createElement(friendlyName);
        newStudentElement.setAttribute("id", newId);

        //Create name elements and set name
        QDomElement studentNameElement = qDoc.createElement("Name");
        QDomText studentTextName = qDoc.createTextNode(name);
        studentNameElement.appendChild(studentTextName);

        //Create email elements and set email
        QDomElement studentEmailElement = qDoc.createElement("Email");
        QDomText studentTextEmail = qDoc.createTextNode(email);
        studentEmailElement.appendChild(studentTextEmail);

        // append to newStudentElement
        newStudentElement.appendChild(studentNameElement);
        newStudentElement.appendChild(studentEmailElement);

        //Add to root
        root.appendChild(newStudentElement);

        QFile outFile(fullXmlPath);
        if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Couldn't open file for writing.";
            return -1;
        }

        QTextStream stream(&outFile);
        stream << qDoc.toString();
        outFile.close();

        result = true;
    } catch (...) {
        result = false;
        std::cerr << "Caught unknown exception" << std::endl;
    }

    return result;
}

void DatabaseManager::readStudent(int id) {

}

void DatabaseManager::updateStudent(int id) {

}

void DatabaseManager::deleteStudent(int id) {

}

QDomDocument DatabaseManager::getAllRecords(const QString &type) {
    return {};
}

QDomElement DatabaseManager::getARecord(const QString &type, int id) {
    return {};
}

[[maybe_unused]] int DatabaseManager::getNextIdForObject(SolutionObjectType objectType) {

    QString nodeName;

    switch (objectType) {
        case STUDENT:
            nodeName = DatabaseManager::enumToString(objectType);
            break;
        case ADVISOR:
            nodeName = DatabaseManager::enumToString(objectType);
            break;
        case MODULE:
            nodeName = DatabaseManager::enumToString(objectType);
            break;
        case DEGREE:
            nodeName = DatabaseManager::enumToString(objectType);
            break;
        default:
            break;

    }

    int newId = getNextId(nodeName);

    return newId;

}

QString DatabaseManager::enumToString(SolutionObjectType enumObject) {

    switch (enumObject) {
        case SolutionObjectType::STUDENT:
            return {"Student"};
        case SolutionObjectType::ADVISOR:
            return {"Student"};
        case SolutionObjectType::MODULE:
            return {"Module"};
        case SolutionObjectType::DEGREE:
            return {"Degree"};
        default:
            return {"Unknown"};
    }
}

int DatabaseManager::getNextId(const QString &nodeName) {

    QString filePath = xmlPrefixPath + "/" + nodeName + ".xml";
    // Convert std string to QString

    // Get and open Qfile
    QFile xmLfile(filePath);
    if (!xmLfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Couldn't open the XML file.";
        return -1;
    }

    // Instantiate QXmlStreamReader with a reference to the
    QXmlStreamReader xml(&xmLfile);
    int maxId = 0;


    // Loop until the end of the XML file or until an error is encountered
    while (!xml.atEnd() && !xml.hasError()) {
        // Read the next XML token (could be StartElement, EndElement, Characters, etc.)
        QXmlStreamReader::TokenType token = xml.readNext();

        // Check if the token is a StartElement (e.g., <Student>)
        if (token == QXmlStreamReader::StartElement) {
            // Check if the element name matches the target node name (e.g., "Student")
            if (xml.name() == nodeName) {
                // Retrieve all attributes of the current StartElement
                QXmlStreamAttributes attributes = xml.attributes();

                // Check if the element has an attribute named "id"
                if (attributes.hasAttribute("id")) {
                    // Declare a boolean variable to check the success of the conversion
                    bool ok;

                    // Convert the "id" attribute value to an integer
                    int id = attributes.value("id").toInt(&ok);

                    // Check if the conversion was successful and if the new id is greater than maxId
                    if (ok && id > maxId) {
                        // Update maxId with the new greater id value
                        maxId = id;
                    }
                }
            }
        }
    }


    if (xml.hasError()) {
        qWarning() << "XML error: " << xml.errorString();
    }

    xmLfile.close();

    return maxId + 1;  // return the next available ID
}




