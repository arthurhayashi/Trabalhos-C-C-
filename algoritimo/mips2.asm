
	.data
	.align 0
	
	op_6:	.asciiz " 6 - calc_imc\n"
	
	.text
	.globl main

main:
	la $a0, op_6
	syscall
	ler_op:
	#c�digo p/ ler inteiro
	addi $v0, $zero, 5
	syscall
	
	add $t9, $v0, $zero #armazenar op
	
	beq $t9, $zero, quit
	
	bltz $t9, invalid_op #op negativa
	
	addi $t8, $zero, 11
	ble $t8, $t9, invalid_op   #op maior que 10
	
ler_arg:#leitura do primeiro argumento
	#c�digo para ler inteiro
	addi $v0, $zero, 5
	syscall
	add $t0, $v0, $zero #armazenar primeio argumento
	
	#verifica��o se a op��o eh maior que 6
	#op��es maiores que 6 s� exigem 1 (um) argumento
	addi $t8, $zero, 6
	blt $t8, $t9, exec_op  
	
ler_arg2: #leitura do segundo argumento, se necess�rio
	beq $t9, $t8, ler_float #no calculo do imc, lemos a altura em ponto flutuante
	
	addi $v0, $zero, 5 
	syscall
	
	j exec_op

ler_float:
	addi $v0, $zero, 6
	syscall
	
exec_op:	
	addi $t8, $zero, 6
 	beq $t8, $t9, exec_calc_imc #se operacao for 6, calc_imc
	
exec_calc_imc:
	blt $a0,$zero, invalid_op4
	blt $a1,$zero, invalid_op4
	
	jal calc_imc
	
	j print_float
	calc_imc:
	mtc1 $a0, $f1
	cvt.s.w $f1,$f1
	
	mul.s $f0, $f0, $f0
	div.s $f1, $f1, $f0
	
	jr $ra
	
	print_float:
	add.s $f12, $f30, $f1
	addi $v0, $zero, 2
	syscall
	
	j print_continue
	
invalid_op:
	#tratamento de op��es inv�lidas
	la $a0, error
	addi $v0, $zero, 4
	syscall
	
	j print_continue
	
	print_continue:
	la $a0, continue
	addi $v0, $zero, 4
	syscall
	
	addi $v0, $zero, 12
	syscall
	
	j main
	
invalid_op2:
	#tratamento de input inv�lidos
	la $a0, error2
	addi $v0, $zero, 4
	syscall
	
	j print_continue

invalid_op3:
	#tratamento de raiz negativa
	la $a0, error3
	addi $v0, $zero, 4
	syscall
	
	j print_continue
	
invalid_op4:
	#tratamento de altura ou massa negativa
	la $a0, error4
	addi $v0, $zero, 4
	syscall
	
	j print_continue
quit:
	#fim do programa
	addi $v0, $zero, 10
	syscall
