#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


//~ Макроси отримання кольорів із формату RGB555
#define GET_BLUE(pixel)		(pixel & BLUE)
#define GET_GREEN(pixel)	((pixel & GREEN) >> 5)
#define GET_RED(pixel)		((pixel & RED) >> 10)

//~ Макроси встановлення кольорів у піксель формату RGB555 - 1 піксель - змінна типу uint16_t
#define SET_BLUE(pixel)		(pixel >> 3)
#define SET_GREEN(pixel)	((pixel >> 3) << 5)
#define SET_RED(pixel)		((pixel >> 3) << 10)


//~ Дві структури для зчитування метаданих файлу - інформацію про зображення
//~ Файл .BMP має таку структуру:
//~ Заголовак (структура) BMPFileHeader
//~ Заголовак (структура) BMPInfoHeader
//~ Службові дані
//~ Масив пікселів

typedef struct {
	uint16_t fileType;    // Тип файлу ("BM" для BMP)
	uint32_t fileSize;    // Розмір файлу
	uint16_t reserved1;   // Зарезервовано
	uint16_t reserved2;   // Зарезервовано
	uint32_t dataOffset;  // Зміщення до початку даних зображення
} __attribute__ ((packed)) BMPFileHeader ;

typedef struct {
	uint32_t headerSize;       // Розмір цього заголовка (40 байт)
	int32_t  width;            // Ширина зображення в пікселях
	int32_t  height;           // Висота зображення в пікселях
	uint16_t planes;           // Кількість колірних площин (має бути 1)
	uint16_t bitsPerPixel;     // Кількість біт на піксель (24 біти для 16,7 млн кольорів)
	uint32_t compression;      // Тип стиснення (0 = без стиснення)
	uint32_t imageSize;        // Розмір даних зображення (в байтах)
	int32_t  xPixelsPerMeter;  // Горизонтальна роздільна здатність
	int32_t  yPixelsPerMeter;  // Вертикальна роздільна здатність
	uint32_t colorsUsed;       // Кількість кольорів у палітрі
	uint32_t importantColors;  // Важливі кольори (0 = всі важливі)
} __attribute__ ((packed))  BMPInfoHeader;

