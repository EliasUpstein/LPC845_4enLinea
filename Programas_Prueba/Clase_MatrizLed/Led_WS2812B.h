#ifndef WS2812B
#define WS2812B

typedef struct 
{
    uint8_t r;
    uint8_t g;    
    uint8_t b;    
} Led_WS2812B;

// typedef unsigned char uchar;

// typedef struct {
// 	uchar b0:1;
// 	uchar b1:1;
// 	uchar b2:1;
// 	uchar b3:1;
// 	uchar b4:1;
// 	uchar b5:1;
// 	uchar b6:1;
// 	uchar b7:1;
// } B2BColor;

// typedef union
// {
//     Led_WS2812B led;
//     B2BColor color[3];  //  Chequear si el vector no se superpone
// } Bit_WS2812B;

#endif