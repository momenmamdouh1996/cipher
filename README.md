# cipher

##vignere cipher repo

this repo contains a working c++ code for vignere's cipher that works on alphabetic charcters only according to these instructions:

In this method, a keyword is repeatedly added character by character to each alphabetic letter in the original message. The addition is carried out using the ASCII codes for each of the characters, modulo 26 (the number of letters in the alphabet), and the result is added to the code for the letter 'A' in the ASCII code sequence. For example, if the original message is "due November 4" and the keyword is "HWone", the message will be encrypted as follows: message: DUE NOVEMBER 4 |||||||||||||| repeated keyword: HWONEHWONEHWON |||||||||||||| encrypted message: KQS RVRSZFLN 4

Assumptions and Restrictions. The message to be encoded and the keyword will both be read in from the keyboard. Only alphabetic characters will be encoded; all other characters will be outputted unchanged. Check to ensure keyword is only alphabetic characters. All alphabetic characters should be converted to uppercase before the encoding process begins. The input message should be restricted to 80 characters, the keyword to 8 characters (your program needs to check these limits).
