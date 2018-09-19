#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }

    /* open input file */
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "can not open %s.\n", argv[1]);
        return 2;
    }

    // buffer for the beginning of jpeg

    int counter = 0;
    char filename[8];
    int read_num;
    FILE *img = NULL;
    uint8_t buffer[512];

    /* repeat read 512 bytes from inptr until end of card*/
    do
    {
        read_num = fread(&buffer, 1, 512, inptr);
        // find the beginning of jpeg
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0)  == 0xe0)
        {
            // if a file is open, close the old one before create a new one.
            if (img != NULL)
            {
                fclose(img);
            }
            // create filename and open a file
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            counter++;
        }
        // if the img file is open, write 512 bytes.
        if (img != NULL)
        {
            fwrite(buffer, 1, read_num, img);
        }

    }
    while (read_num == sizeof(buffer));

    fclose(img);
    fclose(inptr);
}