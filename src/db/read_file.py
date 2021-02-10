import cog

def read_file_as_string(filename):
    with open(filename) as f:
        lines = f.readlines()
        for line in lines:
            cog.outl("\"%s\"" % line.replace("\n", ""))
