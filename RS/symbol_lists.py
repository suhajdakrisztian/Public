NYSE_SYMBOLS = open("RS/nyse.txt", "r").read().split('\n')
NASDAQ_SYMBOLS = open("RS/nasdaq.txt", "r").read().split('\n')

SYMBOL_LIST = NASDAQ_SYMBOLS + NYSE_SYMBOLS