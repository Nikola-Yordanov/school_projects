def extract_chars_with_positions(message) :
    chars = {}
    k = 0
    for i in message :
        l1 = [k]
        chars[i.lower()] = l1
        k+=1
        
    

    
        

    print(chars)

extract_chars_with_positions('HelloWorld')