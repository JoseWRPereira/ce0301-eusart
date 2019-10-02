#ifndef EUSART_H
#define EUSART_H

unsigned char rxEUSART( void );
unsigned char rxStatusEUSART( void );
void txEUSART( unsigned char d );
unsigned char txStatusEUSART( void );
void initEUSART( void );

#endif
