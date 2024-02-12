//Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 1
//----------------------------------------------------------------------------------------------------------------------
#ifndef ASS1_Q1_MYSTAFFMEMBER_H
#define ASS1_Q1_MYSTAFFMEMBER_H

#include <QString>
#include <QDate>

// Enum for holding the different position type
enum class AppTypeEnum {
    Permanent,
    PartTime,
    Contract
};

// The StaffMember header class
class MyStaffMember {

    // Public properties and functions
public:
    MyStaffMember(const QString &n, const QDate &bdate, AppTypeEnum apptype);

    //  StaffMemberGetters
    QString getN() const;
    QDate getBdate() const;
    AppTypeEnum getAppType() const;
    static QString getStringFromAppType(AppTypeEnum type);
    static AppTypeEnum getTypeFromString(QString typeString);

    //  StaffMemberSetters
    void setName(const QString &n);
    void setBirthdate(const QDate &bdate);
    void setAppointmentType(AppTypeEnum apptype);

    // Private properties and functions
private:
    QString n;
    AppTypeEnum apptype;
    QDate bdate;

};

#endif