#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(600,400, OF_WINDOW);			// <-------- setup the GL context
	ofRunApp(new testApp);
}
