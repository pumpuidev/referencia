#! /usr/bin/python
import pickle

f=open("adatok.txt", 'r')
print f
# <open file 'adatok.txt', mode 'r' at 0xb7850480>

#mode:  'r'  --- csak olvasasra (ez a default), ha nincs ilyen fajl, hiba
#       'w'  --- csak irasra (ha volt ilyen nevu fajl, akkor felulirja)
#       'a'  --- hozzafuzes celjabol (ha nem letezik, letrehozza)
#       'r+' --- irasra es olvasasra, ha nincs ilyen fajl, hiba
#       'rb', 'wb', 'ab', 'r+b'  --- ugyanez binaris fajlra 
#                                      (Windows/MAC eseten lenyeges)

print f.read(3), # parameterben megadott byte-ot olvas
print "----------\n",
print f.read()  # teljes fajl (az olvasasi poziciotol), 
                # ha mar elertuk a fajl veget ures karakterlancot ad
#23
#----------
#45
#65

f=open("adatok.txt", 'r')
print f.readline(),
print "----------\n",
print f.readline()
#23
#----------
#45

f=open("adatok.txt", 'r')
print f.readlines()
#['23\n', '45\n', '65\n']

f=open("adatok.txt", 'r')
for line in f :
    print line,

#23
#45
#65


f=open("kimenet.txt", 'w')
f.write("Kiirt szoveg...\n")

tel = {'Peter': 1234, 'Janos': 3456, 'Miklos': 2341}
f.write(str(tel))


f=open("tmp.txt", 'w')
f.write('0123456')
f=open("tmp.txt", 'r+')
f.seek(2)        # adott sorszamu byte-ra ugrik 
print f.read(1)
# 2
f.seek(3,0)      # adott byte-ot ugrik, a fajl elejerol (ez a default)
print f.read(1)
# 3
f.seek(2,1)      # adott byte-ot ugrik, aktualis poziciotol
print f.read(1)
# 6
f.seek(-3,2)     # adott byte-ot ugrik, a fajl vegetol
print f.read(1)
# 4
print f.tell()   # aktualis pozicio
# 5
f.close()          # felszabaditja a fajlhoz kotott eroforrasokat,
                   # innentol a fajl nem elerheto
                 

f=open("tmp.txt", 'w')
tel = {'Peter': 1234, 'Janos': 3456, 'Miklos': 2341}
pickle.dump(tel, f)    # kodoltan kiirja az objektumot
f=open("tmp.txt", 'r')
x = pickle.load(f)
print x
#{'Miklos': 2341, 'Janos': 3456, 'Peter': 1234}
