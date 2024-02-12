#ifndef ASS1_Q1_MYSTAFFMEMBER_H
#define ASS1_Q1_MYSTAFFMEMBER_H

#include <QString>
#include <QDate>
#include <QObject>
#include "MyAppTypeWrapper.h"

// The StaffMember header class
class MyStaffMember {

public:
    MyStaffMember();

public slots:

    void setNameSlot(const QString &n);

    void setBirthdateSlot(const QDate &bdate);

    void setAppointmentTypeSlot(QString apptype);

    QString getNameSlot();

    QDate getBirthdateSlot();

    QString getAppointmentTypeSlot();

    // Private properties and functions
private:
    QString n;
    MyAppTypeWrapper::MyAppType apptype;
    QDate bdate;

    //  StaffMemberGetters
    QString getN() const;

    QDate getBdate() const;

    MyAppTypeWrapper::MyAppType getAppType() const;

    static QString getStringFromAppType(MyAppTypeWrapper::MyAppType type);

    static MyAppTypeWrapper::MyAppType getAppTypeFromString(QString typeString);


    //  StaffMemberSetters
    void setName(const QString &n);

    void setBirthdate(const QDate &bdate);

    void setAppointmentType(QString apptype);

};

#endif