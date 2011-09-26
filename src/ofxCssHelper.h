/*
 *  ofxCssHelper.h
 *  uGuiExample
 *
 *  Created by Philip Whitfield on 9/25/11.
 *  Copyright 2011 undef.ch. All rights reserved.
 *
 */

#ifndef _CLASS_ofxCssHelper_
#define _CLASS_ofxCssHelper_

#include "ofxcss.h"

class ofxCssHelper{
public:
      ofxCssHelper();
      ~ofxCssHelper();
	ofxCssBlock& cssBlock();
	void setCss(ofxCss* css);
	void setCssElement(string elementName);
	void setCssClass(string className);
	
protected:
private:
	ofxCss* css;
	string cssElement;
	string cssClass;
};

#endif