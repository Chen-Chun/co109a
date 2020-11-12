// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.


(WHILE1)
@16384
D=A
@i
M=D
@24576
D=A
@i
D=M-D  //計算16384~24576間有多少數字
@END2
D;JGE   
@color
M=0
@24576
D=M
@NEXT
D;JEQ
@COLOR
M=-1
(NEXT)
@color
D=M
@i
A=M
M=D
@i
M=M+1
@WHILE2
0;JMP
(END2)
@WHILE1
0;JMP