#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ///////////////////
    //     STEP 1    //
    ///////////////////
    //initialize values
    maxFrames = 30 ; 
    currentFrame = 0 ; 
    bMousePressed = false ; 
    
    //For each of our max frames create push an FBO into frames
    //then reference it by index to allocate it the size of the OF window
    
    for ( int i = 0; i < maxFrames ; i++ ) 
    {
        // ...
    }
    
    //resetAllFbos( ) ;
    
    //Prevents screen tearing
    ofSetVerticalSync( true ) ; 
    ofSetFrameRate( maxFrames ) ; 
    ofBackground( 0 , 0, 0 ) ; 
    
    ///////////////////
    //     STEP 2    //
    ///////////////////
    lastMouse = ofPoint ( 0 , 0 ) ;
    
    ///////////////////
    //     STEP 3    //
    ///////////////////
    /*
    float dim = 35 ;    //height of sliders
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
    float length = 320-xInit; 

    red = ofRandom( 255 ) ; 
    green = ofRandom( 255 ) ; 
    blue= ofRandom( 255 ) ; 
    red2 = ofRandom( 255 ) ; 
    green2 = ofRandom( 255 ) ; 
    blue2 = ofRandom( 255 ) ; 
    
    //Here a new instance of ofxUICanvas is created, we store a refernce to it using a pointer
    gui = new ofxUICanvas(0, 0, length+xInit, ofGetHeight());
    
    //When accessing pointers you use the "->" notation
    gui->addWidgetDown(new ofxUILabel("AWESOME LABEL", OFX_UI_FONT_LARGE));
    //Setup sliders for the first Colors
    gui->addWidgetDown(new ofxUISlider(length-xInit,dim, 0.0, 255.0, red, "RED" ));
    //complete for the other sliders...

    
    //Add an event listener to react to changes in the ofxUI changes
    ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);
    
    //Turn off the ofxUI rendering for now
    gui->disable() ;
    gui->loadSettings("ofxUISettings.xml") ;
    */
}

//--------------------------------------------------------------
void testApp::update(){

    ///////////////////
    //     STEP 1    //
    ///////////////////
    currentFrame++ ; 
    
    if ( currentFrame == maxFrames ) 
        currentFrame = 0 ; 
 

    ofSetWindowTitle( ofToString( ofGetFrameRate() ) ) ; 
}

//--------------------------------------------------------------
void testApp::draw(){

        ///////////////////
        //     STEP 2    //
        ///////////////////
        //record the current mouse position
        //get the distance between this position and last position
        
    
        ///////////////////
        //     STEP 1    //
        ///////////////////
        ofSetColor( 255 , 255 , 255 ) ; 
        //Begin recording the FBO
    
        //draw the fbo into itself

        //If the mouse is pressed draw a circle at the mouse position
        ///////////////////
        //     STEP 2    //
        ///////////////////
        //draw the circle radius based on the mouse distance
        
        //stop drawing into FBO
        
        //Draw the FBO with full color
        ofSetColor ( 255 , 255 , 255 ) ; 
        //frames[currentFrame].draw(0 , 0 ) ;
    
        ///////////////////
        //     STEP 2    //
        ///////////////////
        //set lastMousePos to the mousePos right now
    
}

void testApp::resetAllFbos()
{
    //Easy way to reset each FBO is to draw it with a full rectangle
    for ( int i = 0; i < maxFrames ; i++ ) 
    {
        frames[i].begin() ; 
        ofSetColor( 0 , 0 , 0 ) ; 
        ofRect( 0 , 0 , ofGetWidth() , ofGetHeight() ) ;
        frames[i].end() ;
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{    
    //This function listens for keyboardEvents
    // Maps the "R" key to clearing all the FBOs
    switch ( key) 
    {
        case 'r' :
        case 'R' :
            resetAllFbos() ; 
            break;
            
#ifdef STEP3
        case 'g':
        case 'G':
            gui->toggleVisible(); 
            break ; 
#endif
        default:
            break;
    }
}



//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    bMousePressed = true ;
    
    ///////////////////
    //     STEP 2    //
    ///////////////////
    //create a random color
    randomColor = ofColor ( ofRandom ( 255 ) , ofRandom ( 255 ) , ofRandom( 255 ) ) ;
    
    ///////////////////
    //     STEP 3    //
    ///////////////////
    //If gui is open and we are clicking over it we dont want to be recording that into the FBO
    //if ( gui->isEnabled() == true && x < 300 )
    //    bMousePressed = false ;
    
    //set our cursor color to something random between our ofxUI slider values
    
    
}

void testApp::mouseReleased(int x, int y, int button){
    bMousePressed = false ; 
}


///////////////////
//     STEP 3    //
///////////////////
/*
void testApp::guiEvent(ofxUIEventArgs &e)
{
    //First the name of the widget is useful
	string name = e.widget->getName(); 
    
    if(name == "RED")
	{
        //Since all our widgets are ofxUISlider type, we know we can cast them without trouble
        //in c++ you case like 
        //int myInt = (int) 34.23 ; 
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		red = slider->getScaledValue(); 
    }
    ... repeat for all other values
 
    //We can also store our settings to an external XML file ! If we want to resume our settings after the app closes
    gui->saveSettings("ofxUISettings.xml") ; 
}
 */
