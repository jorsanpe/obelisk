/*
 * File:         umoddi3.S
 * Based on:
 * Author:
 *
 * Created:
 * Description:
 *
 * Modified:
 *               Copyright 2004-2006 Analog Devices Inc.
 *
 * Bugs:         Enter bugs at http://blackfin.uclinux.org/
 */

#define CARRY AC0

#ifdef CONFIG_ARITHMETIC_OPS_L1
.section .l1.text
#else
.text
#endif


.globl ___umoddi3;
.align 8;
___umoddi3:

  [SP +0] = R0;
	[SP +4] = R1;
	[SP +8] = R2;
	R3 = [SP +12];

	P0 = R4;		// Working space

	// If  x < y, then return x.
	CC = R1 < R3 (IU);
	R4 = CC;
	CC = R1 == R3;
	R4 = ROT R4 BY 1;
	CC = R0 < R2 (IU);
	R4 = ROT R4 BY 1;
	CC = R4 < 3;
	R4 = P0;
	IF !CC JUMP RET_X;

	LINK 16;

	// Compute d = x / y
	[SP +12] = R3;
	CALL.X ___udivdi3;

	// then compute z = d * y
	R2 = [FP +16];
	R3 = [FP +20];
	[SP +12] = R3;
	CALL.X ___mullu3;

	UNLINK;

	// r = x - z, so r = -z + x

	R0 = -R0;
	CC = CARRY;
	CC = !CC;
	R3 = CC;
	R1 = -R1;
	R1 = R1 - R3;	// z now negated

	R2 = [SP +0];
	R3 = [SP +4];

	R0 = R0 + R2;
	CC = CARRY;
	R2 = CC;
	R1 = R1 + R3;
	R1 = R1 + R2;

RET_X:
	RTS;

