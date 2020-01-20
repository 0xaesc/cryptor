# Caesar chiffre tool

This tools help in dealing with caesar chiffre, also known as rotation chiffre.

## Documentation

### Usage

./caesar [mode] [input_file] [shift]

**file** is the absolute path to the text file you want to work with.

**shift** for encrypt and decrypt mode the shift is the integer by wich to shift the letters. In match mode, shift are to matching letters from cipher and clear text. Every letter in the file will be shifted accordingly.

**mode** can be either *encrypt*, *decrypt* or *match*.

*encrypt*  
encrypts the file. shifting every letter in the given text file by the given shift.

*decrypt*  
decrypts the file. shifting every letter in the given text file by the given shift.

*match*  
shifts the letters in the text file according to a given matching pair of letters. Not case sensiteve.

## TODO

### reorganize to classes
· file handling
· caesar cipher
· comparing

### file input
· check size and formatting

### file output
· way to name/direct output

### modes
· guess mode: basic statistical analysis of given text (find the e)
· search mode: try different shifts and crosscheck with a dictionary

### usability
· dump mode to pipe stuff directly
· a way to accept text via pipe not just from text file
· case sensitivity options
