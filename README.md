# probable-lamp

The program can be excuted using ./emulator after the repo has been cloned.

The program uses the 'input' file to run.

./emulator input <enter>

To compile on Linux use:
	
	gcc emulator.c -o emulator <enter>
	
	./emulator <enter>


The following instructions are accepted by the emulator:
********************************************************
Instruction	- Description				- Example input
********************************************************
	ADD		- Add and store result		- add r4, r4, #1
	SUB		- Subtract and store result	- sub r5, r5, #1
	CMP		- Compare to value			- cmp r3, #111
	MOV		- Move value to reg			- mov r8, #65
	SWI		- SWI Exit call				- swi SWI_Exit
	LDR		- Load str from mem			- ldr r4,=str
	LDRB	- Load byte from mem		- ldrb r3, [r4]
	BEQ		- Branch if equal			- beq branch
	BGT		- Branch if greater than	- beq branch
	B		- Loads Branch				- b branch
	STRB	- Stores byte				- strb r8, [r4]


##Future Developments

There are many more instructions left to impliment before this simulator is complete. 

Next steps should include the addition of:
		The MUL instruction - multiply and store result
		The SWP and SWPB - swapping words or btyes 
		Logical opertations including : AND, EOR and ORR

Further work on opcodes should be considered next, in addition to the full binary string instruction being generated and accetped by the emulator. 

