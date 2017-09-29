#include "SSD1306_OLED_HW_I2C_PRINT_8X16_LIB.h"

#include "font8x16.h"



SSD1306_OLED_HW_I2C_PRINT_8X16_LIB::SSD1306_OLED_HW_I2C_PRINT_8X16_LIB(void) : x_position (0), y_position (0)
{

}

// Override write ////////////////////////////////////////

size_t SSD1306_OLED_HW_I2C_PRINT_8X16_LIB::write(uint8_t character) { 
  D_PRINT_CHAR_8x16(character);
  return 1;
}

size_t SSD1306_OLED_HW_I2C_PRINT_8X16_LIB::write(const char *str) { 
  D_PRINT_STR_8x16(str);
  return 1;
}

size_t SSD1306_OLED_HW_I2C_PRINT_8X16_LIB::write(const uint8_t *buffer, size_t size) { 
  D_PRINT_STR_8x16(buffer, size);
  return 1;
}

// Override write ////////////////////////////////////////

// Set cursor position
void SSD1306_OLED_HW_I2C_PRINT_8X16_LIB::D_SETPOS(uint8_t x, uint8_t y) {  
  // Record values, for use in 2 line printing
  x_position = x;
  y_position = y;
  // Adjust character cursor co-ordinates for big characters?
//  x_position = x*2;
//  y_position = y*2;
  
  SSD1306_OLED_HW_I2C_PRINT_LIB::D_SETPOS(x,y);  // call previous SETPOS() with adjusted co-ordinates
}

// My modification of D_PRINT_CHAR
void SSD1306_OLED_HW_I2C_PRINT_8X16_LIB::D_PRINT_CHAR_8x16(char ch) {                                // print 1 character
  uint8_t c = ch - 32;

  D_SETPOS(x_position, y_position);  // necessary because y_position is shifted

//  SSD1306_OLED_HW_I2C_PRINT_LIB::D_START_DAT();
  D_START_DAT();
  for (uint8_t i = 0; i < 8; i++)
  {
    D_TX(pgm_read_byte(&ssd1306xled_font8x16[c * 16 + i]));
  }
  D_STOP();

  D_SETPOS(x_position, y_position + 1);

  D_START_DAT();
  for (uint8_t i = 0; i < 8; i++)
  {
    D_TX(pgm_read_byte(&ssd1306xled_font8x16[c * 16 + i + 8]));
  }
  D_STOP();
  x_position +=8;
  y_position -=1;
}

void SSD1306_OLED_HW_I2C_PRINT_8X16_LIB::D_PRINT_STR_8x16(char *s) {                                 // print string (char array)
  while (*s) {
    D_PRINT_CHAR_8x16(*s++);
  }
}

// print string (char array)
void SSD1306_OLED_HW_I2C_PRINT_8X16_LIB::D_PRINT_STR_8x16(char *s, size_t size) {                                 
  for (int n=0; n < size; n++) {
    D_PRINT_CHAR_8x16(s[n]);
  }
}

