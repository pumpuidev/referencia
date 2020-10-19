# encoding: UTF-8

list = [1, "2", 5.0, 'kakukk']
puts list
# 1
# 2
# 5.0
# kakukk

puts list[0]
# 1

puts list[0,1]
# 1

puts list[0,2]
# 1
# 2

puts list[2,2]
# 5.0
# kakukk


puts list[1..2]
# 2
# 5.0

puts list[-2]
# 5.0

puts list[-2, 2]
# 5.0
# kakukk

puts list[-3..-2]
# 2
# 5.0

#[1, "2", 5.0, 'kakukk']

list[1] = "3"
list[-2,2] = ["a","b"]
list[-3..-2] = ["c","d"]


str = list.join("--")
puts str
# 1--c--d--b

puts str.split("--")
# 1
# c
# d
# b

hash = {1 => 2, "2" => "4"}
puts hash["2"]
# 4

hash['uj'] = 32
hash.delete "2"
puts hash
# 12uj32


