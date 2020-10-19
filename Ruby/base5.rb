# encoding: UTF-8

x = 12

if x == 12 
 puts "egyenlő!" 
end
# egyenlő!

if x == 12 then puts "egyenlő!" end
# egyenlő!

if x == 12 ; puts "egyenlő!" end
# egyenlő!


# if x == 12 puts "egyenlő!" end
#
# base5.rb:17: syntax error, unexpected tIDENTIFIER, expecting keyword_then or ';' or '\n'
# if x == 12 puts "egyenlő!" end
#               ^
# base5.rb:17: syntax error, unexpected keyword_end, expecting $end


if x > 2
  puts x.to_s + " nagyobb!"
puts "mint 2"  
else
puts x.to_s + " kisebb!"
end
# 12 nagyobb!
# mint 2

if x > 20
  puts x.to_s + " nagyobb!"
else
  if x > 10
     puts x.to_s + " közte van!"
  else
     puts x.to_s + " kisebb!"
  end   
end
# 12 közte van!


if x > 20
puts x.to_s + " nagyobb!"
else
if x > 10
puts x.to_s + " közte van!"
else
puts x.to_s + " kisebb!"
end   
end
# 12 közte van!

if x > 20
   puts x.to_s + " nagyobb!"
elsif x > 10
   puts x.to_s + " közte van!"
else
   puts x.to_s + " kisebb!"   
end
# 12 közte van!


case x
   when 1,2,3
      puts "egy"
   when 10..12, 6
      puts "ketto"
   when 20..22
      puts "harom"
end
# ketto


x = 10
unless x > 5
  print x
  puts " kisebb"
else
  print x
  puts " nagyobb"
end
# 10 nagyobb


puts "10!" if x == 10
puts "nem 10!" if x != 10
# 10!

puts "unless 10!" unless x == 10
puts "unless nem 10!" unless x != 10
# unless nem 10!
