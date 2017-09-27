// SSD1306_OLED_HW_I2C_PRINT_8X16_LIB_HelloWorld.ino
// Prints "Hello World"
//
// connect display SCL to pin A5, and SDA to pin A4
// connect LED to pin 4 (it will blink in case of I2C error)

#include <SSD1306_OLED_HW_I2C_PRINT_8X16_LIB.h>
#include <avr/io.h>

SSD1306_OLED_HW_I2C_PRINT_8X16_LIB lcd = SSD1306_OLED_HW_I2C_PRINT_8X16_LIB();

void setup(void) {
    lcd.D_INIT();       // Initialize OLED
}


void loop(void) {
  lcd.D_CLEAR();
  lcd.D_SETPOS(0,0);;         // Set position
  lcd.D_PRINT_CHAR_8x16('H');         // Print 'H'
  lcd.D_SETPOS(8,0);;         // Set position
  lcd.D_PRINT_STR_8x16("ello");         // Print 'ello'
  delay(2000);
  lcd.D_CLEAR();
  lcd.D_SETPOS(0,2);;         // Set position
  lcd.D_PRINT_CHAR_8x16('W');         // Print 'W'
  lcd.D_SETPOS(8,2);;         // Set position
  lcd.D_PRINT_STR_8x16("orld");         // Print 'orld'
  delay(2000);
}
