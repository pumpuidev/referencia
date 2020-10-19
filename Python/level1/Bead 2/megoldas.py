#!/usr/bin/python

import os

# Extend file class

class fileEx(file):
	shortedData = ""
	def shortedWrite(self, data):
		self.shortedData += data

	def shortedCommit(self):
		lines = self.shortedData.split(os.linesep)
		if lines[-1] == "":
			lines = lines[0 : -1]
		self.shortedData = ""

		lines.sort()
		
		self.write(os.linesep.join(lines) + os.linesep)

open = fileEx

# Main code

db = {}
for line in open("data.txt", "r").read().splitlines():
	parts = line.split(" ")
	db[parts[-3]] = { 'name': " ".join(parts[0 : -3]), 'date': parts[-2], 'debit': int(parts[-1]) }

update_lines = open("update", "r").read().splitlines()
update_date = update_lines[0]
update_lines.pop(0)
new_acc = []
old_acc = []
for line in update_lines:
	parts = line.split(" ")

	if db.has_key(parts[-2]):
		if not parts[-2] in old_acc:
			old_acc.append(parts[-2])

		db[parts[-2]] = { 'name': " ".join(parts[0 : -2]), 'date': update_date, 'debit': db[parts[-2]]['debit'] + int(parts[-1]) }
	else:
		if not parts[-2] in new_acc:
			new_acc.append(parts[-2])

		db[parts[-2]] = { 'name': " ".join(parts[0 : -2]), 'date': update_date, 'debit': int(parts[-1]) }

# Write data to file

newdata = open('newdata','w')
for user in db:
	newdata.shortedWrite(db[user]['name'] + ' ' + user + ' ' + db[user]['date'] + ' ' + str(db[user]['debit']) + os.linesep)
newdata.shortedCommit()
newdata.close()

log = open('log','w')
log.write(update_date + os.linesep)
log.write(os.linesep)
log.write('new accounts:' + os.linesep)
for user in new_acc:
	log.shortedWrite(db[user]['name'] + ' ' + user + os.linesep)
log.shortedCommit()
log.write(os.linesep)
log.write('other updates:' + os.linesep)
for user in old_acc:
	log.shortedWrite(db[user]['name'] + ' ' + user + os.linesep)
log.shortedCommit()
log.close()
