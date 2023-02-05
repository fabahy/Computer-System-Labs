# Bai 3: Nhap vao mot ki tu in hoa, in ra ki tu thuong
.data
	tb0:.asciiz "Nhap mot ki tu: "
	tb1:.asciiz "\nKi tu thuong: "
.text
	la $a0, tb0	# Xuat thong bao 0
	li $v0, 4
	syscall
	
	li $v0, 12	# Nhap vao 1 ki tu
	syscall
	
	addi $s0, $v0, 0 # Luu ki tu vao thanh s0
	
	la $a0, tb1	# Xuat thong bao 1
	li $v0, 4
	syscall
	
	addi $a0, $s0, 32  # ki tu thuong = ki tu in hoa + 32
	li $v0, 11	   # xuat ki tu 
	syscall
	
	li $v0, 10	# Thoat chuong trinh
	syscall
