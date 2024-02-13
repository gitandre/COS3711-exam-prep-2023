#include <QCoreApplication>
#include <QDebug>
#include <QLineEdit>
#include <QIntValidator>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Simple validator
//    QLineEdit lineEdit;
//    QIntValidator validator(1, 99, &lineEdit);  // Only allow integers between 1 and 99
//    lineEdit.setValidator(&validator);
//    lineEdit.show();

//QRegularExpression

//    QString pattern = "F[a-z]+-X-[A-Z]{3}-Y-[0-9]+-A-[0-9]*[13579]";
//    QString pattern = "F[a-z]{1}[A-Z]{2}-X-[A-Z]{3}-Y-[0-9]+-A-[0-9]*[13579]";
//    QString pattern = "^(?!.*FUP)F[a-z]{1}[A-Z]{2}-X-[A-Z]{3}-Y-[0-9]+-A-[0-9]*[13579]";
    QString pattern = "^(?=.*BIG)(?!DONT)(?!.*FUP)F[a-z]{1}[A-Z]{3}-X-[A-Z]{3}-Y-[0-9]+-A-[0-9]*[13579](?<!CRY)$";

    // + multiple matches
    // * zero or more matches
    // {3} must be 3 of them
    // ^ from the start
    // (?!.*FUP) - negative look ahead for any FUP in string
    // .* = matches in patterns
    // ^(?!DONT).*(?<!CRY)$"
    // $ asserts end of string
    // ^(?!DONT) - cannot start with DONT
    // (?<!CRY)$ - cannot end with CRY
    // ^(?=.*BIG) positive loop ahead - must contain BIG

    QRegularExpression re(pattern);

    QStringList testStrings = {
            "Fa-X-M-Y-12345-A-3", // Does not match
            "Fabc-X-M-Y-12345-A-3", // Does not match
            "Fb-X-N-Y-67890-A-42", // Does not match (42 is not odd)
            "Fc-X-O-Y-11111-A-57", // Does not match
            "Fcabc-X-ABC-Y-112233-A-57", // Does not match
            "FcAB-X-ABC-Y-112233-A-57", // Does not match
            "FcAB-X-ABC-Y-112233-A-57-FUP", // Does not match
            "FcAB-X-ABC-Y-112233-A-57", // Does not match
            "DONT-FcAB-X-ABC-Y-112233-A-57-CRY", // Does not match
            "FcAB-X-ABC-Y-112233-A-57", // Does not match
            "FcAB-X-BIG-Y-112233-A-57", // Does not match
            "FaBCD-X-XYZ-Y-12345-A-1BIG" //does not match
    };

    for (const QString &testString : testStrings) {
        QRegularExpressionMatch match = re.match(testString);
        if (match.hasMatch()) {
            qDebug() << testString << "matches";
        } else {
            qDebug() << testString << "does not match";
        }
    }



    return QCoreApplication::exec();
}
