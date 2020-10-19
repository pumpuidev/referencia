#! /usr/bin/env ruby
# encoding: UTF-8

# ruby1.9.*

# ruby base.rb -- interpretálás
# vagy:
# irb  -- interaktív interpreter


puts (1.0 + 2.0) * 3.0 / 4.5
# 2.0

puts 5 * (12-8) + -15 / 2
# 12

puts 5**2
puts 22 % 4
puts (3-7).abs
# 25
# 2
# 4

puts 'Hello, world! ' + ' Good-bye!'
puts ''
puts '"Idézet!"'
puts "Új 'idézet'!"
puts "o"*3 + 'ps'
puts "Több
soros
szöveg"
# Hello, world!  Good-bye!
#
# "Idézet!"
# Új 'idézet'!
# ooops
# Több
# soros
# szöveg

puts 'a\nb\n' 
puts "a\nb\n"
puts 'a #{6*6} b'
puts "a #{6*6} b"
# a\nb\n
# a
# b
# a #{6*6} b
# a 36 b

x = 12 
puts "a #{x + 5} b"
# a 17 b

puts 10.to_f
puts 5.9.to_i
puts '22'.to_i
puts 10.to_s + 5.9.to_s
# 10.0
# 5
# 22
# 105.9
