#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

#define SIZE(list) (sizeof(list)/sizeof(list[0]))           // 取出記憶體大小
#define DEBUG(...) printf(__VA_ARGS__)                      // ...=變動參數  print出變動參數  用變動參數而非函數 之後可分為內部測試版與release版本
#define BIT(i) (0x0001<<(i))                       //  左移回去

int imTop = 0;

uint16_t im[32768];
int16_t  m[65536];

void run(uint16_t *im, int16_t *m) {
  int16_t D = 0, A = 0, PC = 0;       // 一開始 PC =0 從第0個地方開始
  uint16_t I = 0;
  uint16_t a, c, d, j;
  while (1) {
    int16_t aluOut = 0, AM = 0;
    if (PC >= imTop) {                          // 如果PC 到最後了 結束虛擬機
      DEBUG("exit program !\n");
      break;
    }
    I = im[PC];                                  // 指令提取
    DEBUG("PC=%04X I=%04X", PC, I);              // 提取出來 就印出來 PC=XXXX I=XXXX...   %4X--> 四位的十六進位
    PC ++;
    if ((I & 0x8000) == 0) { // 第一個位元是0  --> A 指令 
      A = I;
    } else { // C 指令            解碼                     // CH4 的表        
      a = (I & 0x1000) >> 12;                             // (16進位) 0001 0000 0000  只要取出 a(I12)  -> a跟1 and 其他跟 0 and  然後右移12(>>12)
      c = (I & 0x0FC0) >>  6;                             // comp   0000 1111 1100 0000
      d = (I & 0x0038) >>  3;                             //  dest  0000 0000 0011 1000
      j = (I & 0x0007) >>  0;                             //  jump  0000 0000 0000 0111

      AM = (a == 0) ? A : m[A];                            // 如果A=0 傳回A 否則傳回m[A]
      switch (c) { // 處理 c1..6, 計算 aluOut
        case 0x2A: aluOut = 0;      break; // "0",   "101010"
        case 0x3F: aluOut = 1;      break; // "1",   "111111"
        case 0x3A: aluOut = -1;     break; // "-1",  "111010"
        case 0x0C: aluOut = D;      break; // "D",   "001100"
        case 0x30: aluOut = AM;     break; // "AM",  "110000"
        case 0x0D: aluOut = D ^ 0xFFFF; break; // "!D",  "001101"       4F(16位元全1)=1111 1111 1111 1111  跟1 xor = 反向
        case 0x31: aluOut = AM ^ 0xFFFF; break; // "!AM", "110001"
        case 0x0F: aluOut = -D;     break; // "-D",  "001111"
        case 0x33: aluOut = -AM;    break; // "-AM", "110011"
        case 0x1F: aluOut = D + 1;  break; // "D+1", "011111"
        case 0x37: aluOut = AM + 1; break; // "AM+1","110111"
        case 0x0E: aluOut = D - 1;  break; // "D-1", "001110"
        case 0x32: aluOut = AM - 1; break; // "AM-1","110010"
        case 0x02: aluOut = D + AM; break; // "D+AM","000010"
        case 0x13: aluOut = D - AM; break; // "D-AM","010011"
        case 0x07: aluOut = AM - D; break; // "AM-D","000111"
        case 0x00: aluOut = D & AM; break; // "D&AM","000000"
        case 0x15: aluOut = D | AM; break; // "D|AM","010101"
        default: assert(0);                                   // 都沒有就直接 false  離開
      }
      if (d & BIT(2)) A = aluOut;               //d1 d2 d3  [2] [1] [0] 
      if (d & BIT(1)) D = aluOut;               // A  D  M   (第四章)
      if (d & BIT(0)) m[A] = aluOut;              
      switch (j) {
        case 0x0: break;                          // 不跳
        case 0x1: if (aluOut >  0) PC = A; break; // JGT      ex:@10;JGT   jump 到  pc= a 的位置
        case 0x2: if (aluOut == 0) PC = A; break; // JEQ
        case 0x3: if (aluOut >= 0) PC = A; break; // JGE
        case 0x4: if (aluOut <  0) PC = A; break; // JLT
        case 0x5: if (aluOut != 0) PC = A; break; // JNE
        case 0x6: if (aluOut <= 0) PC = A; break; // JLE
        case 0x7: PC = A; break;                  // JMP          
      }
    }
    DEBUG(" A=%04X D=%04X m[A]=%04X=%04d", A, D, m[A], m[A]);
    if ((I & 0x8000) != 0) DEBUG(" a=%X c=%02X d=%X j=%X", a, c, d, j);
    DEBUG("\n");
  }
}

// run: ./vm <file.bin>
int main(int argc, char *argv[]) {
  char *binFileName = argv[1];
  FILE *binFile = fopen(binFileName, "rb");
  imTop = fread(im, sizeof(uint16_t), 32768, binFile);
  fclose(binFile);
  run(im, m);
}