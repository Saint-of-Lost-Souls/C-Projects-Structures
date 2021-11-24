#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define MAX_DIMENSIONS 3

typedef struct Guy
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
} Guy;

typedef struct GuyFlex
{
    char *name;
    bool active;
    int dimensions;
    double pos[]; // Can only declare as an incomplete array when it is the last member of a struct
                  // Not considered a part of the struct's physical memory, placeholder 
} GuyFlex;

typedef struct BleHeader // Bluetooth Low Energy Data Packet
{
    uint16_t pdu_type : 4;
    uint16_t rfu_1 : 2;
    uint16_t tx_add : 1;
    uint16_t rx_add : 1;
    uint16_t length : 6;
    uint16_t rfu_2 : 2;
} BleHeader;

typedef struct BlePacket    
{
    BleHeader header;
    uint8_t payload[];
} BlePacket;

GuyFlex *allocGuy(int dimensions)
{
    size_t size = sizeof(((GuyFlex*)0)->pos[0]);
    GuyFlex *guy = malloc(sizeof(GuyFlex) + dimensions * sizeof(double));
    if (!guy)
    {
        return NULL;
    }
    guy->dimensions = dimensions;
    return guy;
}

void readBlePacket(BlePacket *packet)
{
    int len = packet->header.length;
    for (int i = 0; i < len; i++)
    {
        printf("%X", packet->payload[i]);
    }
    printf("\n");    
}

int main()
{
    system("cls");

    printf("sizeof(Guy): %lld\n", sizeof(Guy));
    printf("sizeof(GuyFlex): %lld\n", sizeof(GuyFlex));

    const uint8_t rx_buffer[] = {0x41, 0x06, 0xCA, 0xFE, 0xCA, 0xFE, 0xCA, 0xFE};
    readBlePacket((BlePacket *)rx_buffer);

    printf("\n\n");
    return EXIT_SUCCESS;
}
