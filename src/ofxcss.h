#ifndef OFXCSS_H
#define OFXCSS_H

#include "ofMain.h"
#include "parser_pp.h"

class ofxCssNumber {
public:
	enum types {PIXEL, PERCENT};
	float value;
	types type;
};

class ofxCssBorder {
public:
	bool enabled;
	ofColor color;
	float width;
};

class ofxCssSpacer {
public:
	ofxCssSpacer(float val=0) {
		setAll(val);
	}

	void setAll(float val) {
		top=left=right=bottom=val;
	};

	float operator[](int i) {
		return get(i);
	};

	float get(int i) {
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
		return 0;
	};

	float top;
	float left;
	float right;
	float bottom;
};

class ofxCssBlock {
public:
	bool hasBackground;
	bool hasBackgroundImage;
	ofColor color;
	ofColor backgroundColor;
	ofPtr<ofImage> backgroundImage;
	ofxCssBorder borderTop;
	ofxCssBorder borderRight;
	ofxCssBorder borderBottom;
	ofxCssBorder borderLeft;
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
	ofxCssBlock &get(string element, string ofClass = "");
	ofxCssBlock parseAttributeList(AttributeList list);

private:
	void parseAttribute(ofxCssBlock& block, string property, string value);
	BlockList blocks;
	htmlcxx::CSS::Parser parser;
	ParserFunctionsList parserFunctions;

	/* CSS PARSING FUNCTIONS */
	//colors
	void pBackgroundColor(ofxCssBlock& block, string value);
	void pColor(ofxCssBlock& block, string value);

	//margin
	void pMargin(ofxCssBlock& block, string value);
	void pMarginTop(ofxCssBlock& block, string value);
	void pMarginLeft(ofxCssBlock& block, string value);
	void pMarginRight(ofxCssBlock& block, string value);
	void pMarginBottom(ofxCssBlock& block, string value);

	//padding
	void pPadding(ofxCssBlock& block, string value);
	void pPaddingTop(ofxCssBlock& block, string value);
	void pPaddingLeft(ofxCssBlock& block, string value);
	void pPaddingRight(ofxCssBlock& block, string value);
	void pPaddingBottom(ofxCssBlock& block, string value);

	//border
	void pBorder(ofxCssBlock& block, string value);
	void pBorderTop(ofxCssBlock& block, string value);
	void pBorderRight(ofxCssBlock& block, string value);
	void pBorderBottom(ofxCssBlock& block, string value);
	void pBorderLeft(ofxCssBlock& block, string value);

	//image
	void pBackgroundImage(ofxCssBlock& block, string value);
};

#endif // OFXCSS_H
