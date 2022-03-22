#include <Arduino.h>
#include "src/macros.h"

#define ONE_BIT 250
#define ZERO_BIT 500
#define maxBits 8


class Block
{
public:
    Block( uint8 _transceiver ) ;
    void    begin() ;
    void    transceive() ;
    void    sendByte( uint8 data ) ;
    uint8   available() ;
    uint8   readByte() ;

private:
    uint8   transceiver ;
    bool    byte2read ;

    uint8   transmitting ;
    uint8   receiving ;
    uint8   byte2send ;
    uint8   bitCounter ;

    uint8   transmitt() ;
    uint8   receive() ;

    uint32  lastTime ;
    uint32  bitTime ;
};
