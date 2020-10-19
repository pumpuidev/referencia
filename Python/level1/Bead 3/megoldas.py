#!/usr/bin/python

import os

def convertLine(pyfile, deep, line):
	if line.startswith('ELAGAZAS'):
		pyfile.write('    ' * deep + line[ : line.index('{')].replace('ELAGAZAS', 'if') + ':' + os.linesep)
		
		for lp in line[line.index('{') + 1 : line.rindex('}')].split(';;'):
			convertLine(pyfile, deep + 1, lp)
	elif line.startswith('CIKLUS'):
		pyfile.write('    ' * deep + line[ : line.index('{')].replace('CIKLUS', 'for') + ':' + os.linesep)
			
		for lp in line[line.index('{') + 1 : line.rindex('}')].split(';;'):
			convertLine(pyfile, deep + 1, lp)
	else:
		pyfile.write('    ' * deep + line.replace(';;', os.linesep + '    ' * deep) + os.linesep)
	

for file in os.listdir('.'):
	if file.endswith('.prog'):
		pyfile = open(file[0:-5] + '.py', 'w')
		for line in open(file, 'r').read().splitlines():
			convertLine(pyfile, 0, line)
