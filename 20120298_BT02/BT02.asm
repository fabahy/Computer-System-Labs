# Bai 2: Nhap vao mot ki tu, xuat ra ki tu lien truoc va lien sau
.data 
	tb0:.asciiz "Nhap mot ki tu: "
	tb1:.asciiz "\nKi tu lien truoc: "
	tb2:.asciiz "\nKi tu lien sau: "
.text
	la $a0, tb0        # Xuat thong bao 0
	li $v0, 4
	syscall
	
	li $v0, 12  	   # nhap 1 ki tu 
	syscall            
	
	addi $s0, $v0, 0   # gan ki tu vua nhap vao s0
	
	la $a0, tb1        # Xuat thong bao 1
	li $v0, 4
	syscall
	
	addi $a0, $s0, -1  # ki tu lien truoc = ki tu - 1
	li $v0, 11	   # xuat ki tu 
	syscall
	
	la $a0, tb2        # Xuat thong bao 2
	li $v0, 4
	syscall
	
	addi $a0, $s0, 1   # ki tu lien sau = ki tu + 1
	li $v0, 11         # xuat ki tu 
	syscall
	
	li $v0, 10         # Thoat chuong trinh
    	syscall
