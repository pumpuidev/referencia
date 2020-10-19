# encoding: UTF-8

def kiir x
   puts x
end   

kiir "Próba!"  # --- kiir("Próba!")
# Próba!

def succ x
   x + 1
end   

x = succ 5
puts x
# 6

$x = 10
def add_x y
  z = $x + y
  z
end

out = add_x 12
puts out
# 22 

# hasonlit x y  ----  hasonlit(x(y))  --- Nem jó!!!

def hasonlit(x, y)
  return  x.to_s + " nagyobb mint " + y.to_s if x > y
  return  x.to_s + " kisebb mint " + y.to_s if x < y
  x.to_s + " és " + y.to_s + " egyenlő"  
end

puts hasonlit(10, 22)
# 10 kisebb mint 22

puts hasonlit 3, 3
# 3 és 3 egyenlő

def add(x = 10, y = 30)
   x + y
end

puts add
# 40

puts add 3
# 33

puts add(2,3)
# 5

puts add 2, 3
# 5

def add2 x = 10, y = 30
   x + y
end

puts add2
# 40

def myprint(x, *t)
   puts "A szoveg #{x} és #{t.join(", ")}"
end

myprint("egy")
# A szoveg egy és

myprint("egy", "ketto", "harom")
# A szoveg egy és ketto, harom


def ketszer
  yield
  yield
end

ketszer {puts "Próba!" }
# Próba!
# Próba!

def calcMax(x, y)
   if x < y 
      yield y
   else
      yield x
   end
end      

calcMax(5, 10) {|x| puts x}
# 10

def calcMax2(x,y)
  if block_given?
     if x < y 
        yield y
     else
        yield x
     end
  else
     puts "Nem volt blokk megadva!"
  end
end

calcMax2(3,4)
# Nem volt blokk megadva!

calcMax2(3, 4) {|x| puts x}
# 4



