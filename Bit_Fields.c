#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Bit fields in which we can specify the precise length of a menber in bits
// Defining the contents of a structure bit by bit
// Defining the use of the memory
// Save as much memory as possible
// No bit goes to waste

typedef struct LedStatus
{
    uint8_t led_1;
    uint8_t led_2;
    uint8_t led_3;
} LedStatus;

typedef struct LedStatusBitFields
{
    uint8_t led_1 : 1; // 1 bit long bit field
    uint8_t led_2 : 1; // 1 bit long bit field
    uint8_t led_3 : 1; // 1 bit long bit field

} LedStatusBitFields;

typedef struct BleHeader // Bluetooth Low Energy Data Packet
{
    uint16_t pdu_type : 4;
    uint16_t rfu_1 : 2;
    uint16_t tx_add : 1;
    uint16_t rx_add : 1;
    uint16_t length : 6;
    uint16_t rfu_2 : 2;
} BleHeader;

void printBits(uint8_t *data, int size) // print no of bytes data takes up
{
    for (int i = 0; i < size; i++)
    {
        uint8_t byte = data[i];

        for (int j = 0; j < 8; j++) // 8 because its an 8-bit integer
        {
            printf("%d", (byte >> j) & 1); // Apply a bit mask
        }
    }
    printf("\n");
}

int main()
{
    system("cls");

    printf("sizeof(LedStatus): %lld bytes\n", sizeof(LedStatus));
    printf("sizeof(LedStatusBitFields): %lld byte\n", sizeof(LedStatusBitFields));

    LedStatusBitFields status = {
        .led_1 = 1,
        .led_2 = 1,
        .led_3 = 1,
    };

    printBits((uint8_t *)&status, sizeof(status));

    status.led_1 = 0;
    status.led_2 = 0;

    printBits((uint8_t *)&status, sizeof(status));

    status.led_1 = 1;
    status.led_2 = 0;
    status.led_3 = 1;

    printBits((uint8_t *)&status, sizeof(status));

    BleHeader header = {
        .pdu_type = 3,
        .tx_add = 1,
        .length = 7,
    };

    printBits((uint8_t *)&header, sizeof(header));

    printf("\n\n");
    return EXIT_SUCCESS;
}
