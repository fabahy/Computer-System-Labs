#Bai 8: Nhap vao so nguyen n, tinh tong 1 den n
.data
	tb1: .asciiz "Nhap n: "
	tb2: .asciiz "Tong 1 den "
	tb3: .asciiz " la: "
	n: .word 0
	s: .word 0 
.text
	#xuat tb1
	li $v0,4
	la $a0,tb1
	syscall

	#Nhap so nguyen
	li $v0,5
	syscall

	#Luu v0 vao n
	move $s0,$v0
	sw $v0,n

	#truyen tham so
	lw $a0,n
	
	#goi ham
	jal _TinhTong

	#Lay ket qua tra ve trong $v0
	sw $v0,s
	
	#xuat tb2
	li $v0,4
	la $a0,tb2
	syscall
	
	#xuat n
	li $v0,1
	move $a0, $s0
	syscall
	
	#xuat tb3
	li $v0,4
	la $a0,tb3
	syscall
	
	#xuat s
	li $v0,1
	lw $a0,s
	syscall


	#ket thuc chuong trinh
	li $v0,10
	syscall


# ======== Ham TinhTong ================

#dau thu tuc
_TinhTong:
	addi $sp,$sp,-16 #khai bao stack
	#backup thanh ghi
	sw $ra,($sp)
	sw $s0,4($sp)
	sw $t0,8($sp)
	sw $t1,12($sp)
#than thu tuc
	li $s0,0 # s = 0
	li $t0,1 # i = 1
_TinhTong.Loop: 
	add $s0,$s0,$t0 # s = s + i
	addi $t0,$t0,1 # i++
	slt $t1,$a0,$t0
	beq $t1,0,_TinhTong.Loop

	#Luu kq tra ve
	move $v0,$s0
#Cuoi thu tuc
	#Restore thanh ghi
	lw $ra,($sp)
	lw $s0,4($sp)
	lw $t0,8($sp)
	lw $t1,12($sp)

	#xoa stack
	addi $sp,$sp,16 

	#tra ve
	jr $ra

