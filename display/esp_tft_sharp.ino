#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_I2CDevice.h>
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>             // Arduino SPI library
// Під'єднання дисплею до esp32
#define TFT_MOSI 23  // SDA Pin on ESP32
#define TFT_SCLK 18  // SCL Pin on ESP32
#define TFT_CS   15  // Chip select control pin
#define TFT_DC    2  // Data Command control pin
#define TFT_RST   4  // Reset pin (could connect to RST pin)

// Макроси для встановлення кольорів
#define SET_BLUE(color)	(color >> 3)
#define SET_GREEN(color)	((color >> 2) << 5)
#define SET_RED(color)	((color >> 3) << 11)

// Initialize Adafruit ST7789 TFT library
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
// Функція ініціалізації
void setup(void) { 
  Serial.begin(115200);
  tft.init(135, 240, SPI_MODE3);    // Init ST7789 display 135x240 pixel
  
}
// Циклічна функція
void loop() {
  // Змінні для тимчасового зберігання кольорів
  uint8_t blue = 0, green = 0,red = 0;
  // Маска для встановлення кольорів
  uint8_t initial_color = 0xff;  //1111 1111
  // Стан пікселя будемо повертати в консоль
  Serial.println("New cycle\n");
  // Перший цикл - із синього в зелений
  for (uint32_t j = 0; j <= 5; j++)
  {
    // очистимо верхні три біти маски, щоб не було накладень
    // старші 5 бітів синього потім будуть зміщені на три позиції назад
    blue = initial_color << j + 3;
    // Заповнення байту зеленого кольору
    green = initial_color << (8 - j); 
    // Заповнення пікселя
    uint16_t color = SET_BLUE(blue) | SET_GREEN(green) | SET_RED(red);
    // Вивід вмісу пікселя в консоль
    Serial.print(color, BIN);
    Serial.println();
    // Вивід кольору на дисплей
    tft.fillScreen(color);
    // Пауза
    delay(1000);
  }  
  // Другий цикл - із зеленого в червоний
   for (uint32_t j = 1; j <= 5; j++)
  {
    green = initial_color << j + 3;
    red = initial_color << (8 - j); 
    uint16_t color = SET_BLUE(blue) | SET_GREEN(green) | SET_RED(red);
    Serial.print(color, BIN);
    Serial.println();
    tft.fillScreen(color);
    delay(1000);
  }  
}