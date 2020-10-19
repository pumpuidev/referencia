# encoding: UTF-8

begin
   raise "PROBA!"
rescue
   puts "Hiba történt: #{$!}"
end
# Hiba történt: PROBA!


class MyException < RuntimeError
  def initialize(param)
    @str = param
  end
  
  def jelzes()
    puts @str
  end  
 
end

begin
   raise MyException.new("Itt hiba van!")
rescue MyException => hiba
   hiba.jelzes()
end    
# Itt hiba van!

begin
   puts "Irj be egy fájlnevet!"
   x = gets.chomp
   f = open(x)
rescue
   puts "Hiba a megnyitásnál!"
   retry
end

# !!! Vigyázat a parancssori argumentumokkal!

