#include <QCoreApplication>
#include <QtXmlPatterns/QXmlQuery>
#include <QtXmlPatterns/QXmlResultItems>
#include <QtXmlPatterns/QXmlItem>
#include <QDebug>

int main(int argc, char *argv[])
{    
    QCoreApplication app(argc, argv);

    //set the query, that creates a node, a number and an integer
    QXmlQuery query;
    query.setQuery("<myNode />, 1, 'a string'");

    //evaluate the query
    QXmlResultItems result;
    query.evaluateTo(&result);

    //iterate through the result items and check their type
    QXmlItem item(result.next());
    int index = 1;

    while (!item.isNull()) {     
     if (item.isNode())
	   qDebug() << "Item " << index << " is a node.";
     else 
     if (item.isAtomicValue())
       qDebug() << "Item " << index << " is an atomic value: " << item.toAtomicValue();     

     item = result.next();
     index++;
    }

    if (result.hasError()) {
	// Runtime error!
    }
    
    return 0;
}

