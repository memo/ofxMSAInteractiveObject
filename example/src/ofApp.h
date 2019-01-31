#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

#include "MyTestObject.h"

class testApp : public ofBaseApp {
	
public:
	
	MyTestObject obj;
	void setup();
    void draw();
};

#endif

