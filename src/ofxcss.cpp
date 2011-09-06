#include "ofxcss.h"

using namespace htmlcxx::CSS;

#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

ofxCss::ofxCss() {
	//all the parser functions
	parserFunctions["background-color"] = &ofxCss::pBackgroundColor;
}

ofxCss::~ofxCss() {
}

void ofxCss::load(string fn) {
	ofFile file(fn);
	ofBuffer b = file.readToBuffer();
	parse(b.getText());
}

void ofxCss::parse(string css) {
	parser.parse(css);
}

ofxCssBlock &ofxCss::get(string element) {
	//check if element was already processed
	string key = element;
	BlockList::iterator iter = blocks.find(key);
	if(iter != blocks.end())
		return blocks[key];

	//we have to create a new one
	Parser::Selector selector;
	selector.setElement(element);
	std::vector<Parser::Selector> selectorList;
	selectorList.push_back(selector);
	blocks[key] = parseAttributeList(parser.getAttributes(selectorList));
	return blocks[key];
}

ofxCssBlock ofxCss::parseAttributeList(AttributeList list) {
	ofxCssBlock block;
	for ( AttributeList::const_iterator iter = list.begin(); iter != list.end(); ++iter ) {
		parseAttribute(block, iter->first, iter->second);
	}
	return block;
}

ofxCssBlock &ofxCss::operator [](string element) {
	return get(element);
}

void ofxCss::parseAttribute(ofxCssBlock& block, string property, string value) {
	//check for existance of function pointer
	ParserFunctionsList::iterator iter = parserFunctions.find(property);
	if(iter == parserFunctions.end()) {
		ofLog(OF_LOG_NOTICE, "ofxCSS: unknown property ("+property+")");
		return;
	}

	//call the function pointer
	CALL_MEMBER_FN(*this, parserFunctions[property])(block, value);
}

/*
 * CSS PARSING FUNCTIONS
 */
void ofxCss::pBackgroundColor(ofxCssBlock& block, string value)
{
	cout << value << endl;
}
