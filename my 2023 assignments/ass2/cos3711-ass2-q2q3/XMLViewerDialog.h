#ifndef COS3711_ASS2_Q2_XMLVIEWERDIALOG_H
#define COS3711_ASS2_Q2_XMLVIEWERDIALOG_H
#include <QDialog>

class QTextEdit;
class XMLViewerDialog : public QDialog
{
Q_OBJECT
public:
    explicit XMLViewerDialog(const QString &filePath, QWidget *parent = nullptr);
private:
    QTextEdit *textEdit;
};
#endif