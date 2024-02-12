//Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 3
//----------------------------------------------------------------------------------------------------------------------
#include "MyAlbumModel.h"
#include <QLocale>

//The album model implementation----------------------------------------------------------------------------------------
// Constructor
MyAlbumModel::MyAlbumModel(QObject *p)
        : QAbstractTableModel(p) {
}

//Display data for view
QVariant MyAlbumModel::data(const QModelIndex &i, int myRole) const {
    // Validity checking
    if (!i.isValid())
        return QVariant();

    if (i.row() >= myAlbumList.size() || i.row() < 0)
        return QVariant();

    // Check roles and return QVariant if not display myRole
    if (myRole == Qt::DisplayRole) {
        const auto &myAlbum = myAlbumList.at(i.row());

        //Switch on column indexes and return vals
        switch (i.column()) {
            case 0:
                return myAlbum.composer;
            case 1:
                return myAlbum.name;
            case 2:
                // Setting currency symbol and precision
                return QLocale::system().toCurrencyString(myAlbum.cost, "R ", 2);
            case 3:
                return myAlbum.rating;
        }
    }
    return QVariant();
}

//Set the header row values
QVariant MyAlbumModel::headerData(int section, Qt::Orientation ori, int r) const {

    // Check roles and return QVariant if not display r
    if (r != Qt::DisplayRole)
        return QVariant();

    //Switch on sections and return vals
    if (ori == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Composer");
            case 1:
                return tr("Album Name");
            case 2:
                return tr("Cost");
            case 3:
                return tr("Rating (0-100)");
        }
    }
    return QVariant();
}

// Make model editable
Qt::ItemFlags MyAlbumModel::flags(const QModelIndex &i) const {
    if (!i.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(i) | Qt::ItemIsEditable;
}

//Change model on edit for index and specific column (i.e cell)
bool MyAlbumModel::setData(const QModelIndex &i, const QVariant &v, int myRole) {

    if (i.isValid() && myRole == Qt::EditRole) {
        int row = i.row();

        auto album = myAlbumList.value(row);

        if (i.column() == 0)
            album.composer = v.toString();
        else if (i.column() == 1)
            album.name = v.toString();
        else if (i.column() == 2)
            album.cost = v.toDouble();
        else if (i.column() == 3)
            album.rating = v.toInt();
        else
            return false;

        // Replace the entry with new data
        myAlbumList.replace(row, album);

        //emit the data changed signal
        emit(dataChanged(i, i));

        return true;
    }

    return false;
}

// Add a new myAlbum
void MyAlbumModel::addAlbum(const MyAlbum &myAlbum) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    myAlbumList << myAlbum;

    endInsertRows();
}

//Get the rowcount
int MyAlbumModel::rowCount(const QModelIndex & /*parent*/) const {
    return myAlbumList.count();
}

//Get the column count
int MyAlbumModel::columnCount(const QModelIndex & /*parent*/) const {
    return columns;
}