/*
 *  ofxCssLayoutable.h
 *  example
 *
 *  Created by Philip Whitfield on 3/25/12.
 *  Copyright 2012 undef.ch. All rights reserved.
 *
 */

#ifndef _CLASS_ofxCssLayoutable_
#define _CLASS_ofxCssLayoutable_

#include "ofxcss.h"

class ofxCssLayoutable{
public:
      ofxCssLayoutable();
      ~ofxCssLayoutable();      
	typedef std::vector<ofxCssLayoutable*> list;
	void addChild(ofxCssLayoutable* child);
	void update();
protected:
private:
	ofxCssLayoutable::list children;
};

#endif