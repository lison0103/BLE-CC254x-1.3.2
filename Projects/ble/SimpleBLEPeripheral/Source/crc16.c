#include "crc16.h"


/* THE FUNCTION RETURNS THE CRC AS A UNSIGNED SHORT TYPE */
uint16 Crc16Calculate(uint8 *Puchmsg, uint8 u8Length) 
{
    uint16 CRCResult = 0xFFFF;
    char i,j; 
    for (i = 0; i < u8Length; i++)
    {
        CRCResult = CRCResult ^ Puchmsg[i];
        for (j = 0; j < 8; j++)
        {
            if ((CRCResult & 1) == 1)
            CRCResult = (CRCResult >> 1) ^ 0xA001;
            else
            CRCResult >>= 1;
        }
    } 
    return ((CRCResult >> 8) + ((CRCResult & 0xff) << 8)); 
}


