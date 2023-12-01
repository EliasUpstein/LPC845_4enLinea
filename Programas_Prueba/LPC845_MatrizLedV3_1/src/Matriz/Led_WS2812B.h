#ifndef WS2812B
#define WS2812B

typedef struct
{
    uint8_t b;
    uint8_t g;
    uint8_t r;

    //Sobrecarga del casteo a uint32_t
    operator uint32_t() const
	{
    	 return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
	}
} Led_WS2812B;

#endif
