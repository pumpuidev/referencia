# encoding: UTF-8


f = File.new("teszt", "r")

s = 0
f.each_line{|line|
   s += line.to_i
}
puts s
# 15

f.close


f = open("teszt", "r")

s = 0
f.each_line{|line|
   s += line.to_i
}
puts s
# 15

f.close


File.open("teszt", "r"){|f|

    s = 0
    f.each_line{|line|
       s += line.to_i
    }
    puts s
    # 15
    
    f.close
}

# --------------------------------------------------------

f = File.new("teszt2", "r")

s = 0
f.each_line(":"){|line|
   s += line.chomp(":").to_i
}
puts s
# 15

f.close

# --------------------------------------------------------

s = 0
IO.foreach("teszt") { |line| s += line.to_i }
puts s
# 15


list = IO.readlines("teszt")
list.map!{|x| x.chomp} 
print list.join(", ")
puts ""
# 1, 2, 3, 4, 5

#---------------------------------------------------------

f = File.new("out", "w")
f.write "kakukk\n"
f.close


f = File.new("out", "a")
f << "kakukk\n"
f.close


$stdout << "kakukk\n"
# kakukk



