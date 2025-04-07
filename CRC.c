#include <stdio.h>
#include <string.h>
#define POLYNOMIAL 0xD8    // Example: x^8 + x^7 + x^6 + x^4 + x^3 + x^2 + 1
#define WIDTH 8            // Width of CRC (8 bits)
#define TOPBIT (1 << (WIDTH - 1))
 
unsigned char crc8(unsigned char *data, size_t length) {
   unsigned char remainder = 0; // Initialize the CRC to 0
 
   // Process each byte in the data stream
   for (size_t byte = 0; byte < length; ++byte) {
       remainder ^= data[byte]; // XOR the current byte with the remainder
 
       // Perform bit-by-bit processing for the current byte
       for (unsigned char bit = 8; bit > 0; --bit) {
           if (remainder & TOPBIT) {
               remainder = (remainder << 1) ^ POLYNOMIAL;
           } else {
               remainder = (remainder << 1);
           }
       }
   }
 
   return remainder; // Return the final CRC value
}
 
int main() {
   unsigned char message[] = "Hello, CRC!";
   size_t messageLength = strlen((char *)message);
 
   unsigned char crc = crc8(message, messageLength);
 
   printf("Message: %s\n", message);
   printf("CRC: 0x%02X\n", crc);
 
   return 0;
}
 
