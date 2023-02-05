# Bai 5: Nhap vao 2 so nguyen, xuat ra phep so sanh giua 2 so
.data
	tb1: .asciiz "Nhap so thu nhat: "
	tb2: .asciiz "Nhap so thu hai: "
	tb3: .asciiz "So lon hon la: "
	tb4: .asciiz "\nSo be hon la: "
	tb5: .asciiz "Hai so bang nhau"
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
	
	# so sanh 2 so
	blt $s0, $s1, Less   	# if (n1 < n2) 
	beq $s0, $s1, Equal	# else if (n1 == n2)
	
	#xuat tb3		# else
	li $v0,4
	la $a0,tb3
	syscall
	
	# Xuat so lon 
	li $v0, 1
	move $a0, $s0
	syscall
	
	#xuat tb4
	li $v0,4
	la $a0,tb4
	syscall
	
	# Xuat so be
	li $v0, 1
	move $a0, $s1
	syscall
	
	j Fin
	
Less:	
	#xuat tb3
	li $v0,4
	la $a0,tb3
	syscall
	
	# Xuat so lon 
	li $v0, 1
	move $a0, $s1
	syscall
	
	#xuat tb4
	li $v0,4
	la $a0,tb4
	syscall
	
	# Xuat so be
	li $v0, 1
	move $a0, $s0
	syscall
	
	j Fin
	
Equal:
	#xuat tb5
	li $v0,4
	la $a0,tb5
	syscall
	
	j Fin
	
Fin: 	li $v0, 10
	syscall
		
