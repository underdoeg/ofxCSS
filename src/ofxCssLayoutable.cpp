/*
 *  ofxCssLayoutable.cpp
 *  example
 *
 *  Created by Philip Whitfield on 3/25/12.
 *  Copyright 2012 undef.ch. All rights reserved.
 *
 */

#include "ofxCssLayoutable.h"


ofxCssLayoutable::ofxCssLayoutable(){

};

ofxCssLayoutable::~ofxCssLayoutable(){

};

void ofxCssLayoutable::addChild(ofxCssLayoutable* child){
	children.push_back(child);
}

void ofxCssLayoutable::update(){
	ofxCssLayoutable::list::iterator it = children.begin();
	while(it != children.end()){
		(*it)->update();
		++it;
	}
}