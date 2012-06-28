#include <QCoreApplication>
#include <QStringList>
#include <QtXmlPatterns/QXmlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{    
    QCoreApplication app(argc, argv);
    
    //set the query
    QXmlQuery query;
    query.setQuery("doc('index.html')/html/body/p/string()");

    //check if it is valid
    qDebug() << "IsValid: " << query.isValid();
    QStringList result;

    //evaluate
    qDebug() << "EvaluateTo: " << query.evaluateTo(&result);

    //printout the result
    qDebug() << "Result in a QStringList : \n" <<  result;
    
    return 0;
}

