#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header (always 44)
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check for correct command-line usage
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open input file
    FILE *inptr = fopen(argv[1], "rb");
    if (inptr == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    // Open output file
    FILE *outptr = fopen(argv[2], "wb");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create output file.\n");
        return 1;
    }

    // Parse scaling factor
    float factor = atof(argv[3]);

    // Read and write header
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, inptr);
    fwrite(header, HEADER_SIZE, 1, outptr);

    // Read audio samples and adjust volume
    int16_t sample;
    while (fread(&sample, sizeof(sample), 1, inptr) == 1)
    {
        sample = (int16_t)(sample * factor);
        fwrite(&sample, sizeof(sample), 1, outptr);
    }

    // Close files
    fclose(inptr);
    fclose(outptr);

    return 0;
}
