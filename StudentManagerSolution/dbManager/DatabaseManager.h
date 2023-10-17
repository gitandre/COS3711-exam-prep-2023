#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QDomDocument>
#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class DatabaseManager
{
public:
    static DatabaseManager& getInstance();
    bool loadXMLFiles();
    // CRUD methods for different objects will go here

private:
    DatabaseManager();
    DatabaseManager(const DatabaseManager&) = delete;
    void operator=(const DatabaseManager&) = delete;

    QDomDocument studentsDoc;
    QDomDocument advisorsDoc;
    QDomDocument modulesDoc;
    QDomDocument degreesDoc;

    bool loadXMLFile(const QString& filePath, QDomDocument& doc);
};

#endif // DATABASEMANAGER_H
