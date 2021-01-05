from optparse import OptionParser
from os import path
from sys import exit

import file_handler

"""
    option parser to provide encryption type, cipher and arguments for decryption
"""


def parse_cmdline(avbl_enc_types):
    cmd_parser = OptionParser()

    cmd_parser.add_option('-c', '--cipher', dest='cipher_string',
                          help='cipher single string mode.'
                               ' Provide a single string to decrypt, not intended for larger encrypted data')

    cmd_parser.add_option('-i', '--infile', dest='input_file',
                          help='cipher file mode.'
                               ' Provide an encrypted file to decrypt.'
                               ' File will be interpreted as single encrypted string per line.'
                               ' If CIPHER_STRING is provided as well it will be appended.'
                               ' Maximum file size is 1 GB size.')

    cmd_parser.add_option('-t', '--type',   dest='encryption_type',
                          help='Set type for used encryption.')

    cmd_parser.add_option('-l', '--list',   dest='list_bool',
                          help='List available decryption types.')

    (options, args) = cmd_parser.parse_args()

    """
        list available encryption types or
        check if required options are provided
        
        required options:
                            - encryption type
                            - cipher: as string or as file
    """

    if options.list_bool:
        if len(avbl_enc_types) is 0:
            print('No decryption modules found')
        else:
            print('Available encryption types are:')
            for e in avbl_enc_types:
                print(e)
        exit(0)

    if not options.encryption_type:
        cmd_parser.error('ARGUMENT ERROR - provide an encryption type')

    if options.encryption_type not in avbl_enc_types:
        cmd_parser.error('DECRYPTION ERROR - encryption type not available')

    """
        if a file is provided check if it is valid
        a valid file exists and is smaller than 1000 Bytes
        
        if a cipher string is provided add it to the cipher list
        
        if valid encrypted data is provided return it
    """

    if not options.cipher_string or not options.input_file:
        cmd_parser.error('ARGUMENT ERROR - no cipher provided')

    cipher = []

    if options.input_file:
        if path.exists(options.input_file):
            cmd_parser.error('ARGUMENT ERROR - provided file does not exist')
        if path.isdir(options.input_file):
            cmd_parser.error('ARGUMENT ERROR - provided file is a directory')
        if path.isfile(options.input_file):
            if path.getsize(options.input_file) > 1000:
                cmd_parser.error('ARGUMENT ERROR - provided file is too large: 1GB maximum')
            else:
                cipher = [file_handler.read_cipher(options.input_file)]

    if options.cipher_string:
        cipher.append(options.cipher_string)

    if len(cipher) is 0:
        cmd_parser.error('ARGUMENT ERROR - no data was provided')
    else:
        return cipher
