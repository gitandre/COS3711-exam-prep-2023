#include <QString>
#include <QDate>
#include <iostream>
#include "MyStaffMember.h"

// Staff member implementation
QString MyStaffMember::getN() const {
    return n;
}

QDate MyStaffMember::getBdate() const {
    return bdate;
}

MyAppTypeWrapper::MyAppType MyStaffMember::getAppType() const {
    return apptype;
}

void MyStaffMember::setName(const QString &n) {
    this->n = n;
}

void MyStaffMember::setBirthdate(const QDate &bdate) {
    this->bdate = bdate;
}

void MyStaffMember::setAppointmentType(QString apptype) {
    this->apptype = MyStaffMember::getAppTypeFromString(apptype);
}

[[maybe_unused]] QString MyStaffMember::getStringFromAppType(MyAppTypeWrapper::MyAppType t) {

    QObject *object = qvariant_cast<MyAppTypeWrapper *>('getAppTypeAsArray');
    MyAppTypeWrapper *matw = qobject_cast<MyAppTypeWrapper *>(object);
    QString val = matw->getStringFromAppType(t);
    return val;
}

MyAppTypeWrapper::MyAppType MyStaffMember::getAppTypeFromString(QString typeString) {
    std::cout << typeString.toStdString() << std::endl;

    if (typeString.toStdString() == "Contract") {
        return MyAppTypeWrapper::MyAppType::Contract;
    } else if (typeString.toStdString() == "PartTime") {
        return MyAppTypeWrapper::MyAppType::PartTime;
    } else {
        return MyAppTypeWrapper::MyAppType::Permanent;
    }
}

MyStaffMember::MyStaffMember() {

}

void MyStaffMember::setNameSlot(const QString &n) {
    this->setName(n);
}

void MyStaffMember::setBirthdateSlot(const QDate &bdate) {
    this->setBirthdate(bdate);
}

void MyStaffMember::setAppointmentTypeSlot(QString apptype) {
    this->setAppointmentType(apptype);
}

QString MyStaffMember::getNameSlot() {
    return this->getN();
}

QDate MyStaffMember::getBirthdateSlot() {
    return this->getBdate();
}

QString MyStaffMember::getAppointmentTypeSlot() {

    return MyStaffMember::getStringFromAppType(this->getAppType());
}


