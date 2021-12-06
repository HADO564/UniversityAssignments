x=input("Enter instruction: ")
op = x.split()[0]
part = x.split()[1] 
op1= part.split(',')[0]
op2= x.split(',')[1]

if(op1[0]=='['):#done for memory access
    if(op.lower()=="mov"):
        opcode= "10000000"
    elif(op.lower()=="add"):
        opcode= "10000001"
    elif(op.lower()=="sub"):
        opcode= "10000010"
    elif(op.lower()=="mpy"):
        opcode= "10000011"
    elif(op.lower()=="div"):
        opcode= "10000100"
