#include "buart.h"
#include "main.h"
#include "cmsis_os.h"
#include "string.h"
#define MAX_PACKET_SIZE 256

typedef struct {
    uint8_t length;
    uint8_t sender;
    uint8_t seqNum;
    uint8_t *payload; // Header + CRC
    uint32_t crc;
} B_tcpPacket_t;

typedef struct {
    B_uartHandle_t**    transmitBuarts;
    uint8_t             numTransmitBuarts;
    B_uartHandle_t*     rxBuart;
    uint8_t             tcpSeqNum;
    QueueHandle_t       txQ;
    TaskHandle_t        rxTask;
    CRC_HandleTypeDef*  crc;
} B_tcpHandle_t;


B_tcpHandle_t* B_tcpStart(B_uartHandle_t** transmitBuarts, 
                            B_uartHandle_t* rxBuart, 
                            uint8_t numTransmitBuarts,
                            CRC_HandleTypeDef* crc);
void serialParse(B_tcpPacket_t *pkt);

// GEN11: Added the following to prevent build warning (implicit declaration of function 'B_tcpSend')
void B_tcpSend(B_tcpHandle_t *btcp, uint8_t *msg, uint8_t length);

