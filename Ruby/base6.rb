# encoding: UTF-8

for x in (2..6)
   print x
   print " "
end   
# 2 3 4 5 6 
puts ""

for x in [1, "elem", 3.4]
   print x
   print " "
end   
# 1 elem 3.4 
puts ""


[1, "elem", 3.4].each{|x|
   print x
   print " "
}
# 1 elem 3.4 
puts ""

[1, "elem", 3.4].each do |x|
   print x
   print " "
end
# 1 elem 3.4
puts ""


"a\nb\nc\n".each_line do |x|
   print x.chomp
   print " "
end
# a b c
puts ""


3.times { |x|
   print x
   print " "
}
# 0 1 2
puts ""

3.times do |x|
   print x
   print " "
end
# 0 1 2
puts ""

----------------------------------------------------

x = 0
while x < 4
   print x
   print " "
   x += 1
end   
# 0 1 2 3 
puts ""

x = 0
y = 0
while x < 4
   print x
   print " "
   if x==1 and y ==0
      y = 1
      redo
   end    
   x += 1
end   
# 0 1 1 2 3 
puts ""

x = 0
while x < 4
   print x
   print " "
   if x==2 
      break
   end    
   x += 1
end   
# 0 1 2
puts ""

x = -1
while x < 3
   x = x + 1
   if x==2 
      next
   end    
   print x
   print " "
end   
# 0 1 3 
puts ""

----------------------------------------------------------

y = 0
for x in [1, "elem", 3.4, 5.2]
   print x
   print " "
   if x==3.4 and y ==0
      y = 1
      redo
   end  
end   
# 1 elem 3.4 3.4 5.2 
puts ""

x = 0
until x > 3
   print x
   print " "
   x = x + 1
end   
# 0 1 2 3 
puts ""

x = 0
until x > 3
   print x
   print " "
   if x==2 
      break
   end    
   x += 1
end   
# 0 1 2  
puts ""

i=0
puts i+=1 while i < 3
# 1
# 2
# 3



