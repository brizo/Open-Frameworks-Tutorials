#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
    

    ///////////////////
    //     STEP 1    //
    ///////////////////
    //First the background color
    //pixel values are between 0 and 255
    //ofBackground ( R , G , B ) 
    ofBackground( 15 , 15 , 15 ) ;
    
    //ofSetVerticalSync forces vertical sync which prevents screentearing
    ofSetVerticalSync( true ) ;
    //Initialize our MAX number of circles
    maxCircles = 5000 ;

    ///////////////////
    //     STEP 3    //
    ///////////////////
    //Allocate the FBO so it knows how big it's texture size is
    //we start with an FBO as big as the screen and then later we only need 1/4 of the total screen space
    //mirrorFbo.allocate( ofGetWidth() / 2 , ofGetHeight() / 2 ) ;
    
    ///////////////////
    //     STEP 4    //
    ///////////////////
    //To setup the color palette push 4-6 colors into colorPool
    //colorPool.push_back( ofColor( r , g , b )  ) ;

    
}

//--------------------------------------------------------------
void testApp::update(){

    //Draws more interesting shapes
    ofSetCircleResolution( sin( ofGetElapsedTimef() ) * 10.0f + 13.0f ) ;
    
    //OF gives acces to a lot of values to the window including the title
    //OF also has a string conversion utility ofToString( ) 
    ofSetWindowTitle( ofToString( ofGetFrameRate() ) ) ; 
    
    ///////////////////
    //     STEP 2    //
    ///////////////////
    //Generate a colorPoint object and fill it with data to draw
    /*
     Declare a colorPoint 'cp' 
     give cp a random color, in OF you can use ofRandom( min , max ) and ofColor( red, green blue ) 
     give cp a position based on the mouse, in OF you have mouseX and mouseY in the testApp
     give cp a random radius
     
     BONUS : use a color from a color palette instead of a random color
    */
    
    ///////////////////
    //     STEP 3    //
    ///////////////////
    /*
     calcuate the distance between the mouse position last frame and this frame
     first check to see that there is more than 1 ColorPoint, otherwise there's nothing to compare it to
     get the position for this frames CP and last frames CP
     get the distance between two points using ofDist( x1 , y1 , x2 , y2 )
     set the radius of the CP to something based off of the distance
     add the CP to points, it points.size() is larger than maxCircles call points.erase( points.begin() ) 
     */
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ///////////////////
    //     STEP 3    //
    ///////////////////
    //to record into an FBO call begin() 
    
    ///////////////////
    //     STEP 1    //
    ///////////////////
    //Draw the background
    ofSetColor ( 0 , 0, 0 ) ; 
    ofRect( 0 , 0 , ofGetWidth() , ofGetHeight() ) ; 


    //Let's to scale the scene and then flip it for a kaleidscope effect
    //Push and pop are modifiers that effect everything drawn already in the draw() loop
    ofPushMatrix() ; 
    

        //Before anything gets drawn we have to set the color for OF
        //ofSetColor( r , g , b )
        ofSetColor( 0 , ofRandom( 125 , 255 ) , ofRandom( 125 , 255 ) ) ; 
        
        //Now we draw a circle
        ofCircle ( mouseX , mouseY , 25 ) ; 

        ///////////////////
        //     STEP 3    //
        ///////////////////
        //scale the FBO in HALF being drawn as it will be redrawn and flipped 4 times
    
        ///////////////////
        //     STEP 2    //
        ///////////////////
        //Iterate and draw all the circles
        for ( int i = 0 ; i < points.size() ; i++ ) 
        {
            //set the CP color
            //draw a circle at the CP location
            
        }
    
    //End scaling the scene
    ofPopMatrix() ; 
    
    ///////////////////
    //     STEP 3    //
    ///////////////////
    //end the FBO draw
    
    
    //Now we move the whole scene to the middle so the FBOs can be flipped and still drawn at 0 , 0 
    ofPushMatrix() ;
        //First 
        //ofTranslate( screenCenter )  ;
        
        //Draw the FBO at full color
        //ofSetColor ( 255 , 255 , 255 ) ;
        //Draw top left
    
        //Flip in the X axis
        //Draw top right
        
        //Flip in the Y axis
        //Bottom Left    
     
        //Flip in the X + Y axis
        //Bottom Right

    ofPopMatrix() ;
    
}

///////////////////
//     STEP 4    //
///////////////////
ofColor testApp::getRandomColor( ) 
{
    //Get a random color index between 0 and colorPool.size()
    //return a color from within colorPool with that index
    return ofColor() ;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    ///////////////////
    //     STEP 4    //
    ///////////////////
    switch ( key ) 
    {
        //if upper or lower case C was pressed down on the keyboard
        case 'c':
        case 'C':
            //reset points
            points.clear() ; 
            //draw a black rectangle over the FBO to reset it's appearence
            mirrorFbo.begin() ; 
                ofSetColor ( 0 , 0, 0 ) ; 
                ofRect( 0 , 0 , ofGetWidth() , ofGetHeight() ) ; 
            mirrorFbo.end() ; 

            break ; 
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}