#!/usr/bin/python

import os, sys 

class Ford:
	def __init__(self, szotar):
		self.szotar = szotar
	
	def fordit(self, inname, outname):
		if not os.path.isfile(inname):
			print 'Nincs input file!'
			sys.exit(1)
		
		outfile = open(outname, 'w')
		for line in open(inname).read().splitlines():
			newline = []
			for word in line.split(' '):
				needsDot = word[-1] == '.'
				if needsDot:
					word = word[:-1]
				
				if not self.szotar.has_key(word):
					continue
				
				if needsDot:
					newline.append(self.szotar[word] + '.')
				else:
					newline.append(self.szotar[word])
			outfile.write(' '.join(newline) + os.linesep)
	
	def visszafordit(self, inname, outname):
		self.szotar = dict(zip(self.szotar.values(),self.szotar.keys()))
		self.fordit(inname, outname)
		self.szotar = dict(zip(self.szotar.values(),self.szotar.keys()))
