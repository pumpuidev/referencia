# encoding: UTF-8

puts "abcde".reverse
# edcba

puts 'kakukk'.length
# 6

letters = 'aAbBcCdDeE'
puts letters.upcase
puts letters.downcase
puts letters.swapcase
puts letters.capitalize
# AABBCCDDEE
# aabbccddee
# AaBbCcDdEe
# Aabbccddee

lineWidth = 20
str = '!!!'
puts str.ljust  lineWidth
puts str.center lineWidth
puts(str.rjust(lineWidth))
# !!!                 
#         !!!         
#                  !!!

# a b c d ----- a(b(c(d)))

