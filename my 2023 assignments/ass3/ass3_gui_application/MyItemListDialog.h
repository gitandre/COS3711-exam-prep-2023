#include <QDialog>
#include <QListWidget>
#include "MyItem.h"

class MyItemListDialog : public QDialog {
Q_OBJECT
public:
    explicit MyItemListDialog(const QList<MyItem> &items, QWidget *parent = nullptr);
private:
    QListWidget *listWidget;
};
