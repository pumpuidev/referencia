# encoding: UTF-8

puts "Idő: 12:35" =~ /\d\d:\d\d/
# 5
puts $~
# 12:35


puts "Idő: 12::35" =~ /\d\d:\d\d/
# nil


puts "Idő: 12:35" =~ /(\d\d):\d\d/
# 5
puts $~
# 12:35
puts $~[1]
# 12

r = Regexp.new('(\d\d):\d\d')

puts "Idő: 12:35" =~ r
# 5
puts $~
# 12:35
puts Regexp.last_match(1)
# 12

r2 = Regexp.union(/\d\d:\d\d/, /\d\d::\d\d/)
puts "Idő: 12:35" =~ r2
# 5
puts "Idő: 12::35" =~ r2
# 5


prb = "HELLO"
case prb
   when /^[a-z]*$/; puts "Kisbetűs!"
   when /^[A-Z]*$/; puts "Nagybetűs!"
   else;            puts "Kis- és nagybetű is van!"
end
# Nagybetűs!



# -----------------------------------------------------------


puts /:(.*):/.match("szoveg:minta:szoveg:")
# :minta:szoveg:

puts /:(.*):/.match("szoveg:minta:szoveg:")[1]
# minta:szoveg

puts /:(.*?):/.match("szoveg:minta:szoveg:")
# :minta:


# -----------------------------------------------------------


puts "kis_at_email.hu, nagy<at>email.hu".sub(/.at./, "@")
# kis@email.hu, nagy<at>email.hu


puts "kis_at_email.hu, nagy<at>email.hu".gsub(/.at./, "@")
# kis@email.hu, nagy@email.hu


puts "cím: www.valami.hu".gsub(/(w{3}\..+?\.hu)/, 'http://\1')
# cím: http://www.valami.hu


puts "kave: 25, tea: 20".gsub(/\d+/) {|s| (s.to_i * 1.2).to_i.to_s}      
# kave: 30, tea: 24


# -----------------------------------------------------------


fout = open("jegy.txt", "w")

IO.foreach("zh.txt") { |line| 
   
   etr = /.{7}\.ELTE/.match(line)[0]
   jegy = line.split(":")[-1]
   fout.write etr + " " + jegy
    
}

fout.close




