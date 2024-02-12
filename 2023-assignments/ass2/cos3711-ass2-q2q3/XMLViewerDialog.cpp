#include <QTextEdit>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include "XMLViewerDialog.h"

XMLViewerDialog::XMLViewerDialog(const QString &filePath, QWidget *parent)
        : QDialog(parent), textEdit(new QTextEdit(this))
{
    textEdit->setReadOnly(true);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    setLayout(layout);

    QFile file(filePath);

    // Open and read the file into a QStream
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }

    QString title =  "XML Viewer: " + file.fileName();
    // Set title and size
    setWindowTitle(title);
    resize(600, 800);
}
