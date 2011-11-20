#ifndef __GF_XML_PARSER__
#define __GF_XML_PARSER__

#include <map>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>

using std::cout;
using std::map;
using std::multimap;
using std::pair;
using std::string;
using std::istringstream;
using std::transform;
using std::tolower;
XERCES_CPP_NAMESPACE_USE

//string comparator
struct strCmp {
  bool operator()( string s1, string s2 ) const {
		return strcmp( s1.c_str(), s2.c_str() ) < 0;
  }
};


#define GF_XML_MMAP multimap<string, GFXmlElement *>
class GFXmlElement {
private:		
protected:
	string name;
	string contents;
	GF_XML_MMAP childs; 
	map<string, string, strCmp>			 attributes;	
public:
	inline const string &getName() { return name; }
	inline void setname( const string &name) { this->name = name; }
	inline const string &getContents() { return contents; }
	inline int getContentsAsInteger() { int ret; istringstream is1(contents); is1 >> ret; return ret; }
	inline float getContentsAsFloat() { float ret; istringstream is1(contents); is1 >> ret; return ret; }
	inline void setContents( const string &contents) { this->contents = contents; }

	GFXmlElement(string name) { this->name = name; }
	~GFXmlElement() { /*TODO iterate over childs and delete recursively*/ }
	
	inline  const map<string, string, strCmp> & getAttributes() { 	return  (const map<string, string, strCmp> &) attributes; } 
	inline const string getAttributeValueAsString(const string name) { return  attributes[name]; }
	inline int getAttributeValueAsInteger(const string name) { int ret; istringstream is1(attributes[name]); is1 >> ret; return ret; }
	inline float getAttributeValueAsFloat(const string name) { float ret; istringstream is1(attributes[name]); is1 >> ret; return ret; }
	inline bool getAttributeValueAsBool(const string name) {	
		string temp=attributes[name]; 		transform (temp.begin(), temp.end(), temp.begin(), tolower);		return (temp=="true");	}
	inline void addAtribute(const string &name, const string &value) { attributes.insert(make_pair(name, value)); }

	inline  const GF_XML_MMAP & getChilds() { 	return  (const GF_XML_MMAP &) childs; } 
	inline GFXmlElement * getChild(const string name) { return  (childs.find(name)!=childs.end()) ? childs.find(name)->second : NULL; }
	inline void addChild(const string &name, GFXmlElement * value) { childs.insert( pair<string, GFXmlElement *>(name, value)); }
};

class GFXmlDocument {
private:		
protected:
	GFXmlElement *rootElement;
public:
	GFXmlDocument() { rootElement=NULL; }
	~GFXmlDocument() {delete rootElement; }
	inline GFXmlElement *getRootElement() { return rootElement; }
	inline void setRootElement(GFXmlElement *newElement) { rootElement = newElement; }
};

class GFXmlParser {
private:		
	void initialize();
	GFXmlElement *populateElement(DOMElement *rootNode);
protected:
	
public:
	static GFXmlParser *getInstance();
	GFXmlParser() { initialize(); }
	~GFXmlParser() {}
	GFXmlDocument * parse(const char *xmlFile);
};





#endif //__GF_XML_PARSER__