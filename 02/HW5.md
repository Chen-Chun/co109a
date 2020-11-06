# ALU-nostat
## code:

          // This file is part of www.nand2tetris.org
          // and the book "The Elements of Computing Systems"
          // by Nisan and Schocken, MIT Press.
          // File name: projects/02/ALU.hdl

          /**
           * The ALU (Arithmetic Logic Unit).
           * Computes one of the following functions:
           * x+y, x-y, y-x, 0, 1, -1, x, y, -x, -y, !x, !y,
           * x+1, y+1, x-1, y-1, x&y, x|y on two 16-bit inputs, 
           * according to 6 input bits denoted zx,nx,zy,ny,f,no.
           * In addition, the ALU computes two 1-bit outputs:
           * if the ALU output == 0, zr is set to 1; otherwise zr is set to 0;
           * if the ALU output < 0, ng is set to 1; otherwise ng is set to 0.
           */

          // Implementation: the ALU logic manipulates the x and y inputs
          // and operates on the resulting values, as follows:
          // if (zx == 1) set x = 0        // 16-bit constant
          // if (nx == 1) set x = !x       // bitwise not
          // if (zy == 1) set y = 0        // 16-bit constant
          // if (ny == 1) set y = !y       // bitwise not
          // if (f == 1)  set out = x + y  // integer 2's complement addition
          // if (f == 0)  set out = x & y  // bitwise and
          // if (no == 1) set out = !out   // bitwise not
          // if (out == 0) set zr = 1
          // if (out < 0) set ng = 1

          CHIP ALU {
              IN  
                  x[16], y[16],  // 16-bit inputs        
                  zx, // zero the x input?
                  nx, // negate the x input?
                  zy, // zero the y input?
                  ny, // negate the y input?
                  f,  // compute out = x + y (if 1) or x & y (if 0)
                  no; // negate the out output?

              OUT 
                  out[16], // 16-bit output
                  zr, // 1 if (out == 0), 0 otherwise
                  ng; // 1 if (out < 0),  0 otherwise

              PARTS:
             // Put you code here:
             Mux16(a=x,b=false,sel=zx,out=x0);
             Not16(in=x0,out=notx0);
             Mux16(a=x0,b=notx0,sel=nx,out=x0nxnotx0);
             //mux16的sel=0時，選擇a，mux16的sel=1時，選擇b
             Mux16(a=y,b=false,sel=zy,out=y0);
             Not16(in=y0,out=noty0);
             Mux16(a=y0,b=noty0,sel=ny,out=y0nynoty0);

             Add16(a=x0nxnotx0,b=y0nynoty0,out=aaddb);
             And16(a=x0nxnotx0,b=y0nynoty0,out=aandb);

             Mux16(a=aandb,b=aaddb,sel=f,out=f0);
             Not16(in=f0,out=notf0);
             Mux16(a=f0,b=notf0,sel=no,out[0..7]=no0A,out[8..15]=no0B,out[15]=ng,out=out);
             
             
※先用ALU-nostat.tst測試，再接著把ALU完成
# ALU
## code:

            // This file is part of www.nand2tetris.org
            // and the book "The Elements of Computing Systems"
            // by Nisan and Schocken, MIT Press.
            // File name: projects/02/ALU.hdl

            /**
             * The ALU (Arithmetic Logic Unit).
             * Computes one of the following functions:
             * x+y, x-y, y-x, 0, 1, -1, x, y, -x, -y, !x, !y,
             * x+1, y+1, x-1, y-1, x&y, x|y on two 16-bit inputs, 
             * according to 6 input bits denoted zx,nx,zy,ny,f,no.
             * In addition, the ALU computes two 1-bit outputs:
             * if the ALU output == 0, zr is set to 1; otherwise zr is set to 0;
             * if the ALU output < 0, ng is set to 1; otherwise ng is set to 0.
             */

            // Implementation: the ALU logic manipulates the x and y inputs
            // and operates on the resulting values, as follows:
            // if (zx == 1) set x = 0        // 16-bit constant
            // if (nx == 1) set x = !x       // bitwise not
            // if (zy == 1) set y = 0        // 16-bit constant
            // if (ny == 1) set y = !y       // bitwise not
            // if (f == 1)  set out = x + y  // integer 2's complement addition
            // if (f == 0)  set out = x & y  // bitwise and
            // if (no == 1) set out = !out   // bitwise not
            // if (out == 0) set zr = 1
            // if (out < 0) set ng = 1

            CHIP ALU {
                IN  
                    x[16], y[16],  // 16-bit inputs        
                    zx, // zero the x input?
                    nx, // negate the x input?
                    zy, // zero the y input?
                    ny, // negate the y input?
                    f,  // compute out = x + y (if 1) or x & y (if 0)
                    no; // negate the out output?

                OUT 
                    out[16], // 16-bit output
                    zr, // 1 if (out == 0), 0 otherwise
                    ng; // 1 if (out < 0),  0 otherwise

                PARTS:
               // Put you code here:
               Mux16(a=x,b=false,sel=zx,out=x0);
               Not16(in=x0,out=notx0);
               Mux16(a=x0,b=notx0,sel=nx,out=x0nxnotx0);
               //mux16的sel=0時，選擇a，mux16的sel=1時，選擇b
               Mux16(a=y,b=false,sel=zy,out=y0);
               Not16(in=y0,out=noty0);
               Mux16(a=y0,b=noty0,sel=ny,out=y0nynoty0);

               Add16(a=x0nxnotx0,b=y0nynoty0,out=aaddb);
               And16(a=x0nxnotx0,b=y0nynoty0,out=aandb);

               Mux16(a=aandb,b=aaddb,sel=f,out=f0);
               Not16(in=f0,out=notf0);
               Mux16(a=f0,b=notf0,sel=no,out[0..7]=no0A,out[8..15]=no0B,out[15]=ng,out=out);
               // Or16Way(in=no0, out=nzr);
               // Not(in=nzr, out=zr);
               Or8Way(in=no0A,out=nzrA);
               Not(in=nzrA,out=zrA);
               Or8Way(in=no0B,out=nzrB);
               Not(in=nzrB,out=zrB);
               Or(a=nzrA,b=nzrB,out=nzrAB);
               
               
## picture:
<img src="./picture2/ALU1.jpg" height=400 weight=600 />
<img src="./picture2/ALU2.jpg" height=400 weight=600 />