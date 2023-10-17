#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QtXml/QDomDocument>
#include <iostream>
#include "../SolutionObjectType.h"
#include "../Advisor.h"
#include "../Student.h"

using namespace std;

// As a singleton :) vs simpleton :0
class DatabaseManager {
public:

    static QString xmlPrefixPath;

    static DatabaseManager &getInstance();

    DatabaseManager(const DatabaseManager &) = delete;

    // CRUD for Student

    void readStudent(int id);

    void updateStudent(int id);

    void deleteStudent(int id);

    // CRUD for StudentAdvisor
//    void createStudentAdvisor(const QString& name, const QString& email);
//    // Placeholder methods for StudentAdvisor
//    void readStudentAdvisor(int id);
//    void updateStudentAdvisor(int id);
//    void deleteStudentAdvisor(int id);
//
//    // CRUD for Module
//    void createModule(const QString& name, int credits, const QList<int>& degreeIds);
//    // Placeholder methods for Module
//    void readModule(int id);
//    void updateModule(int id);
//    void deleteModule(int id);
//
//    // CRUD for Degree
//    void createDegree(const QString& name, int duration);
//    // Placeholder methods for Degree
//    void readDegree(int id);
//    void updateDegree(int id);
//    void deleteDegree(int id);

    // Get all records
    QDomDocument getAllRecords(const QString &type);

    // Get a record by ID
    QDomElement getARecord(const QString &type, int id);

    [[maybe_unused]] static int getNextIdForObject(SolutionObjectType objectType);

    static QString enumToString(SolutionObjectType enumObject);

    bool createNew(Advisor p_advisor);
    bool createNew(Student p_student);
    bool createXML(QString name, QString email, SolutionObjectType enumObject, QString friendlyName);

private:
    DatabaseManager();

    void operator=(const DatabaseManager &) = delete;

    static int getNextId(const QString &nodeName);


    QString getXmlpathForObject(SolutionObjectType enumObject);


};

#endif // DATABASEMANAGER_H
