include Irvine32.inc

.data
inputPrompt byte "Enter the marks between 0 and 100. Enter -1 to exit: ",0
errorPrompt byte "Value entered is out of range, try again later",0

gradePromptA byte "Grade: A",0 ;prompt to show grade if marks entered are within a certain range
gradePromptB byte "Grade: B",0
gradePromptC byte "Grade: C",0
gradePromptD byte "Grade: D",0
gradePromptF byte "Grade: F",0
score dword ?

.code
Main Proc
mov ecx, 10

; main prog loop
l1:
; make loop infinite by inc ecx everytime
inc ecx
; ask for user input
mov edx, offset inputPrompt
call writestring;display promt to ask for input
call readint;;read input and store in EAX
cmp eax,-1
je break;if entered input is -1, jump to break

cmp eax,90
jae Agrade1;if the input is above or equal to 90, go to Agrade1
jmp pointb;if the statement above is not true, jump to pointb
Agrade1:
cmp eax,100
jbe Agrade2;if the marks are below 100, the input is valid and jump to agrade2
mov edx, offset errorPrompt
call writestring
call crlf
jne l1 ;jump to start of loop after error is displayed
Agrade2:
mov edx, offset gradePromptA;since the input is valid, print that the grade is A 
call writestring
call crlf
jne l1;jump to start of loop

pointb:
cmp eax,80
jae Bgrade1;if the input is above or equal to 80, jump to Bgrade1
jmp pointc;if the statement is not true, jump to point c
Bgrade1:
cmp eax,89
jbe Bgrade2;if the input is below 89, go to Bgrade2
mov edx, offset errorPrompt
call writestring
call crlf

jne l1;jump to start of loop after error
Bgrade2:
mov edx, offset gradePromptB;since the input is in range, print grade B
call writestring
call crlf

jne l1;jump to start of loop


pointc:
cmp eax,70
jae Cgrade1;if the input is greater than or equal to 70, jump to Cgrade1
jmp pointD;if the statement is false, jump to point d
Cgrade1:
cmp eax,79;if the value is within range, jump to Cgrade2
jbe Cgrade2
mov edx, offset errorPrompt;if its out of range, print error message
call writestring
call crlf

jne l1;jump to start of loop after error is displayed
Cgrade2:
mov edx, offset gradePromptC;print grade c 
call writestring
call crlf

jne l1;jump to start of loop

pointD:
cmp eax,60
jae Dgrade1;if the input is above 60, jump to Dgrade1
jmp pointF
Dgrade1:
cmp eax,69;if the value is below or equal to 69
jbe Dgrade2;jump to dgrade2
mov edx, offset errorPrompt;if its false, display error prompt
call writestring
call crlf

jne l1;jump to start of loop after error is displayed
Dgrade2:
mov edx, offset gradePromptD;print grade D
call writestring
call crlf

jne l1;jump to start of loop 

pointF:
cmp eax,0
jae Fgrade1;if the grade is greater than 0, jump to Fgrade1
Fgrade1:
cmp eax,59
jbe Fgrade2;if the value is within the range, jump to Fgrade2
mov edx, offset errorPrompt;else print an error message
call writestring
call crlf

jne l1;jump to start of loop after error is displayed
Fgrade2:
mov edx, offset gradePromptF;display grade F
call writestring
call crlf

jne l1;jump to start of loop 





; exit if -1 input
break:





exit
Main ENDP
end main