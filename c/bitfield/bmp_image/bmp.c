#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//~ Структура з бітовими полями для опису стану пікселя
//~ RGB-555 - один колір - 5 бітів. Стан пікселя - 2 байти
typedef struct
{
	uint16_t blue	: 5;
	uint16_t green	: 5;
	uint16_t red	: 5;
} pixel_RGB555;


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


	int nbytes = infoHeaderIn.bitsPerPixel / 8;

	//~ Було оглошено масив unsigned char, але в па'ять під масив записуємо структури
	pixel_RGB555 * iterator = (pixel_RGB555 * ) pixelOut;
										//~ Структура 2 байти, відповідно ітерація по одному рядку пікселів у 2 рази менша
	for (unsigned i = 0 ; i < infoHeaderIn.height; i++, k = i * rowSizeOut / 2)
	{
		//~ початкове значення j задано попереду (в оголошенні масиву по i) 
		for (j = i * rowSizeIn; j < (i + 1) * rowSizeIn; j += nbytes, k++)
		{
			 

			iterator[k].blue	= pixelData[j]		>> 3;
			iterator[k].green	= pixelData[j + 1]	>> 3;
			iterator[k].red   = pixelData[j + 2]	>> 3;
			
			uint8_t gray = iterator[k].blue / 9 + iterator[k].green / 2 + iterator[k].red / 4;

			iterator[k].blue	= gray;
			iterator[k].green	= gray;
			iterator[k].red   = gray;
			
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
