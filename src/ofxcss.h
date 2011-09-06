#ifndef OFXCSS_H
#define OFXCSS_H

#include "ofMain.h"
#include "parser_pp.h"

class ofxCssSpacer {
public:
	float &operator[](int i) {
		return get(i);
	};
	float &get(int i) {
		switch(i) {
		case 0:
			return top;
		case 1:
			return right;
		case 2:
			return bottom;
		case 3:
			return left;
		};
	};
	float top;
	float left;
	float right;
	float bottom;
};

class ofxCssBlock {
public:
	bool hasBg;
	bool hasBorder;
	ofColor color;
	ofColor backgroundColor;
	ofColor borderColor;
};


class ofxCss {

public:
	typedef std::map<string, ofxCssBlock> BlockList;
	typedef std::map<std::string, std::string> AttributeList;
	typedef void (ofxCss::*ParserFunctionPtr)(ofxCssBlock& block, string value);
	typedef std::map<string, ParserFunctionPtr> ParserFunctionsList;

	ofxCss();
	~ofxCss();
	void load(string file);
	void parse(string css);
	ofxCssBlock &operator[](string element);
	ofxCssBlock &get(string element);
	ofxCssBlock parseAttributeList(AttributeList list);

private:
	void pBackgroundColor(ofxCssBlock& block, string value);

	void parseAttribute(ofxCssBlock& block, string property, string value);
	BlockList blocks;
	htmlcxx::CSS::Parser parser;
	ParserFunctionsList parserFunctions;
};

#endif // OFXCSS_H
