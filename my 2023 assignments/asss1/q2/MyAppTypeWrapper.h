//
// Created by jonny boo on 2023/05/28.
//
#include <QObject>

#ifndef COS3711_ASS1_Q2_CCC_H
#define COS3711_ASS1_Q2_CCC_H

#include <QString>

class MyAppTypeWrapper : public QObject {
Q_OBJECT
    Q_ENUMS(MyAppType)
    Q_PROPERTY(MyAppType myapptype READ getAppType WRITE setAppType)
public:

    const int len = 3;

    MyAppTypeWrapper(QObject *parent) : QObject(parent), m_myAppType(Permanent) {
        qRegisterMetaType<MyAppTypeWrapper::MyAppType>("MyAppType");
    }

    enum MyAppType {
        Permanent, PartTime, Contract
    };

    void setAppType(MyAppType t) { m_myAppType = t; }

    MyAppType getAppType() const { return m_myAppType; }

    static std::array<QString, 3> getAppTypeAsArray() {
        std::array<QString, 3> values = {"Permanent", "PartTime", "Contract"};
        return values;
    }

    static QString getStringFromAppType(MyAppTypeWrapper::MyAppType t) {
        switch (t) {
            case MyAppTypeWrapper::MyAppType::Permanent:
                return "Permanent";
            case MyAppTypeWrapper::MyAppType::PartTime:
                return "PartTime";
            case MyAppTypeWrapper::MyAppType::Contract:
                return "Contract";
            default:
                return "Unknown";
        }
    }

private:
    MyAppType m_myAppType;
};

Q_DECLARE_METATYPE(MyAppTypeWrapper::MyAppType)

#endif //COS3711_ASS1_Q2_CCC_H
