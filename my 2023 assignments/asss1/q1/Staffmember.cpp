//Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 1
//----------------------------------------------------------------------------------------------------------------------
#include <QString>
#include <QDate>
#include <iostream>
#include "MyStaffMember.h"

// Staff member implementation
MyStaffMember::MyStaffMember(const QString &n, const QDate &bdate, AppTypeEnum apptype)
        : n(n), bdate(bdate), apptype(apptype) {}

QString MyStaffMember::getN() const
{
    return n;
}

QDate MyStaffMember::getBdate() const {
    return bdate;
}

AppTypeEnum MyStaffMember::getAppType() const {
    return apptype;
}

void MyStaffMember::setName(const QString &n) {
    this->n = n;
}

void MyStaffMember::setBirthdate(const QDate &bdate) {
    this->bdate = bdate;
}

void MyStaffMember::setAppointmentType(AppTypeEnum apptype) {
    this->apptype = apptype;
}

QString MyStaffMember::getStringFromAppType(AppTypeEnum type) {

    switch (type) {
        case AppTypeEnum::Permanent:
            return "Permanent";
        case AppTypeEnum::PartTime:
            return "Part-Time";
        case AppTypeEnum::Contract:
            return "Contract";
        default:
            return "Unknown";
    }
}

AppTypeEnum MyStaffMember::getTypeFromString(QString typeString) {
    std::cout << typeString.toStdString() << std::endl;

    if (typeString.toStdString() == "Contract") {
        return AppTypeEnum::Contract;
    } else if (typeString.toStdString() == "Part-Time") {
        return AppTypeEnum::PartTime;
    } else {
        return AppTypeEnum::Permanent;
    }
}
