#include "src/io.h"
#include "src/date.h"
#include "src/version.h"
#include "src/macros.h"
#include "block.h"

Block downLine(1,2), upLine(3,4) ; // add true IO


void setup()
{
    initIO() ;
    Serial.begin( 115200 ) ;
    Serial.println( version ) ;
    Serial.println( date ) ;

    downLine.begin() ;
      upLine.begin() ;
}

void loop()
{
    downLine.transceive() ;
    upLine.transceive() ;

    if( downLine.available() )
    {
        byte b = downLine. read() ;
    }
    
    if( upLine.available() )
    {
        byte b = upLine. read() ;
    }

    // if( downLine.sendingTrain() ) {;] // follow pwm 
    // if(   upLine.sendingTrain() ) {;] // follow pwm 
    // else pwm.update() ;
}