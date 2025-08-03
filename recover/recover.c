#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    FILE *inptr = fopen(argv[1], "rb");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[512];
    FILE *outptr = NULL;
    int file_count = 0;
    char filename[8];

    // Read 512-byte chunks until EOF
    while (fread(buffer, sizeof(BYTE), 512, inptr) == 512)
    {
        // Check for JPEG header
        bool is_jpeg_header = buffer[0] == 0xff &&
                              buffer[1] == 0xd8 &&
                              buffer[2] == 0xff &&
                              (buffer[3] & 0xf0) == 0xe0;

        if (is_jpeg_header)
        {
            // Close previous file if open
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            // Create new filename and open it for writing
            sprintf(filename, "%03i.jpg", file_count);
            outptr = fopen(filename, "wb");
            if (outptr == NULL)
            {
                printf("Could not create %s\n", filename);
                fclose(inptr);
                return 1;
            }

            file_count++;
        }

        // Write to file if one is open
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, outptr);
        }
    }

    // Close any open files
    if (outptr != NULL)
    {
        fclose(outptr);
    }
    fclose(inptr);

    return 0;
}
