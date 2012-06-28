#include <QCoreApplication>
#include <QtXmlPatterns/QXmlQuery>
#include <QtXmlPatterns/QXmlFormatter>
#include <QTextStream>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{    
    QCoreApplication app(argc, argv);
    
    //initialize the query
    QXmlQuery query;
    query.setQuery("doc('index.html')/html/body/p[1]");

    
    //run through the serializer
    QFile f("result-serializer.xml");
    f.open(QIODevice::WriteOnly);
    QXmlSerializer serializer(query, &f);
    query.evaluateTo(&serializer);
    f.close();
    
    qDebug() << "result-serializer.xml created";

    //run through the formatter
    QFile file("result-formatter.xml");
    file.open(QIODevice::WriteOnly);
    QXmlFormatter formatter(query, &file);
    formatter.setIndentationDepth(4);
    query.evaluateTo(&formatter);
    file.close();

    qDebug() << "result-formatter.xml created";

    return 0;
}

