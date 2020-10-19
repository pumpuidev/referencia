# encoding: UTF-8

class Szam
  def initialize(x)
    @g  = x
  end
  
  def add x
    @g = @g + x
  end
  
  def show
    puts @g
  end
  
end

s1 = Szam.new 10
s2 = Szam.new 20
s1.add 5
s2.add 7
s1.show
s2.show
# 15
# 27


class Szam2
 def initialize(x)
    @g  = x
  end
  
 attr_reader :g

end

s1 = Szam2.new 10
puts s1.g
# 10

#s1.g = 12
#base8.rb:39: undefined method `g=' for #<Szam2:0x7fcbbb819ca8 @g=10> (NoMethodError)

class Szam3
 def initialize(x)
    @g  = x
  end
     
 attr_reader :g
 attr_writer :g

end

s1 = Szam3.new 10
s1.g = 20
puts s1.g
# 20

class Szam4
 def initialize(x)
    @g  = x
  end
  
 attr_reader :g
 attr_writer :g

 def g_mintszoveg=(str)
   @g = str.to_i
 end
end

s1 = Szam4.new 10
s1.g_mintszoveg = "53"
puts s1.g
# 53

class Szam5
 @@id = 0   
 def initialize(x)
    @@id += 1
    @id = @@id
    @g  = x
  end
  
 attr_reader :g, :id
 attr_writer :g

end

s1 = Szam5.new 10
s2 = Szam5.new 20
puts s1.id
puts s2.id
# 1
# 2


class Szam6
 @@id = 0   
 
 def Szam6.setid x
   @@id = x
 end
 
 def initialize(x)
    @@id += 1
    @id = @@id
    @g  = x
  end
  
 attr_reader :g, :id
 attr_writer :g

end

s1 = Szam6.new 10
Szam6.setid(5)
s2 = Szam6.new 20
puts s1.id
puts s2.id
# 1
# 6


class Szam7
 @@id = 0   
 
 def setid x
   @@id = x
 end
 
 def initialize(x)
    @@id += 1
    @id = @@id
    @g  = x
  end
  
 attr_reader :g, :id
 attr_writer :g

end

s1 = Szam7.new 10
s1.setid(5)
s2 = Szam7.new 20
puts s1.id
puts s2.id
# 1
# 6


