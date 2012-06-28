#include <QCoreApplication>
#include <QStringList>
#include <QtXmlPatterns/QXmlQuery>
#include <QtXmlPatterns/QXmlFormatter>
#include <QFile>
#include <QTextStream>

#include <QtXml/QDomDocument>

#include <QDebug>

void useQDom()
{
//Load the artists and albums files and select the albums for a 
//specific artist. Create a new file with the selected album titles
//and release years.
  QDomDocument artists;
  QFile file("artists.xml");
  if (!file.open(QIODevice::ReadOnly))
    return;
  if (!artists.setContent(&file)) {	
      file.close();
      return;
  }
  file.close();

  QDomDocument albums;
  file.setFileName("albums.xml");
  if (!file.open(QIODevice::ReadOnly))
    return;
  if (!albums.setContent(&file)) {	
      file.close();
      return;
  }
  file.close();
  
  QString artistName = "Helloween";
  int artistId = -1;
  QDomNodeList artistNodes = artists.elementsByTagName("artist");
  for (int i = 0; i < artistNodes.count(); i++)
  {
     QDomNode node = artistNodes.at(i);  
     QString name = node.firstChild().nodeValue();
     if (name.endsWith(artistName)) 
     {
       artistId = node.toElement().attribute("id", "-1").toInt();
       break;
     }
  }

  if (artistId == -1)
    return;

  QDomDocument result;
  QDomElement root = result.createElement("result"); 
  result.appendChild(root);
  QDomNodeList albumNodes = albums.elementsByTagName("album");
  for (int i = 0; i < albumNodes.count(); i++)
  {
     QDomNode node = albumNodes.at(i);  
     QDomNodeList albumInfoNodes = node.childNodes();
     QString title;
     QString year;
     int artistRef = -1; 
     for (int j = 0; j < albumInfoNodes.count(); j++)
     {
       QDomNode infoNode = albumInfoNodes.at(j);
       if (infoNode.nodeName() == "title")
	  title = infoNode.firstChild().nodeValue();
       else
       if (infoNode.nodeName() == "year")
	  year = infoNode.firstChild().nodeValue();
       else
       if (infoNode.nodeName() == "artistRef")
	  artistRef = infoNode.firstChild().nodeValue().toInt();
     }
     if (artistRef == artistId)
     {
	QDomElement element = result.createElement("album");
	element.setAttribute("name", title);
	element.setAttribute("year", year);
	root.appendChild(element);
     }
  }
  	
  file.setFileName("result-qdom.xml");
  if (!file.open(QIODevice::WriteOnly))
   return;
  QTextStream stream(&file);
  stream << result.toString();
  file.close();

  qDebug() << "Result saved into result-qdom.xml";
}

void useQXmlQuery()
{
// Run a query that is loaded from a file and save the result in a .xml file.
// The query does the same selection like the useQDom() code.
    QFile file("query.xq");
    if (!file.open(QIODevice::ReadOnly))
        return;
    QTextStream stream(&file);
    
    QString queryString = stream.readAll();
    file.close();
    
    QXmlQuery query;
    query.setQuery(queryString);
    
    QFile resultFile("result-xquery.xml");
    if (!resultFile.open(QIODevice::WriteOnly))
        return;
    
    QXmlFormatter formatter(query,&resultFile);
    formatter.setIndentationDepth(2);
    query.evaluateTo(&formatter);
    resultFile.close();
    
    qDebug() << "Result saved into result-xquery.xml";
    
}

int main(int argc, char *argv[])
{    
    QCoreApplication app(argc, argv);
    
    useQXmlQuery();
    useQDom();
    
    return 0;
}

