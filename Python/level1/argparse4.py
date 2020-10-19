import argparse

parser = argparse.ArgumentParser(description='Argumentumkezelo pelda.', prog='argparse3', prefix_chars='-+')

parser.add_argument('-verbose', dest='verb', action='store_true', 
                      help='Setting verbose mode.')

parser.add_argument('+i', dest='params1', action='append', type=int,
                      help='Adding int arguments.')

parser.add_argument('+s', dest='params2', action='append', 
                      help='Adding string arguments.')

args = parser.parse_args()

if args.verb : 
   print "Parameter tipus proba!\nA kapott ertekek:\n"

for x in args.params1 + args.params2:
    print x*2
    

#$ python argparse4.py -v +i 5 +i 6 +s egy +s ketto
#Parameter tipus proba!
#A kapott ertekek:
#
#10
#12
#egyegy
#kettoketto

