# encoding: UTF-8


a = "hello"

class <<a
    
  def double
    self + self
  end

end

puts a.double
# hellohello

b = "hello"

def b.double
   self + self
end   

puts b.double
#hellohello

#---------------------------------

module Szulo1
   def ertek
      10
   end 
end

module Szulo2
   def show
      puts self.ertek
   end 
end


class Gyerek 

   include Szulo1, Szulo2

end

gy = Gyerek.new
gy.show
# 10

module Szulo1
   def ertek
      20
   end 
end

gy.show
# 20

#-----------------------------------

module MyShow
   def show
      print "Az ertekem:"
      puts self.to_s
   end
end

a = [1,2,3]
a.extend MyShow
a.show
# Az ertekem:123

b = "szoveg" 
b.extend MyShow
b.show
# Az ertekem:szoveg



