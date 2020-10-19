# encoding: UTF-8

puts Dir.entries(".")
# feladat.txt
# jegy.txt
# ..
# bead.rb
# zh.txt
# eredmeny.txt
# base15.rb
# base14.rb
# tmp
# .
# input.txt
# base12.rb
# tmp2
# base13.rb

puts Dir.pwd
# /home/matej/scny/2016/ea11

Dir.chdir("tmp")
puts Dir.pwd
# /home/matej/scny/2016/ea11/tmp

Dir.chdir("..")

Dir.chdir("tmp"){
   puts Dir.entries(".")
}
# ..
# tmp.txt
# .

puts Dir.pwd
# /home/matej/scny/2016/ea11


Dir.foreach("tmp2"){|n|
  puts n
}
# ..
# tmp2.txt
# .
# subtmp
# tmp5.txt


Dir.chdir("tmp2")

Dir.glob('*.txt'){|n|
  puts n
}
# tmp2.txt
# tmp5.txt

txtfiles = File.join("**", "*.txt") # ** -- alkönyvtárat jelöl


Dir.glob(txtfiles){|n|
  puts n
}
# tmp2.txt
# subtmp/tmp3.txt
# subtmp/tmp4.txt
# tmp5.txt

puts Dir.pwd
#/home/matej/scny/2016/ea11/tmp2

puts File.directory?("subtmp")
# true

puts File.file?("klkl")
# false

out =  `dir`
puts out
# subtmp	tmp2.txt  tmp5.txt

n = "subtmp"
out = `dir #{n}`
puts out
# tmp3.txt  tmp4.txt

n = "subtmp"
out = %x{dir #{n}}
puts out
# tmp3.txt  tmp4.txt

system("dir")
# subtmp	tmp2.txt  tmp5.txt





