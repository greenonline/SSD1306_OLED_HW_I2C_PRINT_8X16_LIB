#ifndef SSD1306_OLED_HW_I2C_PRINT_8X16_LIB_h
#define SSD1306_OLED_HW_I2C_PRINT_8X16_LIB_h
#include <SSD1306_OLED_HW_I2C_PRINT_LIB.h>

class SSD1306_OLED_HW_I2C_PRINT_8X16_LIB : public SSD1306_OLED_HW_I2C_PRINT_LIB {

  public:

    SSD1306_OLED_HW_I2C_PRINT_8X16_LIB(void);

    virtual size_t write(uint8_t);
    virtual size_t write(const char *str);
    virtual size_t write(const uint8_t *buffer, size_t size);

    void D_SETPOS(uint8_t x, uint8_t y);

    void D_PRINT_CHAR_8x16(char ch);
    void D_PRINT_STR_8x16(char *s);
    void D_PRINT_STR_8x16(char *s, size_t size);



  private:

    int x_position;
    int y_position;

};
#endif