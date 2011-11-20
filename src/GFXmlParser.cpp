
#include <iostream>
#include "GFXmlParser.h"

XERCES_CPP_NAMESPACE_USE
using std::cout;
using std::map;
using std::string;

static GFXmlParser * _instance=NULL;
GFXmlParser *
GFXmlParser::getInstance() {
	if (_instance==NULL) {
		_instance = new GFXmlParser();
	}
	return _instance;
}

void
GFXmlParser::initialize() {

	try {
      XMLPlatformUtils::Initialize();
  }
  catch (const XMLException& toCatch) {
      char* message = XMLString::transcode(toCatch.getMessage());
			std::cerr << "Error during initialization! :\n"
            << message << "\n";
      XMLString::release(&message);
  }
}

GFXmlDocument * 
GFXmlParser::parse(const char *xmlFile) {
	XercesDOMParser* parser = new XercesDOMParser();
	
  parser->setValidationScheme(XercesDOMParser::Val_Always);    
  parser->setDoNamespaces(true);    // optional

  ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
  parser->setErrorHandler(errHandler);

	GFXmlDocument * newdoc = NULL;
	XERCES_CPP_NAMESPACE::DOMDocument * xmldoc;

	try {
		parser->parse(xmlFile);	
		xmldoc = parser->getDocument();
		newdoc = new GFXmlDocument();

		DOMElement *rootNode = xmldoc->getDocumentElement();
		GFXmlElement * newnode;
		
		newnode = populateElement(rootNode);
		newdoc->setRootElement(newnode);

	} catch (const XMLException& e) {
		cout << "ERROR: " << XMLString::transcode(e.getMessage());
		return NULL;
	} catch (const DOMException& e) {
		cout << "ERROR: " << XMLString::transcode(e.getMessage());
		return NULL;
	} catch (exception& e) {
		cout << "ERROR: " << e.what();
		return NULL;
	} catch (...) {
    cout << "Unexpected Exception \n" ;
    return NULL;
	}


	delete parser;
  delete errHandler;
	return newdoc;
}

GFXmlElement *
GFXmlParser::populateElement(DOMElement *rootNode){
	GFXmlElement * newnode = new GFXmlElement(XMLString::transcode(rootNode->getNodeName())); 
	newnode->setContents(XMLString::transcode(rootNode->getTextContent()));

	//Iterate over the attributes
	DOMNamedNodeMap *attributes = rootNode->getAttributes();
	for (unsigned int i=0; i< attributes->getLength(); i++) {
			DOMNode *node = attributes->item(i);		
			//cout << "Node type = "<< node->getNodeType() << " Node name = "<< XMLString::transcode(node->getNodeName()) <<"\n";
			if(	node->getNodeType() != DOMNode::ATTRIBUTE_NODE ) // if it isn't element ,
					continue; // skip
			DOMAttr *attribute = (DOMAttr *) node;
			string name		= XMLString::transcode(attribute->getName());
			string value	= XMLString::transcode(attribute->getValue());
			//cout << "ADDING ATTR " << name << " =  " << value << "\n";
			newnode->addAtribute(name, value);
	}

	//Iterate over the child elements
	DOMNodeList *childs = rootNode->getChildNodes();
	for (unsigned int i=0; i< childs->getLength(); i++) {
			DOMNode *node = childs->item(i);			
			if(	node->getNodeType() != DOMNode::ELEMENT_NODE ) // if it isn't element ,
					continue; // skip
			DOMElement *element = (DOMElement *) node;
			GFXmlElement *newChild = populateElement(element);
			//cout << "ADDING CHILD  " << newChild->getName() << "\n";
			newnode->addChild(newChild->getName(), newChild);
	}
	return newnode;
}








