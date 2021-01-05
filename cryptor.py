import cmd_parser
"""
    cryptor main function
"""


def main():
    avbl_enc_types = ["caesar"]     # at some point dynamic
    cmd_parser.parse_cmdline(avbl_enc_types)


if __name__ == '__main__':
    main()
