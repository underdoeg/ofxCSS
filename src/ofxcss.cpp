#include "ofxcss.h"
#include "regex.hpp"

using namespace htmlcxx::CSS;

#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

ofxCss::ofxCss() {
	//all the parser functions
	parserFunctions["background-color"] = &ofxCss::pBackgroundColor;
	parserFunctions["color"] = &ofxCss::pColor;
	//
	parserFunctions["margin"] = &ofxCss::pMargin;
	parserFunctions["margin-top"] = &ofxCss::pMarginTop;
	parserFunctions["margin-left"] = &ofxCss::pMarginLeft;
	parserFunctions["margin-bottom"] = &ofxCss::pMarginBottom;
	parserFunctions["margin-right"] = &ofxCss::pMarginRight;
	//
	parserFunctions["padding"] = &ofxCss::pPadding;
	parserFunctions["padding-top"] = &ofxCss::pPaddingTop;
	parserFunctions["padding-left"] = &ofxCss::pPaddingLeft;
	parserFunctions["padding-bottom"] = &ofxCss::pPaddingBottom;
	parserFunctions["padding-right"] = &ofxCss::pPaddingRight;
	//
	parserFunctions["border"] = &ofxCss::pBorder;
	parserFunctions["border-top"] = &ofxCss::pBorderTop;
	parserFunctions["border-right"] = &ofxCss::pBorderRight;
	parserFunctions["border-bottom"] = &ofxCss::pBorderBottom;
	parserFunctions["border-left"] = &ofxCss::pBorderLeft;
	//
	parserFunctions["background-image"] = &ofxCss::pBackgroundImage;
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

ofxCssBlock &ofxCss::get(string element, string ofClass) {
	//check if element was already processed
	bool hasClass = false;
	if(ofClass != "")
		hasClass = true;

	string key = element;
	if(hasClass)
		key +=":"+ofClass;
	BlockList::iterator iter = blocks.find(key);
	if(iter != blocks.end())
		return blocks[key];

	//we have to create a new one
	/*
	std::vector<string> elements = ofSplitString(element, " ", true, true);
	for(std::vector<string>::iterator it=elements.begin(); it!=elements.end();++it){
	}
	*/
	std::vector<Parser::Selector> selectorList;
	Parser::Selector selector;
	selector.setElement(element);
	if(hasClass)
		selector.setClass(ofClass);
	selectorList.push_back(selector);

	blocks[key] = parseAttributeList(parser.getAttributes(selectorList));
	return blocks[key];
}

ofxCssBlock ofxCss::parseAttributeList(AttributeList list) {
	ofxCssBlock block;
	for ( AttributeList::const_iterator iter = list.begin(); iter != list.end(); ++iter ) {
		cout << iter->first << ": " << iter->second << endl;
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
		ofLog(OF_LOG_NOTICE, "ofxCSS: unknown property ( "+property+" )");
		return;
	}

	//call the function pointer
	CALL_MEMBER_FN(*this, parserFunctions[property])(block, value);
}

/*
 * CSS PARSING FUNCTIONS
 */
//color
void ofxCss::pBackgroundColor(ofxCssBlock& block, string value) {
	if(ofIsStringInString(value, "#")){//color is hexadecimal
		ofStringReplace(value, "#", "0x");
		stringstream convert(value);
		block.backgroundColor = ofColor::fromHex(ofHexToInt(value));
		cout << (int)block.backgroundColor.r << endl;
	}else if(ofIsStringInString(value, "rgb")){
		boost::regex rexpr("[^0-9]*([0-9]*)[^0-9]*([0-9]*)[^0-9]*([0-9]*)[^0-9]*");
		boost::cmatch match;
		if(regex_match(value.c_str(), match, rexpr)){
			block.backgroundColor.set(ofToInt(string(match[1].first, match[1].second)), ofToInt(string(match[2].first, match[2].second)), ofToInt(string(match[3].first, match[3].second)));
		}
	}else if(ofIsStringInString(value, "rgba")){ //TODO: DOESN'T WORK YET...
		boost::regex rexpr("[^0-9]*([0-9]*)[^0-9]*([0-9]*)[^0-9]*([0-9]*)[^0-9]*([0-9]*)[^0-9]*");
		boost::cmatch match;
		if(regex_match(value.c_str(), match, rexpr)){
			cout << match[0] << endl;
			block.backgroundColor.set(ofToInt(string(match[1].first, match[1].second)), ofToInt(string(match[2].first, match[2].second)),
										ofToInt(string(match[3].first, match[3].second)), ofToInt(string(match[4].first, match[4].second)));
		}
	}else{
		ofLog(OF_LOG_WARNING, "ofxCSS: unknown color format ( "+value+" )");
	}
}

void ofxCss::pColor(ofxCssBlock& block, string value) {

}

//margin
void ofxCss::pMargin(ofxCssBlock& block, string value) {

}

void ofxCss::pMarginBottom(ofxCssBlock& block, string value) {
}

void ofxCss::pMarginLeft(ofxCssBlock& block, string value) {
}

void ofxCss::pMarginRight(ofxCssBlock& block, string value) {
}

void ofxCss::pMarginTop(ofxCssBlock& block, string value) {
}

//padding
void ofxCss::pPadding(ofxCssBlock& block, string value) {
}

void ofxCss::pPaddingBottom(ofxCssBlock& block, string value) {
}

void ofxCss::pPaddingLeft(ofxCssBlock& block, string value) {
}

void ofxCss::pPaddingRight(ofxCssBlock& block, string value) {
}

void ofxCss::pPaddingTop(ofxCssBlock& block, string value) {
}

//border
void ofxCss::pBorder(ofxCssBlock& block, string value) {
}

void ofxCss::pBorderBottom(ofxCssBlock& block, string value) {
}

void ofxCss::pBorderLeft(ofxCssBlock& block, string value) {
}

void ofxCss::pBorderRight(ofxCssBlock& block, string value) {
}

void ofxCss::pBorderTop(ofxCssBlock& block, string value) {
}

//bg
void ofxCss::pBackgroundImage(ofxCssBlock& block, string value) {
}
