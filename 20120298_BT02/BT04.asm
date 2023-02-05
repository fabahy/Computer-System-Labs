# Bai 4: Nhap vao 2 so nguyen, tinh tong, hieu, tich, thuong 2 so do.
.data
	tb1: .asciiz "Nhap so thu nhat: "
	tb2: .asciiz "Nhap so thu hai: "
	tb3: .asciiz "Tong: "
	tb4: .asciiz "\nHieu: "
	tb5: .asciiz "\nTich: "
	tb6: .asciiz "\nThuong: "
	tb7: .asciiz " du "
.text
	#xuat tb1
	li $v0,4
	la $a0,tb1
	syscall

	#nhap so nguyen
	li $v0,5
	syscall
	
	#gan $s0 = $v0
	move $s0,$v0

	#xuat tb2
	li $v0,4
	la $a0,tb2
	syscall

	#nhap so nguyen
	li $v0,5
	syscall
	
	#gan $s1 = $v0
	move $s1,$v0

	#tinh Tong
	add $s2,$s0,$s1

	#xuat tb3
	li $v0,4
	la $a0,tb3
	syscall

	#xuat s2
	li $v0,1
	move $a0,$s2
	syscall
		
	
	#tinh Hieu
	sub $s2,$s0,$s1


	#xuat tb4
	li $v0,4
	la $a0,tb4
	syscall

	#xuat s2
	li $v0,1
	move $a0,$s2
	syscall

	# tich Tich
	mult $s0, $s1
	mflo $s2
	
	#Xuat tb5
	li $v0, 4
	la $a0, tb5
	syscall
	
	# xuat ket qua phep nhan
	li $v0, 1
	move $a0, $s2
	syscall
	
	# tich Thuong
	div $s0, $s1
	mflo $s2
	mfhi $s3
	
	#Xuat tb6
	li $v0, 4
	la $a0, tb6
	syscall
	
	# xuat ket qua phep chia
	li $v0, 1
	move $a0, $s2
	syscall
	
	#Xuat tb7
	li $v0, 4
	la $a0, tb7
	syscall
	
	#Xuat du
	li $v0, 1
	move $a0, $s3
	syscall

