#include "DatabaseManager.h"
#include <QFile>
#include <string>
#include <QDebug>
#include <QXmlStreamReader>
#include <iostream>

using namespace std;

QString DatabaseManager::xmlPrefixPath = QString("../xml/");

// Singleton instance
DatabaseManager &DatabaseManager::getInstance() {
    static DatabaseManager instance;
    return instance;
}

// Constructor
DatabaseManager::DatabaseManager() = default;

void DatabaseManager::createStudent(const QString &name, const QString &email) {
    // here we will create a new student record
    // we need to get the last or max id of any existing records and increment it and add

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

[[maybe_unused]] int DatabaseManager::getNextIdForObject(DatabaseManager::ObjectType objectType) {

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

QString DatabaseManager::enumToString(DatabaseManager::ObjectType enumObject) {
    switch (enumObject) {
        case DatabaseManager::ObjectType::STUDENT:
            return {"Student"};
        case DatabaseManager::ObjectType::ADVISOR:
            return {"Advisor"};
        case DatabaseManager::ObjectType::MODULE:
            return {"Module"};
        case DatabaseManager::ObjectType::DEGREE:
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




