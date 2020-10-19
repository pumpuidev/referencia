import argparse

parser = argparse.ArgumentParser(description='Argumentumkezelo pelda.', prog='argparse3', prefix_chars='-+')

parser.add_argument('-verbose', dest='verb', action='store_true', 
                      help='Setting verbose mode.')

parser.add_argument('-c', dest='value', action='store', 
                      help='Adding value.')

parser.add_argument('+i', dest='params', action='append_const', 
                      const=int, help='Adding int type.')

parser.add_argument('+s', dest='params', action='append_const', 
                      const=str, help='Adding string type.')

args = parser.parse_args()

if args.verb : 
   print "Ez egy echo program!\nA beirt szoveg:\n"

print args.value
print args.params

#$ python argparse3.py -v +i +s -c 5
#Ez egy echo program!
#A beirt szoveg:
#
#5
#[<type 'int'>, <type 'str'>]
