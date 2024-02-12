#include <QCoreApplication>
#include <QCommandLineParser>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QCommandLineOption>

// A function to return the number of matches for a specified file content and specified regex pattern
int getPatternMatchCount(const QString &content, QRegularExpression expression) {

    // Create a global pattern matcher
    QRegularExpressionMatchIterator i = expression.globalMatch(content);

    int countA = 0;
    // loop and count the matches
    while (i.hasNext()) {
        i.next();
        countA++;
    }

    // return the count
    return countA;
}

// Main application entry point
int main(int argc, char *argv[]) {

    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("Regex Word Count for Files");

    QCommandLineParser myRegexParser;
    myRegexParser.setApplicationDescription("Counts occurrences of certain types of words (via regex matches) in given allFiles");
    myRegexParser.addHelpOption(); // Enable help options

    QCommandLineOption aFlag(QStringList() << "a", "Count the number of words longer than 4 characters that start with a capital letter.");
    myRegexParser.addOption(aFlag);

    QCommandLineOption bFlag(QStringList() << "b", "Count the number of words that are hyphenated.");
    myRegexParser.addOption(bFlag);

    QCommandLineOption cFlag(QStringList() << "c", "Count the number of words that start and end on the same character.");
    myRegexParser.addOption(cFlag);

    QCommandLineOption dFlag(QStringList() << "d", "Count the number of words that do not start with a vowel.");
    myRegexParser.addOption(dFlag);

    myRegexParser.addPositionalArgument("file", "The file to process.");

    myRegexParser.process(app); // enable the myRegexParser and app

    // Allow the positional arguments to be of type file
    const QStringList allFiles = myRegexParser.positionalArguments();

    // Simple error handling for no allFiles passed in
    if(allFiles.isEmpty()) {
        QTextStream(stdout) << "No file path/s argument provided. Provide one or more file path/s arguments.\n";
        return 0;
    }

    //Set myRegexParser flags
    const bool a = myRegexParser.isSet(aFlag);
    const bool b = myRegexParser.isSet(bFlag);
    const bool c = myRegexParser.isSet(cFlag);
    const bool d = myRegexParser.isSet(dFlag);
    const bool noFlags = !(a || b || c || d);

    // a. Regex for Count the number of words longer than 4 characters that start with a capital letter.
    QRegularExpression regexA("\\b[A-Z][a-zA-Z]{4,}\\b");

    // b. Regex for count the number of words that are hyphenated.
    QRegularExpression regexB(R"(\b\w+-\w+\b)");

    // c. Regex for count the number of words that start and end on the same character.
    QRegularExpression regexC(R"(\b(\w)\w*\1\b)");

    // d. Regex for getting all words and those starting with vowels will use a difference calculation
    QRegularExpression regexD("\\b[aeiouAEIOU]\\w*\\b");
    QRegularExpression regexAllWords("\\b\\w+\\b");

    // for each file provided, read the content and based on args provided perform regex matches
    // and print out the associated counts
    int fileIndex = 1;
    for (const QString& filePath : allFiles) {

        // Open the file
        QFile file(filePath);
        if(!file.open(QIODevice::ReadOnly)) {

            // If unable to open the file, print error message but continue to next file
            QTextStream(stderr) << "Error: Could not open file: " << filePath << "\n";
            continue;
        }

        // Get the file fileContent
        QString fileContent = QTextStream(&file).readAll();

        // Close the file
        file.close();

        QTextStream(stdout) << "\n";
        QTextStream(stdout) << fileIndex << ". File path: " << filePath << "\n";

        // Handle the set arguments for a given run
        if(a || noFlags){
            QTextStream(stdout) << " a. Count for all words longer than 4 characters that start with a capital letters: ";
            QTextStream(stdout) << getPatternMatchCount(fileContent, regexA) << "\n";
        }
        if(b || noFlags){
            QTextStream(stdout) << " b. Count the number of words that are hyphenated: ";
            QTextStream(stdout) << getPatternMatchCount(fileContent, regexB) << "\n";
        }
        if(c || noFlags){
            QTextStream(stdout) << " c. Count the number of words that start and end on the same character; ";
            QTextStream(stdout) << getPatternMatchCount(fileContent, regexC) << "\n";
        }
        if(d || noFlags){
            QTextStream(stdout) << " d. Count the number of words that do not start with a vowel: ";
            QTextStream(stdout) << getPatternMatchCount(fileContent, regexAllWords) - getPatternMatchCount(fileContent, regexD) << "\n";
        }

        fileIndex++;
    }
    return 0;
}
