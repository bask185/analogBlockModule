#include "block.h"

Block::Block( uint8 _transceiver ) 
{
    transceiver = _transceiver ;
}

void Block::begin()
{
    pinMode( transceiver, INPUT_PULLUP ) ;
}

void Block::transceive()
{
    if( transmitting )
    {
        if( transmitt() ) transmitting = false ;
    }
    else if( receiving )
    {
        if( receive() ) receiving = false ;
    }
    else if( digitalRead( Rx ) == false ) // start bit
    {
        receiving = true ;
        lastTime = micros() ;
    }
}

void Block::sendByte( uint8 data )
{
    byte2send = data ;
    transmitting = true ;
    lastTime = micros() ;
    bitCounter = 0  ;
    digitalWrite( transceiver, FALSE ) ; // start bit
}

uint8 Block::available()
{
    return byte2read ;
}

uint8 Block::readByte()
{

}


uint8 Block::transmitt()
{
    uint32 currentTime = micros() ;

    if( currentTime - lastTime >= bitTime )
    {
        bool bitState = byte2send & ( 1 << bitCounter ) ;
        
        if( bitState )  bitTime =  ONE_BIT ;
        else            bitTime = ZERO_BIT ;

        digitalWrite( transceiver, !digitalRead ( transceiver )  ;)
    }

    if( ++ bitCounter == maxBits )
    {
        return true ;
    }
    return false ;
}

uint8 Block::receive()
{

}