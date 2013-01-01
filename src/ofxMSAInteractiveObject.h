#pragma once

#include "ofMain.h"


class ofxMSAInteractiveObject : public ofRectangle {
public:
	bool		enabled;				// set this to false to temporarily disable all events
	bool		verbose;

	ofxMSAInteractiveObject();			// constructor
	virtual ~ofxMSAInteractiveObject();	// destructor

	void enableAllEvents();				// enable all event callbacks
	void disableAllEvents();			// disable all event callbacks

	void enableMouseEvents();			// call this if object should receive mouse events
	void disableMouseEvents();			// call this if object doesn't need to receive mouse events (default)

	void enableKeyEvents();				// call this if object should receive key events
	void disableKeyEvents();			// call this if object doesn't need to receive key events (default)

	void enableAppEvents();				// call this if object should update/draw automatically	(default)
	void disableAppEvents();			// call this if object doesn't need to update/draw automatically

    
//	void setPos(float _x, float _y);	// replaced with ofRectangle::setPosition
	void setSize(float _w, float _h);	// set size of object
//	void setPosAndSize(float _x, float _y, float _w, float _h);		// replaced with ofRectangle::set

    
	bool isMouseOver();                     // returns true if mouse is over object (based on position and size)
	bool isMousePressed(int mouseButton=0);    // returns true if mouse button is down and was pressed over object (based on position and size)
    
    
	int	 getMouseX();                       // returns mouse X (in screen coordinates)
	int  getMouseY();                       // returns mouse Y (in screen coordinates)
//	int  getLastMouseButton();              // returns last mouse button to have activity
    
    unsigned long getStateChangeMillis();   // returns milliseconds since last state change

	virtual bool hitTest(int tx, int ty);		// returns true if given (x, y) coordinates (in screen space) are over the object (based on position and size)

//	void killMe();						// if your object is a pointer, and you are done with it, call this

	// extend ofxMSAInteractiveObject and override all or any of the following methods
	virtual void setup()	{}	// called when app starts
	virtual void update()	{}	// called every frame to update object
    virtual void draw()		{}	// called every frame to draw object
	virtual void exit()		{}	// called when app quites

	// these behave very similar to those in flash
	virtual void onRollOver(int x, int y)					{}		// called when mouse enters object x, y, width, height
	virtual void onRollOut()								{}		// called when mouse leaves object x, y, width, height
	virtual void onMouseMove(int x, int y)					{}		// called when mouse moves while over object x, y, width, height
	virtual void onDragOver(int x, int y, int button)		{}		// called when mouse moves while over object and button is down
	virtual void onDragOutside(int x, int y, int button)	{}		// called when mouse moves while outside the object after being clicked on it
	virtual void onPress(int x, int y, int button)			{}		// called when mouse presses while over object
	virtual void onPressOutside(int x, int y, int button)	{}		// called when mouse presses while outside object
	virtual void onRelease(int x, int y, int button)		{}		// called when mouse releases while over object
	virtual void onReleaseOutside(int x, int y, int button)	{}		// called when mouse releases outside of object after being pressed on object

	virtual void onKeyPress(int key) {}
	virtual void onKeyRelease(int key) {}
    
    virtual void mouseMoved(ofMouseEventArgs &e) {}                 // called when mouse moves anywhere
	virtual void mousePressed(ofMouseEventArgs &e) {}               // called when mouse pressed anywhere
	virtual void mouseDragged(ofMouseEventArgs &e) {}               // called when mouse dragged anywhere
	virtual void mouseReleased(ofMouseEventArgs &e) {}              // called when mouse released anywhere
    
	virtual void keyPressed(ofKeyEventArgs &e) {}                   // called when keypressed anywhere
	virtual void keyReleased(ofKeyEventArgs &e) {}                  // called when keyreleased anywhere


	// you shouldn't need access to any of these unless you know what you are doing
	// (i.e. disable auto updates and call these manually)
	void _setup(ofEventArgs &e);
	void _update(ofEventArgs &e);
    void _draw(ofEventArgs &e);
	void _exit(ofEventArgs &e);

	void _mouseMoved(ofMouseEventArgs &e);
	void _mousePressed(ofMouseEventArgs &e);
	void _mouseDragged(ofMouseEventArgs &e);
	void _mouseReleased(ofMouseEventArgs &e);

	void _keyPressed(ofKeyEventArgs &e);
	void _keyReleased(ofKeyEventArgs &e);

private:
//	int             _mouseX, _mouseY;   // mouse coordinates
//  int             _mouseButton;       // last mouse button to see action;
	bool            _isMouseOver;       // is mouse over the rect
	vector<bool>    _isMousePressed;       // is mouse down over the rect (for any given mouse button)
    unsigned long   _stateChangeTimestampMillis;
	ofRectangle	oldRect;
};

