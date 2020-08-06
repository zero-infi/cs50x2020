#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{  
    if (argc < 2)                                                                                    //check for correct arguments
    {
        return 1;
    }
    BYTE buffer[512];
    FILE *file = fopen(argv[1], "r");
    char fpix[] = "000.jgp";
    FILE *img = NULL;

    int count = 0;
    //int temp = fread(buffer , 512 , 1 , file) == 1;
    while (fread(buffer, 512, 1, file) == 1)
    {
        if (buffer [0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            
            if (count != 0) // not a first file
            {
                fclose(img);
            }
            sprintf(fpix, "%03i.jpg", count);  // naming jpgfile 
            count++;
            img = fopen(fpix, "w");   // write
            fwrite(buffer, 512, 1, img);

        }
        else if (count != 0)   // not a jpg file and found jpg file
        {

            fwrite(buffer, 512, 1, img); 

        }


    }
    fclose(img);                                                                                            //closing all the files
    fclose(file);
    return 0;


}
