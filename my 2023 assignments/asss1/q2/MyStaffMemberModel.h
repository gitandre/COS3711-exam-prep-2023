// MyStaffMemberModel.h
#ifndef STAFFMEMBERMODEL_H
#define STAFFMEMBERMODEL_H

#include <QAbstractListModel>
#include "MyStaffMember.h"

class MyStaffMemberModel : public QAbstractListModel {
Q_OBJECT
public:
    explicit MyStaffMemberModel(QObject *parent = nullptr);

    // Row count and data setup
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Set date
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    // Adding data
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Add a staff member
    void addStaffMember(const MyStaffMember &staffMember);

private:
    QList<MyStaffMember> staffMembers;
};

#endif
