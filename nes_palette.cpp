#include "nes_palette.h"

uint16_t RGBA( uint8_t r, uint8_t g, uint8_t b )
{
    return ( (((r&0xF8)|(g>>5)) << 8) | ((g<<5)&0xE0) | (b>>3) );
}

const uint16_t s_palette[64] =
{
    /*00*/ RGBA( 117, 117, 117 ),
    /*01*/ RGBA( 39,  27,  143 ),
    /*02*/ RGBA( 0,   0,   171 ),
    /*03*/ RGBA( 71,  0,   159 ),
    /*04*/ RGBA( 143, 0,   119 ),
    /*05*/ RGBA( 171, 0,   19  ),
    /*06*/ RGBA( 167, 0,   0   ),
    /*07*/ RGBA( 127, 11,  0   ),
    /*08*/ RGBA( 67,  47,  0   ),
    /*09*/ RGBA( 0,   71,  0   ),
    /*0A*/ RGBA( 0,   81,  0   ),
    /*0B*/ RGBA( 0,   63,  23  ),
    /*0C*/ RGBA( 27,  63,  95  ),
    /*0D*/ RGBA( 0,   0,   0   ),
    /*0E*/ RGBA( 0,   0,   0   ),
    /*0F*/ RGBA( 0,   0,   0   ),

    /*10*/ RGBA( 188, 188, 188 ),
    /*11*/ RGBA( 0,   115, 239 ),
    /*12*/ RGBA( 35,  59,  239 ),
    /*13*/ RGBA( 131, 0,   243 ),
    /*14*/ RGBA( 191, 0,   191 ),
    /*15*/ RGBA( 231, 0,   91  ),
    /*16*/ RGBA( 219, 43,  0   ),
    /*17*/ RGBA( 203, 79,  15  ),
    /*18*/ RGBA( 139, 115, 0   ),
    /*19*/ RGBA( 0,   151, 0   ),
    /*1A*/ RGBA( 0,   171, 0   ),
    /*1B*/ RGBA( 0,   147, 59  ),
    /*1C*/ RGBA( 0,   131, 139 ),
    /*1D*/ RGBA( 0,   0,   0   ),
    /*1E*/ RGBA( 0,   0,   0   ),
    /*1F*/ RGBA( 0,   0,   0   ),

    /*20*/ RGBA( 255, 255, 255 ),
    /*21*/ RGBA( 63,  191, 255 ),
    /*22*/ RGBA( 95,  151, 255 ),
    /*23*/ RGBA( 167, 139, 253 ),
    /*24*/ RGBA( 247, 123, 255 ),
    /*25*/ RGBA( 255, 119, 183 ),
    /*26*/ RGBA( 255, 119, 99  ),
    /*27*/ RGBA( 255, 155, 59  ),
    /*28*/ RGBA( 243, 191, 63  ),
    /*29*/ RGBA( 131, 211, 19  ),
    /*2A*/ RGBA( 79,  223, 75  ),
    /*2B*/ RGBA( 88,  248, 152 ),
    /*2C*/ RGBA( 0,   235, 219 ),
    /*2D*/ RGBA( 0,   0,   0   ),
    /*2E*/ RGBA( 0,   0,   0   ),
    /*2F*/ RGBA( 0,   0,   0   ),

    /*30*/ RGBA( 255, 255, 255 ),
    /*31*/ RGBA( 171, 231, 255 ),
    /*32*/ RGBA( 199, 215, 255 ),
    /*33*/ RGBA( 215, 203, 255 ),
    /*34*/ RGBA( 255, 199, 255 ),
    /*35*/ RGBA( 255, 199, 219 ),
    /*36*/ RGBA( 255, 191, 179 ),
    /*37*/ RGBA( 255, 219, 171 ),
    /*38*/ RGBA( 255, 231, 163 ),
    /*39*/ RGBA( 227, 255, 163 ),
    /*3A*/ RGBA( 171, 243, 191 ),
    /*3B*/ RGBA( 179, 255, 207 ),
    /*3C*/ RGBA( 159, 255, 243 ),
    /*3D*/ RGBA( 0,   0,   0   ),
    /*3E*/ RGBA( 0,   0,   0   ),
    /*3F*/ RGBA( 0,   0,   0   ),
};
