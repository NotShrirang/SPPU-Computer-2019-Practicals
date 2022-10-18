import sys

KEYWORDS = ["START", "DC", "DW", "LTORG", "MOVER", "END"]
AD = ["START", "END", "LTORG"]
DS = ["DC", "DW"]
IS = ["MOVER"]
OPCODETABLE = {}

class SymbolTableEntry():
    def __init__(self, symbolName: str, address: int) -> None:
        self.symbol_name: str = symbolName
        self.address: int = address


class LiteralTableEntry():
    def __init__(self, litName: str, address: int) -> None:
        self.literal_name: str = litName
        self.address: int = address


class PoolTableEntry():
    def __init__(self, index: int) -> None:
        self.index: int = index


class Assembler():
    def __init__(self, path: str) -> None:
        self.start: bool = False
        self.filepath: str = path
        self.startingAddr: int = 0
        self.current_address: int = 0
        self.code: list[str] = []
        self.symTab: list[SymbolTableEntry] = []
        self.litTab: list[LiteralTableEntry] = []
        self.poolTab: list[PoolTableEntry] = []
        self.literal_buffer: list[LiteralTableEntry] = []
        self.end_address: int = -1

    def pass1(self) -> None:
        with open(self.filepath, "r") as f:
            print("Code:\n" + f.read(), "\n")
        with open(self.filepath, "r") as f:
            self.code = f.read().split("\n")
        
        for cnt, line in enumerate(self.code):
            if self.end_address != -1:
                break
            words = line.split(" ")
            if cnt == 0 and words[0] != "START":
                raise(Exception("Program should always start with START keyword."))
            self.parse(words, cnt)

        print("\nSymTab:")
        for symb in self.symTab:
            print(symb.symbol_name, symb.address)
        
        print("\nLitTab:")
        for symb in self.litTab:
            print(symb.literal_name, symb.address)
        
        print("\nPoolTab:")
        for cnt, pool in enumerate(self.poolTab):
            print(f"#{cnt}", pool.index)
        
        with open("output.txt", "w") as f:
            f.write("SymTab: \n")
            for cnt, symb in enumerate(self.symTab):
                f.write(f"{cnt}\t{symb.symbol_name}\t{symb.address}\n")
            f.write("\nLitTab: \n")
            for cnt, lit in enumerate(self.litTab):
                f.write(f"{cnt}\t{lit.literal_name}\t{lit.address}\n")
            f.write("\nPoolTab: \n")
            for cnt, lit in enumerate(self.poolTab):
                f.write(f"{cnt}\t#{lit.index}\n")

    def parse(self, words: list[str], address: int):
        if words[0] in KEYWORDS:
            # print(self.current_address)
            if words[0] in AD:
                # print(f"{self.current_address=}")
                if words[0] == "START":
                    self.startingAddr = int(words[1])
                    self.current_address = self.startingAddr
                    self.current_address = int(self.current_address) + 1
                elif words[0] == "END":
                    p = PoolTableEntry(index=len(self.litTab))
                    # print(f"end : {len(self.litTab)=}")
                    self.poolTab.append(p)
                    self.litTab.extend(self.literal_buffer)
                    self.literal_buffer = []
                    self.end = True
                    self.current_address = int(self.current_address) + 1
                elif words[0] == "LTORG":
                    for lit in self.literal_buffer:
                        # print(f"{self.current_address=}")
                        lit.address = self.current_address
                    p = PoolTableEntry(index=len(self.litTab))
                    # print(f"ltorg : {len(self.litTab)=}")
                    self.poolTab.append(p)
                    self.litTab.extend(self.literal_buffer)
                    self.literal_buffer = []
                else:
                    pass
            elif words[0] in DS:
                s = SymbolTableEntry(symbolName=words[1], address = (int(self.startingAddr) + int(address)))
                self.symTab.append(s)
                self.current_address = int(self.current_address) + 1
            elif words[0] in IS:
                self.current_address = int(self.current_address) + 1
                pass
        for word in words:
            index = word.find('"=') # if it is literal
            if index != -1:
                literal = word[index+2 : -1]
                # print(literal)
                l = LiteralTableEntry(litName=literal, address=(int(self.startingAddr) + int(self.current_address)))
                # print(f"Literal Address : {l.address=}")
                self.current_address = int(self.current_address) + 1
                self.literal_buffer.append(l)

    def pass2(self):
        pass                

if __name__ == "__main__":
    a = Assembler(sys.argv[1])
    # a = Assembler("asm1.txt")
    a.pass1()
    a.pass2()
