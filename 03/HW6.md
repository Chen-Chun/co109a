# DFF

## code:
     預設
     
## picture:
<img src="./picture3/DFF.jpg" height=400 weight=600 />

# Bit

## code:

          // This file is part of www.nand2tetris.org
          // and the book "The Elements of Computing Systems"
          // by Nisan and Schocken, MIT Press.
          // File name: projects/03/a/Bit.hdl

          /**
           * 1-bit register:
           * If load[t] == 1 then out[t+1] = in[t]
           *                 else out does not change (out[t+1] = out[t])
           */

          CHIP Bit {
              IN in, load;
              OUT out;

              PARTS:
              // Put your code here:
              Mux(b=in,a=o,sel=load,out=Muxab);
              DFF(in=Muxab,out=o,out=out);
              //out有兩個是因為一個是用來讓他回去再次使用
          }

## picture:
<img src="./picture3/Bit.jpg" height=400 weight=600 />

# Register

## code:

          // This file is part of www.nand2tetris.org
          // and the book "The Elements of Computing Systems"
          // by Nisan and Schocken, MIT Press.
          // File name: projects/03/a/Register.hdl

          /**
           * 16-bit register:
           * If load[t] == 1 then out[t+1] = in[t]
           * else out does not change
           */

          CHIP Register {
              IN in[16], load;
              OUT out[16];

              PARTS:
              // Put your code here:
              Bit(in=in[0],load=load,out=out[0]);
              Bit(in=in[1],load=load,out=out[1]);
              Bit(in=in[2],load=load,out=out[2]);
              Bit(in=in[3],load=load,out=out[3]);
              Bit(in=in[4],load=load,out=out[4]);
              Bit(in=in[5],load=load,out=out[5]);
              Bit(in=in[6],load=load,out=out[6]);
              Bit(in=in[7],load=load,out=out[7]);
              Bit(in=in[8],load=load,out=out[8]);
              Bit(in=in[9],load=load,out=out[9]);
              Bit(in=in[10],load=load,out=out[10]);
              Bit(in=in[11],load=load,out=out[11]);
              Bit(in=in[12],load=load,out=out[12]);
              Bit(in=in[13],load=load,out=out[13]);
              Bit(in=in[14],load=load,out=out[14]);
              Bit(in=in[15],load=load,out=out[15]);
          }

## picture:
<img src="./picture3/Register.jpg" height=400 weight=600 />
