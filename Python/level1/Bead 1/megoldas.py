#!/usr/bin/python

import sys, os

if len(sys.argv) < 2:
	print 'Adj meg egy file-t!'
	sys.exit(1)

if not os.path.isfile(sys.argv[1]):
	print 'Nincs ilyen file!'
	sys.exit(2)

items = {}
bids = []

in_items = True
for line in open(sys.argv[1], "r").read().splitlines():
	if line == '':
		in_items = False
		continue
	
	if in_items:
		datas = line.split(';')
		idname = datas[0].split('.')
		info = {}
		info['name'] = idname[1]
		info['price'] = int(datas[2])
		items[int(idname[0])] = info
	else:
		datas = line.split(':')
		idprice = datas[1].split('.')
		info = {}
		info['name'] = datas[0]
		info['id'] = int(idprice[0])
		info['price'] = int(idprice[1])
		bids.append(info)

ress = {}
for bid in bids:
	if bid['price'] < items[bid['id']]['price']:
		continue
	
	if not ress.has_key(bid['id']):
		ress[bid['id']] = bids.index(bid)
		continue
	
	if bid['price'] > bids[ress[bid['id']]]['price']:
		ress[bid['id']] = bids.index(bid)

f = open('eredmeny.txt','w')
for res in ress:
	f.write(str(bids[ress[res]]['id']) + '. ' + items[bids[ress[res]]['id']]['name'] + ', ' + bids[ress[res]]['name'] + ' ' + str(bids[ress[res]]['price']) + os.linesep)
f.close()
