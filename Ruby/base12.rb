#!/usr/bin/env ruby
# encoding: UTF-8

begin
   f = File.new(ARGV[0], "r")
rescue 
   $stderr.puts "Hiba a fájlmegnyitás során: #{$!} \n"
else
   f.close
end  



begin
   f = File.new(ARGV[0], "r")
rescue TypeError
   puts "Hiányzó argumentum!"
rescue Errno::ENOENT
   puts "Hibás argumentum!"   
else
   f.close
end



begin
   f = File.new(ARGV[0], "r")
rescue 
   $stderr.print "Hiba a fájlmegnyitás során: #{$!} \n"
else
   f.close
ensure 
   puts "Ez mindenképp kiíródik!"
end  
