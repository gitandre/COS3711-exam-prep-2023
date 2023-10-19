## XML and QT6




### Find and read with QXmlStreamReader

```c++
QFile file("test.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Cannot read file" << file.errorString();
        exit(0);
    }

    QXmlStreamReader reader(&file);

    if (reader.readNextStartElement()) {
        if (reader.name() == "root"){
            while(reader.readNextStartElement()){
                if(reader.name() == "childA"){
                    QString s = reader.readElementText();
                    qDebug(qPrintable(s));
                }
                else
                    reader.skipCurrentElement();
            }
        }
        else
            reader.raiseError(QObject::tr("Incorrect file"));
    }
```