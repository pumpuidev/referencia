#!/usr/bin/env ruby
# encoding: UTF-8

puts "Írj be egy számot!"
x = gets    # Vigyázat a parancssori argumentumokkal!
puts "A szám: "+ x + " !"

puts "Írj be egy 2. számot!"
x = gets
puts "A szám: "+ x.chomp + " !"

puts "Írj be egy 3. számot!"
x = STDIN.gets.chomp
puts "A szam" , x

# ruby get.rb inp.txt
