//Name: Bobby Nooba | Student Number: 666123 | Assignment 1 Unique number: 724933 | Question 3
//----------------------------------------------------------------------------------------------------------------------
#ifndef COS3711_ASS1_Q3_MYALBUMMODEL_H
#define COS3711_ASS1_Q3_MYALBUMMODEL_H

#include <QAbstractTableModel>
#include "MyAlbum.h"

// The album model inherited from QAbstractTableModel
class MyAlbumModel : public QAbstractTableModel {
Q_OBJECT

public:
    //Constructor-----------------------------
    explicit MyAlbumModel(QObject *p = nullptr);

    const int columns = 4;

    // Abstract functions---------------------------------------------------------------------------------------------
    int rowCount(const QModelIndex &p = QModelIndex()) const override;

    int columnCount(const QModelIndex &p = QModelIndex()) const override;

    QVariant data(const QModelIndex &i, int myRole = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation ori, int r = Qt::DisplayRole) const override;

    // Editable model methods/functions--------------------------------------------------------------------------------
    Qt::ItemFlags flags(const QModelIndex &i) const override;

    bool setData(const QModelIndex &i, const QVariant &v, int myRole = Qt::EditRole) override;

    // Additional method for adding album
    void addAlbum(const MyAlbum &myAlbum);

    // Private properties----------------------------------------------------------------------------------------------
private:
    QList<MyAlbum> myAlbumList;
};

#endif
