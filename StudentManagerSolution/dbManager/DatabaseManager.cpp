#include "DatabaseManager.h"
#include <QFile>
#include <string>

using namespace std;

// Singleton instance
DatabaseManager& DatabaseManager::getInstance() {
    static DatabaseManager instance;
    return instance;
}

// Constructor
DatabaseManager::DatabaseManager() {
    xmlPath = "../xml/";
}

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

int DatabaseManager::getNextIdForObject(DatabaseManager::ObjectType objectType) {

    string xmlFilePath = "../xml/";

    switch(objectType){
        case STUDENT:
            xmlFilePath = xmlFilePath + "Student.xml";
            break;
        case STUDENT_ADVISOR:
            xmlFilePath = xmlFilePath + "StudentAdvisor.xml";
            break;
        case MODULE:
            xmlFilePath = xmlFilePath + "Module.xml";
            break;
        case DEGREE:
            xmlFilePath = xmlFilePath + "Degree.xml";
            break;
        default:
            break;

    }

    int newId = getNextId(xmlFilePath);

    return newId;

}

int DatabaseManager::getNextId(const string& basicString) {




    return 0;
}

