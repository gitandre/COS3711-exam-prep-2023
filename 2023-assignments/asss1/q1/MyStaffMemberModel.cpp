//Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 1
//----------------------------------------------------------------------------------------------------------------------
#include "MyStaffMemberModel.h"

// The staff member model derived from QAbstractListModel
MyStaffMemberModel::MyStaffMemberModel(QObject *parent)
        : QAbstractListModel(parent) {
}

void MyStaffMemberModel::addStaffMember(const MyStaffMember &staffMember) {
    const int index = staffMembers.size();
    beginInsertRows(QModelIndex(), index, index);
    staffMembers.append(staffMember);
    endInsertRows();
}

int MyStaffMemberModel::rowCount(const QModelIndex &) const {
    return staffMembers.size();
}

QVariant MyStaffMemberModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= staffMembers.size())
        return QVariant();

    const MyStaffMember &staffMember = staffMembers.at(index.row());
    if (role == Qt::DisplayRole) {
        return QString("%1, %2, %3").arg(
                staffMember.getN(),
                staffMember.getBdate().toString(),
                MyStaffMember::getStringFromAppType(staffMember.getAppType()));
    }

    return QVariant();
}

Qt::ItemFlags MyStaffMemberModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

bool MyStaffMemberModel::setData(const QModelIndex &index, const QVariant &value, int role) {

    // not fully implemented yet
    return false;
}

bool MyStaffMemberModel::insertRows(int row, int count, const QModelIndex &parent) {
    beginInsertRows(parent, row, row + count - 1);

    // not fully implemented yet
    endInsertRows();
    return true;
}

bool MyStaffMemberModel::removeRows(int row, int count, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row + count - 1);

    // Not fully implemented yat
    endInsertRows();
    return true;
}