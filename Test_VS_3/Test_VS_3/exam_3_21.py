
def decrypt(offset, encrypted_message):
	alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
	
	offset_alphabet = alphabet[offset:] + alphabet[offset-3:offset]
	encrypted_message *= 0
	while offset>0 :
		backstep = 1
		while backstep<=offset:
			encrypted_message.append(offset_alphabet[-backstep])
			backstep = backstep + 1
		

	print(encrypted_message)










decrypt(3, ['x', 'y', 'z'])