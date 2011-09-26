/*
 *  ofxCssHelper.cpp
 *  uGuiExample
 *
 *  Created by Philip Whitfield on 9/25/11.
 *  Copyright 2011 undef.ch. All rights reserved.
 *
 */

#include "ofxCssHelper.h"


ofxCssHelper::ofxCssHelper(){

};

ofxCssHelper::~ofxCssHelper(){

};

ofxCssBlock& ofxCssHelper::cssBlock(){
	return css->get(cssElement, cssClass);
};

void ofxCssHelper::setCss(ofxCss* c){
	css = c;
};

void ofxCssHelper::setCssElement(string elementName){
	cssElement = elementName;
};

void ofxCssHelper::setCssClass(string className){
	cssClass = className;
};