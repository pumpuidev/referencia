import argparse

parser = argparse.ArgumentParser(description='Argumentumkezelo pelda.'
                                    , epilog='Echo program.')

parser.add_argument('--verbose', dest='verb', action='store_true', 
                      help='Setting verbose mode.')

parser.add_argument('str_args', type=str, metavar='Str', nargs='+',
                   help='Arguments of the program.')


args = parser.parse_args()

if args.verb : 
   print "Ez egy echo program!\nA beirt szoveg:\n"

for s in args.str_args: print s 

#$ python argparse2.py --v egy ketto
#Ez egy echo program!
#A beirt szoveg:
#
#egy
#ketto
