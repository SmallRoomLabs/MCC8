#ifndef CHIP8_H_
#define	CHIP8_H_

#include <stdint.h>


extern uint8_t     c8screen[64*32/8];  // 64 x 32 pixels 1bpp screen buffer
extern uint8_t     c8ram[4096];        // RAM for chip-8 code, execution starts at 0x200
extern uint8_t     c8reg[16];          // The sixteen chip-8 working registers
extern uint16_t    c8i;                // The chip-8 index I register
extern volatile uint8_t c8dt;          // Delay timer, decrements down to 0 @ 60Hz
extern volatile uint8_t c8st;          // Sound timer, decrements down to 0 @ 60Hz
extern uint16_t    c8stack[16];        // Sixteen level deep stack for chip-8
extern uint8_t     c8sp;               // Stack pointer for chip-8
extern uint16_t    c8pc;               // Program counter for chip-8
extern uint8_t     chip8debug;         // 0=Normal, 1=Debuginfo & slow, 2=Single step

void Chip8RefreshScreen(void);
void Chip8Reset(const uint8_t *pLoad, const uint16_t lenLoad);
int Chip8Emulate(void);
void Chip8HandleTimers(void);


#endif

