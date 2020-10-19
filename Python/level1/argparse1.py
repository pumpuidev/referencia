# -*- coding: utf-8 -*-
import argparse  # az optparse modul "utódja", a 2.6 vagy annál régebbi verziókban a régi modul van

parser = argparse.ArgumentParser(description='Argumentumkezelo pelda.', epilog='Echo program.')

parser.add_argument('--verbose', dest='verb', action='store_const', 
                      const=True, default=False, help='Setting verbose mode.')

parser.add_argument('str_args', type=str, nargs='*', metavar='Str',
                   help='Arguments of the program.')


args = parser.parse_args()

if args.verb : 
   print "Ez egy echo program!\nA beirt szoveg:\n"

for s in args.str_args: print s 

#$ python argparse1.py --v egy ketto
#Ez egy echo program!
#A beirt szoveg:
#
#egy
#ketto

