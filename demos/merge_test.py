#coding:utf8

# files
import os, sys
import shutil

# utils
import re

def walk(search_path, output, appen):
    if appen.strip(" ").strip("\n").strip("\r") == "n":
        fout = open(output + ".for.test", "w+")
    else:
        fout = open(output + ".for.test", "a")
    for path, dirs, files in os.walk(search_path):
        for fn in files:
            surfix = os.path.splitext(fn)[1][1:]
            name = os.path.splitext(fn)[0]
            if surfix in ["f90", "for", "f"]:
                f = open(path + "/" + fn, "r")
                fout.write(f.read())
                fout.write("\n")
                f.close()
    fout.close()                
if __name__ == '__main__':
    if len(sys.argv) < 4:
        print "gen_test.py <tests_dir> <output_file> <append> = [y/n]"
    else:
        walk(sys.argv[1], sys.argv[2], sys.argv[3])

