# HalfAdder:

## code:
          // This file is part of www.nand2tetris.org
          // and the book "The Elements of Computing Systems"
          // by Nisan and Schocken, MIT Press.
          // File name: projects/02/HalfAdder.hdl

          /**
           * Computes the sum of two bits.
           */

          CHIP HalfAdder {
              IN a, b;    // 1-bit inputs
              OUT sum,    // Right bit of a + b 
                  carry;  // Left bit of a + b

              PARTS:
              // Put you code here:
              Xor(a=a,b=b,out=sum);
              And(a=a,b=b,out=carry);
          }

## picture:
<img src="./picture2/HalfAdder.jpg" height=400 weight=600 />

# FullAdder:

## code:
          // This file is part of www.nand2tetris.org
          // and the book "The Elements of Computing Systems"
          // by Nisan and Schocken, MIT Press.
          // File name: projects/02/FullAdder.hdl

          /**
           * Computes the sum of three bits.
           */

          CHIP FullAdder {
              IN a, b, c;  // 1-bit inputs
              OUT sum,     // Right bit of a + b + c
                  carry;   // Left bit of a + b + c

              PARTS:
              // Put you code here:
              HalfAdder(a=a,b=b,sum=ab,carry=cab);
              HalfAdder(a=c,b=ab,sum=sum,carry=i);
              Or(a=cab,b=i,out=carry);
          }

## picture:
<img src="./picture2/FullAdder.jpg" height=400 weight=600 />

# Add16:

## code:
          // This file is part of www.nand2tetris.org
          // and the book "The Elements of Computing Systems"
          // by Nisan and Schocken, MIT Press.
          // File name: projects/02/Adder16.hdl

          /**
           * Adds two 16-bit values.
           * The most significant carry bit is ignored.
           */

          CHIP Add16 {
              IN a[16], b[16];
              OUT out[16];

              PARTS:
             // Put you code here:
             HalfAdder(a=a[0],b=b[0],sum=out[0],carry=c);
             FullAdder(a=a[1],b=b[1],c=c,sum=out[1],carry=d);
             FullAdder(a=a[2],b=b[2],c=d,sum=out[2],carry=e);
             FullAdder(a=a[3],b=b[3],c=e,sum=out[3],carry=f);
             FullAdder(a=a[4],b=b[4],c=f,sum=out[4],carry=g);
             FullAdder(a=a[5],b=b[5],c=g,sum=out[5],carry=h);
             FullAdder(a=a[6],b=b[6],c=h,sum=out[6],carry=i);
             FullAdder(a=a[7],b=b[7],c=i,sum=out[7],carry=j);
             FullAdder(a=a[8],b=b[8],c=j,sum=out[8],carry=k);
             FullAdder(a=a[9],b=b[9],c=k,sum=out[9],carry=l);
             FullAdder(a=a[10],b=b[10],c=l,sum=out[10],carry=m);
             FullAdder(a=a[11],b=b[11],c=m,sum=out[11],carry=n);
             FullAdder(a=a[12],b=b[12],c=n,sum=out[12],carry=o);
             FullAdder(a=a[13],b=b[13],c=o,sum=out[13],carry=p);
             FullAdder(a=a[14],b=b[14],c=p,sum=out[14],carry=q);
             FullAdder(a=a[15],b=b[15],c=q,sum=out[15],carry=carry);
          }

## picture:
<img src="./picture2/Add16.jpg" height=400 weight=600 />

# Inc16:

## code:
          // This file is part of www.nand2tetris.org
          // and the book "The Elements of Computing Systems"
          // by Nisan and Schocken, MIT Press.
          // File name: projects/02/Inc16.hdl

          /**
           * 16-bit incrementer:
           * out = in + 1 (arithmetic addition)
           */

          CHIP Inc16 {
              IN in[16];
              OUT out[16];

              PARTS:
             // Put you code here:
              /*  HalfAdder(a=in[0],b=true,sum=out[0],carry=c1);
                  HalfAdder(a=in[1],b=c1,sum=out[1],carry=c2);
                  HalfAdder(a=in[2],b=c2,sum=out[2],carry=c3);
                  HalfAdder(a=in[3],b=c3,sum=out[3],carry=c4);
                  HalfAdder(a=in[4],b=c4,sum=out[4],carry=c5);
                  HalfAdder(a=in[5],b=c5,sum=out[5],carry=c6);
                  HalfAdder(a=in[6],b=c6,sum=out[6],carry=c7);
                  HalfAdder(a=in[7],b=c7,sum=out[7],carry=c8);
                  HalfAdder(a=in[8],b=c8,sum=out[8],carry=c9);
                  HalfAdder(a=in[9],b=c9,sum=out[9],carry=c10);
                  HalfAdder(a=in[10],b=c10,sum=out[10],carry=c11);
                  HalfAdder(a=in[11],b=c11,sum=out[11],carry=c12);
                  HalfAdder(a=in[12],b=c12,sum=out[12],carry=c13);
                  HalfAdder(a=in[13],b=c13,sum=out[13],carry=c14);
                  HalfAdder(a=in[14],b=c14,sum=out[14],carry=c15);
                  HalfAdder(a=in[15],b=c15,sum=out[15]); */

              Add16(a=in, b[0]=true, b[1..15]=false, out=out);
          }

## picture:
<img src="./picture2/Inc16.jpg" height=400 weight=600 />

