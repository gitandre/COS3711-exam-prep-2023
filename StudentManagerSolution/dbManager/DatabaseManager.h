#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QtXml/QDomDocument>

// As a singleton :) vs simpleton :0
class DatabaseManager {
public:
    static DatabaseManager& getInstance();

    DatabaseManager(const DatabaseManager&) = delete;

    enum ObjectType {
        STUDENT,
        STUDENT_ADVISOR,
        MODULE,
        DEGREE
    };

    // CRUD for Student
    void createStudent(const QString& name, const QString& email);
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
    QDomDocument getAllRecords(const QString& type);

    // Get a record by ID
    QDomElement getARecord(const QString& type, int id);

private:
    DatabaseManager();

    void operator=(const DatabaseManager&) = delete;

    QString xmlPath;

    static int getNextIdForObject(DatabaseManager::ObjectType objectType);

    static int getNextId(const std::string& basicString);
};

#endif // DATABASEMANAGER_H