int main() {

	//~ Файл із зображенням для обробки
	const char *filename = "aster.bmp";
	//~ Файл, в який буде збережено оброблене зображення
	const char *fileout =  "tmp.bmp";
    
	//~ Відкриваємо файл у двійковому режимі
	FILE *file = fopen(filename, "rb");
	if (file == NULL) {
		perror("Помилка відкриття файлу");
		return 1;
	}

	 //~ Читаємо заголовки BMP
	BMPFileHeader fileHeaderIn, fileHeaderOut;
	fread(&fileHeaderIn, sizeof(BMPFileHeader), 1, file);

	BMPInfoHeader infoHeaderIn, infoHeaderOut;
	fread(&infoHeaderIn, sizeof(BMPInfoHeader), 1, file);

	//~ Перевіряємо чи це BMP файл
	if (fileHeaderIn.fileType != 0x4D42) { // 0x4D42 відповідає "BM" у ASCII
		printf("Файл не є BMP.\n");
		fclose(file);
		return 1;
	}
	//~ Виведення деякої інформації про зображення
	//~ Ширина та висота зображення в пікселях. Важливий параметр, має бути вказаний
	printf("Wight:	%d\n", infoHeaderIn.width);
	printf("Height:	%d\n", infoHeaderIn.height);
	//~ Біт на піксель. Важливий параметр, має бути вказаний
	printf("BPP:	%d\n", infoHeaderIn.bitsPerPixel);
	//~ Рошидільна задатність. Неважливий параметр, можна задати 0
	printf("xPixelsPerMeter:	%d\n", infoHeaderIn.xPixelsPerMeter);
	printf("yPixelsPerMeter:	%d\n", infoHeaderIn.yPixelsPerMeter);
	//~ В даному прикладі наступні параметри не використовуються
	printf("compression:	%d\n", infoHeaderIn.compression);
	printf("colorsUsed:	%d\n", infoHeaderIn.colorsUsed);
	printf("imageSize:	%d\n", infoHeaderIn.imageSize);
	printf("importantColors:	%d\n", infoHeaderIn.importantColors); 
	//~ Переміщаємо позицію файлу на початок масиву пікселів
	fseek(file, fileHeaderIn.dataOffset, SEEK_SET);
	//~ Заголовки вихідного файлу = заголовкам вхідного файлу
	fileHeaderOut = fileHeaderIn;
	infoHeaderOut = infoHeaderIn;
	//~ Відкриваємо файл для запису вихідного зображення
	FILE * fileOut = fopen(fileout, "wb");
	//~ Міняємо інформацію у заголовках вихідного файлу
	//~ У вихідному файлі буде кодування 16 біт на піксель
	infoHeaderOut.bitsPerPixel	= 16;
	//~ Неважливі параметри = 0
	fileHeaderOut.fileSize	= 0;
	infoHeaderOut.imageSize	= 0;
	infoHeaderOut.xPixelsPerMeter	= 0;
	infoHeaderOut.yPixelsPerMeter	= 0;

	//~ Записуємо заголовки у вихідний файл
	fwrite(&fileHeaderOut, sizeof(fileHeaderOut), 1, fileOut);
	fwrite(&infoHeaderOut, sizeof(infoHeaderOut), 1, fileOut);
	//~ Масив пікселів у вихідному файлі посинається з тої ж позиції, що й у вхідному. Для іншої позиції потрібно міняти значення відступу в заголовку файлу
	fseek(fileOut, fileHeaderOut.dataOffset, SEEK_SET);

	//~ Розраховуємо кількість байтів у рядку з урахуванням вирівнювання
	//~ Кількість байтів у рядку має бути кратна 4. Якщо в нас кодуваня 3 байти, і для кратного числа не вистачає кілька байтів, необхідні 2-3, чи 1 байт заповнюються нулями.
	int rowSizeIn  = (infoHeaderIn.bitsPerPixel * infoHeaderIn.width + 31) / 32 * 4;
	int rowSizeOut = (infoHeaderOut.bitsPerPixel * infoHeaderOut.width + 31) / 32 * 4;
	
	
	// Виділяємо пам'ять для пікселів з вхідного файлу
	unsigned char *pixelData = (unsigned char *) malloc (rowSizeIn * infoHeaderIn.height);
		if (pixelData == NULL) {
		perror("pixelData");
		fclose(file);
		return 1;
	}
	//~ Масив піксеоів для вихідного файлу
	unsigned char *pixelOut = (unsigned char *) malloc (rowSizeOut * infoHeaderOut.height);
		if (pixelData == NULL) {
		perror("pixelOut");
		fclose(file);
		return 1;
	}

	//~ Читаємо дані зображення
	fread(pixelData, rowSizeIn * infoHeaderIn.height, 1, file);

	//~ Закриваємо вхідний файл
	fclose(file);
	//~ цикл по пікселям вхідного та вихідного файлів.
	unsigned k = 0, j = 0;
	//~ Зчитування по рядках: i < infoHeaderIn.height; i++
	//~ Масив пікселів це не двовимірний масив, а одновимірний, де рядки записані послідовно
	//~ j - ітератор вхідного масиву
	//~ k - ітератор вихідного масиву
	for (unsigned i = 0 ; i < infoHeaderIn.height; i++, k = i * rowSizeOut, j = i * rowSizeIn)
	{
		//~ початкове значення j задано попереду (в оголошенні масиву по i) 
		for (; j < i * rowSizeIn + infoHeaderIn.width * infoHeaderIn.bitsPerPixel / 8;)
		{
			//~ Змінні для тимчасового запису кольорів піселя
			unsigned char blue;
			unsigned char green;
			unsigned char red;
			//~ Якщо кодування пікселя трьохбайтне
			if (infoHeaderIn.bitsPerPixel == 24) {
				blue  = pixelData[j];
				green = pixelData[j + 1];
				red   = pixelData[j + 2];
				//~ 3 елементи вхідного масиву зчитані - ітератор збільшуємо на 3
				j += 3;
			//~ Якщо кодування чотирьохбайтне. Прозорість (alpha) ігноруємо
			} else if (infoHeaderIn.bitsPerPixel == 32) {
				blue  = pixelData[j + 0];
				green = pixelData[j + 1];
				red   = pixelData[j + 2];
				//~ 4 елементи вхідного масиву зчитані - ітератор збільшуємо на 4
				j += 4;
			}

			//~ Формула для чорнобілого зображення	
			//~ unsigned char grey = blue / 9 + green / 2 + red / 4;

			//~ Піксель вихідного зображення
			unsigned short tmp_pixel = 0;

			//~ Просте перетворення з RGB888 в RGB555 (двобайтне кодування) 
			tmp_pixel = SET_BLUE(blue) | SET_GREEN(green) | SET_RED(red);

			//~ Наступні варіанти перетворення. Попередній закоментуйте, а потрібний - розкоментуйте
			
			//~ Для перетворення в чорнобіле
			//~ tmp_pixel = SET_BLUE(grey) | SET_GREEN(grey) | SET_RED(grey);

			//~ Перетворення в RGB555 (двобайтне кодування) із інверсією - синій колір міняється з зеленим.
			//~ tmp_pixel = SET_BLUE(green) | SET_GREEN(blue) | SET_RED(red);
			 
			//~ Перетворення uint16_t на два елементи зі масиву типу uint8_t
			//~ 0-й елемент масиву - молодший байт змінної uint16_t
			pixelOut[k]	= tmp_pixel;
			//~ перший елемент масиву uint8_t - Старший байт змінної uint16_t
			pixelOut[k + 1]	= tmp_pixel >> 8;
			//~ і так далі
			//~ два елементи вихідного масиву присвоєнні, ітератор вихідного масиву збільшуємо на 2
			k += 2;
 
		}	 
	}
	//~ Записування у вихідний файл масиву пікселів
	fwrite(pixelOut, rowSizeOut * infoHeaderOut.height, 1, fileOut);
	//~ закриття файлу та звільнення пам'яті
	fclose(fileOut);
	free(pixelData);
	free(pixelOut);
    return 0;
}
