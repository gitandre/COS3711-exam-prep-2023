#ifndef MYITEM_H
#define MYITEM_H

#include <QString>
#include <QMetaType>

class MyItem {

public:
    QString name;

    void setName(const QString &name) {
        MyItem::name = name;
    }

    void setType(const QString &type) {
        MyItem::type = type;
    }

    const QString &getName() const {
        return name;
    }

    QString type;

    const QString &getType() const {
        return type;
    }

    // Factory pattern
    static MyItem createBook(const QString &name) {
        return MyItem(name, "Book");
    }

    static MyItem createMagazine(const QString &name) {
        return MyItem(name, "Magazine");
    }

    MyItem() : name(""), type("") {}

    MyItem(const QString &name, const QString &type) : name(name), type(type) {}

    MyItem(const MyItem &other) : name(other.name), type(other.type) {}

    MyItem &operator=(const MyItem &other) {
        if (this == &other) return *this;
        name = other.name;
        type = other.type;
        return *this;
    }
};

#endif